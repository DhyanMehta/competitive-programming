#include <bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> &arr, vector<int> &subset, int index)
{
    if (index == arr.size())
    {
        cout << "{ ";
        for (int num : subset)
            cout << num << " ";
        cout << "}" << endl;
        return;
    }

    subset.push_back(arr[index]);
    generateSubsets(arr, subset, index + 1);

    subset.pop_back();
    generateSubsets(arr, subset, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> subset;
    generateSubsets(arr, subset, 0);

}