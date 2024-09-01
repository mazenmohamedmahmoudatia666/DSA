// https://leetcode.com/problems/decode-ways/
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX];
string text;

int can2digits1(int idx) {\t// careful!
\tif (idx + 1 >= (int) text.size())
\t\treturn false;\t// 1 digit only

\tif (text[idx] == '1')
\t\treturn true;\t// 1x
\t// 20 to 26 is valid
\treturn text[idx] == '2' && text[idx + 1] <= '6';
\t// 0x or 3x, 4x, ... 9x are invalid
}

int can2digits(int idx) {\t// safer
\tif (idx + 1 >= (int) text.size())
\t\treturn false;\t// 1 digit only
\tint val = stoi(text.substr(idx, 2));
\treturn 1 <= val && val <= 26;
}

int cntWays(int idx) {
\tif (idx == (int) text.size())
\t\treturn 1;   // one valid way

\tif (text[idx] == '0')\t// invalid
\t\treturn 0;\t    \t// no ways

\tauto &ret = memory[idx];
\tif (ret != -1)
\t\treturn ret;

\t// 2 cases: 1 digit or 2 digits
\tret = cntWays(idx + 1);
\tif (can2digits(idx))
\t\tret += cntWays(idx + 2);
\treturn ret;
}

class Solution {

public:
\tint numDecodings(string text_) {
\t\ttext = text_;
\t\tmemset(memory, -1, sizeof(memory));
\t\treturn cntWays(0);
\t}
};


