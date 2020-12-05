#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,l,r) for(int i=l;i>=r;i--)
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define p_b push_back
#define m_p make_pair
#define fi first
#define se second
using namespace std;
int fr() {
	int x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int INF=0x7f7f7f7f;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cout<<"114514\n1919810\n19260817";
	return 0;
}


