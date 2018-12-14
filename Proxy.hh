#pragma once

template<typename PT, typename P>
class Proxy
{
public:
    virtual bool operator () (PT* pot, std::string condition) = 0;
    // virtual bool check(PT* pot, const std::string& condition) = 0;
    // virtual void move(PT* pot, P* p, const std::string& select) = 0;
};
