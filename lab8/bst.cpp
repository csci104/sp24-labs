#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

/*
int rangeSum(Node *root, int L, int R) {

    int sum = 0;
    //Base case - called on a null node -> return 0!
    if (root == nullptr) {
        return 0;
    }

    //Otherwise get the value of the left and right trees under you (recursive call)
    rangeSum(root->left, L, R);
    rangeSum(root->right, L, R);

    //Sum em
    if (root->key >= L && root->key <= R) {
        sum += root->key;
    }
    //Should add node->key to the sum?
    //Return the sum!
    return sum;
}
*/

int rangeSum(Node *root, int L, int R)
{

    // Base case - called on a null node -> return 0!
    if (root == nullptr)
    {
        return 0;
    }

    int sum = 0;

    if (root->key >= L && root->key <= R)
    {
        sum += root->key;
    }

    // Otherwise get the value of the left and right trees under you (recursive call)
    if (root->key > L)
    {
        sum += rangeSum(root->left, L, R);
    }

    if (root->key < R)
    {
        sum += rangeSum(root->right, L, R);
    }

    // Return the sum!
    return sum;
}

// helper function:
int checkBalance(Node *node, bool &isBalanced)
{
    if (node == nullptr)
    {
        return 0;
    }

    int left = checkBalance(node->left, isBalanced);
    int right = checkBalance(node->right, isBalanced);

    if (abs(left - right) > 1)
        isBalanced = false;

    return 1 + max(left, right);
}

bool isBalanced(Node *root)
{
    // Get the heights of the left and right subtrees - helper func?
    // Determine if this node is balanced! If not ret false!
    bool isBalanced = true;
    checkBalance(root, isBalanced);
    return isBalanced;

    // Check if there are subtrees under us
    // Are they balanced?

    // If all nodes are balanced return true!
}
/*

Given a binary tree, return the level order traversal of its nodes' values. (i.e. from left to right, level by level).


If you're given this binary tree as input:

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> results;
    if (root == NULL)
        return results;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        vector<int> v;

        for (int i = 0; i < s; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
            v.push_back(node->key);
        }
        results.push_back(v);
    }

    return results;
}