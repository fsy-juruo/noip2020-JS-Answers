#include<cstdio>
using namespace std;
int n,m,i,j,p[100][500],c[100],so1[1000000],so2[1000000];
int cnt=0;
bool okk(){
	int iii,jjj,fff;
	fff=1;
	for(iii=1;iii<=n;iii+=1){
		for(jjj=2;jjj<=m;jjj+=1){
			if(p[iii][jjj]!=p[iii][jjj-1]){
				fff=0;
				break;
			}
		}
	}
	return fff;
}
void ddd(int ff){
	int ii;
	if(c[ff]==0) ddd(ff+1);
	for(ii=1;ii<=n;ii+=1){
		if(c[ii]<m){
			p[ii][c[ii]+1]=p[ff][c[ff]];
			p[ff][c[ff]]=0;
			c[ff]-=1;
			c[ii]+=1;
			cnt+=1;
			so1[cnt]=ff;
			so2[cnt]=ii;
		}
		if(okk()) return;
	}
	if(okk()) return;
	else ddd(ff+1);
}
int main(){	
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cnt=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i+=1) for(j=1;j<=m;j+=1) scanf("%d",&p[i][j]);
	for(i=1;i<=m;i+=1) p[n+1][i]=0;
	for(i=1;i<=n;i+=1) c[i]=m;
	c[n+1]=0;
	ddd(1);
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i+=1) printf("%d %d",so1[i],so2[i]);
	return 0;
}
