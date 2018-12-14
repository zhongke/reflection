#pragma once

template<typename PT, typename P>
class Checker
{
public:
    virtual bool operator () (std::string condition) = 0;
};
