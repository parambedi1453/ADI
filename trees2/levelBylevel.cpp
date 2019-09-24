/*
1 
2 3 
4 5 6 7 
*/
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
void levelBylevel(Node *root)
{
    if(root==NULL)
    return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.empty()==false)
    {
        Node *temp = q.front();
        // cout<<temp->data<<" ";
        if(temp==NULL)
        {
            cout<<"\n";
            q.pop();
            if(q.empty()==false)
            q.push(NULL);
        }
        else
        { 
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            q.pop();
            cout<<temp->data<<" ";
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelBylevel(root);
    
}