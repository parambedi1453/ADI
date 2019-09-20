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

void findMirror(node* root)
{
	if(root==NULL)
      return;
  findMirror(root->left);
  findMirror(root->right);
  node *temp = root->left;
  root->left=root->right;
  root->right = temp;
}
node* build(int t[],int i,int n)
{
  if(i>=n)
    return NULL;
  node *root = new node(t[i]);
  root->left = build(t,2*i+1,n);
  root->right = build(t,2*i+2,n);
  return root;
}


int main()
{
    int a[] = {1 ,2 ,3 ,4, 5, 6};
    node *root = build(a,0,6);

}
