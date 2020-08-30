#include "ip_filter.hpp"

#include "gtest/gtest.h"

//-----------------------------------------------------------------------------------------
TEST(FilterTest, FirstOne)
{
    ipv4::FirstOne filter = ipv4::FirstOne(46);
    
    ASSERT_TRUE (filter(ipv4::Address(46, 87, 203, 225)));
    ASSERT_FALSE(filter(ipv4::Address(1 , 87, 203, 225)));
}
//-----------------------------------------------------------------------------------------
TEST(FilterTest, FirstTwo)
{
    ipv4::FirstTwo filter = ipv4::FirstTwo(46, 70);
    
    ASSERT_TRUE (filter(ipv4::Address(46, 70, 225, 39)));
    ASSERT_FALSE(filter(ipv4::Address(46, 87, 203, 225)));
    ASSERT_FALSE(filter(ipv4::Address(45, 70, 203, 225)));
    ASSERT_FALSE(filter(ipv4::Address(45, 71, 203, 225)));
}
//-----------------------------------------------------------------------------------------
TEST(FilterTest, Any)
{
    ipv4::Any filter = ipv4::Any(46);
    
    ASSERT_TRUE (filter(ipv4::Address(186, 204, 34,  46 )));
    ASSERT_TRUE (filter(ipv4::Address(186, 46,  222, 194)));
    ASSERT_TRUE (filter(ipv4::Address(46,  223, 254, 56 )));
    ASSERT_TRUE (filter(ipv4::Address(25,  55,  46,  98 )));
    ASSERT_TRUE (filter(ipv4::Address(46,  46,  46,  46 )));
    ASSERT_FALSE(filter(ipv4::Address(186, 90,  222, 194)));
}
//-----------------------------------------------------------------------------------------
TEST(FilterTest, All)
{
    ipv4::All filter = ipv4::All();
    
    ASSERT_TRUE (filter(ipv4::Address(186, 204, 34,  46 )));
    ASSERT_TRUE (filter(ipv4::Address(186, 46,  222, 194)));
    ASSERT_TRUE (filter(ipv4::Address(46,  223, 254, 56 )));
    ASSERT_TRUE (filter(ipv4::Address(25,  55,  46,  98 )));
    ASSERT_TRUE (filter(ipv4::Address(46,  46,  46,  46 )));
    ASSERT_TRUE (filter(ipv4::Address(186, 90,  222, 194)));
    ASSERT_TRUE (filter(ipv4::Address(46,  70,  225, 39 )));
}
//-----------------------------------------------------------------------------------------
