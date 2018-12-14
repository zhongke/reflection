#include <map>
#include <string>

using namespace std;

template<typename PT, typename P>
class CheckerInt
{
public:
        CheckerInt(std::function<bool()> has,
                std::function<int()> getter,
                std::function<void(int)> setter) :
                hasM(has), getterM(getter), setterM(setter)
        {}

        bool operator () (string condition) {

                return false;

        }

private:
        std::function<bool()> hasM;
        std::function<int()> getterM;
        std::function<void(int)> setterM;
};


