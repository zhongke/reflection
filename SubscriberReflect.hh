#pragma once

#include <vector>
#include <functional>
#include "GenericReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"
#include "CheckerInt.hh"
#include "CheckerString.hh"


class SubscriberReflect : public GenericReflect<SubscriberPot, SubscriberPod>
{
public:
    SubscriberReflect(SubscriberPot* pot, SubscriberPod* pod)
        : GenericReflect<SubscriberPot, SubscriberPod>(pot, pod)
    {
        attributeMap =
        {
            {
                "eventTrigger", new CheckerInt<SubscriberPot, SubscriberPod>(
                    std::bind(&SubscriberPot::eventTrigger_hasValue, pot),
                    std::bind(&SubscriberPot::eventTrigger_get, pot),
                    std::bind(&SubscriberPod::setEventTrigger, pod, std::placeholders::_1))
            },
            {
                "id", new CheckerString<SubscriberPot, SubscriberPod>(
                    std::bind(&SubscriberPot::id_hasValue, pot),
                    std::bind(&SubscriberPot::id_get, pot),
                    std::bind(&SubscriberPod::setId, pod, std::placeholders::_1))
            }
        };
    }

    RefectingMap getAttributeMap() const
    {
        return attributeMap;
    }
private:

};

