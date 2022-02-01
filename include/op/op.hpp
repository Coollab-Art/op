#pragma once

namespace op {

template<typename Derived>
class Scalable {
public:
    friend Derived operator*(float x, Derived derived)
    {
        return Derived{derived.value * x};
    }

    friend Derived operator*(Derived derived, float x)
    {
        return operator*(x, derived);
    }

    friend Derived operator/(Derived derived, float x)
    {
        return Derived{derived.value / x};
    }

    void operator*=(float x)
    {
        This().value *= x;
    }

    void operator/=(float x)
    {
        This().value /= x;
    }

private:
    Derived& This()
    {
        return *static_cast<Derived*>(this);
    }
};

} // namespace op
