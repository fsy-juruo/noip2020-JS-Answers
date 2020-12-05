#include<bits/stdc++.h>
#define N 51
#define M 401
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=sig;
}
template<typename T> void write(T x){
	if (x<0){putchar('-');x=-x;}
	T y=0;int wei=0;
	while (x>9){y=y*10+x%10;x/=10;++wei;}putchar(x+48);
	while (wei--){putchar(y%10+48);y/=10;}
}
void open(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	return;
}
int n,m;
int col[N][M];
int x[N][M];
int y[N][M];
int len[N];
int ansx[820010];
int ansy[820010];
int anslen;
int hig[N];
int find(int zhu,int co){
	for (int i=m;i>=1;i--) if (col[zhu][i]==co) return i;
	return 0;
}
void put(int x,int y){
	++anslen;
	ansx[anslen]=x;
	ansx[anslen]=y;
	hig[y]++;
	col[y][hig[y]]=col[x][hig[x]];
	hig[x]--;
	return;
}
void yi(int x,int y){
	for (int i=hig[x];i>=1;i--) put(x,y);
	return;
}
void give(int x,int y){
	yi(y,n+1);
	yi(x,y);
	yi(n+1,y);
	return;
}
void merge(int co,int x,int y,int z){
	while (1){
		int w1=find(x,co);
		int w2=find(y,co);
		if (!w1&&!w2) return;
		if (!w1) return;
		if (!w2){
			give(x,y);
			return;
		}
		int flag=0;
		while (1){
			if (hig[z]==m){
				if (hig[x]<hig[y]) yi(x,y);
				else yi(y,x);
				break;
			}
			if ((!flag&&((!w2)||(w1&&hig[x]-w1<=hig[y]-w2)))||flag==1){
				put(x,z);
				flag=1;
			}
			else{
				put(y,z);
				flag=2;
			}
			w1=find(x,co);
			w2=find(y,co);
		}
		if (!hig[x]) yi(z,x);
		else yi(z,y);
	}
	return;
}
int main(){
	open();
	read(n);read(m);
	for (int i=1;i<=n;i++){
		hig[i]=m;
		for (int j=1;j<=m;j++){
			read(col[i][j]);
			x[col[i][j]][++len[col[i][j]]]=i;
			y[col[i][j]][len[col[i][j]]]=j;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n-i;j++){
			merge(i,j,j+1,n+1);
		}
	}
	write(anslen);
	for (int i=1;i<=anslen;i++){
		write(ansx[i]);putchar(' ');write(ansy[i]);putchar('\n');
	}
	return 0;
}

