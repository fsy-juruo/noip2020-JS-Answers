#include<bits/stdc++.h>
#define D 20
#define N 500010
#define Mod 1000000007
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
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	return;
}
int n,k;
int w[D];
int c[N];
int d[N];
int lef[D];
int rig[D];
int now[D];
int sid[D];
int P;
int ans;
bool chkzero(){
	for (int i=1;i<=k;i++) if (now[i]) return false;
	for (int i=1;i<=k;i++) if (w[i]-rig[i]<1-lef[i]) return false;
	return true;
}
int id(){
	int res=0;
	int dr=1;
	for (int i=k;i>=1;i--){
		res+=dr*(sid[i]-1);
		dr*=w[i];
	}
	return res;
}
void change(int pos){
	for (int i=k;i>=1;i--){
		int dr=w[i];
		sid[i]=pos%dr+1;
		pos/=dr;
	}
	return;
}
bool ok(){
	for (int i=1;i<=k;i++) if (sid[i]<1||sid[i]>w[i]) return false;
	return true;
}
int blwalk(int pos){
	change(pos);
	int i=1;
	int res=1;
	while (1){
		sid[c[i]]+=d[i];
		if (sid[c[i]]<1||sid[c[i]]>w[c[i]]) return res;
		res++;
		++i;
		if (i==n+1) i=1;
	}
	return 0;
}
int suan(int pos){
	change(pos);
	return blwalk(pos);
}
void bl(){
	for (int i=0;i<=P-1;i++){
		ans=(ans+suan(i))%Mod;
	}
	write(ans);putchar('\n');
	return;
}
int main(){
	open();
	read(n);read(k);
	P=1;
	for (int i=1;i<=k;i++){
		read(w[i]);
		P*=w[i];
	}
	for (int i=1;i<=n;i++){
		read(c[i]);read(d[i]);
		now[c[i]]+=d[i];
		lef[c[i]]=min(lef[c[i]],now[c[i]]);
		rig[c[i]]=max(rig[c[i]],now[c[i]]);
	}
	if (chkzero()){
		puts("-1");
		return 0;
	}
	if (n<=100){
		bl();
		return 0;
	}
	return 0;
}

