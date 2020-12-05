#include<bits/stdc++.h>
using namespace std;
int cnt[205];
string s;
int f(string ss){
	int len=ss.size();
	for(int i='a';i<='z';i++)cnt[i]=0;
	for(int i=0;i<len;i++)cnt[ss[i]]++;
	int ans=0;
	for(int i='a';i<='z';i++)if(cnt[i]&1)ans++;
	return ans;
}
bool check(int i,int k){
	int q=k/i;
	if(k%i!=0)return false;
	for(int j=1;j<i;j++)if(s.substr(0,q)!=s.substr(q*j,q))return false;
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int ca=0;
	while(t--){
		ca++;
		cin>>s;
		int len=s.size();
		string c;
		int ans=0;
		for(int k=2;k<len;k++){
			c=s.substr(k,len-k);
			int num=f(c);
			for(int i=1;i<=k;i++){
				if(check(i,k)){
					int q=k/i;
					for(int j='a';j<='z';j++)cnt[j]=0;
					int qwq=0;
					for(int j=0;j<q-1;j++){
						if(cnt[s[j]]==0){
							qwq++;
							cnt[s[j]]=1;
						}
						else{
							qwq--;
							cnt[s[j]]=0;
						}
						if(qwq<=num){
							ans++;
						}
					}
				}
			} 
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
