#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y){
	if (x%y==0) return y;
	x%=y;
	long long tmp=x;
	x=y;y=tmp;
	return gcd(x, y);
}
struct uct{
	long long fz, fm;
}v[100001];
long long head[100001], a[100001][6], now, tmp[100001];
int main(){
	freopen ("water.in","r",stdin);
	freopen ("water.out","w",stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i=1; i<=n; i++) v[i].fm=1;
	for (long long i=1; i<=m; i++) v[i].fz=1;
	head[0]=-1;
	for (long long i=1; i<=n; i++){
		cin >> a[i][0];
		if (a[i][0]==0) continue;
		v[i].fm*=a[i][0];
		long long x=gcd(v[i].fm, v[i].fz);
		long long fm=v[i].fm/x, fz=v[i].fz/x;
		v[i].fm=1, v[i].fz=0;
		long long pfm=fm, pfz=fz;
		for (long long j=1; j<=a[i][0]; j++){
			cin >> a[i][j];
			if (a[i][j]<i){head[0]=0;now++;head[now]=a[i][j];}
			long long tmp=gcd(fm, v[a[i][j]].fm);
			fz*=(v[a[i][j]].fm/tmp);
			v[a[i][j]].fz*=(fm/tmp);
			v[a[i][j]].fz+=fz;
			v[a[i][j]].fm*=(fm/tmp);
			tmp=gcd(v[a[i][j]].fm, v[a[i][j]].fz);
			v[a[i][j]].fm/=tmp, v[a[i][j]].fz/=tmp;
			fm=pfm, fz=pfz;//9:26
		}
	}//9:15
	while (head[0]==0){
		head[0]=-1;
		long long usednow=now;
		now=0;
		for (long long i=1; i<=usednow; i++){
			if (a[head[i]][0]==0) continue;
			v[head[i]].fm*=a[head[i]][0];
			long long x=gcd(v[head[i]].fm, v[head[i]].fz);
			long long fm=v[head[i]].fm/x, fz=v[head[i]].fz/x;
			v[head[i]].fm=1, v[head[i]].fz=0;
			long long pfm=fm, pfz=fz;
			for (long long j=1; j<=a[head[i]][0]; j++){
				if (a[head[i]][j]<i){head[0]=0;now++;tmp[now]=a[head[i]][j];}
				long long tmp=gcd(fm, v[a[head[i]][j]].fm);
				fz*=(v[a[head[i]][j]].fm/tmp);
				v[a[head[i]][j]].fz*=(fm/tmp);
				v[a[head[i]][j]].fz+=fz;
				v[a[head[i]][j]].fm*=(fm/tmp);
				tmp=gcd(v[a[head[i]][j]].fm, v[a[head[i]][j]].fz);
				v[a[head[i]][j]].fm/=tmp, v[a[head[i]][j]].fz/=tmp;
				fm=pfm, fz=pfz;
			}
		}//9:36
		for (long long i=1; i<=now; i++) head[i]=tmp[i];
	}
	for (long long i=1; i<=n; i++)
		if (a[i][0]==0) cout << v[i].fz << ' ' << v[i].fm << endl;
	return 0;
}
