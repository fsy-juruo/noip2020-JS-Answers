#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=10010,M=1000010;
struct liuliang{
	LL up;
	LL down;
}f[N];
int  n,m,t,tot=0;
bool be[N],ed[N];
int head[N],Next[M],ver[M],d[N];
void add(int x,int y){
	ver[++tot]=y,Next[tot]=head[x],head[x]=tot;
}
LL gcd(LL a,LL b){
	LL c;
	while(a!=0){
		c=b%a;
		b=a;
		a=c;
	}
	return b;
}
void mul(int i,int x){
	LL b,a,e;
	a=f[x].up,b=f[x].down*d[x];
	e=f[i].down*b;
	a=f[i].down*f[x].up;
	f[i].up=f[i].up*b+a;	
	f[i].down=e;	
	LL kk=gcd(f[i].up,f[i].down);
	f[i].up/=kk;
	f[i].down/=kk;
}
void dfs(int x){
	LL kk=gcd(f[x].up,f[x].down);		
	f[x].up=f[x].up/kk;
	f[x].down=f[x].down/kk;	
	if(ed[x]){
		LL kk=gcd(f[x].up,f[x].down);		
		return;
	}		

	for(int i=head[x];i;i=Next[i]){
		mul(ver[i],x);
		dfs(ver[i]);

	}		
	f[x].up=0;
	f[x].down=1;
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);	
	scanf("%d",&n);
	scanf("%d",&m);
	memset(d,-1,sizeof(d));
	memset(be,true,sizeof(be));
	memset(ed,false,sizeof(ed));
	memset(head,false,sizeof(head));
	memset(Next,false,sizeof(Next));
	memset(ver,0,sizeof(ver));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)f[i].down=1;
	int  x,y;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]==0){
			ed[i]=true;
			continue;
		}
		for(int j=1;j<=d[i];j++){
			cin>>y;
			be[y]=false;
			add(i,y);
		}	
	}
	for(int i=1;i<=n;i++){
		if(be[i]){
			f[i].up=1;f[i].down=1;	
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		if(ed[i]){
			cout<<f[i].up<<' '<<f[i].down<<endl;
		}
	}
	return 0;
}
