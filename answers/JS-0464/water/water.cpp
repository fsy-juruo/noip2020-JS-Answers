//I love Chiaki Nanami
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fst first
#define snd second
#define lowbit(x) x&(-x)
const int inf=1e9+7;
//const int mod=;
const int maxn=1e5+7;
const int maxw=10000;
inline int read(){
	int re=0;char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){re=re*10+(c^48);c=getchar();}
	return re;
}
int n,m;
int m2[27],m3[17],m5[17];
struct BIGINT{
	int a[8],sz;
	void init(int x){
		if (!x) sz=0;
		else sz=1,a[0]=x;
	}
};
BIGINT BIGcheng(BIGINT x,int t){
	int cnt=0;
	for (int i=0;i<x.sz;i++){
		x.a[i]=x.a[i]*t+cnt;
		if (x.a[i]>=maxw){
			cnt=x.a[i]/maxw;x.a[i]%=maxw;
		}
		else cnt=0;
	}
	if (cnt){
		x.a[x.sz]=cnt;x.sz++;
	}
	return x;
}
BIGINT cheng(BIGINT x,int t,int c){
	while (c--) x=BIGcheng(x,t);
	return x;
}
BIGINT BIGadd(BIGINT x,BIGINT y){
	int cnt=0;
	x.sz=max(x.sz,y.sz);
	for (int i=0;i<x.sz;i++){
		x.a[i]+=y.a[i]+cnt;
		if (x.a[i]>=maxw){
			cnt=1;
			x.a[i]-=maxw;
		}
		else cnt=0;
	}
	if (cnt){
		x.a[x.sz]=cnt;x.sz++;
	}
	return x;
}
bool canchu(BIGINT x,int t){
	if (t==2 || t==5){
		if (x.a[0]%t==0) return true;
		else return false;
	}
	else{
		int sum=0;
		for (int i=0;i<x.sz;i++){
			sum+=x.a[i];
		}
		if (sum%3==0) return true;
		return false;
	}
}
BIGINT chu(BIGINT x,int t){
	int cnt=0;
	bool f=true;
	for (int i=x.sz-1;i>=0;i--){
		int jj=(x.a[i]+cnt*maxw)%t;
		x.a[i]=(x.a[i]+cnt*maxw)/t;
		cnt=jj;
		if (f && x.a[i]==0) x.sz--;
		else f=false;
	}
	return x;
}
void BIGprint(BIGINT x){
	if (x.sz==0){
		printf("0");return;
	}
	printf("%d",x.a[x.sz-1]);
	for (int i=x.sz-2;i>=0;i--){
		if (x.a[i]>=1000)printf("%d",x.a[i]);
		else if (x.a[i]>=100) printf("0%d",x.a[i]);
		else if (x.a[i]>=10) printf("00%d",x.a[i]);
		else printf("000%d",x.a[i]);
	}
}
struct FS{
	BIGINT p;
	int q2,q3,q5;
	void init(int x){
		p.init(x);q2=0;q3=0;q5=0;
	}
	void q(){
		int s0=min(q2,q5);
		q5-=s0;q2-=s0;
		printf("%lld",1ll*m2[q2]*m3[q3]*m5[q5]);
		for (int i=0;i<s0;i++) putchar('0');
	}
	void print(){
		while (canchu(p,3) && q3){
			q3--;p=chu(p,3);
		}
		while (canchu(p,2) && q2){
			q2--;p=chu(p,2);
		}
		while (canchu(p,5) && q5){
			q5--;p=chu(p,5);
		}
		BIGprint(p);printf(" ");q();puts("");
	}
}dp[maxn];
struct Edge{
	int nxt,to;
}G[maxn*10];
int bG=0,hG[maxn];
void add(int x,int y){
	G[bG].nxt=hG[x];G[bG].to=y;hG[x]=bG++;
}
void FSadd(int x,int y,int d){
//	cout<<x<<' '<<y<<' ';
//	dp[x].print();cout<<dp[x].p.sz<<' ';
//	dp[y].print();cout<<' ';
//	cout<<d<<' ';
	
	FS t=dp[y];
	if (d==5) t.q5++;
	else if(d==4) t.q2+=2;
	else if(d==3) t.q3++;
	else if(d==2) t.q2++;
	
	if (t.q2<dp[x].q2) t.p=cheng(t.p,2,dp[x].q2-t.q2),t.q2=dp[x].q2;
	else dp[x].p=cheng(dp[x].p,2,t.q2-dp[x].q2),dp[x].q2=t.q2;
	if (t.q3<dp[x].q3) t.p=cheng(t.p,3,dp[x].q3-t.q3),t.q3=dp[x].q3;
	else dp[x].p=cheng(dp[x].p,3,t.q3-dp[x].q3),dp[x].q3=t.q3;
	if (t.q5<dp[x].q5) t.p=cheng(t.p,5,dp[x].q5-t.q5),t.q5=dp[x].q5;
	else dp[x].p=cheng(dp[x].p,5,t.q5-dp[x].q5),dp[x].q5=t.q5;
//	cout<<dp[x].p.sz<<' ';
	dp[x].p=BIGadd(dp[x].p,t.p);
	
//	dp[x].print();
//	cout<<dp[x].p.sz<<' ';puts("");
}
int rd[maxn],d[maxn];
vector<int> wout;
queue<int> dl;
void tuopu(){
	for (int i=0;i<n;i++){
		if (!rd[i]) dl.push(i);
	}
	while (!dl.empty()){
		int v=dl.front();dl.pop();
		for (int e=hG[v];e!=-1;e=G[e].nxt){
			int u=G[e].to;
			FSadd(u,v,d[v]);
			rd[u]--;if (!rd[u]) dl.push(u);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	m2[0]=1;m3[0]=1;m5[0]=1;
	for (int i=1;i<23;i++) m2[i]=m2[i-1]*2;
	for (int i=1;i<12;i++){
		m3[i]=m3[i-1]*3;
		m5[i]=m5[i-1]*5;
	}
	memset(hG,-1,sizeof(hG));
	for (int i=0;i<n;i++){
		if (i<m) dp[i].init(1);
		else dp[i].init(0);
		d[i]=read();
		if (!d[i]) wout.push_back(i);
		for (int j=0;j<d[i];j++){
			int u=read();u--;add(i,u);rd[u]++;
		}
	}
	tuopu();
	for (int i=0;i<wout.size();i++){
		dp[wout[i]].print();
	}
	return 0;
}
