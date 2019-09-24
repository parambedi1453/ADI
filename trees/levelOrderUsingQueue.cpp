/*
    level order traversal using queue
    time required is o(n)
*/
#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public :
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left=NULL;
        right=NULL;
    }
};

void levelOrderUsingQueue(Node *root)
{
    queue<Node *> q;
    Node *curr=root;
    if(root!=NULL)
    q.push(root);
    q.push(NULL);//delemiter for a new line character
    while(!q.empty())
    {
        curr = q.front();
        if(curr==NULL)
        {
            cout<<endl;
             q.pop();
             if(!q.empty())
             q.push(NULL);
        }
        else
        {
            cout<<curr->data<<" ";
            q.pop();
             
             if(curr->left)
             q.push(curr->left);
             if(curr->right)
             q.push(curr->right);
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right=new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
   
   levelOrderUsingQueue(root); 
   
}