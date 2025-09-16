#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0)
            return result;

        vector<int> extended(n * 3);
        for (int i = 0; i < n * 3; i++)
        {
            extended[i] = code[i % n];
        }

        int windowSum = 0;
        int start = n;
        int absK = abs(k);

        if (k > 0)
        {
            for (int i = start; i < start + absK; i++)
            {
                windowSum += extended[i + 1];
            }

            for (int i = 0; i < n; i++)
            {
                result[i] = windowSum;
                windowSum -= extended[i + 1];
                windowSum += extended[i + k + 1];
            }
        }
        else
        {
            for (int i = start; i > start - absK; i--)
            {
                windowSum += extended[i - 1];
            }

            for (int i = 0; i < n; i++)
            {
                result[i] = windowSum;
                windowSum -= extended[start + i - absK];
                windowSum += extended[start + i];
            }
        }

        return result;
    }
};

void printVector(const vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
            cout << ",";
    }
    cout << "]";
}

void testCase(vector<int> &code, int k)
{
    Solution solution;
    cout << "Input: code = ";
    printVector(code);
    cout << ", k = " << k << endl;

    vector<int> result = solution.decrypt(code, k);
    cout << "Output: ";
    printVector(result);
    cout << endl
         << endl;
}

int main()
{
    vector<int> code1 = {5, 7, 1, 4};
    vector<int> code2 = {1, 2, 3, 4};
    vector<int> code3 = {2, 4, 9, 3};
    vector<int> code4 = {1, 2, 3, 4, 5};
    vector<int> code5 = {5, 2, 7, 1, 4};

    cout << "Test Case 1:" << endl;
    testCase(code1, 3);

    cout << "Test Case 2:" << endl;
    testCase(code2, 0);

    cout << "Test Case 3:" << endl;
    testCase(code3, -2);

    cout << "Test Case 4:" << endl;
    testCase(code4, 2);

    cout << "Test Case 5:" << endl;
    testCase(code5, -3);

    return 0;
}
