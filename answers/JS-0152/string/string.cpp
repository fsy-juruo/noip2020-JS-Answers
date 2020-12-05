#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	int nex;
	int t;
}edg[1];
int hea[1],tai[1],cnt=1;
inline void add(int a,int b)
{
	if(hea[a]=0)hea[a]=cnt;
	edg[cnt].t=b;
	edg[tai[a]].nex=cnt;
	tai[a]=cnt;
	++cnt;
}
bool cmp(int a,int b)
{
	return a<b;//from small to big
}
inline LL read()
{
	LL a=0;
	char c;
	do
	{
		c=getchar();
	}while(c>'9'||c<'0');
	while(c<='9'&&c>='0')
	{
		a=(a<<3)+(a<<1)+c-'0';
		c=getchar();
	}
	return a;
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	return 0;
}
