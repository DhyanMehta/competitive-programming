#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGondolas(int N, int X, vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = N - 1;
        int gondolas = 0;

        while (left <= right)
        {
            if (left == right)
            {
                gondolas++;
                break;
            }

            if (arr[left] + arr[right] <= X)
            {
                gondolas++;
                left++;
                right--;
            }
            else
            {
                gondolas++;
                right--;
            }
        }

        return gondolas;
    }
};

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

void testCase(int N, int X, vector<int> &arr)
{
    Solution solution;
    cout << "N = " << N << ", X = " << X << ", arr = ";
    printArray(arr);
    cout << " -> " << solution.minGondolas(N, X, arr) << endl;
}

int main()
{
    vector<int> arr1 = {7, 2, 3, 9};
    vector<int> arr2 = {2, 3, 3, 4};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    vector<int> arr4 = {5, 5, 5, 5, 5};
    vector<int> arr5 = {1, 1, 1, 2, 2, 2, 3, 3};

    cout << "Test Case 1: ";
    testCase(4, 10, arr1);

    cout << "Test Case 2: ";
    testCase(4, 6, arr2);

    cout << "Test Case 3: ";
    testCase(5, 7, arr3);

    cout << "Test Case 4: ";
    testCase(5, 9, arr4);

    cout << "Test Case 5: ";
    testCase(8, 4, arr5);

    return 0;
}
