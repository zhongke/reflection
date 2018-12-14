#pragma once

template<typename PT, typename P>
class Checker
{
public:
    virtual bool operator () (PT* pot, std::string condition) = 0;
};
