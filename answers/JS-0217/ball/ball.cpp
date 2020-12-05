#include<bits/stdc++.h>
using namespace std;
int n,m,a[101][101],t,x,y,k,b[820001],d[820001];
void fq(){
	while(a[1][x]==1){
		k++;
		x--;
		t++;
		b[k]=1;
		d[k]=3;
	}
	while(a[2][y]==1){
		t++;
		y--;
		k++;
		b[k]=2;
		d[k]=3;
	}
    while(a[2][y]==2)
		if(x<m){
			x++;
			y--;
			k++;
			b[k]=2;
			d[k]=1;
		}
		else
			while(a[1][x]==2&&t<=m){
				t++;
				x--;
				k++;
				b[k]=1;
				d[k]=3;
			}
		
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	x=m;
	y=m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        scanf("%d",&a[i][j]);
	fq();
	printf("%d\n",k);
	for(int i=1;i<=k;i++)
	    printf("%d %d\n",b[i],d[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
