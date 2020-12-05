#include<bits/stdc++.h>
using namespace std;
#define int long long

void read(int &x){
	char c=getchar();int fc=1;
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') fc=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	x*=fc;
}
int n,m,a[100010][10],top[100010],ans[100010][3],qwq;
bool change[100010];
queue<int> q;
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(top[i]);
		for(int j=1;j<=top[i];j++){
			read(a[i][j]);
		}
		if(i<=m) q.push(i);
	}
	for(int i=1;i<=m;i++){
		ans[i][1]=ans[i][2]=1;
	}
	memset(change,true,sizeof(change));
	while(!q.empty()){
		int now=q.front();q.pop();
		if(!change[now]) continue;
		change[now]=false;
		for(int i=1;i<=top[now];i++){
			int p1=ans[a[now][i]][1],p2=ans[a[now][i]][2];
			int q1=ans[now][1],q2=top[now]*ans[now][2];
			if(p1==0||p2==0){
				ans[a[now][i]][2]=ans[now][2]*top[now];
				ans[a[now][i]][1]=ans[now][1];
				int aaa=gcd(ans[a[now][i]][1],ans[a[now][i]][2]);
				ans[a[now][i]][1]/=aaa;ans[a[now][i]][2]/=aaa;
				change[a[now][i]]=true;
			}
			else{
				qwq=p2*q2/gcd(p2,q2);
				ans[a[now][i]][2]=qwq;
				ans[a[now][i]][1]=qwq/p2*p1+qwq/q2*q1;
				int aaa=gcd(ans[a[now][i]][1],ans[a[now][i]][2]);
				ans[a[now][i]][1]/=aaa;ans[a[now][i]][2]/=aaa;
				change[a[now][i]]=true;
			}
			if(top[a[now][i]]) q.push(a[now][i]);
		}
		ans[now][1]=ans[now][2]=0;
	}
	for(int i=1;i<=n;i++){
		if(!top[i])
		printf("%lld %lld\n",ans[i][1]/gcd(ans[i][1],ans[i][2]),ans[i][2]/gcd(ans[i][1],ans[i][2]));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
