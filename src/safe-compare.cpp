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
#include <utility>
#include <iostream>

using namespace std;

template <typename X, typename Y>
constexpr bool compare_less(X x, Y y) {
    using UX = make_unsigned_t<X>;
    using UY = make_unsigned_t<Y>;

    if constexpr (is_signed_v<X> && is_signed_v<Y>) {
        return x < y;
    } else if constexpr (is_signed_v<X>) {
        return x < 0 || static_cast<UX>(x) < y;
    } else {
        return !(y < 0) && x < static_cast<UY>(y);
    }
}

int main(int argc, char* argv[]) {
    int x{-3};
    unsigned y{7};

    cout << x << " <  " << y << ": ";
    if (x < y)
        puts("true");
    else
        puts("false");

    cout << x << " <  " << y << ": ";
    if (cmp_less(x, y))
        puts("true");
    else
        puts("false");

    cout << boolalpha;
    cout << x << " == " << y << ": " << cmp_equal(x, y) << endl;
    cout << x << " != " << y << ": " << cmp_not_equal(x, y) << endl;
    cout << x << " <  " << y << ": " << cmp_less(x, y) << endl;
    cout << x << " <= " << y << ": " << cmp_less_equal(x, y) << endl;
    cout << x << " >  " << y << ": " << cmp_greater(x, y) << endl;
    cout << x << " >= " << y << ": " << cmp_greater_equal(x, y) << endl;
    cout << noboolalpha;

    cout << x << " <  " << y << ": ";
    if (compare_less(x, y))
        puts("true");
    else
        puts("false");

    return EXIT_SUCCESS;
}