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
Node* buildTree(int a[],int start,int end)
{
    if(start>end)
    return NULL;

    int mid = (start+end)/2;
    Node *root =  new Node(a[mid]);
    root->left = buildTree(a,start,mid-1);
    root->right = buildTree(a,mid+1,end);
    return root;
    
}
int main()
{
    int n;
    cout<<"Enter Size of Array =\n";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    Node *root = buildTree(a,0,n-1);

    cout<<"\n\n\n";
    levelOrderUsingQueue(root)
;
}