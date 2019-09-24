#include<iostream>
#include<queue>
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
void printLevelOrder(Node *root)
{
    queue<Node*> q;
    if(root==NULL)
    return ;
    q.push(root);
    while(q.empty()==false)
    {
        Node *temp = q.front();
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
        q.pop();
        cout<<temp->data<<" ";
    }
}
int main()
{
    Node *root = NULL;
    root = new Node(10);
    root->left = new Node(16);
    root->right = new Node(5);
    root->left->right = new Node(-3);
    root->right->left = new Node(6);
    root->right->right = new Node(11);
    printLevelOrder(root);
}