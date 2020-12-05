#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p1,p2,q1,q2,q,p;
ll mod;
int n,m;
vector<int> vec[1010];
int col[1010];//root:0 leaf:2 else:1
int has_father[1010];
pair<ll,ll> a[1010];//a[i]=<q,p>
pair<ll,ll>r;
int d,x;
pair<ll,ll>ans[1010];
inline ll gcd(ll a1,ll a2){
	if(a2!=0)return gcd(a2,a1%a2);
	return a1;
}
inline void add(){
//	q1/p1+q2/p2=q/p;
//	mod=gcd(p1,q1); p1/=mod;q1/=mod;
//	mod=gcd(p1,q2); p1/=mod;q2/=mod;
//	mod=gcd(p2,q1); q1/=mod;p2/=mod;
//	mod=gcd(p2,q2); q2/=mod;p2/=mod;
	p=(p1*p2); q=((q1*p2)+(q2*p1));
	mod=gcd(p,q); p/=mod;q/=mod;
}
void bfs(){
	queue<pair<int,pair<ll,ll> > >que;//<name,<q,p>>
	for(int i=1;i<=n;i++)
		if(a[i]==r)que.push(make_pair(i,a[i]));
	while(que.size()){
		pair<int,pair<ll,ll> > tmp=que.front();
		que.pop();
		int idx=tmp.first;
		q1=tmp.second.first;
		p1=vec[idx].size();
		mod=gcd(p1,q1); p1/mod;q1/mod;
		p1*=tmp.second.second;
		mod=gcd(p1,q1); p1/mod;q1/mod;
		if(vec[idx].size()==0){
			ans[idx]=a[idx];
		}
		for(int i=0;i<vec[idx].size();i++){
			int u=vec[idx][i];
			has_father[u]--;
			q2=a[u].first;
			p2=a[u].second;
//			cout<<q2<<' '<<p2<<'\n';
			if(q2==0){
				p=p1;
				q=q1;
			}
			else
				add();
			a[u].first=q;
			a[u].second=p;
			if(has_father[u]==0)
				que.push(make_pair(u,make_pair(q,p)));
//			cout<<idx<<' '<<u<<' '<<q1<<'/'<<p1<<'+'<<q2<<'/'<<p2<<'='<<a[u].first<<'/'<<a[u].second<<'\n';
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin.tie(0);
	r.first=1,r.second=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d;if(d==0)col[i]++;
		for(int j=0;j<d;j++)
			cin>>x,vec[i].push_back(x),col[x]+=(has_father[x]==0),has_father[x]++;
	}
	for(int i=1;i<=n;i++)
		if(col[i]==1&&has_father[i]==0)col[i]=0;
	for(int i=1;i<=n;i++)
		if(col[i]==0)a[i]=make_pair(1,1);
		else a[i]=make_pair(0,1);
	bfs();
//	for(int i=1;i<=n;i++){
//		cout<<a[i].first<<'/'<<a[i].second<<'\n';
//	}
	for(int i=1;i<=n;i++){
		if(vec[i].size()==0)
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
	return 0;
}

