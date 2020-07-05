#include "ip_address.hpp"

namespace ipv4 {

//-----------------------------------------------------------------------------------------
Address::Address(uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4)
    : data_(std::make_tuple(a1, a2, a3, a4))
{ }
//-----------------------------------------------------------------------------------------
uint8_t Address::getN1() const { return std::get<0>(data_); }
uint8_t Address::getN2() const { return std::get<1>(data_); }
uint8_t Address::getN3() const { return std::get<2>(data_); }
uint8_t Address::getN4() const { return std::get<3>(data_); }
//-----------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Address& ip)
{
    os << unsigned(ip.getN1()) << '.'
       << unsigned(ip.getN2()) << '.'
       << unsigned(ip.getN3()) << '.'
       << unsigned(ip.getN4());
    
    return os;
}
//-----------------------------------------------------------------------------------------
bool Address::operator<(const Address& rhs) const
{
    return data_ < rhs.data_;
}
//-----------------------------------------------------------------------------------------
bool Address::operator>(const Address& rhs) const
{
    return rhs < *this;
}
//-----------------------------------------------------------------------------------------
Address from_string(const std::string& ip_str)
{
    int n1_i, n2_i, n3_i, n4_i;
    size_t pos1 = ip_str.find_first_of('.');
    size_t pos2 = ip_str.find('.', pos1 + 1);
    size_t pos3 = ip_str.find('.', pos2 + 1);
    
    // throw exception if pos* == std::string::npos
    if (pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos)
    {
        std::string error_msg = "Incorrect data format: " + ip_str;
        throw std::runtime_error(error_msg);
    }
    
    try
    {
        n1_i = stoi(ip_str.substr(0, pos1));
        n2_i = stoi(ip_str.substr(pos1 + 1, pos2 - pos1));
        n3_i = stoi(ip_str.substr(pos2 + 1, pos3 - pos2));
        n4_i = stoi(ip_str.substr(pos3 + 1, std::string::npos));
    }
    catch (const std::invalid_argument& ex) { throw ex; }
    catch (const std::out_of_range&     ex) { throw ex; }

    
    // throw exception if values > 255
    if (n1_i > 255 || n2_i > 255 || n3_i > 255 || n4_i > 255)
    {
        std::string error_msg = "All values must be in range [0, 255]: " + ip_str;
        throw std::overflow_error(error_msg);
    }
    
    // throw exception if values < 0
    if (n1_i < 0 || n2_i < 0 || n3_i < 0 || n4_i < 0)
    {
       std::string error_msg = "All values must be in range [0, 255]: " + ip_str;
       throw std::underflow_error(error_msg);
    }

    return Address(static_cast<uint8_t>(n1_i),
                   static_cast<uint8_t>(n2_i),
                   static_cast<uint8_t>(n3_i),
                   static_cast<uint8_t>(n4_i));
}
//-----------------------------------------------------------------------------------------
}


