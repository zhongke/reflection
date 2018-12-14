#pragma once

#include <map>
#include <iostream>
#include "Checker.hh"

template<typename PT, typename P>
class GenericReflect
{
public:
       GenericReflect(PT* pot, P* pod)
              : pot(pot), pod(pod)
       {
       }

    // TODO: Use real condition structure for filter and select
    // std::pair<std::map<std::string, std::vector<std::string>>, std::vector<std::string>>
    // 1. map -> filter key : vector
    // 2. vector -> selected fields
       void getPodByCondition(std::map<std::string, std::string>& condition)
       {
              auto map = getAttributeMap();

              // TODO: only check condition
              for (const auto& c : condition) {
                      auto iter = map.find(c.first);
                      if (iter != map.end()) {
                             if (!(*iter->second)(c.second))
                                    break;
                      }
              }

              // TODO: Set selected fields if has value

       }
       using RefectingMap=std::map<std::string, Checker<PT, P>*>;
       virtual RefectingMap getAttributeMap() const = 0;
protected:
       RefectingMap attributeMap ;

       PT* pot;
       P* pod;

};

