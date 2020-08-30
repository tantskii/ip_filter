#include "ip_filter.hpp"

namespace ipv4
{
//-----------------------------------------------------------------------------------------
Any::Any(uint8_t n) : n_(n)
{ }
//-----------------------------------------------------------------------------------------
bool Any::operator()(const Address& ip) const
{
    return ip.getN1() == n_
        || ip.getN2() == n_
        || ip.getN3() == n_
        || ip.getN4() == n_;
}
//-----------------------------------------------------------------------------------------
bool All::operator()(const Address&) const
{
    return true;
}
//-----------------------------------------------------------------------------------------
FirstOne::FirstOne(uint8_t n) : n_(n)
{ }
//-----------------------------------------------------------------------------------------
bool FirstOne::operator()(const Address& ip) const
{
    return ip.getN1() == n_;
}
//-----------------------------------------------------------------------------------------
FirstTwo::FirstTwo(uint8_t n1, uint8_t n2) : n1_(n1), n2_(n2)
{ }
//-----------------------------------------------------------------------------------------
bool FirstTwo::operator()(const Address& ip) const
{
    return ip.getN1() == n1_ && ip.getN2() == n2_;
}
//-----------------------------------------------------------------------------------------
}