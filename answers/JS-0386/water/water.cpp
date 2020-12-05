#include<bits/stdc++.h>
#define LL long long 
using namespace std;
vector<LL>v[100010];
LL a[100010][2];
LL h[100010];
pair<LL,LL>b[100010];
LL gcd(LL x,LL y){
	return y==0?x:gcd(y,x%y);
}
LL lcm(LL x,LL y){
	return x/gcd(x,y)*y;
}
pair<LL,LL> add(pair<LL,LL>p1,pair<LL,LL>p2){
	LL x1=p1.first;
	if(x1==0)return p2; 
	LL y1=p1.second;
	LL x2=p2.first;
	if(x2==0)return p1; 
	if(x1==0&&x2==0)return make_pair(0,0); 
	LL y2=p2.second;
	LL y3=lcm(y1,y2);
	LL x3=y3/y1*x1+y3/y2*x2;
	LL g3=gcd(x3,y3);
	x3/=g3;y3/=g3;
	return make_pair(x3,y3);
}
pair<LL,LL> times(pair<LL,LL>p1,pair<LL,LL>p2){
	LL x1=p1.first;
	if(x1==0)return make_pair(0,0); 
	LL y1=p1.second;
	LL x2=p2.first;
	if(x2==0)return make_pair(0,0); 
	LL y2=p2.second;
	LL y3=y1*y2;
	LL x3=x1*x2;
	LL g3=gcd(x3,y3);
	x3/=g3;y3/=g3;
	return make_pair(x3,y3);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		LL k;
		cin>>k;
		a[i][0]=k;
		for(LL j=1;j<=k;j++){
			LL x;
			cin>>x;
			a[x][1]++;
			v[i].push_back(x);
		}
	}
	for(LL i=1;i<=m;i++){
		for(LL j=0;j<v[i].size();j++){
			a[v[i][j]][1]--;
			b[v[i][j]]=add(b[v[i][j]],make_pair(1,a[i][0]));
		}
	}
	for(LL i=1;i<=n;i++){
		LL mx=0;
		for(LL j=m+1;j<=n;j++){
			if(a[j][1]==0&&a[j][0]&&!h[j]){
				mx=j;
				h[j]=1;
				break;
			}
		}
		if(mx==0)break;
		for(LL j=0;j<v[mx].size();j++){
			a[v[mx][j]][1]--;
			b[v[mx][j]]=add(b[v[mx][j]],times(b[mx],make_pair(1,a[mx][0])));
		}
	}
	for(LL i=1;i<=n;i++){
		if(a[i][0]==0){
			cout<<b[i].first<<" "<<b[i].second<<endl;
		}
	}
	return 0;
}
