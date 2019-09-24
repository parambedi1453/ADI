/*
    Iterative Preorder print using stack
*/
#include<iostream>
#include<stack>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right=NULL;
    }
};
void printPreOrder(Node *root)
{
    if(root==NULL)
    return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);
    }
}
int main()
{
    Node *root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printPreOrder(root);
    cout<<endl;
}