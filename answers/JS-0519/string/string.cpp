#include<bits/stdc++.h>
using namespace std;
string s;
int hc[300],ha[300],c=0;
bool  check(int l,int r,int len){
	for(int i=0;i<len;i++)
	for(int j=1;j<(r-l+1)/len;j++)
	if(s[i]!=s[j*len+i])return 0;
	return 1;
}
int find(int l,int r,int m){
	int ans=0;
	for(int i=1;i<=r-l+1;i++){
		if((r-l+1)%i==0){
			if(check(l,r,i)){
				memset(ha,0,sizeof(ha));
				int cnt=0;
				for(int j=0;j<i-1;j++){
					if(ha[s[j]]%2==0)cnt++;
					else cnt--;
					ha[s[j]]++;
					if(cnt<=m)ans++;
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long ans=0;
		cin>>s;
		memset(hc,0,sizeof(hc));
		c=0;
		for(int i=s.size()-2;i>0;i--){
			hc[s[i+1]]++;
			if(hc[s[i+1]]%2==1)c++;
			else c--;
			ans+=find(0,i,c);
		}
		cout<<ans<<endl;
	}
	return 0;
}
