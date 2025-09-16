#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }

    string sortVowels(string s)
    {
        vector<char> vowels;
        vector<int> positions;

        for (int i = 0; i < s.length(); i++)
        {
            if (isVowel(s[i]))
            {
                vowels.push_back(s[i]);
                positions.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end());

        for (int i = 0; i < positions.size(); i++)
        {
            s[positions[i]] = vowels[i];
        }

        return s;
    }
};

void testCase(const string &s)
{
    Solution solution;
    cout << "Input: s = \"" << s << "\"" << endl;
    cout << "Output: \"" << solution.sortVowels(s) << "\"" << endl;
    cout << endl;
}

int main()
{
    cout << "Test Case 1:" << endl;
    testCase("lEetcOde");

    cout << "Test Case 2:" << endl;
    testCase("lYmpH");

    cout << "Test Case 3:" << endl;
    testCase("aAeEiIoOuU");

    cout << "Test Case 4:" << endl;
    testCase("Hello World");

    cout << "Test Case 5:" << endl;
    testCase("AEIOU aeiou");

    return 0;
}
