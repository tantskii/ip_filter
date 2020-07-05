#include "ip_pool.hpp"

namespace ipv4 {
//-----------------------------------------------------------------------------------------
void Pool::print(std::ostream& os, const IFilter& filter) const
{
    for (const Address& address : data_) {
        if (filter(address)) {
            os << address << '\n';
        }
    }
}
//-----------------------------------------------------------------------------------------
void Pool::sort()
{
    std::sort(data_.begin(), data_.end(),
              [](const Address& lhs, const Address& rhs)
    {
        return lhs > rhs;
    });
}
//-----------------------------------------------------------------------------------------
void Pool::pushBack(const Address& ip)
{
    data_.push_back(ip);
}
//-----------------------------------------------------------------------------------------
}
