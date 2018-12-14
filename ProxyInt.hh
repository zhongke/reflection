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

    virtual bool match(PT* pot, const std::string& condition)
    {
        if (hasM(pot) && std::to_string(getterM(pot)) == condition)
            return true;
        else
            return false;
    }

    virtual void set(PT* pot, P* p)
    {
        setterM(p, getterM(pot));
    }

private:
    std::function<bool(PT*)> hasM;
    std::function<int(PT*)> getterM;
    std::function<void(P*, int)> setterM;
};
