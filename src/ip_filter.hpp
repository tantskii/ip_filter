#pragma once

#include "ip_address.hpp"

namespace ipv4
{

// Filter's interface
// operator() returns true if ip adrees
// satisfies the requirements of Filter
class Filter
{
public:
    virtual ~Filter() = default;
    virtual bool operator()(const Address&) const = 0;
};

// Filter that passes every ip-address
class All : public Filter
{
public:
    bool operator()(const Address&) const override;
};

// Filter that passess ip-adress if it's
// first number is equal to n_
class FirstOne : public Filter
{
public:
    FirstOne(uint8_t);
    bool operator()(const Address&) const override;
private:
    const uint8_t n_;
};

// Filter that passes ip adress if it's
// first and second nubmers are equal to n1_ and n2_
class FirstTwo : public Filter
{
public:
    FirstTwo(uint8_t, uint8_t);
    bool operator()(const Address&) const override;
private:
    const uint8_t n1_;
    const uint8_t n2_;
};

// Filter that passes ip adress if it's
// any number is equal to n_
class Any : public Filter
{
public:
    Any(uint8_t);
    bool operator()(const Address&) const override;
private:
    const uint8_t n_;
};

}
