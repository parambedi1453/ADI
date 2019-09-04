#include<iostream>
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

int countNodes(Node *root)
{
    if(root==NULL)
    return 0;

    int c1 = countNodes(root->left);
    int c2 = countNodes(root->right);

    return c1+c2+1;// for counting the node itself
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
   
    int cnt = countNodes(root);
    cout<<cnt<<endl;
   
}