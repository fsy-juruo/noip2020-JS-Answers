#include<bits/stdc++.h>
using namespace std;
#define N 100005
struct{int p,q;}dat[N];
int n,m,hea[N],nex[N],ver[N],tot,k,pi,deg[N],ru,jie[N],chu[N];
bool c[N];
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')y=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*y;
}
void add(int x,int y)
{
	ver[++tot]=y;
	nex[tot]=hea[x];hea[x]=tot;
}
void bfs(int x)
{
	queue<int>qq;
	qq.push(x);
	while(qq.size()>0){
		int xi=qq.front(); qq.pop();
		if(!c[xi])dat[xi].q=dat[xi].q*chu[xi];
		for(int i=hea[xi];i;i=nex[i]){
			if(dat[ver[i]].p!=0&&dat[ver[i]].q!=0){
				dat[ver[i]].p=dat[xi].p*dat[ver[i]].q+dat[ver[i]].p*dat[xi].q;
			    dat[ver[i]].q=dat[xi].q*dat[ver[i]].q;
			}
			else {
				dat[ver[i]].p=dat[xi].p;
			    dat[ver[i]].q=dat[xi].q;
			}
			//dat[ver[i]].q=chuo(ver[i]);
			qq.push(ver[i]);
		}
		if(!c[xi])dat[xi].p=0,dat[xi].q=0;
	}
}
int exgcd(int x,int y)
{
	if(y==0)return x;
	exgcd(y,x%y);
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(c,false,sizeof(c));
	n=read();m=read();
	int qi=0;
	//cout<<n<<m;
	for(int i=1;i<=n;i++){
		k=read();
		chu[i]=k;
		if(k==0){
			jie[++pi]=i;qi++;
			c[i]=true;
		}
		for(int j=1;j<=k;j++){
			int y=read();
			add(i,y);
			deg[y]++;
		}
	}
	//for(int i=1;i<=n;i++)cout<<chu[i]<<" ";
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			ru=i;
			break;
		}
	}
	dat[ru].p=1;dat[ru].q=1;
	bfs(ru);
	//cout<<dat[jie[1]].p;
	for(int i=1;i<=qi;i++){
		int h=dat[jie[i]].q,w=dat[jie[i]].p;
		int zuixiao=exgcd(h,w);
		//cout<<dat[jie[i]].q<<" "<<dat[jie[i]].p;
		dat[jie[i]].p/=zuixiao;
		dat[jie[i]].q/=zuixiao;
		printf("%d %d\n",dat[jie[i]].p,dat[jie[i]].q);
		//cout<<zuixiao;
	}
	return 0;
}

