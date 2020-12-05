#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
bool p;
int a[60][500];
int x[820010],y[820010];
int hsh[500][500];

template <typename T> void read(T &x){
	x=0;char h=getchar();
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;
}
bool chk(){
	for (int i=1;i<=n;i++)
	if (a[i][0]!=m) return false;
	for (int i=1;i<=n;i++){
		for (int j=1;j<m;j++)
		if (a[i][j]!=a[i][j+1]) return false;
	}
	return true;
}
void wrk(int dep){
	if (p) return ;
	if (chk()) {
		p=true;
		cout<<dep<<endl;
		for (int i=1;i<=dep;i++) 
			printf("%d %d\n",x[i],y[i]);
		return ;
	}
//	cout<<1;
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=n+1;j++){
			if (i==j || a[j][0]==m || a[i][0]==0 || hsh[j][i]==1) continue;
			a[j][0]++;
			a[j][a[j][0]]=a[i][a[i][0]];
			a[i][0]--;
			hsh[i][j]=1;
			x[dep+1]=i;y[dep+1]=j;
			wrk(dep+1);
			hsh[i][j]=0;
		}
	}
	return ;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);p=false;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) read(a[i][j]);
		a[i][0]=m;
	}
	wrk(0);
	return 0;
}

