//
// Created by Admin on 2022/7/20.
//
#include <fakeit.hpp>
using namespace fakeit;
struct SomeInterface {
    virtual void foo(int) = 0;
    virtual int bar(int,int) = 0;
};
TEST(FakeitTest, test_fake_it) {
    Mock<SomeInterface> mock;
// Following 3 lines do exactly the same:
    Fake(Method(mock,foo));
    When(Method(mock,foo)).AlwaysReturn();
    When(Method(mock,foo)).AlwaysDo([](...){});

// And here is another example:
    Fake(Method(mock,bar));
    When(Method(mock,bar)).AlwaysReturn(0);
    When(Method(mock,bar)).AlwaysDo([](...){return 0;});

    SomeInterface &i = mock.get();

    // Production code
    i.bar(1, 2);

    // Verify method mock.bar was invoked.
    Verify(Method(mock,bar));

    // Verify method mock.bar was invoked with specific arguments.
    Verify(Method(mock,bar).Using(1,_));
}