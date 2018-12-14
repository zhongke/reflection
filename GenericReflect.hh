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

       void getPodByCondition(std::map<std::string, std::string>& condition)
       {
              auto map = getAttributeMap();
              for (const auto& c : condition) {
                      auto iter = map.find(c.first);
                      if (iter != map.end()) {
                             if (!(*iter->second)(c.second))
                                    break;
                      }
              }

       }
       using RefectingMap=std::map<std::string, Checker<PT, P>*>;
       virtual RefectingMap getAttributeMap() const = 0;
protected:
       RefectingMap attributeMap ;

       PT* pot;
       P* pod;

};

