#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline void file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
template <typename T> inline void read(T&x){
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-48;
}
vector<int>a[100005];
int s[100005];
bool prt[100005],vis[100005];
LL p[100005],q[100005];
LL ansp[100005],ansq[100005];
queue<int>qu;
int n,m;
LL gcd(LL a,LL b){
	if(a==0)return b;
	return gcd(b%a,a);
}
inline void pluser(LL &np,LL &nq,LL _p,LL _q){
	LL c,d;
	c=np*_q+nq*_p;
	d=nq*_q;
	LL g=gcd(c,d);
	np=c/g;
	nq=d/g;
}
void bfs(){
	while(qu.size()){
		int x=qu.front();
		qu.pop();
//		vis2[x]=2;
		for(int i=0;i<s[x];i++){
			pluser(p[a[x][i]],q[a[x][i]],p[x],q[x]*s[x]);
			pluser(ansp[a[x][i]],ansq[a[x][i]],p[x],q[x]*s[x]);
//				vis2[a[x][i]]=1;
				qu.push(a[x][i]);
		}
		p[x]=0;
		q[x]=1;
	}
}
int main(){
	file("water");
	read(n);
	read(m);
	for(int i=1;i<=n;i++)
		ansq[i]=q[i]=1;
	for(int i=1;i<=n;i++){
		read(s[i]);
		if(s[i]==0)prt[i]=1;
		for(int j=1;j<=s[i];j++){
			int x;
			read(x);
			a[i].push_back(x);
			vis[x]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])qu.push(i),p[i]=1;
	}
	bfs();
	for(int i=1;i<=n;i++){
		if(prt[i]==1){
			printf("%lld %lld\n",ansp[i],ansq[i]);
		}
	}
	return 0;
}

