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
        refectingMap =
        {
            {
                "eventTrigger", new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::eventTrigger_hasValue),
                    std::mem_fn(&SubscriberPot::eventTrigger_get),
                    std::mem_fn(&SubscriberPod::setEventTrigger))
            },
            {
                "id", new ProxyString<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::id_hasValue),
                    std::mem_fn(&SubscriberPot::id_get),
                    std::mem_fn(&SubscriberPod::setId))
            }
        };
    }

    RefectingMap getRefectingMap() const
    {
        return refectingMap;
    }
private:

};
