#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
struct fenshu{
	long long p,q;
}Ans[maxn];
int n,m;
int num[maxn],cnt[maxn];
vector<int> Adj[maxn];
queue<int> q;
bool vis[maxn];
long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void yuefen(int id){
	long long G=gcd(max(Ans[id].p,Ans[id].q),min(Ans[id].p,Ans[id].q));
	Ans[id].p/=G;
	Ans[id].q/=G;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		int a;
		for(int j=1;j<=num[i];j++){
			scanf("%d",&a);
			Adj[i].push_back(a);
			cnt[a]++;
		}
	}
	while(1){
		if(q.size()==n)break;
		for(int i=1;i<=n;i++){
			if(!cnt[i]&&!vis[i]){
				vis[i]=true;
				q.push(i);
				for(int j=0;j<Adj[i].size();j++){
					cnt[Adj[i][j]]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		Ans[i].p=0;
		Ans[i].q=1;
	}
	while(!q.empty()){
		int top=q.front();
		//cout<<top<<endl;
		q.pop();
		if(top<=m){
			Ans[top].p=1;
			Ans[top].q=1;
		}
		if(num[top]==0){
			cout<<Ans[top].p<<" "<<Ans[top].q<<endl;//yuefen
			continue;
		}
		for(int i=0;i<Adj[top].size();i++){
			long long tmp=Ans[Adj[top][i]].q;
			Ans[Adj[top][i]].q=Ans[Adj[top][i]].q*Ans[top].q*num[top];
			Ans[Adj[top][i]].p=Ans[Adj[top][i]].p*Ans[top].q*num[top]+Ans[top].p*tmp;
			yuefen(Adj[top][i]);
		}
		//cout<<Ans[top].p<<" "<<Ans[top].q<<endl;
	}
	return 0;
}
