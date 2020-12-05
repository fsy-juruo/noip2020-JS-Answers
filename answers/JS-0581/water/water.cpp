#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int n,m;
long long gcd(long long x,long long y){
	long long r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
int re[100010];
long long p[100010],q[100010];
vector<int>v[100010];
vector<int>ans;
void bfs(int x){
	if(v[x].size()==0)return;
	q[x]*=v[x].size();
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(q[y]){
			p[y]=p[y]*q[x]+p[x]*q[y];
			q[y]*=q[x];	
		}else{
			p[y]=p[x];
			q[y]=q[x];
		}
		long long g=gcd(p[y],q[y]);
		p[y]/=g;
		q[y]/=g;
		bfs(y);
	}
	p[x]=0;q[x]=0;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		int x;
		read(x);
		if(x==0)ans.push_back(i);
		for(int j=1;j<=x;j++){
			int y;
			read(y);
			re[y]++;
			v[i].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		if(re[i]==0){
			p[i]=1;q[i]=1;
			bfs(i);
		}
	}
	
	for(int i=0;i<ans.size();i++){
		long long g=gcd(p[ans[i]],q[ans[i]]);
		cout<<p[ans[i]]/g<<" "<<q[ans[i]]/g<<endl;
	}
	return 0;
}

