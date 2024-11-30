// https://leetcode.com/problems/powx-n/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <limits>
#include <random>
using namespace std;

/*

Simple idea
If we have a = 3^5, then 3^10 = a*a  and 3^11 = a*a*3

So divide the power to n/2
Compute the answer
Square it
If n was odd, multiply with extra x

 */

class Solution {
public:
\tdouble fastPow(double x, long long n) {\t\t// log(n)
\t\tif (n == 0)
\t\t\treturn 1.0;

\t\tdouble result = fastPow(x, n / 2);

\t\tresult *= result;
\t\tif (n % 2 != 0)
\t\t\tresult *= x;

\t\treturn result;
\t}
\tdouble myPow(double x, int n) {
\t\tlong long N = n;
\t\tif (N < 0) {
\t\t\tx = 1 / x;
\t\t\tN = -N;\t// -MAX_INT overflows.
\t\t}
\t\treturn fastPow(x, N);
\t}
};

