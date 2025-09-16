#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestAwesome(string s)
    {
        vector<int> firstSeen(1024, s.length());
        firstSeen[0] = -1;
        int mask = 0;
        int maxLen = 1;

        for (int i = 0; i < s.length(); i++)
        {
            mask ^= (1 << (s[i] - '0'));

            maxLen = max(maxLen, i - firstSeen[mask]);

            for (int j = 0; j < 10; j++)
            {
                int newMask = mask ^ (1 << j);
                maxLen = max(maxLen, i - firstSeen[newMask]);
            }

            firstSeen[mask] = min(firstSeen[mask], i);
        }

        return maxLen;
    }
};

void testCase(const string &s)
{
    Solution solution;
    cout << "Input: s = \"" << s << "\"" << endl;
    cout << "Output: " << solution.longestAwesome(s) << endl;
    cout << endl;
}

int main()
{
    cout << "Test Case 1:" << endl;
    testCase("3242415");

    cout << "Test Case 2:" << endl;
    testCase("12345678");

    cout << "Test Case 3:" << endl;
    testCase("213123");

    cout << "Test Case 4:" << endl;
    testCase("11111");

    cout << "Test Case 5:" << endl;
    testCase("9494940");

    cout << "Test Case 6:" << endl;
    testCase("01234321");

    cout << "Test Case 7:" << endl;
    testCase("1234123");

    cout << "Test Case 8:" << endl;
    testCase("999999");

    return 0;
}
