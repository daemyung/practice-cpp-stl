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

#include <iostream>
#include <cstdlib>
#include <string>
#include <numbers>
#include "fmt/format.h"

using namespace std;
using namespace fmt;

struct Point {
    int x;
    int y;
};

template<>
struct fmt::formatter<Point> {
    template<typename ParseContext>
    constexpr auto parse(ParseContext& context) {
        return context.begin();
    }

    template<typename FormatContext>
    auto format(const Point& point, FormatContext& context) {
        return format_to(context.out(), "[{}, {}]", point.x, point.y);
    }
};

int main(int argc, char* argv[]) {
    const string who{ "everyone" };
    const double pi{ std::numbers::pi };

    cout << format("Hello, {}!\n", who);
    cout << format("π is {}.\n", pi);
    cout << format("Does {} know that π is {:.2f}?\n", who, pi);
    cout << format("Hello, {0}! and π is {1:.5f}.\n", who, pi);
    cout << format("Hello, {1}! and π is {0:.5f}.\n", pi, who);

    const int32_t number = 77;

    cout << format("{:.<10}\n", number);
    cout << format("{:.^10}\n", number);
    cout << format("{:.>10}\n", number);

    Point point{1, 3};
    cout << format("{}\n", point);

    return EXIT_SUCCESS;
}