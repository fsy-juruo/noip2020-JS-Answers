#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll H=31,Mod=998244353;
int T,n;
string s;
int cnt[202020][28],lch[28],cn[28];
ll Hash[202020],pw[202020],ch[202020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<201010;i++)pw[i]=pw[i-1]*H%Mod;
	cin>>T;
	while(T--){
		for(int i=0;i<=26;i++)cn[i]=0;
		ll ans=0;
		cin>>s;
		n=s.size();
		for(int i=0;i<26;i++)cnt[0][i]=0;
		cnt[0][s[0]-'a']=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<26;j++)cnt[i][j]=cnt[i-1][j];
			cnt[i][s[i]-'a']++;
		}
		Hash[0]=s[0]-'a';
		for(int i=1;i<n;i++)Hash[i]=(Hash[i-1]*H+(s[i]-'a'))%Mod;
		for(int i=1;i<n;i++){
			ch[1]=Hash[i-1];
			for(int j=2;j<=n/i+1;j++)ch[j]=(ch[j-1]*pw[i]+Hash[i-1])%Mod;
			int l=0,r=n/i;
			while(l<=r){
				int md=(l+r)/2;
				if(ch[md]!=Hash[md*i-1])r=md-1;
				else l=md+1;
			}
			l--;
			if(l*i==n)l--;
			int Cn=0;
			for(int j=0;j<26;j++){
				lch[j]=cnt[n-1][j]-cnt[l*i-1][j];
				Cn+=lch[j]%2;
			}
			ans+=1ll*(l-l/2)*cn[Cn];
			Cn=0;
			for(int j=0;j<26;j++){
				lch[j]+=cnt[i-1][j];
				Cn+=lch[j]%2;
			}
			ans+=1ll*(l/2*cn[Cn]);
			int An=0;
			for(int j=0;j<26;j++) An+=cnt[i-1][j]%2;
			for(int j=An;j<=26;j++)cn[j]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
