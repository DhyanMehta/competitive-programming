#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum2;
    vector<int> arr(n);
    int sum = ((n + 2) * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum2 += arr[i];
    }
    cout << sum - sum2 << endl;
}