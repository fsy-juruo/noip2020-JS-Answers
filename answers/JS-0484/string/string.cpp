#include<bits/stdc++.h>
using namespace std;
int T,cnt[26],fa,fc,res;
string s;
void solve(){
	res=0;
	cin>>s;
	int n=s.size();
	s="?"+s;
	for(int alen=1;alen<=n;alen++){
		for(int blen=1;blen<=n-alen;blen++){
			for(int clen=n%(alen+blen);clen<=n-alen-blen;clen+=(alen+blen)){
				if(clen==0) continue;
				int ok=1;
				for(int i=alen+blen+1;i<=n-clen;i++){
					if(s[i]!=s[i-alen-blen]){
						ok=0;
						break;
					}
				}
				if(ok==0) continue;
				fa=0;
				fc=0;
				for(int i=0;i<26;i++) cnt[i]=0;
				for(int i=1;i<=alen;i++) cnt[s[i]-'a']++;
				for(int i=0;i<26;i++) if(cnt[i]%2==1) fa++;
				for(int i=0;i<26;i++) cnt[i]=0;
				for(int i=n-clen+1;i<=n;i++) cnt[s[i]-'a']++;
				for(int i=0;i<26;i++) if(cnt[i]%2==1) fc++;
				if(fa>fc) continue;
				res++;
			}
		}
	}
	cout<<res<<endl;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
  REMEMBER to init vals
  REMEMBER to check IO
  REMEMBER to compile before submitting
*/
