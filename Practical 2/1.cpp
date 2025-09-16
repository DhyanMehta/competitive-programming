#include <bits/stdc++.h>
using namespace std;

int Max_Subarray_Sum(vector<int> arr, int n)
{
    int current_sum = arr[0];
    int max_sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}
// -2,1,-3,4,-1,2,1,-5,4
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max_sum = Max_Subarray_Sum(arr, n);
    cout << max_sum << endl;
}