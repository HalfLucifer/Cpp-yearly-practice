#include <iostream>

using namespace std;

inline int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

template <int a, int b>
struct gcd_meta {
    static constexpr int value = gcd_meta<b, a % b>::value;
};

template <int a>
struct gcd_meta<a, 0> {
    static constexpr int value = a;
};

void test_cases() {
    cout << "gcd_recursive(5, 15) = " << gcd_recursive(5, 15) << endl;
    cout << "gcd_recursive(13, 19) = " << gcd_recursive(13, 19) << endl;
    cout << "gcd_recursive(60, 18) = " << gcd_recursive(60, 18) << endl;

    cout << "gcd_meta(5, 15) = " << gcd_meta<5, 15>::value << endl;
    cout << "gcd_meta(13, 19) = " << gcd_meta<13, 19>::value << endl;
    cout << "gcd_meta(60, 18) = " << gcd_meta<60, 18>::value << endl;
}
