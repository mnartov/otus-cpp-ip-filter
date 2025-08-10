#include <stdexcept>
#include <iostream>
#include "lib.h"
#include "version.h"

uint32_t version() 
{
    return PROJECT_VERSION_PATCH;
}

std::vector<SS> splitString(SS str, uint8_t symb)
{
    std::vector<SS> result;
    size_t start = 0;
    size_t end = str.find(symb);
    
    while (end != SS::npos) 
    {
        result.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(symb, start);
    }
    result.push_back(str.substr(start));
    return result;
}

IP parseIp(SS str) 
{
    auto parts = splitString(str, '.'); 
    if (parts.size() != 4) 
    {
        throw std::invalid_argument("Invalid IP");
    }
    
    return {
        parseByte(parts[0]),
        parseByte(parts[1]),
        parseByte(parts[2]),
        parseByte(parts[3])
    };
}

void printIp(const IP& ip) 
{
    auto [b1, b2, b3, b4] = ip;
    std::cout << +b1 << '.' << +b2 << '.' << +b3 << '.' << +b4 << '\n';
}

uint8_t parseByte(SS str) 
{
    try {
        size_t pos;
        int byte = std::stoi(std::string(str), &pos);
        if (pos != str.length()) {
            throw std::invalid_argument("Extra characters after number");
        }
        if (byte < 0 || byte > 255) {
            throw std::out_of_range("Byte value out of range");
        }
        return static_cast<uint8_t>(byte);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Invalid byte value: " + std::string(str));
    } catch (const std::out_of_range& e) {
        throw std::out_of_range("Byte value out of range: " + std::string(str));
    }
}