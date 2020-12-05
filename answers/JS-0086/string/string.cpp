#include<bits/stdc++.h>
using namespace std;

namespace io{
	const int size=1<<22|1;
	char iBuf[size],*iS,*iT,c;
	char getc(){
		if(iS==iT){
			iS=iBuf;
			iT=iBuf+fread(iBuf,1,size,stdin);
		}
		if(iS==iT)return EOF;
		return *iS++;
	}
	template<class T>void qread(T &x){
		int f=1;
		for(c=getc();c<'0'||c>'9';c=getc())
			if(c=='-')f=-1;
		for(x=0;c>='0'&&c<='9';c=getc())
			x=(x<<3)+(x<<1)+(c&15);
		x*=f;
	}
	void reads(char *s,int &n){
		for(c=getc();c<'a'||c>'z';c=getc());
		for(n=0;c>='a'&&c<='z';c=getc())*s++=c,n++;
	}
}

const int maxn=1100005;
const int maxm=35;
int T,n,cnt;
char s[maxn];
int z[maxn],suf[maxn],pre[maxm],cur[maxm];
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	io::qread(T);
	while(T--){
		io::reads(s,n);
		int l=0,r=0;
		z[0]=0;
		for(int i=1;i<n;i++){
			if(i<r)z[i]=min(z[i-l],r-i);
			else z[i]=0;
			while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
			if(i+z[i]-1>r)l=i,r=i+z[i]-1;
		}
		z[0]=n;
		for(int i=0;i<26;i++)cur[i]=0;
		cnt=0;
		for(int i=n-1;i>=0;i--){
			if(cur[s[i]-'a'])cnt--;
			cur[s[i]-'a']^=1;
			if(cur[s[i]-'a'])cnt++;
			suf[i]=cnt;
		}
		for(int i=0;i<26;i++)cur[i]=0;
		cnt=0;
		ans=0;
		for(int i=0;i<=26;i++)pre[i]=0;
		for(int len=1;len<=n;len++){
			if(len>1){
				for(int i=0;i+len<n;i+=len){
					if(z[i]<len)break;
					ans+=pre[suf[i+len]];
				}
			}
			if(cur[s[len-1]-'a'])cnt--;
			cur[s[len-1]-'a']^=1;
			if(cur[s[len-1]-'a'])cnt++;
			for(int i=cnt;i<=26;i++)pre[i]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
