#include "gmock/gmock.h"
#include "SubscriberReflect.hh"

using namespace testing;
using namespace std;



class ReflectUtil: public Test
{
public:
        SubscriberReflect reflect;

        ReflectUtil() : reflect(nullptr, nullptr)
        {
        }
};

TEST_F(ReflectUtil, getOneFilter)
{
       map<string, string> condition {
              {"eventTrigger", "200"}
       };
       reflect.getPodByCondition(condition);
}
