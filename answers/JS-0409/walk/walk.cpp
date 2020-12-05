#include<bits/stdc++.h>
#define N 500007
using namespace std;
struct node{
	int c,d,step;
}a[N];
int w[17],p[17],maxp[17],minp[17];
bool pan=0;
bool cmp(node a,node b){
	return a.c==b.c?a.step<b.step:a.c<b.c;
}
long long ans=0;
int e[17],k,n;
void ji(){
	int sum=0,q[17],i=0;
	for(int i=1;i<=k;i++) q[i]=e[i];
	while(1){
		i++;
		q[a[i].c]+=a[i].d;sum++;
		if(q[a[i].c]==0||q[a[i].c]==w[a[i].c]+1) break;
		if(i==n) i=0;
	}
	ans+=sum;
	return ;
}
int dfs(int x){
	if(x==k+1){
		ji();
		return 0;
	}
	for(int i=1;i<=w[x];i++){
		e[x]=i;
		dfs(x+1);
	}
	return 0;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].c,&a[i].d);a[i].step=i;
		p[a[i].c]+=a[i].d;
		maxp[a[i].c]=max(p[a[i].c],maxp[a[i].c]);
		minp[a[i].c]=min(p[a[i].c],minp[a[i].c]);
	}
	for(int i=1;i<=k;i++){
		if(maxp[i]-min(0,minp[i])>=w[i]||p[a[i].c]!=0) pan=1;
	}
	if(!pan) printf("-1\n");
	else {
		dfs(1);
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
