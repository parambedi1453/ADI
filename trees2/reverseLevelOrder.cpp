/*
7 6 5 4 
3 2 
1
*/
#include<iostream>
#include<stack>
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
void reverseLevel(Node *root)
{
    stack<Node*> s;
    queue<Node*> q;
    if(root==NULL)
    return ;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node *temp = q.front();
        if(temp==NULL)
        {
            q.pop();
            s.push(NULL);
            if(!q.empty())
            q.push(NULL);
            
        }
        else
        {
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            s.push(temp);
            q.pop();
        }
    }
    s.pop();

    while(!s.empty())
    {
        Node *t = s.top();
        if(t == NULL)
        cout<<endl;
        else
        {
            cout<<t->data<<" ";
        }
        s.pop();
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

    reverseLevel(root);
    
}