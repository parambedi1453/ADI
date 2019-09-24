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
void printInorder(Node *root)
{
   stack<Node*> s;
    while(true)
    {
        if(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if(s.empty())break;
            else
            {
                root = s.top();
                cout<<root->data<<" ";
                s.pop();
                root=root->right;
            }
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

    printInorder(root);
    cout<<endl;
}