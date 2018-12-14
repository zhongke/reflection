#include "gmock/gmock.h"
#include "GenericReflect.hh"
#include "SubscriberReflect.hh"
#include "SubscriberPot.hh"
#include "SubscriberPod.hh"

using namespace testing;
using namespace std;



class ReflectUtil: public Test
{
public:
    GenericReflect<SubscriberPot, SubscriberPod>::PotVector pv =
    {
        new SubscriberPot{"", 0, 0, ""},
        new SubscriberPot{"", 0, 0, ""},
        new SubscriberPot{"", 0, 0, ""},
        new SubscriberPot{"", 0, 0, ""},
        new SubscriberPot{"", 0, 0, ""},
        new SubscriberPot{"", 0, 0, ""}
    };
    SubscriberReflect reflect;

    ReflectUtil() :  reflect(pv)
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

