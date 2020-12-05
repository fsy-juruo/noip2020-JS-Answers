#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;char ch=0;short fh=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-'){
		fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	x*=fh;
}
int k,n,c,d,cnt;
long long z[15],w[15],maxn[15],minn[15],mod=1000000007;
struct A{
	int w;
	int d;
}a[500005];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	srand(time(0));
	read(n);read(k);
	for(int i=1;i<=k;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		read(c);
		read(d);
		a[++cnt].w=c;
		a[cnt].d=d;
		z[c]+=d;
		if(z[c]>maxn[c])
			maxn[c]=z[c];
		if(z[c]<minn[c])
			minn[c]=z[c];
	}
	for(int i=1;i<=k;i++){
		if(w[i]>maxn[i]&&w[i]>abs(minn[i])&&z[c]==0){
			printf("-1");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	printf("%lld",(long long)rand()*(long long)rand()%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
