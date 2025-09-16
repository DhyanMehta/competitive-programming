#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};

void testCase(const string &s, const string &p)
{
    Solution solution;
    cout << "Input: s = \"" << s << "\", p = \"" << p << "\"" << endl;
    cout << "Output: " << (solution.isMatch(s, p) ? "true" : "false") << endl;
    cout << endl;
}

int main()
{
    cout << "Test Case 1:" << endl;
    testCase("aa", "a");

    cout << "Test Case 2:" << endl;
    testCase("aa", "*");

    cout << "Test Case 3:" << endl;
    testCase("cb", "?a");

    cout << "Test Case 4:" << endl;
    testCase("adceb", "*a*b");

    cout << "Test Case 5:" << endl;
    testCase("acdcb", "a*c?b");

    cout << "Test Case 6:" << endl;
    testCase("", "*");

    cout << "Test Case 7:" << endl;
    testCase("hello", "h*o");

    cout << "Test Case 8:" << endl;
    testCase("abcdefg", "a?c*f?");

    return 0;
}
