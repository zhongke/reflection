#pragma once

#include <string>
#include <vector>

class SubscriberPod {
public:
        std::string getId() const;
        void setId(const std::string& id);
        bool isSetId() const;

        int getEventTrigger() const;
        void setEventTrigger(int eventTrigger);
        bool isSetEventTrigger() const;

private:
        std::pair<std::string, bool> idM;
        std::vector<std::string> dataplans;
        std::pair<int, bool> eventTriggerM;
};
