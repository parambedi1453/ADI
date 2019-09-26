	/*
        Geeks for Geeks question solved
        https://practice.geeksforgeeks.org/problems/construct-an-expression-tree/1/?ref=self
    */
    
//  STUB CODE
//     if (c == '+' || c == '-' ||
// 			c == '*' || c == '/' ||
// 			c == '^')
// 		return true;
// 	return false;
// }
// void inorder(et *t)
// {
// 	if(t)
// 	{
// 		inorder(t->left);
// 		printf("%c ", t->value);
// 		inorder(t->right);
// 	}
// }
// et* constructTree(char []);
// int main()
// {   
//     int t;
//     cin>>t;
//     while(t--){
//     char postfix[25];
// 	cin>>postfix;
// 	et* r = constructTree(postfix);
// 	inorder(r);
// 	cout<<endl;
// }
// return 0;
// }
// }{
// #include<bits/stdc++.h>
// using namespace std;
// struct et
// {
// 	char value;
// 	et* left, *right;
	
// 	et(char x){
// 	    value = x;
// 	    left = right = NULL;
// 	}
// };
// bool isOperator(char c)
// {

/*This is a function problem.You only need to complete the function given below*/
/*struct et
{
	char value;
	et* left, *right;
};*/
//function to construct expression tree
#include<stack>
et* constructTree(char postfix[])
{
    
    stack<struct et*> s;
    for(int i=0;postfix[i];i++)
    {
        if((postfix[i]>='a'&&postfix[i]<='z' )|| (postfix[i]>='A'&&postfix[i]<='Z'))
        {
            struct et *temp = (struct et *)calloc(1,sizeof(struct et));
            temp->value=postfix[i];
            temp->left=NULL;
            temp->right=NULL;
            s.push(temp);
        }
        else if(postfix[i]=='*'||postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='/'||postfix[i]=='^')
        {
            struct et *temp = (struct et *)calloc(1,sizeof(struct et));
            temp->value=postfix[i];
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();
            s.push(temp);
        }
    }
    return s.top();
}