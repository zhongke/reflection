#include <string>

#include "Proxy.hh"

template<typename PT, typename P>
class ProxyString : public Proxy<PT, P>
{
public:
    ProxyString(std::function<bool()> has,
                std::function<std::string()> getter,
                std::function<void(std::string)> setter) :
        hasM(has), getterM(getter), setterM(setter)
    {

    }

    bool operator () (PT* pot, std::string condition)
    {
        if (hasM() && getterM() == condition)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    virtual bool match(PT* pot, const std::string& condition)
    {
        return true;
    }

    virtual void move(PT* pot, P* p, const std::string& select)
    {
    }

private:
    std::function<bool()> hasM;
    std::function<std::string()> getterM;
    std::function<void(std::string)> setterM;
};
