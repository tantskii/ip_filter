#pragma once

#include <iostream>
#include <cstdint>
#include <tuple>
#include <stdexcept>

namespace ipv4
{

class Address
{
public:
    explicit Address(uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t getN1() const;
    uint8_t getN2() const;
    uint8_t getN3() const;
    uint8_t getN4() const;
    
    bool operator<(const Address& rhs) const;
    bool operator>(const Address& rhs) const;
private:
    std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> data_;
};

std::ostream& operator<<(std::ostream& os, const Address& ip);

Address from_string(const std::string&);

}

