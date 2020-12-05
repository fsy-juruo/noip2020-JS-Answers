#include <bits/stdc++.h>
#define LL long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int f=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	x*=f;
}

const int maxmove=820000+100,maxn=20,maxm=30;
struct node{
	int x,y;
}move[maxmove];
node ansm[maxmove];
int n,m,a[maxn][maxm],times[maxn];
int ans=INT_MAX/2;

bool check(){
	for(int i=1;i<=n;i++){
		if(times[i]!=m)return 0;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=2;j<=m;j++)if(a[i][j]!=a[i][j-1])return 0;
	}
	return 1;
}
set<pair<string,int> > s;
bool exist(){
	int hf=0;string ss;
	char ch;
	for(int i=1;i<=n+1;i++)
	for(int j=1;j<=times[i];j++){
		ch=a[i][j]+'0'-1;
		ss.push_back(ch);
	}
	for(int i=1;i<=n+1;i++)hf=hf*(m+1)+times[i];
	if(s.find(make_pair(ss,hf))!=s.end())return 1;
	s.insert(make_pair(ss,hf));
	return 0;
}
int maxxx;

void dfs(int step){
	if(step>ans||step>maxxx)return;
	if(check()){
		ans=min(ans,step-1);
		for(int i=1;i<=ans;i++)ansm[i]=move[i];
		return;
	}
	if(exist())return;
	for(int i=1;i<=n+1;i++)
	for(int j=1;j<=n+1;j++){
		if(i==j||times[j]>=m||times[i]<=0)continue;
		++times[j];
		a[j][times[j]]=a[i][times[i]];
		--times[i];
		move[step]=(node){i,j};
		dfs(step+1);
		++times[i];
		a[i][times[i]]=a[j][times[j]];
		times[j]--;
	}
}
bool can(int maxx){
	maxxx=maxx;
	ans=INT_MAX/2;
	s.clear();
	dfs(1);
	if(ans!=INT_MAX/2)return 1;
	else return 0;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)read(a[i][j]);
	for(int i=1;i<=n;i++)times[i]=m;
	for(int i=1;i<=1000;i++){
		if(can(i)){
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
	printf("%d %d\n",ansm[i].x,ansm[i].y);
	}
	return 0;
	}
	}
}

