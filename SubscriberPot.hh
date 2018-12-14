#pragma once

#include <string>
#include <vector>

class SubscriberPot {
public:
        std::string id_get() const;
        void id_put(const std::string& id);
        bool id_hasValue() const;

        int eventTrigger_get() const;
        void eventTrigger_put(int eventTrigger);
        bool eventTrigger_hasValue() const;

private:
        std::pair<std::string, bool> idM;
        std::vector<std::string> dataplans;
        std::pair<int, bool> eventTriggerM;


};
