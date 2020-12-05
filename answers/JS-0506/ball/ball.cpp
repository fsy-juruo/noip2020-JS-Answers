#include<bits/stdc++.h>
using namespace std;
int n,m,a[60][500],lim[60],sz[60],spare;
bool fin[60];
vector<pair<int,int> >v;
struct node{
	int x,y,z;//at pos (x,y),can be used as heighted z.
	node(int X=0,int Y=0,int Z=0){x=X,y=Y,z=Z;}
	friend bool operator <(const node &x,const node &y){
		if(x.z!=y.z)return x.z<y.z;
		if(x.x!=y.x)return x.x<y.x;
		return x.y<y.y;
	}
}pos[60][500];
int findcolor(){
	for(int i=1;i<=n;i++)lim[i]=0;
	for(int i=1;i<=n+1;i++)for(int j=sz[i];j;j--){
		int col=a[i][j];
		if(lim[col]&&pos[col][lim[col]].x==i&&pos[col][lim[col]].y==j+1){
			int tmp=pos[col][lim[col]].z;
			pos[col][++lim[col]]=node(i,j,tmp);
		}else pos[col][++lim[col]]=node(i,j,j);
	}
	for(int i=1;i<=n;i++){
		if(fin[i])continue;
		sort(pos[i]+1,pos[i]+m+1);
//		for(int j=1;j<=m;j++)printf("(%d,%d,%d)",pos[i][j].x,pos[i][j].y,pos[i][j].z);puts("");
		bool ok=true;
		for(int j=m;j>=1;j--)if(pos[i][j].z<j){ok=false;break;}
		if(ok)return i;
	}
	exit(0);
}
bool inva[60];
void mov(int p,int q){//move from p to q
//	printf("MOV:%d %d\n",p,q);
	a[q][++sz[q]]=a[p][sz[p]--],v.push_back(make_pair(p,q));
}
void findspace(int ip){
	inva[ip]=true;
	for(int i=1;i<=n+1;i++)if(!inva[i]&&sz[i]<m){mov(ip,i),inva[ip]=false;return;}
	exit(0);
}
void funccolor(int col){
	inva[spare]=true;
	for(int j=m;j>=1;j--){
		while(sz[pos[col][j].x]>pos[col][j].y)findspace(pos[col][j].x);
		mov(pos[col][j].x,spare);
	}
	fin[col]=true;
}
int reshape(){
	int mnp=-1;
	for(int i=1;i<=n+1;i++){
		if(inva[i])continue;
		if(mnp==-1||sz[i]<sz[mnp])mnp=i;
	}
	while(sz[mnp])findspace(mnp);
	return mnp;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)sz[i]=m;
	spare=n+1;
	for(int i=1;i<=n;i++){
		int col=findcolor();
		funccolor(col);
//		puts("FIN1");
		spare=reshape();
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++)printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
