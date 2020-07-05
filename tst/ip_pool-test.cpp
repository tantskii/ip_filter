#include "ip_pool.hpp"

#include "gtest/gtest.h"

#include <sstream>

//-----------------------------------------------------------------------------------------
TEST(IpPoolTest, PushBack)
{
    ipv4::Pool pool;
    std::ostringstream os;
    
    pool.pushBack(ipv4::Address(1, 1,  1, 1));
    pool.pushBack(ipv4::Address(1, 2,  1, 1));
    pool.pushBack(ipv4::Address(1, 10, 1, 1));
    pool.print(os);
    
    ASSERT_EQ(os.str(), "1.1.1.1\n1.2.1.1\n1.10.1.1\n");
}
//-----------------------------------------------------------------------------------------
TEST(IpPoolTest, Sort)
{
    ipv4::Pool pool;
    std::ostringstream os;

    pool.pushBack(ipv4::Address(1, 1,  1, 1));
    pool.pushBack(ipv4::Address(1, 2,  1, 1));
    pool.pushBack(ipv4::Address(1, 10, 1, 1));
    pool.sort();
    pool.print(os);
    
    ASSERT_EQ(os.str(), "1.10.1.1\n1.2.1.1\n1.1.1.1\n");
}
//-----------------------------------------------------------------------------------------
TEST(IpPoolTest, PrintFilteredByFirstOne)
{
    ipv4::Pool pool;
    std::ostringstream os;
    
    pool.pushBack(ipv4::Address(1 , 154, 10, 10 ));
    pool.pushBack(ipv4::Address(37, 154, 10, 10 ));
    pool.pushBack(ipv4::Address(1 , 173, 12, 255));
    pool.pushBack(ipv4::Address(1 , 100, 1 , 76 ));
    pool.pushBack(ipv4::Address(74, 154, 1 , 10 ));
    pool.sort();
    pool.print(os, ipv4::FirstOne(1));
    
    ASSERT_EQ(os.str(), "1.173.12.255\n1.154.10.10\n1.100.1.76\n");
}
//-----------------------------------------------------------------------------------------
TEST(IpPoolTest, PrintFilteredByFirstTwo)
{
    ipv4::Pool pool;
    std::ostringstream os;
    
    pool.pushBack(ipv4::Address(46, 70,  10, 10 ));
    pool.pushBack(ipv4::Address(46, 154, 10, 10 ));
    pool.pushBack(ipv4::Address(46, 70,  12, 255));
    pool.pushBack(ipv4::Address(1 , 70,  1,  76 ));
    pool.pushBack(ipv4::Address(74, 154, 1,  10 ));
    pool.sort();
    pool.print(os, ipv4::FirstTwo(46, 70));
    
    ASSERT_EQ(os.str(), "46.70.12.255\n46.70.10.10\n");
}
//-----------------------------------------------------------------------------------------
TEST(IpPoolTest, PrintFilteredByFirstAny)
{
    ipv4::Pool pool;
    std::ostringstream os;
    
    pool.pushBack(ipv4::Address(46, 70,  10, 10 ));
    pool.pushBack(ipv4::Address(46, 154, 10, 10 ));
    pool.pushBack(ipv4::Address(10, 70,  12, 46));
    pool.pushBack(ipv4::Address(1 , 70,  1,  76 ));
    pool.pushBack(ipv4::Address(74, 154, 46, 10 ));
    pool.sort();
    
    pool.print(os, ipv4::Any(46));
    ASSERT_EQ(os.str(), "74.154.46.10\n46.154.10.10\n46.70.10.10\n10.70.12.46\n");
}
//-----------------------------------------------------------------------------------------
