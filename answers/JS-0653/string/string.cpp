#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int cnta[30],cntc[30];
long long ans;
void solve() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ans=0;
	for(int i=1;i<s.size();i++) {
		for(int j=-1;;j++) {
			int flag=1;
			if(i+(j+1)*(i+1)+1>=s.size()) break;
			for(int k=i+j*(i+1)+1;k<=i+(j+1)*(i+1);k++) {
				if(s[k]!=s[k-i-j*(i+1)-1]) {
					flag=0;
					break;
				}
			}
			if(flag==0) {break;}
			//else cout<<j<<endl;
			memset(cntc,0,sizeof(cntc));
			for(int k=i+(j+1)*(i+1)+1;k<s.size();k++) {
				cntc[s[k]-'a'+1]++;
			}
			int ccnt=0;
			
			for(int k=1;k<=26;k++) {
				if(cntc[k]&1) ccnt++;
			}
			memset(cnta,0,sizeof(cnta));
			int acnt=0;
			for(int k=0;k<i;k++) {
				cnta[s[k]-'a'+1]++;
				if(cnta[s[k]-'a'+1]&1) acnt++;
				else acnt--;
				if(acnt<=ccnt) ans++;
			}
		}
	}
	cout<<ans<<endl;
}

int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		solve();
	}
	return 0;
}

