#include "gmock/gmock.h"
#include "SubscriberReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"

using namespace testing;
using namespace std;



class ReflectUtil: public Test
{
public:
    SubscriberPot pot;
    SubscriberPod pod;
    SubscriberReflect reflect;

    ReflectUtil() : reflect(&pot, &pod)
    {
    }
};

TEST_F(ReflectUtil, getOneFilter)
{
    map<string, string> condition
    {
        {"eventTrigger", "200"}
    };
    reflect.getPodByCondition(condition);
}

