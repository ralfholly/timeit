// Copyright 2019 Ralf Holly.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
// of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:
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

#ifndef TIMEIT_H_
#define TIMEIT_H_

#if __cplusplus < 201103L
#error "This header requires C++11 or later."
#endif

#include <functional>
#include <chrono>

// Calculates (and optionally prints) the runtime in seconds of a given block
// of code.
//
// Example:
// TIMEIT_PRINT(result_matrix = maxtrix_mul(matrix1, matrix2));
// Output:
// result_matrix = maxtrix_mul(matrix1, matrix2): 0.000031

#define TIMEIT(code) timeit([&]() {code;})
#define TIMEIT_PRINT(code) std::cout << #code << ": " << timeit([&]() {code;}) << std::endl;

inline double timeit(const std::function<void()>& lambda) {
    using hires_clock = std::chrono::high_resolution_clock;
    auto start = hires_clock::now();
    lambda();
    auto end = hires_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start);
    return duration.count();
}

#endif
