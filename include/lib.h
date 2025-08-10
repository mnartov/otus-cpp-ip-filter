#pragma once
#include <vector>
#include <cstdint>
#include <string_view>
#include <tuple>

using IP = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;
using SS = std::string_view;

uint32_t version();
std::vector<SS> splitString(SS, uint8_t);
IP parseIp(SS);
void printIp(const IP&);
uint8_t parseByte(SS);