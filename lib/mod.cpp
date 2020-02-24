#include "mod.hpp"


int mod_power(int base, int exponent, int mod) {
    int ret = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            ret = (ret * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return ret;
}

int mod_inverse(int n, int mod) {
    return mod_power(n, mod-2, mod);
}

std::vector<int> mod_factorial_table(int n, int mod) {
    std::vector<int> ret({1});
    int factorial = 1;
    for (int m = 1; m <= n; ++m) {
        factorial = (factorial * m) % mod;
        ret.push_back(factorial);
    }
    return ret;
}
