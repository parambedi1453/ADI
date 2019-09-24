#include<iostream>
#include<vector>
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
int printRootToLeafPath(Node *root,int sum,vector<int> &v)
{
    if(root==NULL)
    return 0;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->data == sum)
        {
            v.push_back(root->data);
            return 1;
        }
        else
        return 0;
    }

    if(printRootToLeafPath(root->left,sum-root->data,v))
    {
        v.push_back(root->data);
        return 1;
    }
    if(printRootToLeafPath(root->right,sum-root->data,v))
    {
        v.push_back(root->data);
        return 1;
    }
    return 0;
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
    int sum = 26;
    
    vector<int> v;
    if(printRootToLeafPath(root,sum,v))
    {
        //output vector will be from leaf to root reverse it print
        for(int i=v.size()-1;i>=0;i--)
        cout<<v[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"NO SUCH PATH IS PISSIBLE\n";
    }
    
}