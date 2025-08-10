#include <sstream>
#include <algorithm>
#include <iostream>

#include "lib.h"

int main(int, char **) 
{
	std::cout << "IP Filter version: " << version() << std::endl;

    std::vector<IP> ipPool;

    for (std::string line; std::getline(std::cin, line);) 
    {
        if (line.empty()) 
        {
            break;
        }

        std::istringstream iss(line);
        std::string text;
        std::getline(iss, text, '\t');
        ipPool.emplace_back(parseIp(text));       
    }

    // Reverse lexicographic sort
    std::sort(ipPool.rbegin(), ipPool.rend());

    std::for_each(ipPool.begin(), ipPool.end(), [](const IP& ip) 
    {
        printIp(ip);
    });

    // Filter IPs with first byte equal to 1
    auto filterFirstByte1 = [](const IP& ip) -> bool 
    {
        return std::get<0>(ip) == 1;
    };

    std::for_each(ipPool.begin(), ipPool.end(), [&](const IP& ip) {
        if (filterFirstByte1(ip)) {
            printIp(ip);
        }
    });

    // Filter IPs with first byte equal to 46 and second byte equal to 70
    auto filterFirstByte46SecondByte70 = [](const IP& ip) -> bool {
        return get<0>(ip) == 46 && get<1>(ip) == 70;
    };

    for_each(ipPool.begin(), ipPool.end(), [&](const IP& ip) {
        if (filterFirstByte46SecondByte70(ip)) {
            printIp(ip);
        }
    });

    // Filter IPs with any byte equal to 46
    auto filterAnyByte46 = [](const IP& ip) -> bool {
        return get<0>(ip) == 46 || get<1>(ip) == 46 || get<2>(ip) == 46 || get<3>(ip) == 46;
    };

    for_each(ipPool.begin(), ipPool.end(), [&](const IP& ip) {
        if (filterAnyByte46(ip)) {
            printIp(ip);
        }
    });

	return 0;
}
