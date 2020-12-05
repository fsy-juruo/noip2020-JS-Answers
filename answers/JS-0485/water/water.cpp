#include<bits/stdc++.h>
#define reg register
#define ll long long
#define NOF "water"
#define N (int)1e5
using namespace std;

inline int read(){
	int s = 0,w = 1;
	char ch; ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+ch-'0';ch=getchar();}
	return s*w;
}

bool ifput[N];
ll pointup[N] , pointdown[N];
vector < int > tree[N];

inline ll gcd(ll a,ll b){
	ll tmp;
	if(a==b) return a;
	if(a<b) swap(a,b);
	while(b>0){
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

void dfs( int pre , ll up ,ll down){
	
//	cout<<pre<<' '<<up<<' '<<down<<endl;
	
	if(!tree[pre].size()){
		if(down==pointdown[pre]){
			pointup[pre] += up;
		}
		else{
			if(!pointup[pre]&&!pointdown[pre]){
				pointup[pre] = up;
				pointdown[pre] = down;
			}
			else{
				up = up*pointdown[pre]+pointup[pre]*down;
				down *=pointdown[pre];
				ll tmp = gcd(up,down);
				pointup[pre] = up/tmp;
				pointdown[pre] = down/tmp;
			}
		}
	}
	
	else{
		
		ll nextup = up;
		ll nextdown = down*tree[pre].size();
		ll tmpgcd = gcd(nextup,nextdown);
		nextup /= tmpgcd;
		nextdown /= tmpgcd;
		
		for(reg int i = 0;i<tree[pre].size();++i){
			dfs(tree[pre][i],nextup,nextdown);
		}
	
	}
	
}

int main(){
	
	freopen(NOF ".in","r",stdin);
	freopen(NOF ".out","w",stdout);
	
	int n = read(),m = read(),v,num;
	for(reg int i = 1;i<=n;++i){
		num = read();
		if(num==0) ifput[i] = true;
		for(reg int j = 1;j<=num;++j){
			v = read();
			tree[i].push_back(v);	
		}
	}
	
	for(reg int i = 1;i<=m;++i){
		dfs(i,1,1);
	}
	
	ll actmp;
	for(reg int i = 1;i<=n;++i){
		if(ifput[i]){
			actmp = gcd(pointdown[i],pointup[i]);
			cout<<pointup[i]/actmp<<' '<<pointdown[i]/actmp<<endl;
		}
	}
	return 0;
}
