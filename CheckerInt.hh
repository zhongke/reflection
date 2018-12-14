#include <map>
#include <string>

#include "Checker.hh"

#include <iostream>


template<typename PT, typename P>
class CheckerInt : public Checker <PT, P>
{
public:
    CheckerInt(std::function<bool()> has,
               std::function<int()> getter,
               std::function<void(int)> setter) :
        hasM(has), getterM(getter), setterM(setter)
    {}

    bool operator () (std::string condition)
    {
        if (!hasM() or condition != std::to_string(getterM())) {
               return false;
        } else {
            // TODO: Move to another place to handle setter
               setterM(getterM());
        }

        return true;

    }

private:
    std::function<bool()> hasM;
    std::function<int()> getterM;
    std::function<void(int)> setterM;
};


