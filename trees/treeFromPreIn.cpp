#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void print(node *root)
{
    if(root==NULL)
    return ;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
node* createTreeFromInPre(int *in,int *pre,int s,int e)
{
    static int i =0;

    if(s>e)
    return NULL;

    node *root = new node(pre[i]);

    int k = -1;

    for(int j=s;j<=e;j++)
    {
        if(pre[i]==in[j])
        {
            k=j;
            break;
        }
    }

    i++;
    root->left = createTreeFromInPre(in,pre,s,k-1);
    root->right  = createTreeFromInPre(in,pre,k+1,e);

    return root;
}
int main()
{
    int in[] = {3,2,8,4,1,6,7,5};
    int pre[] = {1,2,3,4,8,5,6,7};

    node *root = createTreeFromInPre(in,pre,0,7);

    print(root);
}