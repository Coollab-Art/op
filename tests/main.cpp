#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <op/op.hpp>

TEST_CASE("Scalable")
{
    struct MyScalable : public op::Scalable<MyScalable> {
        MyScalable(float value)
            : value{value} {}

        float value;
    };

    SUBCASE("Multiplication")
    {
        MyScalable x{3.f};
        SUBCASE("Operator *=")
        {
            x *= 2.f;
        }
        SUBCASE("Left scale")
        {
            x = 2.f * x;
        }
        SUBCASE("Right scale")
        {
            x = x * 2.f;
        }
        CHECK(x.value == doctest::Approx{6.f});
    }

    SUBCASE("Division")
    {
        MyScalable x{3.f};
        SUBCASE("Operator /=")
        {
            x /= 2.f;
        }
        SUBCASE("Operator /")
        {
            x = x / 2.f;
        }
        CHECK(x.value == doctest::Approx{1.5f});
    }
}