#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
typedef double db;
typedef unsigned long long ull;
const int INF=2147483647;
typedef vector<int> vi;
typedef priority_queue<int> pi;
typedef priority_queue<int,greater<int>,vi> pir;
const int N=1e5+10;

inline int read(){
	int x=0;
//	int neg=1;
	char ch=getchar();
	while(!isdigit(ch)){
//		if(ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}

pii add(pii a,pii b){
	pii cnt;
	cnt.second=a.second*b.second;
	cnt.first=a.second*b.first+a.first*b.second;
	int tmp=__gcd(cnt.first,cnt.second);
	cnt.first/=tmp;
	cnt.second/=tmp;
	return cnt;
}

pii divide(pii a,ll b){
	int tmp=__gcd(a.first,b);
	pii cnt=a;
	cnt.first/=tmp;
	cnt.second*=b/tmp;
	return cnt;
}

int n,m;
vi ed[N];
pii ans[N];
int in_degree[N],out_degree[N];
int final[N],final_sum;
queue<int> q;

inline int Input(){
	n=read();
	m=read();
	for(int i=0;i<n;i++){
		out_degree[i]=read();
		if(out_degree[i]==0) final[final_sum++]=i;
		else
			for(int j=0;j<out_degree[i];j++){
				int x;
				x=read()-1;
				ed[i].pb(x);
				in_degree[x]++;
			}
	}
//	puts("Input is finished.");
}

inline void Init(){
	for(int i=0;i<n;i++) {
		ans[i].first=0;
		ans[i].second=1;
		if(!in_degree[i]){
			q.push(i);
			ans[i].first+=1;
		}
	}
//	puts("Init is finished.");
}

inline void Check(){
	for(int i=0;i<final_sum;i++)
		printf("%d\n",final[i]);
	for(int i=0;i<n;i++){
		printf("%d : %d , %d : ",i,in_degree[i],out_degree[i]);
		for(int j=0;j<out_degree[i];j++)
			printf("%d ",ed[i][j]);
		printf("			%d %d\n",ans[i].first,ans[i].second);
	}
}

void Solve(){
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		if(!out_degree[cur]) continue;
		pii cnt=divide(ans[cur],(ll)out_degree[cur]);
//		printf("%d\n",cur);
		for(int i=0;i<out_degree[cur];i++){
			int v=ed[cur][i];
//			printf("    %d\n",v);
			in_degree[v]--;
			ans[v]=add(ans[v],cnt);
//			puts("add?");
			if(in_degree[v]==0) q.push(v);
		}
	}
//	puts("Solved.");
}

void Print(){
	for(int i=0;i<final_sum;i++)
		printf("%lld %lld\n",ans[final[i]].first,ans[final[i]].second);
//	puts("Printed.");
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	Input();
	Init();
//	Check();
	Solve();
	Print();
	return 0;
}

