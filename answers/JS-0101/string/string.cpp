#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(ll x){
	write(x),putchar('\n');
}
char s[1050005];
ll h[255],l[1050005],r[1050005],f[1050005],sum[35];
bool ok(int p,int q){
	for(int i=1;i<=q;++i)if(s[p+i-1]!=s[i])return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char ch=' ';
	ll t=read(),n,ans,f;
	while(t--){
		n=ans=0;
		f=1;
		while(!islower(ch))ch=getchar();
		while(islower(ch)){
			s[++n]=ch;
			ch=getchar();
		}
		for(int i=1;i<=n;++i){
			if(s[i]!=s[i-1]&&i>1)f=0;
			if(h[s[i]])l[i]=l[i-1]-1;
			else l[i]=l[i-1]+1;
			h[s[i]]^=1;
		}
		memset(h,0,sizeof(h));
		for(int i=n;i>=1;--i){
			if(h[s[i]])r[i]=r[i+1]-1;
			else r[i]=r[i+1]+1;
			h[s[i]]^=1;
		}
		memset(h,0,sizeof(h));
		memset(sum,0,sizeof(sum));
		if(f){
			for(int i=2;i<=n;++i){
				for(int j=l[i-1];j<=26;++j)++sum[j];
				for(int j=1;j<=n-i;j+=i)ans+=sum[r[i+j]];
			}
			writeln(ans);
			continue;
		}
		for(int i=2;i<=n;++i){
			for(int j=l[i-1];j<=26;++j)++sum[j];
			for(int j=1;j<=n-i;j+=i){
				if(ok(j,i))ans+=sum[r[i+j]];
				else break;
			}
		}
		writeln(ans);
	}
	return 0;
}
