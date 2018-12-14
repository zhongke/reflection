#include "SubscriberPot.hh"

std::string SubscriberPot::id_get() const
{
       return idM.first;

}
void SubscriberPot::id_put(const std::string& id)
{
       idM.first = id;
       idM.second = true;
}
bool SubscriberPot::id_hasValue() const
{
       return idM.second;
}

int SubscriberPot::eventTrigger_get() const
{
       return eventTriggerM.first;
}
void SubscriberPot::eventTrigger_put(int eventTrigger)
{
       eventTriggerM.first = eventTrigger;
       eventTriggerM.second = true;
}
bool SubscriberPot::eventTrigger_hasValue() const
{
       return eventTriggerM.second;
}
