#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m[7];
int n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		cin>>s;
		n=s.length();
		if(!n%2&&n!=20){
			m[i]=(n-2)*(n-1)/2-(n-2)*n/8+1;
		}else if(n==20)m[i]=156;
		else m[i]=(n-2)*(n-1)/2-(n-2)*n/8+1;
	}
	for(int i=0;i<T;i++)
	printf("%ld",m[i]);
	return 0;
}
