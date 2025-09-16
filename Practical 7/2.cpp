#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int num : arr)
        {
            freq[num]++;
        }

        unordered_set<int> uniqueFreq;
        for (auto &pair : freq)
        {
            if (!uniqueFreq.insert(pair.second).second)
            {
                return false;
            }
        }

        return true;
    }
};

void printResult(vector<int> &arr, bool result)
{
    cout << "Array: [";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ",";
    }
    cout << "] -> ";
    cout << (result ? "true" : "false") << endl;
}

int main()
{
    Solution solution;

    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    vector<int> arr4 = {1, 1, 1, 2, 2, 2};

    cout << "Test Case 1: ";
    printResult(arr1, solution.uniqueOccurrences(arr1));

    cout << "Test Case 2: ";
    printResult(arr2, solution.uniqueOccurrences(arr2));

    cout << "Test Case 3: ";
    printResult(arr3, solution.uniqueOccurrences(arr3));

    cout << "Test Case 4: ";
    printResult(arr4, solution.uniqueOccurrences(arr4));

    return 0;
}
