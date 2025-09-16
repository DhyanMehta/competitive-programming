#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (i == levelSize - 1)
                {
                    result.push_back(node->val);
                }

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return result;
    }
};

TreeNode *createTree(vector<string> &values)
{
    if (values.empty())
        return nullptr;

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(values[0]));
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        if (i < values.size() && values[i] != "null")
        {
            current->left = new TreeNode(stoi(values[i]));
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != "null")
        {
            current->right = new TreeNode(stoi(values[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

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

    vector<string> tree1 = {"1", "2", "3", "4", "5", "null", "null"};
    vector<string> tree2 = {"1", "null", "3"};
    vector<string> tree3 = {"1", "2", "3", "null", "5", "null", "4"};

    TreeNode *root1 = createTree(tree1);
    TreeNode *root2 = createTree(tree2);
    TreeNode *root3 = createTree(tree3);

    cout << "Test Case 1: ";
    printVector(solution.rightSideView(root1));

    cout << "Test Case 2: ";
    printVector(solution.rightSideView(root2));

    cout << "Test Case 3: ";
    printVector(solution.rightSideView(root3));

    return 0;
}
