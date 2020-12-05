#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
ll s=0,f=1;
char ch=getchar();
while(!isdigit(ch)){
if(ch=='-')f=-f;
ch=getchar();
}
while(isdigit(ch)){
s=(s<<1)+(s<<3)+ch-48;
ch=getchar();
}
return s*f;
}
struct node{
	ll v,wz,wm;
};
ll tf(node &a){ll g=__gcd(a.wm,a.wz);a.wm/=g;a.wz/=g;}
vector < node > e[10001];
ll n,m;
bool sc[10001];
void pushdown(ll x){
	for(int i=1;i<=e[x][0].v;i++){
		node f;
		//cout<<x<<' '<<e[x][0].wm<<'F'<<endl;
		f.wm=e[x][0].wm;
		f.wz=e[x][0].wz*e[x][0].v;
		tf(f);
		//cout<<x<<' '<<f.wm<<' '<<f.wz<<'F'<<endl;
		
		ll z=e[e[x][i].v][0].wm,y=e[e[x][i].v][0].wz;
		if(y!=f.wz){
			ll l1=y,l2=f.wz;
			y*=l2;
			z*=l2;
			f.wm*=l1;
			f.wz*=l1;
		}
		z+=f.wm;
		e[e[x][i].v][0].wm=z;
		e[e[x][i].v][0].wz=y;
		//cout<<e[e[x][i].v][0].wm<<' '<<e[e[x][i].v][0].wz<<endl;
		tf(e[e[x][i].v][0]);
		//cout<<x<<' '<<e[x][i].v<<' '<<e[e[x][i].v][0].wm<<'P'<<endl;
		pushdown(e[x][i].v);
		
		
		
	}
	if(sc[x]==0){
		e[x][0].wz=1;
		e[x][0].wm=0;
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
for(int i=1;i<=m;i++){
	int j=read();
	int l=j;
	if(j==0)sc[i]=1;
	node t;
	t.v=j;
	t.wm=1;
	t.wz=1;
	e[i].push_back(t);
	while(j--){
		t.v=read();
		t.wm=1;
		t.wz=l;
		e[i].push_back(t);
	} 
}
for(int i=m+1;i<=n;i++){
	int j=read();
	if(j==0)sc[i]=1;
	node t;
	t.v=j;
	t.wm=0;
	t.wz=1;
	e[i].push_back(t);
	while(j--){
		t.v=read();
		t.wm=0;
		t.wz=1;
		e[i].push_back(t);
	} 
}
for(int i=1;i<=m;i++){
	pushdown(i);
}
/*
for(int i=1;i<=n;i++){
cout<<e[i][0].v<<' '<<e[i][0].wm<<' '<<e[i][0].wz<<endl;
}
*/
for(int i=1;i<=n;i++){
	if(sc[i]==1){
		tf(e[i][0]);
		cout<<e[i][0].wm<<' '<<e[i][0].wz<<endl;
	}
}
return 0;
}

