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
        reflectingMap =
        {
            {
                "id",
                new ProxyString<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::id_hasValue),
                    std::mem_fn(&SubscriberPot::id_get),
                    std::mem_fn(&SubscriberPod::setId))
            },
            {
                "eventTrigger",
                new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::eventTrigger_hasValue),
                    std::mem_fn(&SubscriberPot::eventTrigger_get),
                    std::mem_fn(&SubscriberPod::setEventTrigger))
            },
            {
                "subscriptionType",
                new ProxyInt<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::subscriptionType_hasValue),
                    std::mem_fn(&SubscriberPot::subscriptionType_get),
                    std::mem_fn(&SubscriberPod::setSubscriptionType))
            },
            {
                "eventTrigger",
                new ProxyString<SubscriberPot, SubscriberPod>(
                    std::mem_fn(&SubscriberPot::peerId_hasValue),
                    std::mem_fn(&SubscriberPot::peerId_get),
                    std::mem_fn(&SubscriberPod::setPeerId))
            }
        };
    }

    ReflectingMap getReflectingMap() const
    {
        return reflectingMap;
    }

    std::string getId() {
        // TODO: We need pot instance here to invoke his member function
        // return SubscriberPot::id_get();
        return pot->id_get();
    }
private:

};
