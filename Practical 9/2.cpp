#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<pair<int, int>> st; // {temperature, index}

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > st.top().first)
            {
                answer[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        return answer;
    }
};

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ",";
    }
    cout << "]";
}

void testCase(vector<int> &temperatures)
{
    Solution solution;
    cout << "Input: temperatures = ";
    printArray(temperatures);
    cout << endl;

    vector<int> result = solution.dailyTemperatures(temperatures);
    cout << "Output: ";
    printArray(result);
    cout << endl
         << endl;
}

int main()
{
    vector<int> temp1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> temp2 = {30, 40, 50, 60};
    vector<int> temp3 = {30, 60, 90};
    vector<int> temp4 = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70};
    vector<int> temp5 = {55, 38, 53, 81, 61, 93, 97, 32, 43, 78};

    cout << "Test Case 1:" << endl;
    testCase(temp1);

    cout << "Test Case 2:" << endl;
    testCase(temp2);

    cout << "Test Case 3:" << endl;
    testCase(temp3);

    cout << "Test Case 4:" << endl;
    testCase(temp4);

    cout << "Test Case 5:" << endl;
    testCase(temp5);

    return 0;
}
