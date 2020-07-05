#pragma once

#include "ip_address.hpp"
#include "ip_filter.hpp"

#include <vector>
#include <iostream>
#include <algorithm>

namespace ipv4
{

class Pool
{
public:
    void print(std::ostream& os, const IFilter& filter = ipv4::All()) const;
    void sort();
    void pushBack(const Address&);
private:
    std::vector<Address> data_;
};

}

