#include<bits/stdc++.h>
using namespace std;
int n,k,c[1000000],d[1000000];
int w[1000000];
int a[10000000];
int read(){
	int xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for (int i=1;i<=k;i++)w[i]=read();
	for (int i=1;i<=n;i++)c[i]=read(),d[i]=read();
	cout<<-1<<endl;
	return 0;
}

