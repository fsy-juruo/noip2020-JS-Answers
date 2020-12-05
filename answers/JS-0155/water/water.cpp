#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define print shuchu

inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	if(ch=='-') f=-1;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+(ch^'0');
		ch=getchar();
	}
	
	return ans*f;
}

int n,m;
int d[100005];
vector<int> v[100005];
int ind[100005];
pii a[100005];

inline int gcd(int a,int b){
	if(b==0)  return a;
	else return gcd(b,a%b);
}

inline pii add(pii x,pii y){
	int xa=x.first,xb=x.second,ya=y.first,yb=y.second;
	pii ans=make_pair(xa*yb+xb*ya,xb*yb);
	int cd=gcd(ans.first,ans.second);
	if(ans.first&&ans.second) ans.first/=cd,ans.second/=cd;
	return ans;
}

inline pii div(pii x,int dv){
	pii ans=make_pair(x.first,x.second*dv);
	int cd=gcd(ans.first,ans.second);
	if(ans.first&&ans.second) ans.first/=cd,ans.second/=cd;
	return ans;
} 

inline void print(pii x){
	printf("%lld %lld\n",x.first,x.second);
}

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	register int i,j;
	
	int x;
	for(i=1;i<=n;++i){
		d[i]=read();
		for(j=1;j<=d[i];++j){
			x=read();
			++ind[x];
			v[i].push_back(x);
		}
		a[i].second=1;
	}
	
	for(i=1;i<=n;++i){
		if(ind[i]==0) a[i].first=1;
		if(d[i]==0) continue;
		for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it){
			int idx=*it;
			a[idx]=add(a[idx],div(a[i],d[i]));
		}
	}
	
	for(i=1;i<=n;++i) if(d[i]==0) print(a[i]);
	return 0;
}
