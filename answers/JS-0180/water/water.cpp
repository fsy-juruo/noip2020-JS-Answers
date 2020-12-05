#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int rd(){
	int x=0;char c;c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}
void pr(ll x){
	if(x>9)pr(x/10);
	putchar(x%10+48);
}
ll mygcd(ll x,ll y){
	while(x){
		x^=y^=x^=y%=x;
	}
	return y;
}

struct fen{
	ll p,q;
	fen(){
		p=0;q=1;
	}
	fen operator +(const fen b)const{
		fen c,t;t=*this;
		c.p=t.p*b.q+t.q*b.p;
		c.q=t.q*b.q;
		ll l=mygcd(c.p,c.q);
		c.p/=l;c.q/=l;             ////////////
		return c;
	}
}a[N],cur;

int n,m,d[N],ans[N];
struct xx{
	int to,nxt;
}e[N*5];int hd[N],num;
void add(int fm,int to){
	e[++num].to=to;
	e[num].nxt=hd[fm];hd[fm]=num;
}
/*****************/
void st(){
	for(int i=1;i<=n;i++)
		a[i].q=1,a[i].p=0;             ////////////
}
void clear(){
	for(int i=1;i<=n;i++){
		if(d[i]!=0)a[i].q=1,a[i].p=0;//////////////////
	}
}
queue<int>que;int inq[N];
void solve(int x){
	a[x].p=a[x].q=1;          ////////////////
	que.push(x);inq[x]=1;
	while(!que.empty()){
		int u=que.front();que.pop();inq[u]=0;
		if(d[u]==0)continue;
		cur=a[u];
		cur.q*=d[u];
		for(int t=hd[u];t;t=e[t].nxt){
			int y=e[t].to;
			a[y]=a[y]+cur;
			if(!inq[y]){
				inq[y]=1;
				que.push(y);
			}
		}
		a[u].p=0;a[u].q=1;            /////////
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=rd();m=rd();
	for(int i=1,y;i<=n;i++){
		d[i]=rd();
		for(int j=1;j<=d[i];j++){
			y=rd();
			add(i,y);
		}
		if(d[i]==0)
			ans[++ans[0]]=i;
	}
	st();
	for(int i=1;i<=m;i++){
		if(i>=2)clear();
		solve(i);
	}
	for(int i=1;i<=ans[0];i++){
		pr(a[ans[i]].p);putchar(' ');
		pr(a[ans[i]].q);putchar('\n');           //////////
	}
	return 0;
}
