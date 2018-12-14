#pragma once

#include <map>
#include <iostream>
#include "CheckerInt.hh"

template<typename PT, typename P>
class GenericReflect
{
public:

       void getPodByCondition(std::map<std::string, std::string>& condition)
       {
              auto map = getAttributeMap();
              auto it = map.begin();
              for (const auto& c : condition) {
                      auto iter = map.find(c.first);
                      if (it != map.end()) {
                             if (!(it->second)(c.second))
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

