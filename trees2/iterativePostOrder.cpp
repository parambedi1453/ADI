/*
    iterative postOrder using two stacks
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
void iterPostOrder(Node *root)
{
    stack<Node *> s1,s2;
    if(root==NULL)
    return ;
    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s2.push(root);
        s1.pop();
        if(root->left)
        s1.push(root->left);
        if(root->right)
        s1.push(root->right);
    }
    while(!s2.empty())
    {
        Node * t = s2.top();
        cout<<t->data<<" ";
        s2.pop();
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

    iterPostOrder(root);
    
}