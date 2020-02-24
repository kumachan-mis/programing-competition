#ifndef _COMPETITION_MOD_HPP_
#define _COMPETITION_MOD_HPP_

#include <vector>

int MOD = (int)(1e9 + 7);

int mod_power(int base, int exponent, int mod = MOD);

int mod_inverse(int n, int mod = MOD);

std::vector<int> mod_factorial_table(int n, int mod = MOD);

#endif // _COMPETITION_MOD_HPP_
