#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
string s;
int aa[1<<20+1],cc[1<<20+1];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
		cout<<rand()%200<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
