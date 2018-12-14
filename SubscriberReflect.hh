#pragma once

#include <vector>
#include <functional>
#include "GenericReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"
#include "ProxyInt.hh"
#include "ProxyString.hh"


class SubscriberReflect : public GenericReflect<SubscriberPot, SubscriberPod>
{
public:
    SubscriberReflect(const PotVector& pv)
        : GenericReflect<SubscriberPot, SubscriberPod>(pv)
    {
        attributeMap =
        {
            {
                "eventTrigger", new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::eventTrigger_hasValue),
                    std::mem_fn(&SubscriberPot::eventTrigger_get),
                    std::bind(&SubscriberPod::setEventTrigger, pod, std::placeholders::_1))
            },
            {
                "id", new ProxyString<SubscriberPot, SubscriberPod>(
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
