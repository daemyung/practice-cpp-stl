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
#include <iostream>
#include <concepts>

using namespace std;

template<typename T>
T sub42(T value) {
    return value - 42;
}

template<typename T>
concept Numeric = integral<T> || floating_point<T>;

template<typename T>
requires Numeric<T>
T add42(T value) {
    return value + 42;
}

template<Numeric T>
T mul42(T value) {
    return value * 42;
}

int main(int argc, char* argv[]) {
    cout << "100 - 42 = " << sub42(100) << endl;
    cout << "100 - 42 = " << sub42("100") << endl; // Compile and run without an error.
    cout << "100 + 42 = " << add42(100) << endl;
    // cout << "100 - 42 = " << add42("100") << endl; // Compilation error!!!
    cout << "100 * 42 = " << mul42(100) << endl;

    return EXIT_SUCCESS;
}