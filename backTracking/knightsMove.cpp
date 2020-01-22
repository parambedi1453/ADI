#include<iostream>
using namespace std;
const int d = 8;
int fcall;
bool canplace(int board[d][d],int n,int i,int j)
{
    return 
    i>=0 && i<n && 
    j>=0 && j<n && 
    board[i][j]==0;
}
bool knightMove(int board[d][d],int n,int prevMoveNo,int currRow,int currCol)
{
    fcall++;
    // as knigjht covers the complete board in  n*n ways
    if(prevMoveNo == n*n)
    return true;

    // total no of moves knight can make is 8   
    int row [] = {-2,-2,+2,+2,-1,-1,+1,+1};
    int col [] = {+1,-1,+1,-1,+2,-2,+2,-2};

    // int row[] = {+2,+1,-1,-2,-2,-1,+1,+2};
    // int col[] = {+1,+2,+2,+1,-1,-2,-2,-1};
    for(int i=0;i<8;i++)
    {
        int nextRow = currRow+row[i];
        int nextCol = currCol+col[i];
        if(canplace(board,n,nextRow,nextCol)==true)
        {
            board[nextRow][nextCol] = prevMoveNo+1;
            bool ans = knightMove(board,n,prevMoveNo+1,nextRow,nextCol);
            if(ans == true)
            return true;
            board[nextRow][nextCol] = 0;
        } 
    }
    return false;
}
void printBoard(int board[d][d],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        
         cout<<endl;
    }       
}
int main()
{

    int n;
    // n less than 8 ans 8 is the largest size of board
    cin>>n;
    int board[d][d] = {0};
    board[0][0] = 1;
    fcall = 0;
    bool ans = knightMove(board,n,1,0,0);
    if(ans == true)
    {
        cout<<"YES"<<endl;
        printBoard(board,n);
    }
    else
    {
        cout<<"NOT POOSIBLE"<<endl;
    }
    cout<<fcall<<endl;
}