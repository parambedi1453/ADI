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
int height(Node *root)
{
    if(root==NULL)
    return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    return max(h1,h2)+1;
}
int diameter(Node *root)
{
    if(root==NULL)
    return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);
    int ans1 = h1+h2;
    int ans2 = diameter(root->left);
    int ans3 = diameter(root->right);
    return max(ans1,max(ans2,ans3));
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right=new Node(6);
    root->left->right->left=new Node(9);
    root->left->right->right=new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    
    // to print the tree
    levelOrderUsingQueue(root);
    cout<<diameter(root)<<endl;
   
}