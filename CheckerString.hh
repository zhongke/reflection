#include <string>

template<typename PT, typename P>
class CheckerString : public Checker<PT, P>
{
public:
    CheckerString(std::function<bool()> has,
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

private:
    std::function<bool()> hasM;
    std::function<std::string()> getterM;
    std::function<void(std::string)> setterM;
};
