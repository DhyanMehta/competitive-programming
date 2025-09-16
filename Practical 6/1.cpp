#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (int asteroid : asteroids)
        {
            bool survives = true;

            while (!st.empty() && st.top() > 0 && asteroid < 0 && survives)
            {
                if (st.top() >= abs(asteroid))
                {
                    survives = false;
                }
                else
                {
                    st.pop();
                }
            }

            if (survives)
            {
                st.push(asteroid);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            result[i] = st.top();
            st.pop();
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
    cout << "]" << endl;
}

int main()
{
    Solution solution;

    vector<int> asteroids1 = {8, -8};
    vector<int> asteroids2 = {5, 10, -5};
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> asteroids4 = {-2, -1, 1, 2};

    cout << "Test Case 1: ";
    printVector(solution.asteroidCollision(asteroids1));

    cout << "Test Case 2: ";
    printVector(solution.asteroidCollision(asteroids2));

    cout << "Test Case 3: ";
    printVector(solution.asteroidCollision(asteroids3));

    cout << "Test Case 4: ";
    printVector(solution.asteroidCollision(asteroids4));

    return 0;
}
