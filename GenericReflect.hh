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
              auto it = attributeMap.begin();
              for (const auto& c : condition) {
                      auto iter = attributeMap.find(c.first);
                      if (it != attributeMap.end()) {
                             (it->second)(c.second);
                      }
              }

       }

       virtual std::map<std::string, CheckerInt<PT, P>> getAttributeMap() const = 0;
protected:
       std::map<std::string, CheckerInt<PT, P>> attributeMap ;

       PT* pot;
       P* pod;

};

