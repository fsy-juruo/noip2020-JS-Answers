#include<bits/stdc++.h>
#define D 26
#define N 1050000
#define ll long long
#define Mod1 19491001
#define Mod2 19260817
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
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return;
}
int T;
int num[N];
int cnt[D];
int c[N];
int n;
ll ans;
int sum[D+1];
int tot[D];
int res;
int h1[N];
int h2[N];
int pw1[N];
int pw2[N];
void rd(){
	n=0;
	char ch=getchar();
	for (;ch<'a'||ch>'z';ch=getchar());
	for (;ch>='a'&&ch<='z';ch=getchar()) c[++n]=ch-'a';
	return;
}
void getnum(){
	for (int i=0;i<D;i++) cnt[i]=0;
	num[n+1]=0;
	for (int i=n;i>=1;i--){
		num[i]=num[i+1];
		cnt[c[i]]++;
		if (cnt[c[i]]&1) num[i]++;
		else num[i]--;
	}
	return;
}
void gethash(){
	pw1[0]=pw2[0]=1;
	for (int i=1;i<=n;i++){
		h1[i]=(1ll*h1[i-1]*D+c[i])%Mod1;
		h2[i]=(1ll*h2[i-1]*D+c[i])%Mod2;
		pw1[i]=1ll*pw1[i-1]*D%Mod1;
		pw2[i]=1ll*pw2[i-1]*D%Mod2;
	}
	return;
}
int hsh1(int L,int R){
	int res=1ll*h1[L-1]*pw1[R-L+1]%Mod1;
	res=h1[R]-res;
	if (res<0) res+=Mod1;
	return res;
}
int hsh2(int L,int R){
	int res=1ll*h2[L-1]*pw2[R-L+1]%Mod2;
	res=h2[R]-res;
	if (res<0) res+=Mod2;
	return res;
}
void count(){
	for (int i=0;i<D;i++) tot[i]=0;
	tot[c[1]]++;
	sum[0]=0;
	for (int i=1;i<=D;i++) sum[i]=1;
	res=1;
	ans=0;
	for (int i=2;i<n;i++){
		for (int j=i;j<n;j+=i){
			if (h1[i]!=hsh1(j-i+1,j)||h2[i]!=hsh2(j-i+1,j)) break;
			ans+=sum[num[j+1]];
		}
		tot[c[i]]++;
		if (tot[c[i]]&1) res++;
		else res--;
		for (int j=res;j<=D;j++) sum[j]++;
	}
	write(ans);putchar('\n');
	return;
}
void solve(){
	rd();
	getnum();
	gethash();
	count();
	return;
}
int main(){
	open();
	read(T);
	while (T--) solve();
	return 0;
}

