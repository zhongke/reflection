#include <map>
#include <string>

#include "Checker.hh"

using namespace std;

template<typename PT, typename P>
class CheckerInt : public Checker <PT, P>
{
public:
        CheckerInt(std::function<bool()> has,
                std::function<int()> getter,
                std::function<void(int)> setter) :
                hasM(has), getterM(getter), setterM(setter)
        {}

        bool operator () (string condition) {
               // TODO:
               /*
               if (!hasM() or condition != std::to_string(getterM())) {
                      return false;
               } else {
                      // setterM(this);
               }
               */
                return true;

        }

private:
        std::function<bool()> hasM;
        std::function<int()> getterM;
        std::function<void(int)> setterM;
};


