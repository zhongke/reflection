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

    bool operator () (string condition)
    {
        return true;
    }

    bool operator () (std::function<bool()> hasF,
                      std::function<std::string()> getF,
                      std::function<void(std::string)> setF)

    {

    }

private:
    std::function<bool()> hasM;
    std::function<std::string()> getterM;
    std::function<void(std::string)> setterM;
};
