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
    PodVector getPodByCondition(const std::map<std::string, std::string>& condition,
                                const std::vector<std::string>& select)
    {
        auto map = getRefectingMap();
        PodVector pv;
        for (auto pot : potVec)
        {
            // TODO: only check condition
            auto matched = true;

            for (const auto& c : condition)
            {
                auto iter = map.find(c.first);

                if (iter != map.end())
                {
                    if (!iter->second->match(pot, c.second))
                    {
                        matched = false;
                        break;
                    }
                }
                else
                {
                    // TODO: key not match, do sth!!!
                }
            }

            if (matched)
            {
                auto p = new P;

                for (const auto& s : select)
                {
                    auto it = map.find(s);

                    if (it != map.end())
                    {
                        // TODO: Check if this field has value in Pot or not
                        it->second->set(pot, p);
                        pv.push_back(p);
                    }
                    else
                    {
                        // TODO: key not match, do sth!!!
                    }
                }
            }
        }

        return pv;
    }

protected:
    virtual RefectingMap getRefectingMap() const = 0;

    RefectingMap refectingMap;

    PT* pot;
    P* pod;

    PotVector potVec;
};
