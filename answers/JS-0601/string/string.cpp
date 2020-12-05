#include<bits/stdc++.h>
using namespace std;
const int N=30;
int t,visl[N],visr[N];
string s;
void in(){
	cin>>t;
}
void solve(){
	while(t--){
		memset(visl,0,sizeof(visl));
		memset(visr,0,sizeof(visr));
		cin>>s;
		bool f=1;
		for(int i=1;i<s.size();i++){
			if(s[i]!=s[i-1]){
				f=0;
				break;
			}
		}
		if(f==1){
			long long n=s.size(),ans=0;
			for(int i=1;i<s.size()-1;i++){
				ans+=n-i-1;
			}
			cout<<ans<<endl;
			continue;
		}
		long long ans=0,l=0;
		int kindl=0;
		while(l<s.size()-2){
			int kindr=0,r=s.size()-1;
			memset(visr,0,sizeof(visr));
			visl[s[l]-'a'+1]++;
			if(visl[s[l]-'a'+1]%2==0){
				kindl--;
			}else{
				kindl++;
			}
			while(l<r-1){
				visr[s[r]-'a'+1]++;
				if(visr[s[r]-'a'+1]%2==0){
					kindr--;
				}else{
					kindr++;
				}
				if(kindr>=kindl){
					ans++;
				}
				r--;
			}
			l++;
		}
		cout<<ans<<endl;
	}
}
void out(){
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	in();
	solve();
	out();
	return 0;
}
