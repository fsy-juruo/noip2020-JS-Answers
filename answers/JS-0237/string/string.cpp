#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
char buf[1000005];
string read(){
	scanf("%s",buf);
	return buf;
}
bool st;
int T,n;
string s;
int pre[1000005][26];
int cnt[1000005][26],suf[1000005];
int z[1000005],f[1000005];
bool ed;
void build(){
	int l=1,r=1;
	z[1]=n;int tot=0;
	for(int i=2;i<=n;i++){
		if(i<=r)z[i]=min(r-i,z[i-l+1]);
		while(i<=n&&s[z[i]+1]==s[i+z[i]])z[i]++;
		if(i+z[i]>r){
			l=i;r=i+z[i];
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(z,0,sizeof z);
		s=read();
		n=s.size();s=" "+s;
		build();
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		memset(cnt,0,sizeof cnt);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			memcpy(pre[i],pre[i-1],sizeof pre[i]);
			pre[i][s[i]-'a']++;
		}
		for(int i=n;i>=1;i--){
			int p=s[i]-'a';
			if((pre[n][p]-pre[i-1][p])&1)suf[i]=suf[i+1]+1;
			else suf[i]=suf[i+1]-1;
		}
		for(int i=1;i<=n;i++){
			memcpy(cnt[i],cnt[i-1],sizeof cnt[i]);
			int p=s[i]-'a';
			if(pre[i][p]&1)f[i]=f[i-1]+1;
			else f[i]=f[i-1]-1;
			for(int j=f[i];j<26;j++)cnt[i][j]++;
		}
		long long ans=0;
		for(int len=1;len<=n;len++){
			int pos=1;
			for(int pw=1;pos+len-1<n;pw++){
				if(z[pos]<len)break;
				int got=suf[pos+len];
				ans+=cnt[len-1][got];
				pos+=len;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
