#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> values;
        ListNode *current = head;

        while (current != nullptr)
        {
            values.push_back(current->val);
            current = current->next;
        }

        int maxSum = 0;
        int n = values.size();

        for (int i = 0; i < n / 2; i++)
        {
            maxSum = max(maxSum, values[i] + values[n - 1 - i]);
        }

        return maxSum;
    }
};

ListNode *createLinkedList(vector<int> &values)
{
    if (values.empty())
        return nullptr;

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

int main()
{
    vector<int> list1 = {5, 4, 2, 1};
    vector<int> list2 = {4, 2, 2, 3};

    Solution solution;

    ListNode *head1 = createLinkedList(list1);
    ListNode *head2 = createLinkedList(list2);

    cout << solution.pairSum(head1) << endl;
    cout << solution.pairSum(head2) << endl;

    return 0;
}
