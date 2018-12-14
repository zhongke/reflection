#pragma once

#include <map>
#include <iostream>
#include "CheckerInt.hh"

template<typename PT, typename P>
class GenericReflect
{
public:
       GenericReflect(PT* pot, P* pod)
              : pot(pot), pod(pod)
       {
       }

       void getPodByCondition(std::map<std::string, std::string>& condition)
       {
              auto map = getAttributeMap();
              for (const auto& c : condition) {
                      auto iter = map.find(c.first);
                      if (iter != map.end()) {
                             if (!(iter->second)(c.second))
                                    break;
                      }
              }

       }

       virtual std::map<std::string, CheckerInt<PT, P>> getAttributeMap() const = 0;
protected:
       std::map<std::string, CheckerInt<PT, P>> attributeMap ;

       PT* pot;
       P* pod;

};

