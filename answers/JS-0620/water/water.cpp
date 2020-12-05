#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define int long long
struct node{
	int p,q;
}s[N];
int n,m,f[N],ans[N],anssize,start,ss[N],sizess;
vector<int>a[N];
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void add(int num,int nowp,int nowq){
	int tmp=s[num].q*nowq/gcd(s[num].q,nowq);
	s[num].p=s[num].p*tmp/s[num].q+nowp*tmp/nowq;
	s[num].q=tmp;
	tmp=gcd(s[num].p,s[num].q);
	s[num].p/=tmp;s[num].q/=tmp;
}
void dfs(int now,int lastp,int lastq){
	int size=a[now].size();
	int tmpp=lastp,tmpq=lastq;
	for(int i=0;i<size;i++){
		int u=a[now][i];
		add(u,tmpp,tmpq*size);
		dfs(u,lastp,lastq*size);
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int t,q;
	for(register int i=1;i<=n;i++){
		s[i].p=0,s[i].q=1;
		scanf("%lld",&t);
		if(t==0){
			ans[++anssize]=i;
		}
		for(register int j=1;j<=t;j++){
			scanf("%lld",&q);
			a[i].push_back(q);
			f[q]=1;
		}
	}
	for(register int i=1;i<=n;i++){
		if(f[i]==0){
			ss[++sizess]=i;
		}
	}
	for(register int i=1;i<=sizess;i++){
		dfs(ss[i],1,1);
	}
	for(register int i=1;i<=anssize;i++){
		printf("%d %d\n",s[ans[i]].p,s[ans[i]].q);
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
