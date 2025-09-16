#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> trustCount(n + 1, 0);
        vector<int> trustedBy(n + 1, 0);

        for (const auto &relation : trust)
        {
            trustCount[relation[0]]++;
            trustedBy[relation[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (trustCount[i] == 0 && trustedBy[i] == n - 1)
            {
                return i;
            }
        }

        return -1;
    }
};

void printTrust(const vector<vector<int>> &trust)
{
    cout << "[";
    for (int i = 0; i < trust.size(); i++)
    {
        cout << "[" << trust[i][0] << "," << trust[i][1] << "]";
        if (i < trust.size() - 1)
            cout << ",";
    }
    cout << "]";
}

void testCase(int n, vector<vector<int>> &trust)
{
    Solution solution;
    cout << "n = " << n << ", trust = ";
    printTrust(trust);
    cout << " -> " << solution.findJudge(n, trust) << endl;
}

int main()
{
    vector<vector<int>> trust1 = {{1, 2}};
    vector<vector<int>> trust2 = {{1, 3}, {2, 3}};
    vector<vector<int>> trust3 = {{1, 3}, {2, 3}, {3, 1}};
    vector<vector<int>> trust4 = {{1, 2}, {2, 3}, {3, 1}, {1, 3}};
    vector<vector<int>> trust5 = {{1, 2}, {1, 3}, {2, 1}, {2, 3}, {1, 4}, {4, 3}, {4, 1}};

    cout << "Test Case 1: ";
    testCase(2, trust1);

    cout << "Test Case 2: ";
    testCase(3, trust2);

    cout << "Test Case 3: ";
    testCase(3, trust3);

    cout << "Test Case 4: ";
    testCase(3, trust4);

    cout << "Test Case 5: ";
    testCase(4, trust5);

    return 0;
}
