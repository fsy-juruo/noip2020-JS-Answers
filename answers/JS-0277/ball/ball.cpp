#include<bits/stdc++.h>
using namespace std;
const int maxn=53;
const int maxm=413;
const int inf=1e7;
int n,m,a[maxn][maxm],k;
int b1[inf],b2[inf];
inline int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=read();
		}
	}
	int c1=a[1][1],c2=a[2][1];
	int i=m,cnt=1,j=m;//i top to bottom; cnt bottom to top
	while (a[1][m]!=c1 || a[2][m]!=c2){
		while (a[1][i]!=c1){
			a[3][cnt++]=a[1][i];
			a[1][i]=0;
			b1[++k]=1,b2[k]=3;
			i--;
		}
		while (a[2][j]!=c2){
			a[1][++i]=a[2][j];
			a[2][j]=0;
			b1[++k]=2,b2[k]=1;
			j--;
		}
		while (cnt>=2){
			a[3][--cnt]=a[2][++j];
			a[3][cnt]=0;
			b1[++k]=3,b2[k]=2;
		}
	}	
	printf("%d\n",k);
	for (int i=1;i<=k;i++){
		printf("%d %d\n",b1[i],b2[i]);
	}
	return 0;
}
/*
3 2 
1 1 2
2 1 1
*/
