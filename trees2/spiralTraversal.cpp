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
void spiralPrintTree(Node *root)
{
    if(root==NULL)return;

    stack<Node*> s1,s2;
    s1.push(root);
    while(1)
    {
        if(s1.empty()&&s2.empty())
        return;
        while(!s1.empty())
        {
            Node *temp = s1.top();
            if(temp->left)
            s2.push(temp->left);
            if(temp->right)
            s2.push(temp->right);
            cout<<temp->data<<" ";
            s1.pop();
        }
        while(!s2.empty())
        {
            Node *temp = s2.top();
            if(temp->right)
            s1.push(temp->right);
            if(temp->left)
            s1.push(temp->left);

            cout<<temp->data<<" ";

            s2.pop();
        }
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
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    spiralPrintTree(root);
}