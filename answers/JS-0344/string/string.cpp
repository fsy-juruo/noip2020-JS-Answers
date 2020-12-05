#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],b[N],c[N];
vector<int> e[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int n=s.size();
		memset(c,0,sizeof(c));
		a[0]=1;c[s[0]-'a'+1]++;
		for(int i=1;i<n;i++){
			int ch=s[i]-'a'+1;
			c[ch]++;
			if(c[ch]%2) a[i]=a[i-1]+1;
			else a[i]=a[i-1]-1;
		}
		memset(c,0,sizeof(c));
		b[n-1]=1;c[s[n-1]-'a'+1]++;
		for(int i=n-2;i>=0;i--){
			int ch=s[i]-'a'+1;
			c[ch]++;
			if(c[ch]%2) b[i]=b[i+1]+1;
			else b[i]=b[i+1]-1;
		}
		memset(e,0,sizeof(e));
		for(int len=4;len<n;len++){
			for(int j=2;j<=len/2;j++){
				if(len%j) continue;
				string s1=s.substr(0,j);
				int f=0;
                for(int k=0;k+j-1<len;k+=j){
                	string s2=s.substr(k,j);
                	if(s2!=s1){
                		f=1;
                		break;
					}
				}
				if(f==0)
					e[len-1].push_back(j-1);
			}
		}
		int ans=0;
		for(int i=2;i<n;i++){
			for(int j=0;j<i-1;j++){
				if(a[j]>b[i]) continue;
				ans++;
			}
			for(int j=0;j<e[i-1].size();j++){
				int x=e[i-1][j];
				for(int k=0;k<x;k++){
					if(a[k]>b[i]) continue;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
