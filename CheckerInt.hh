#include <map>
#include <string>
#include <functional>

#include "Checker.hh"

template<typename PT, typename P>
class CheckerInt : public Checker <PT, P>
{
public:
    CheckerInt(std::function<bool(PT*)> has,
               std::function<int(PT*)> getter,
               std::function<void(int)> setter) :
        hasM(has), getterM(getter), setterM(setter)
    {}

    bool operator () (PT* pot, std::string condition)
    {
        if (!hasM(pot) or condition != std::to_string(getterM(pot)))
        {
            return false;
        }
        else
        {
            // TODO: Move to another place to handle setter
            setterM(getterM(pot));
        }

        return true;

    }

private:
    std::function<bool(PT*)> hasM;
    std::function<int(PT*)> getterM;
    std::function<void(int)> setterM;
};


