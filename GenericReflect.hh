#pragma once

#include <map>
#include <iostream>
#include "Proxy.hh"
#include <vector>

template<typename PT, typename P>
class GenericReflect
{
public:
    using ReflectingMap = std::map<std::string, Proxy<PT, P>*>;
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
        // std::cout << "potVec size :[" << potVec.size() << "]" << std::endl;
        auto map = getReflectingMap();
        PodVector pv;
        for (const auto& pot : potVec)
        {
            // TODO: only check condition
            auto matched = true;

            for (const auto& c : condition)
            {
                // std::cout << "key   : [" << c.first << "]" << std::endl;
                // std::cout << "value : [" << c.second << "]" << std::endl;
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

            // std::cout << "Match ----------------------------------------------" << std::endl;

            if (matched)
            {
                // std::cout << "matched : [" << (matched ? "Matched" : "Unmatched") << "]" << std::endl;
                // std::cout << "size :[" << select.size() << "]" << std::endl;
                auto p = new P;

                // TODO:
                // if no field was selected only set <ID> field or the POD
                if (select.empty()) {
                    // TODO: to be discussed
                    // This <ID> field is very special in different POT type
                    // which means it's different field name but same purpose
                    // So I propose a virtual function to getID() for every Reflect

                    // TODO: More issue here:
                    // Regarding the POD also need to map the specific <ID> field
                    p->setId(getId());
                    pv.push_back(p);
                }
                else
                {
                    for (const auto& s : select)
                    {

                        std::cout << "field   : [" << s << "]" << std::endl;
                        auto it = map.find(s);

                        if (it != map.end())
                        {
                            if (it->second->set(pot, p))
                            {
                                std::cout << "push to vector" << std::endl;
                                pv.push_back(p);
                            }
                        }
                        else
                        {
                            // TODO: key not match, do sth!!!
                            // throw an exception for HTTP response 422 unprocessable
                        }
                    }
                }
            }
            // std::cout << "Select ----------------------------------------------" << std::endl;
        }

        return pv;
    }

protected:
    virtual ReflectingMap getReflectingMap() const = 0;

    virtual std::string getId() = 0;

    ReflectingMap reflectingMap;

    PT* pot;
    P* pod;

    PotVector potVec;
};
