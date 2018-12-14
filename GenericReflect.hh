#pragma once

#include <map>
#include <iostream>
#include "Proxy.hh"
#include <vector>

template<typename PT, typename P>
class GenericReflect
{
public:
    using RefectingMap = std::map<std::string, Proxy<PT, P>*>;
    using PotVector = std::vector<PT*>;
    using PodVector = std::vector<P*>;

    GenericReflect(const PotVector& pv)
        : potVec(pv)
    {
    }

    // TODO: Use real condition structure for filter and select
    // std::pair<std::map<std::string, std::vector<std::string>>, std::vector<std::string>>
    // 1. map -> filter key : vector
    // 2. vector -> selected fields
    PodVector getPodByCondition(std::map<std::string, std::string>& condition, std::vector<std::string> select)
    {
        auto map = getAttributeMap();

        for (auto pot : potVec)
        {
            // TODO: only check condition
            auto match = true;

            for (const auto& c : condition)
            {
                auto iter = map.find(c.first);

                if (iter != map.end())
                {
                    if (!iter->second->match(pot, c.second))
                    {
                        match = false;
                        break;
                    }
                }
                else
                {
                    // TODO: key not match, do sth!!!
                }
            }

            if (match)
            {

            }
        }

        // TODO: Set selected fields if has value
        PodVector pv;
        return pv;
    }

protected:
    virtual RefectingMap getAttributeMap() const = 0;

    RefectingMap attributeMap;

    PT* pot;
    P* pod;

    PotVector potVec;
};
