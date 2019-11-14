/*

    Given a string str, find the length of the longest substring without repeating characters.

For “ABDEFGABEF”, the longest substring are “BDEFGA” and “DEFGAB”, with length 6.
For “BBBB” the longest substring is “B”, with length 1.

*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;
    cout<<"Enter String =\n";
    cin>>a;

    int n = a.size();
    int curr_len = 1;
    int max_len = 1;

    int visited[256] ;

    for(int i=0;i<256;i++)
    visited[i]=-1;

    // the visited array stores the index of last occurence of the character
    visited[a[0]]=0;

    for(int i=1;i<n;i++)
    {
        int last_occur = visited[a[i]];

        /* in this if we are checking that if element has not occured then add that in cuur len and second case is that if element is present before then checking that if it is in the curr windowor not*/
        if(last_occur==-1 || i-curr_len > last_occur)
        {
            curr_len+=1;
            max_len = max(curr_len,max_len);
        }
        /*
            in this if elemet is in the curr window then discarding the len of window where the lsst occ of that charater is and the getting the new window len
        */
        else
        {
            max_len=max(max_len,curr_len);
            curr_len = i - last_occur;
        }

        // storing the last occurence of that character in the visited arary
        visited[a[i]] = i;
        max_len=max(max_len,curr_len);
    }

    cout<<"Max len unique character substring is "<<max_len<<endl;
}