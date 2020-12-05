#include <bits/stdc++.h>
using namespace std;
const int maxn=1050000;
int t,m[maxn],s1[maxn],s2[maxn],num[30];
long long ans;
string s,T;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>s;
		
		//for(int i=1;i<=T.length();++i) s[i]=T[i-1];
		//for(int i=1;i<=s.length();++i) cout<<s[i];
		memset(m,0,sizeof(m));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(num,0,sizeof(num));
		int n=s.length();
		for(int i=0;i<n;++i) {
			if(!num[s[i]-'a'+1]) num[s[i]-'a'+1]=1,s1[i]=s1[i-1]+1;
			else num[s[i]-'a'+1]=0,s1[i]=s1[i-1]-1;
		}
		memset(num,0,sizeof(num));
		for(int i=n-1;i>=0;--i) {
			if(!num[s[i]-'a'+1]) num[s[i]-'a'+1]=1,s2[i]=s2[i+1]+1;
			else num[s[i]-'a'+1]=0,s2[i]=s2[i+1]-1;
		}
		//for(int i=0;i<n;++i) cout<<s2[i]<<" ";
		for(int i=0;i<=n-1;++i){
			m[i]=i;int flag=1;
			while(flag&&m[i]<=n-1){
				for(int j=m[i]+1;j<=m[i]+i+1;++j){
					if(s[j]!=s[j-m[i]-1]){
						flag=0;
						break;
					}
				}
				if(flag) m[i]+=(i+1);
			}
			//cout<<"m[i]:"<<m[i]<<" ";
		}
		//cout<<"checkpoint";
		for(int i=1;i<n;++i){for(int j=0;j<=i-1;++j){
			for(int k=0;m[i]-k*(i+1)>=1&&m[i]-k*(i+1)<=n-2;++k){
				 if(s2[m[i]-k*(i+1)]>=s1[j]){
					cout<<i<<" "<<j<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}}
	return 0;
}
