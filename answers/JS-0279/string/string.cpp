#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t;
string s;
int cnta[N][30],cntb[N][30],a[N],b[N];
void solve1(){
	long long ans=0;
	int n=s.size();
	for(int i=2;i<n;i++){
		for(int j=1;i*j<n;j++){
			int c=n-i*j;
			if(c&1)
				ans+=(i-1);
			else
				ans+=(i-1)/2;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>s;
		memset(cnta,0,sizeof(cnta));
		memset(cntb,0,sizeof(cntb));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n=s.size();
		if(n>1000){
			solve1();
			continue;
		}
		long long ans=0;
		cnta[0][s[0]-'a']=1;
		a[0]=1;
		for(int i=1;i<n;i++){
			for(int j=0;j<26;j++)
				cnta[i][j]=cnta[i-1][j];
			cnta[i][s[i]-'a']++;
			for(int j=0;j<26;j++)
				if(cnta[i][j]&1)
					a[i]++;
		}
		cntb[n-1][s[n-1]-'a']=1;
		b[n-1]=1;
		for(int i=n-2;i>=0;i--){
			for(int j=0;j<26;j++)
				cntb[i][j]=cntb[i+1][j];
			cntb[i][s[i]-'a']++;
			for(int j=0;j<26;j++)
				if(cntb[i][j]&1)
					b[i]++;
		}
		for(int i=2;i<n;i++){
			for(int j=1;i*j<n;j++){
				if(i*j>=n)
					break;
				if(s.substr(0,i)!=s.substr((j-1)*i,i))
					break;
				for(int k=0;k<i-1;k++)
					if(a[k]<=b[i*j]){
						ans++;
					}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
