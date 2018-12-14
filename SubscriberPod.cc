#include "SubscriberPod.hh"

std::string SubscriberPod::getId() const
{
       return idM.first;

}
void SubscriberPod::setId(const std::string& id)
{
       idM.first = id;
       idM.second = true;
}
bool SubscriberPod::isSetId() const
{
       return idM.second;
}

int SubscriberPod::getEventTrigger() const
{
       return eventTriggerM.first;
}
void SubscriberPod::setEventTrigger(int eventTrigger)
{
       eventTriggerM.first = eventTrigger;
       eventTriggerM.second = true;
}
bool SubscriberPod::isSetEventTrigger() const
{
       return eventTriggerM.second;
}
