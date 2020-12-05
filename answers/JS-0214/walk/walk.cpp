#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,k,ans;
int w[maxn],c[maxn],d[maxn],cnt[maxn];
pii mp[maxn];
map<int,int> mp2;
vector<int> v;
bool flag=true;

void calc(){
	int p=inf;
	for(int i=1;i<=k;++i){
		if(cnt[i]==0){
			if(v[i-1]+mp[i].first<=w[i]&&v[i-1]+mp[i].second>=1) continue;
			p=0;
		}
		if(cnt[i]>0){
			if(v[i-1]+mp[i].second<1){
				p=0;
				continue;
			}
			int dist=(w[i]-v[i-1]-mp[i].first)/cnt[i];
			if(w[i]-v[i-1]-mp[i].first>=0) dist+=1;
			if(dist<0) dist=0;
			p=min(p,dist);
		}
		if(cnt[i]<0){
			if(v[i-1]+mp[i].first>w[i]){
				p=0;
				continue;
			}
			int dist=(v[i-1]-1-abs(mp[i].second))/abs(cnt[i]);
			if(v[i-1]-1-abs(mp[i].second)>=0)dist+=1;
			if(dist<0) dist=0;
			p=min(p,dist);
		}
	}
	if(p==inf){
		puts("-1");
		flag=false;
		return;
	}
	ans+=p*n;
	ans%=mod;
	vector<int> t=v;
	for(int i=1;i<=k;++i){
		t[i-1]+=p*cnt[i];
	}
	for(int i=1;i<=n;++i){
		t[c[i]-1]+=d[i];
		ans++;
		ans%=mod;
		if(t[c[i]-1]>w[c[i]]||t[c[i]-1]<1) break;
	}
//	for(int i=0;i<v.size();++i) cout<<v[i]<<" ";
//	cout<<endl;
//	cout<<"ans:"<<ans<<" "<<p<<endl;
}

void dfs(int depth){
	if(!flag) return ;
	if(depth==k+1){
		calc();
		return ;
	}
	for(int i=1;i<=w[depth];++i){
		v.pb(i);
		dfs(depth+1);
		v.pop_back();
	}
}

void sol1(){
	int Count=0;
	for(int i=1;i<=n;++i){
		Count+=d[i];
		if(!mp2[Count]) mp2[Count]=i;
	}
	for(int i=1;i<=w[1];++i){
		int p=inf;
		if(cnt[1]==0){
			if(i+mp[i].first<=w[1]&&i-mp[i].second>=1){
				puts("-1");
				return ;
			}
			p=0;
		}
		if(cnt[1]>0){
			if(i+mp[i].second<1){
				p=0;
				continue;
			}
			int dist=(w[1]-i-mp[1].first)/cnt[1];
			if(w[1]-i-mp[1].first>=0) dist+=1;
			if(dist<0) dist=0;
			p=min(p,dist);
		}
		if(cnt[1]<0){
			if(i+mp[i].first>w[1]){
				p=0;
				continue;
			}
			int dist=(i-1-abs(mp[1].second))/cnt[1];
			if(i-1-abs(mp[1].second)>=0) dist+=1;
			if(dist<0) dist=0;
			p=min(p,dist);
		}
		if(p==inf){
			puts("-1");
			return ;
		}
		ans+=p*n;
		ans%=mod;
		i+=cnt[1]*p;
		ans+=min(mp2[i],mp2[w[1]-i+1]);
		ans%=mod;
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>c[i]>>d[i];
		cnt[c[i]]+=d[i];
		mp[c[i]].first=max(mp[c[i]].first,cnt[c[i]]);
		mp[c[i]].second=min(mp[c[i]].second,cnt[c[i]]);
	}
	if(k==1){
		sol1();
		return 0;
	}
	dfs(1);
	if(flag) cout<<ans<<endl;
	return 0;
}
