/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <iostream>
 using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
};
typedef Node* Tree; // dùng để đặt tên cho 1 kiểu dữ liệu có sẵn

Node *createNode(int x)
{
    Node *p = new Node;
    if(p == NULL) cout << "Memory is full";
    p->val = x;
    p->left = p->right = NULL;
    return p;
}

void inputTree(Tree T)
{
    if(T->val == NULL)
    {

    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
}