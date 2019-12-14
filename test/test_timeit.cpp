
#include "gmock/gmock.h"

#include "timeit.h"

using namespace testing;
using namespace std;

namespace testing {
namespace test_timeit {


long long long_function(size_t n) {
    volatile long long sum = 0;
    for (volatile size_t i = 0; i < n; ++i) {
        sum += i;
    }
    return sum;
}

TEST(test_timeit, simple) {
    auto duration = TIMEIT(
        long_function(1000000000);
    );
    cout << "Duration for 1 billion: " << duration << endl;

    TIMEIT_PRINT(long_function(1000000));
    TIMEIT_PRINT(
        long_function(1000000);
        long_function(2000000);
        long_function(3000000);
    );
}

} // namespace test_timeit
} // namespace testing
