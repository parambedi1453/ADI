// C++ program to print all possible 
// substrings of a given string 
#include<bits/stdc++.h> 
using namespace std; 

void subString(string s, int n)  
{ 
    // mentioning the startiing point of the substring
    for(int i=0;i<n;i++)
    {
        // mentionung the endpoint of the substring
        for(int len = 1;len<=n-i;len++)
        cout<<s.substr(i,len)<<endl;
    }
} 
  

int main()  
{ 
    string s = "abcd"; 
    subString(s,s.length()); 
    return 0;
}