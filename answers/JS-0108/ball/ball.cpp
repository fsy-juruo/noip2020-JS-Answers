#include <bits/stdc++.h>
using namespace std;
int n,m,a[55][405],top[55],num[55][55],move[820005][2],moves;
void Move(int x,int y){
	move[++moves][0]=x;
	move[moves][1]=y;
	--num[x][a[x][top[x]]];
	++num[y][a[x][top[x]]];
	++top[y];
	a[y][top[y]]=a[x][top[x]];
	a[x][top[x]]=0;
	--top[x];
}
void MOVE(int x,int y){
	if(x==y+1){
		int t=top[y];
		Move(x+1,y);
		while(a[x][top[x]]!=y) Move(x,y);
		Move(x,x+1);
		while(top[y]>t) Move(y,x);
		Move(x+1,y);
		Move(x,x+1);
	}else{
		int t1=top[y],t2=top[y+1];
		while(a[x][top[x]]!=y){
			if(top[y+1]<n-1) Move(x,y+1);
			else Move(x,y);
		}
		Move(x,y+1);
		while(top[y]>t1) Move(y,x);
		Move(y+1,y);
		while(top[y+1]>t2) Move(y+1,x);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) top[i]=m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			++num[i][a[i][j]];
	for(int i=1;i<=m;++i) Move(1,n+1);
	for(int i=1;i<n;++i)
		for(int j=i+1;j<n+2;++j)
			while(num[j][i]>0)
				MOVE(j,i);
	while(top[n]<m) Move(n+1,n);
	printf("%d\n",moves);
	for(int i=1;i<=moves;++i)
		printf("%d %d\n",move[i][0],move[i][1]);
	return 0;
}
