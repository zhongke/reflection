#pragma once

#include <vector>
#include <functional>
#include "GenericReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"



class SubscriberReflect : public GenericReflect<SubscriberPot, SubscriberPod>
{
public:
       SubscriberReflect(SubscriberPot* pot, SubscriberPod* pod)
              : GenericReflect<SubscriberPot, SubscriberPod>(pot, pod)
       {
               attributeMap = {
                      {"eventTrigger", CheckerInt<SubscriberPot, SubscriberPod>(std::bind(&SubscriberPot::eventTrigger_hasValue, pot),
                                                                                std::bind(&SubscriberPot::eventTrigger_get, pot),
                                                                                std::bind(&SubscriberPod::setEventTrigger, pod, std::placeholders::_1))},
               };
       }

       std::map<std::string, CheckerInt<SubscriberPot, SubscriberPod>> getAttributeMap() const
       {
              return attributeMap;
       }
private:

};

