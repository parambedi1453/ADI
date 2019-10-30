// rabin karp algo is based on rolling hashing technique
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long int
#define prime 119
using namespace std;

/*

    creating hash for eg abc
    65*pow(119,0)+66*pow(119,1)+67*pow(119,2);

    pow will have exponent till pattern.length()-1;
*/
// complexity of the createHashValue is o(n)
ll createHashValue(string str,int n)
{
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans+= (ll)(str[i]*(ll)pow(prime,i));
    }
    return ans;
}
/*

    calculateinh rolling hash 
    abcd 
    oldHash has value of abc
    remove a by oldhash - 'a' 
    devide whole oldHash by prime 
    add d*pow(prime,pat.length()-1);
*/
// complexity of rolling hash function is o(1) because 3 constant opeations are being performed
ll rollingHash(string str,int oldIndex,int newIndex,ll oldHashVal,int patlength)
{
    ll newHash = oldHashVal-str[oldIndex];
    newHash=newHash/prime;
    newHash+=(ll)(str[newIndex]*(ll)(pow(prime,patlength-1)));
    return newHash;
}
bool checkStrings(string str1,int s1,int e1,string str2,int s2,int e2)
{
    // Checking length of strings
    if(e1-s1!=e2-s2)
    return false;

    while(s1<=e1 && s2<=e2)
    {
        if(str1[s1]!=str2[s2])
        return false;
        
        s1++;
        s2++;
    }
    return true;
}
int main()
{
    string str,pat;
    cout<<"Enter String =\n";
    cin>>str;//ababcabdab
    cout<<"Enter pattern =\n";
    cin>>pat;//abd

    ll strhash = createHashValue(str,pat.length());
    ll pathash = createHashValue(pat,pat.length());
    for(int i=0;i<=str.size()-pat.size();i++)
    {
        if(strhash == pathash && checkStrings(str,i,i+pat.length()-1,pat,0,pat.length()-1))
        {
            cout<<"Substring found at index "<<i<<endl;
            return 0;
        }
        if(i<str.length()-pat.length())
        strhash = rollingHash(str,i,i+pat.length(),strhash,pat.length());
    }
    return 0;

}