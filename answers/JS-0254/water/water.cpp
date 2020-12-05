#include<bits/stdc++.h>
#define int unsigned long long 
using namespace std;
void read(int &x){
	int f=1,r=0;char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,tot=0,anstot;
struct info{
	int p,q;
};
struct node{
	int x,p,q;
};
bool cmp(node a,node b){
	return a.x<b.x;
}
info val[100010];
int ver[100010],nxt[100010],head[100010],ind[100010],outd[100010],vis[100010];
node ans[100010];
queue<int> q;
int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;	
}
info sum(int po,int pt,int qo,int qt){
	int fenz=po*qt+pt*qo;
	int fenm=pt*qt;
	int gg=gcd(fenz,fenm);
	return (info){fenz/gg,fenm/gg};
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		int x;read(x);
		outd[i]=x;
		for(int j=1;j<=x;j++){
			int y;read(y);add(i,y);
			ind[y]++;
		}
		val[i].q=1;
	}
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			q.push(i);
			val[i].p=val[i].q=1;
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		if(outd[x]==0&&vis[x]==ind[x]){
			ans[++anstot]=(node){x,val[x].p,val[x].q};
			continue;
		}
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			val[y]=sum(val[y].p,val[y].q,val[x].p,val[x].q*outd[x]);
			vis[y]++;
			if(vis[y]==ind[y])q.push(y);
		}
	}
	sort(ans+1,ans+anstot+1,cmp);
	for(int i=1;i<=anstot;i++){
		write(ans[i].p);putchar(' ');
		write(ans[i].q);putchar('\n');
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
