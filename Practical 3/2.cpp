#include <iostream>
#include <vector>
using namespace std;

void findTwoOddNumbers(vector<int> &nums)
{
    int xor_all = 0;
    for (int num : nums)
        xor_all ^= num;

    int rightmost_set_bit = xor_all & -xor_all;

    int x = 0, y = 0;
    for (int num : nums)
    {
        if (num & rightmost_set_bit)
            x ^= num;
        else
            y ^= num;
    }

    cout << "The two odd occurring numbers are: " << x << " and " << y << endl;
}
int main()
{
    vector<int> arr = {3, 7, 9, 3, 3, 7, 3, 5};
    findTwoOddNumbers(arr);
}
