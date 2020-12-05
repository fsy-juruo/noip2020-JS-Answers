#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int T,cnt[26];
long long hsh[1048577],pw[1048577];
string s;
vector<int>v[1048577];
int CNT[26][1048576],cntf[1048577],cntb[1048577];
void solve(){
	for(int i=0;i<26;i++)cnt[i]=0;
	for(int i=0;i<=s.size();i++)
		hsh[i+1]=(hsh[i]*27+s[i]-'a'+1)%mod;
	for(int i=0;i<=s.size();i++)v[i].clear();
	for(int i=s.size();i>0;i--){
		v[i].push_back(i);
		for(int j=i;j+i<=s.size();j+=i)
			if(hsh[i]==((hsh[j+i]-hsh[j]*pw[i])%mod+mod)%mod)
				v[j+i].push_back(i);
			else
				break;
	}
	int now=0;cntf[0]=0;
	for(int i=1;i<=s.size();i++){
		if(cnt[s[i-1]-'a']%2)now--;else now++;
		cnt[s[i-1]-'a']++;cntf[i]=now;
	}for(int i=0;i<26;i++)cnt[i]=0;now=0;cntb[0]=0;
	for(int i=1;i<=s.size();i++){
		if(cnt[s[s.size()-i]-'a']%2)now--;else now++;
		cnt[s[s.size()-i]-'a']++;cntb[i]=now;
	}long long ans=0;
	for(int i=1;i<=s.size();i++)
		CNT[cntf[i]][i]++;
	for(int i=1;i<=s.size();i++)
		for(int j=0;j<=26;j++)
			CNT[j][i]+=CNT[j][i-1];
	for(int i=1;i<=s.size();i++)
		for(int j=1;j<=26;j++)
			CNT[j][i]+=CNT[j-1][i];
	for(int i=1;i<s.size();i++){
		int maxm=cntb[s.size()-i];
		for(int k=0;k<v[i].size();k++)
			ans+=CNT[maxm][v[i][k]-1];
	}
	cout<<ans<<endl;
	for(int i=0;i<=s.size();i++)
		for(int j=0;j<=26;j++)
			CNT[j][i]=0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<1048577;i++)
		pw[i]=pw[i-1]*27%mod;
	cin>>T;
	while(T--){
		char c;
		c=getchar();
		while(c>'z'||c<'a')c=getchar();
		while(c<='z'&&c>='a'){
			s=s+c;
			c=getchar();
		}
		solve();s="";
	}
	return 0;
}//tourist bless me!
