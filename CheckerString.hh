#include <string>

template<typename PT, typename P>
class CheckerString
{
public:
        CheckerString()
                {

                }

        bool operator () (std::function<bool()> hasF,
                          std::function<std::string()> getF,
                          std::function<void(std::string)> setF)

        {

        }
};
