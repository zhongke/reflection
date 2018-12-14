#include <map>
#include <string>
#include <functional>

#include "Proxy.hh"

template<typename PT, typename P>
class ProxyInt : public Proxy <PT, P>
{
public:
    ProxyInt(std::function<bool(PT*)> has,
             std::function<int(PT*)> getter,
             std::function<void(P*, int)> setter) :
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
            //setterM(getterM(pot));
        }

        return true;

    }

    virtual bool match(PT* pot, const std::string& condition)
    {
        return true;
    }

    virtual void move(PT* pot, P* p, const std::string& select)
    {
    }

private:
    std::function<bool(PT*)> hasM;
    std::function<int(PT*)> getterM;
    std::function<void(P*, int)> setterM;
};
