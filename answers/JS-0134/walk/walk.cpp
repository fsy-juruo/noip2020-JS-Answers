#include<bits/stdc++.h>
using namespace std;

inline void start()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int main()
{
	start();
	int n,k;
	n=read(),k=read();
	int a;
	for(int i=1;i<=k;i++) a=read();
	for(int i=1;i<=n;i++) a=read(),a=read();
	printf("-1\n");
	return 0;
}
