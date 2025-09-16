#include <bits/stdc++.h>
using namespace std;

vector<string> generateBinary(int n)
{
    vector<string> result;
    queue<string> q;

    q.push("1");

    for (int i = 0; i < n; i++)
    {
        string current = q.front();
        q.pop();
        result.push_back(current);

        q.push(current + "0");
        q.push(current + "1");
    }

    return result;
}

void printBinaryNumbers(const vector<string> &numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i];
        if (i < numbers.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

int main()
{
    int testCases[] = {2, 5, 10};

    for (int n : testCases)
    {
        cout << "Binary numbers from 1 to " << n << ": ";
        vector<string> binary = generateBinary(n);
        printBinaryNumbers(binary);
    }

    return 0;
}
