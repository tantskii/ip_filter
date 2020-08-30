#include "ip_pool.hpp"
#include "version_control.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

int main()
{
    try
    {
        ipv4::Pool pool;
        
        for (std::string line; std::getline(std::cin, line);) {
            size_t pos = line.find_first_of('\t');
            std::string ip_str = line.substr(0, pos);
            pool.pushBack(ipv4::from_string(ip_str));
        }
        
        pool.sort();
        pool.print(std::cout);
        pool.print(std::cout, ipv4::FirstOne(1));
        pool.print(std::cout, ipv4::FirstTwo(46, 70));
        pool.print(std::cout, ipv4::Any(46));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
