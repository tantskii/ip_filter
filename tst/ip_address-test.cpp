#include "ip_address.hpp"

#include "gtest/gtest.h"

#include <sstream>
#include <stdexcept>

//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, Lower)
{
    auto ip1 = ipv4::Address(222, 173, 235, 246);
    auto ip2 = ipv4::Address(222, 130, 177, 64 );
    
    ASSERT_LT(ip2, ip1);
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, Greater)
{
    auto ip1 = ipv4::Address(222, 82, 198, 61 );
    auto ip2 = ipv4::Address(1,   29, 168, 152);
    
    ASSERT_GT(ip1, ip2);
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, WriteToStream)
{
    auto ip = ipv4::Address(222, 82, 198, 61 );
    std::ostringstream os;
    
    os << ip;
    
    ASSERT_EQ(os.str(), "222.82.198.61");
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, FromString)
{    
    ipv4::Address ip = ipv4::from_string("222.82.198.61");
    
    ASSERT_EQ(ip.getN1(), 222);
    ASSERT_EQ(ip.getN2(), 82);
    ASSERT_EQ(ip.getN3(), 198);
    ASSERT_EQ(ip.getN4(), 61);
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, FromStringUnderflowError)
{
    ASSERT_THROW(ipv4::from_string("222.-1.198.61"), std::underflow_error);
    ASSERT_THROW(ipv4::from_string("-2.-1.198.61") , std::underflow_error);
    ASSERT_THROW(ipv4::from_string("-2.1.198.61")  , std::underflow_error);
    ASSERT_THROW(ipv4::from_string("222.1.198.-61"), std::underflow_error);
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, FromStringOverflowError)
{
    ASSERT_THROW(ipv4::from_string("1244.1.3.61")         , std::overflow_error);
    ASSERT_THROW(ipv4::from_string("222.1.256.2445")      , std::overflow_error);
    ASSERT_THROW(ipv4::from_string("2220.1000.25600.6100"), std::overflow_error);
}
//-----------------------------------------------------------------------------------------
TEST(IpAddressTest, FromStringIncorrectDataFormatError)
{
    ASSERT_THROW(ipv4::from_string("222")               , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("222.")              , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("222.82.")           , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("222.82.198")        , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("222-82-198-168")    , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("222.82.198.")       , std::runtime_error);
    ASSERT_THROW(ipv4::from_string("tr.ol.lo.lo")       , std::runtime_error);
//    ASSERT_THROW(ipv4::from_string("222.82.198.168.145"), std::runtime_error);
    
    ASSERT_NO_THROW(ipv4::from_string("222.82.198.168"));
}
//-----------------------------------------------------------------------------------------
