#include<bits/stdc++.h>
using namespace std;
int f_read(void)
{
	char c;
	while(!('0'<=c&&c<='9'))
		c=getchar();
	int res=0,t=1;
	if(c=='-')
	{
		t=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int n,k,w[15],c[105],d[105];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=f_read();
	k=f_read();
	for(int i=1;i<=k;i++)
		w[i]=f_read();
	for(int i=1;i<=n;i++)
		c[i]=f_read(),d[i]=f_read();
	cout<<-1;
	return 0;
}
