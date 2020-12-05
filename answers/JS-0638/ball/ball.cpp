#include<bits/stdc++.h>
using namespace std;

void fre() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
}

typedef long long ll;

inline ll read() {
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}

ll n,m;
vector<vector<ll> >cn;

bool check() {
	for(ll i=1; i<=n+1; i++) {
		if(cn[i].size()!=0&&cn[i].size()!=m)return false;
		map<ll,ll>mp;
		for(ll j=0; j<cn[i].size(); j++)
			mp[cn[i][j]]++;
		if(mp.size()!=1&&mp.size()!=0)return false;
	}
	return true;
}

ll gly=0;
bool flag=false;
vector<pair<ll,ll> >ans;
void print() {
	ll len=ans.size();
	cout<<len<<endl;
	for(ll i=0; i<len; i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

ll last[500500]={};
void dfs(ll dept) {
	if(dept==gly) {
		if(!check())return;
		else {
			print();
			flag=true;
			return;
		}
	}
	for(ll i=1; i<=n+1; i++)
		for(ll j=1; j<=n+1; j++) {
			if(flag)continue;
			if(i==j)continue;
			if(last[j]==i)continue;
			if(cn[i].size()==0)continue;
			if(cn[j].size()==m)continue;
			cn[j].push_back(cn[i][cn[i].size()-1]);
			cn[i].pop_back();
			ans.push_back(make_pair(i,j));
			ll pre=last[i];
			last[i]=j;
			dfs(dept+1);

			cn[i].push_back(cn[j][cn[j].size()-1]);
			cn[j].pop_back();
			ans.pop_back();
			last[i]=pre;
			if(flag)return;
		}
}

signed main() {
	fre();
	
	cin>>n>>m;
	for(ll i=0; i<=n+1; i++)
		cn.push_back(vector<ll>());

	for(ll i=1; i<=n; i++)
		for(ll j=0; j<m; j++) {
			ll x;
			cin>>x;
			cn[i].push_back(x);
		}

	while(true) {
		dfs(0);
		gly++;
		if(flag)break;
	}

	return 0;
}
