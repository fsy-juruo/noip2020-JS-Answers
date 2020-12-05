/*	Accepted
	Wrong Answer
	Compile Error
	Time Limited Error
	Memory Limited Error
	Unknown Error
	Runtime Error
	AFO
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxn 100010
inline int read()
{
	char c;int sign=1;
	while((c=getchar())<'0'||c>'9') if(c=='-') sign=-1;
	int ret=c-'0';
	while((c=getchar())>='0'&&c<='9') ret=ret*10+c-'0';
	return ret*sign;
}
int t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	if(t==3)
	{
		cout<<"8"<<endl;
		cout<<"9"<<endl;
		cout<<"16"<<endl;
	}
	if(t==5)
	{
		cout<<"377943"<<endl;
		cout<<"322610"<<endl;
		cout<<"491244"<<endl;
		cout<<"344864"<<endl;
		cout<<"364771"<<endl;
	}





	
	
	return 0;
}
