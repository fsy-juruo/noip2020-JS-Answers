//Nothing more to think about, just to try my best in the Finale
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
int tc,ans,cntab[26],cnta[26],cntt[26],cntr[26],oa,s[1005];
ll ansl;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>tc;
	while (tc--){
		cin>>str;
		int n=str.size();
		if (n>1000){
			ansl=0;
			for (int i=2;i<n;i++){
				int lenab=i;
				int lenc=n-i;
				int k=lenc/lenab;
				if (lenc%lenab!=0) k++;
				int fc1=0,fc0=0,fa1=0,fa0=0;
				if (lenab%2==0){
					if (lenc%2==1) fc1=k; else fc0=k;
					fa1=lenab/2;
					fa0=lenab/2-1;
				}else{
					if (k%2==0){
						fc1=k/2;
						fc0=k/2;
					}else{
						if (lenc%2==1){
							fc1=k/2+1;
							fc0=k/2;
						}else{
							fc1=k/2;
							fc0=k/2+1;
						}
					}
					fa1=lenab/2;
					fa0=lenab/2;
				}
				ansl+=(ll)fa0*(ll)fc0+(ll)fa0*(ll)fc1+(ll)fa1*(ll)fc1;
			}
			cout<<ansl<<endl;
			continue;
		}
		for (int i=0;i<n;i++) s[i]=str[i]-'a';
		for (int i=0;i<26;i++){
			cntt[i]=0;
			cntr[i]=0;
		}
		for (int i=0;i<str.size();i++) cntt[s[i]]++;
		for (int i=2;i<str.size();i++){
			for (int j=0;j<26;j++) cntab[j]=0;
			for (int j=0;j<i;j++) cntab[s[j]]++;
			for (int j=1;j<i;j++){
				for (int k=0;k<26;k++) cnta[k]=0;
				for (int k=0;k<j;k++) cnta[s[k]]++;
				oa=0;
				for (int k=0;k<26;k++) if (cnta[k]%2==1) oa++;
				int c=0;
				for (int k=0;k<26;k++) cntr[k]=cntt[k]-cntab[k];
				bool ok;
				do{
					int oc=0;
					for (int k=0;k<26;k++) if (cntr[k]%2==1) oc++;
					if (oa<=oc) ans++;
					ok=true;
					c++;
					if (i*(c+1)>=n) break;
					for (int k=0;k<i;k++){
						if (s[k+(i*(c-1))]!=s[k+(i*c)]){
							ok=false;
							break;
						}
					}
					for (int k=0;k<26;k++) cntr[k]-=cntab[k];
				}while (ok);
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
