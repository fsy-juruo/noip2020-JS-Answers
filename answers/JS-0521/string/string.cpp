#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define ms memset
#define LD long double
#define STOP system("pause")

template <typename T> inline void read(T &x){
	x=0; T f=1; char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for (;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template <typename T> inline void write(T x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+48);
}
template <typename T> inline void writeln(T x){
	write(x); puts("");
}
int T,n;
string s;
int ans;
int c1[500],c2[500],s1=0,s2[1010],c3[500];
string A="",B="",AB="",C[1010];
inline void solve1(){
	ans=0;
	ms(s2,0,sizeof(s2));
	for (register int i='a';i<='z';++i) c3[i]=c2[i]=c1[i]=0;
	C[n]=s;
	A="";
	for (register int i=0;i<n;++i){
		if (c3[s[i]]) c3[s[i]]=0,s2[n]--;
		else c3[s[i]]=1,s2[n]++;
	}
	for (register int i=n-1;i>=1;--i){
		string p=C[i+1];
		char g=p[0];
		p.erase(p.begin());
		C[i]=p;
		s2[i]=s2[i+1];
		if (c3[g]) c3[g]=0,s2[i]--;
		else c3[g]=1,s2[i]++;
	}
	s1=0;
	for (register int i=0;i<n;++i){
		A+=s[i];
		if (c1[s[i]]) c1[s[i]]=0,s1--;
		else c1[s[i]]=1,s1++;
		for (register int j=i+1;j<n;++j){
			B+=s[j];
			int maxn=s.size()/(A.size()+B.size());
			AB="";
			for (register int k=1;k<=maxn;++k){
				AB=AB+A+B;
				int p=s.size()-AB.size();
				if (s1>s2[p])continue;
				if (AB+C[p]!=s) break;
				if (C[p].size()) ans++;
			}
		}
		B="";
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while (T--){
		s="";
		char ch=getchar();
		while (ch<'a'||ch>'z') ch=getchar();
		while (ch>='a'&&ch<='z') s+=ch,ch=getchar();
		n=s.size();
			solve1();
			writeln(ans);
	}
	return 0;
}

