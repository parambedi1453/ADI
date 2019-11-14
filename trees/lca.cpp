/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int f1,f2;
TreeNode* getlca(TreeNode *root,int B,int C)
{
    if(root==NULL)
    return NULL;
    
    
    TreeNode* ans1 = getlca(root->left,B,C);
    TreeNode* ans2 = getlca(root->right,B,C);
    if(root->val==B)
    {
        f1=1;
        return root;
    }
    if(root->val==C)
    {
        f2=1;
        return root;
    }
    
    if(ans1&&ans2)
    return root;
    else if(ans1==NULL && ans2!=NULL)
    return ans2;
    else if(ans1!=NULL && ans2==NULL)
    return ans1;
    else
    return NULL;
}
int Solution::lca(TreeNode* root, int B, int C) {
    
    
    f1=0;
    f2=0;
    TreeNode *ans = getlca(root,B,C);


    // checking if two are same then and exist in treee f1 or f2 will become 1 hence
      if(B==C )
      {
          if(f1||f2)
          return B;
      }
  
//   first check if element exist in tree or not
    if(f1&&f2)
    {
        
        if(ans==NULL)
        return -1;
        else
        return ans->val;
        
    }
    else
    return -1;
}
