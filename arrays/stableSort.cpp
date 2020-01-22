#include <bits/stdc++.h>
using namespace std;
#define MAX 10005

int main()
{
	string S[] = {"Abhishek", "Zeroess","Hello","Amit","Bananan","Problem","Ankush","Ahmed"};
	int N = sizeof(S)/sizeof(S[0]);
	
	stable_sort(S,S+N);
	
	for(int i=0;i<N;i++)
		cout<<S[i]<<"  ";
		
		
	return 0;
}