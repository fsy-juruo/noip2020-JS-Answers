#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
int pre[maxn],suf[maxn],c[100],ans;
bool dp[maxn][maxn];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	while(t--){
		cin>>s;
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		for(register int i=1;i<=s.size();++i){
			c[s[i-1]-'a']++;
			pre[i]=pre[i-1];
			if(c[s[i-1]-'a']%2==0) pre[i]--;
			else pre[i]++;
		}
		for(register int i=0;i<=100;++i) c[i]=0;
		for(register int i=s.size();i>=1;--i){
			c[s[i-1]-'a']++;
			suf[i]=suf[i+1];
			if(c[s[i-1]-'a']%2==0) suf[i]--;
			else suf[i]++;
		}
		for(register int i=0;i<=100;++i) c[i]=0;
		for(register int i=2;i<=s.size();++i) dp[i][1]=1;
		for(register int i=3;i<=s.size();++i)
		  for(register int j=2;j<=i;++j){
		  	if(i%j!=0) continue;
		  	string s1=s.substr(0,i/j);
		  	string s2=s.substr(i-i/j,i/j);
		  	if(dp[i-i/j][j-1]&&(s1==s2)) dp[i][j]=1;
		  }
		for(register int i=1;i<s.size()-1;++i)
		  for(register int j=1;j<=s.size()-i;++j){
		  	if((s.size()-i)%j!=0||!dp[s.size()-i][j]) continue;
		  	for(register int k=1;k<(s.size()-i)/j;++k)
		  	  if(pre[k]<=suf[s.size()-i+1]) ans++;
		  }
		printf("%d\n",ans);
	}
}
