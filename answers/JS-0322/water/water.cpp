#include<cstdio>
#include<iostream>
#define rep(i,j,k) for (i=j;i<=k;i++)
#define LL long long
using namespace std;
struct HH{
	LL x1,y1;
}del[100005];
LL out1[100005][10],in1[100005],s[100005],e[100005],q[100005];
int d[100005],x;
LL n,m,i,j,tot1,tot2,l,r,u;
LL gcd(LL x,LL y){
	if (y==0) return x;
	else return gcd(y,x%y);
}
void jia(int x,int y,LL del1){
	LL dx=del[x].x1*del1;
	LL dy=del[x].y1;
	LL zx=del[y].x1;
	LL zy=del[y].y1;
	if (zx!=0 && zy!=0)
		del[y].y1=dy*zx+zy*dx;	
	else del[y].y1=dy;
	if (zx!=0 && zy!=0)
		del[y].x1=dx*zx;
	else del[y].x1=dx;
	int ret=gcd(del[y].x1,del[y].y1);
	del[y].x1=del[y].x1/ret;
	del[y].y1=del[y].y1/ret;
}

void print(LL x){
	LL ret=gcd(del[x].x1,del[x].y1);
	cout<<del[x].y1/ret<<' '<<del[x].x1/ret<<endl;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n){
		scanf("%d",&d[i]);
		rep(j,1,d[i]) {
			scanf("%d",&x);
			out1[i][0]++;
			out1[i][out1[i][0]]=x;
			in1[x]++;
		}
	}
	rep(i,1,n) if (out1[i][0]==0) tot2++,e[tot2]=i;
	l=1;r=0;
	rep(i,1,m) del[i].x1=1,del[i].y1=1,r++,q[r]=i;
	while (l<=r){
		x=q[l];
		rep(i,1,out1[x][0]){
			u=out1[x][i];
			jia(x,u,out1[x][0]);
		    in1[u]--;
		    if (in1[u]==0) r++,q[r]=u;
		}
		l++;
	}
	rep(i,1,tot2) print(e[i]);
}
/*
10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

*/
