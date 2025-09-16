#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    water += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
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

void testCase(vector<int> &height)
{
    Solution solution;
    cout << "Input: height = ";
    printArray(height);
    cout << endl;
    cout << "Output: " << solution.trap(height) << endl;
    cout << endl;
}

int main()
{
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height2 = {4, 2, 0, 3, 2, 5};
    vector<int> height3 = {0, 1, 0, 1, 0, 1};
    vector<int> height4 = {5, 4, 1, 2};
    vector<int> height5 = {2, 0, 2};

    cout << "Test Case 1:" << endl;
    testCase(height1);

    cout << "Test Case 2:" << endl;
    testCase(height2);

    cout << "Test Case 3:" << endl;
    testCase(height3);

    cout << "Test Case 4:" << endl;
    testCase(height4);

    cout << "Test Case 5:" << endl;
    testCase(height5);

    return 0;
}
