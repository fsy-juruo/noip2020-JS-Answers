#include<bits/stdc++.h>
using namespace std;

int n,k,Min,Max,sum,p;
long long ans;
int w[20],a[20],b[20];
int x[10010],y[10010];

template <typename T> void read(T &x){
	x=0;char h=getchar();int p=1;
	for (;!isdigit(h);h=getchar()) if (h=='-') p=-1;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;x*=p;
}
void prt(){
	for (int i=1;i<=k;i++) b[i]=a[i];
	while (1){
		bool flg=1;
		for (int i=1;i<=n;i++) {
			b[x[i]]+=y[i];ans++;
			if (b[x[i]]>w[x[i]] || b[x[i]]<1) return ;
		}
		for (int i=1;i<=k;i++)
		if (a[i]!=b[i]) {flg=0;break;}
		if (flg==1) {p=1;return ;}
	}
	return ;
}
void wrk(int x){
	if (x>k) {
		prt();
		return ;
	}
	for (int i=1;i<=w[x];i++){
		if (p==1) return ;
		a[x]=i;
		wrk(x+1);
	}
	return ;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	for (int i=1;i<=k;i++) read(w[i]);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	if (n>1000) {
		cout<<-1<<endl;
		return 0;
	}
	wrk(1);
	if (p==1) cout<<-1<<endl;
		 else cout<<ans<<endl;
	return 0;
}

