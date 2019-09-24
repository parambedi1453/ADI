#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public :
    int data;
    Node *left;
    Node *right;
    Node (int d)
    {
        data = d;
        left =NULL;
        right = NULL;
    }
};
Node* insert(Node *root,int data)
{
    if(root==NULL)
    {
        Node *temp = new Node(data);
        return temp;
    }
    if(data>root->data)
    root->right = insert(root->right,data);
    else
    root->left = insert(root->left,data);

    return root;
}
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
    root = insert(root,5);
    insert(root,3);
    insert(root,7);
    insert(root,1);
    insert(root,9);
    insert(root,8);
    insert(root,-1);

    printLevelOrder(root);
}