#include<bits/stdc++.h>
using namespace std;
int n,k,w[100010],h[100010],c[100010],d[100010],dx[10],dy[10],ans,sxh;
int read(){
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1,ch=getchar();
	}
	while (isdigit(ch)){
		x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	}
	return x*f;
}
void dfs(int dep,int x){
	dx[dep]=x;
//	cout<<dep<<' '<<x<<endl;
	if (dep==k) {//cout<<'!';
		int fl=0;
		for (int i=1; i<=k; i++)
		  dy[i]=dx[i];//,cout<<dy[i]<<' ';
	//	int s=ans;
	    
		while (1){
			for (int i=1; i<=n; i++)
			{
				if (dy[c[i]]+d[i]>0&&dy[c[i]]+d[i]<=w[c[i]]) dy[c[i]]+=d[i],ans=(ans+1)%1000000007;
				else {
					ans=(ans+1)%1000000007;
					fl=1;//
					break;
				}
			}
			if (fl==1) break;
			if (sxh==0){
				cout<<-1<<endl;
				exit(0);
			}
		}
		
	//	cout<<ans-s<<endl;
		return;
	}
	for (int i=1; i<=w[dep+1]; i++)
	  dfs(dep+1,i);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
    n=read(),k=read();
    for (int i=1; i<=k; i++)
    {
    	w[i]=read();
	}
	for (int i=1; i<=n; i++)
	{
		int x,y;
		x=read(),y=read();
		h[x]+=y;
		c[i]=x,d[i]=y;
	}
	for (int i=1; i<=n; i++)
	{
		if (h[i]!=0) sxh=-1;
	}
	for (int i=1; i<=w[1]; i++)
	  dfs(1,i);
	cout<<ans<<endl;
	return 0;
}
