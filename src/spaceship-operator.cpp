// MIT License
//
// Copyright (c) 2023 Daemyung Jang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdlib>
#include <cstdio>
#include <compare>

constinit bool USE_SPACESHIP_OPERATOR{false};

struct Num {
    int value;
#if !USE_SPACESHIP_OPERATOR
    constexpr bool operator==(const Num& rhs) const {
        return value == rhs.value;
    }
    constexpr bool operator!=(const Num& rhs) const {
        return !operator==(rhs);
    }
    constexpr bool operator<(const Num& rhs) const {
        return value < rhs.value;
    }
    constexpr bool operator>(const Num& rhs) const {
        return value > rhs.value;
    }
    constexpr bool operator<=(const Num& rhs) const {
        return !operator>(rhs);
    }
    constexpr bool operator>=(const Num& rhs) const {
        return !operator<(rhs);
    }
#else
    constexpr auto operator<=>(const Num&) const = default;
#endif
};

int main(int argc, char* argv[]) {
    constexpr Num a{7};
    constexpr Num b{7};
    constexpr Num c{42};

    static_assert(a < c);
    static_assert(c > a);
    static_assert(a == b);
    static_assert(a <= b);
    static_assert(a <= c);
    static_assert(c >= a);
    static_assert(a != c);
    puts("done");

    return EXIT_SUCCESS;
}