
// LINKED LIST MATRIX

/*This is a function problem.You only need to complete the function given below*/
/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
	
	Node(int x){
	    data = x;
	    right = NULL;
	    down = NULL;
	}
};
*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]

Node* constructLinkedMatrix(int a[MAX][MAX], int n)
{
    // code here
   Node *m[n][n];
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           m[i][j] = new Node(a[i][j]);
       }
   }
   
// Now setting the pointerts
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==n-1 && j==n-1)
            {
                m[i][j]->right=NULL;
                m[i][j]->down = NULL;
            }
            else if(i==n-1 && j!=n-1)
            {
                m[i][j]->down = NULL;
                m[i][j]->right = m[i][j+1];
            }
            else if(i!=n-1 && j==n-1)
            {
                m[i][j]->down = m[i+1][j];
                m[i][j]->right=NULL;
            }
            else
            {
                m[i][j]->down = m[i+1][j];
                m[i][j]->right = m[i][j+1];
            }
        }
    }
    return m[0][0];
}
