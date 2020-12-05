#include<bits/stdc++.h>
using namespace std;
string s;
int ta[30];
int a[2000000];
int c[2000000];
int t;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		t=0;
		ans=0;
		for(int i=0;i<26;i++){
			ta[i]=0;
		}
		for(int i=1;i<=s.size()-2;i++){
			ta[s[s.size()-i]-'a']++;
			if(ta[s[s.size()-i]-'a']%2==0) t--;
			else t++;
			c[i]=t;
		}
		t=0;
		for(int i=0;i<26;i++){
			ta[i]=0;
		}
		for(int i=0;i<s.size()-2;i++){
			ta[s[i]-'a']++;
			if(ta[s[i]-'a']%2==0) t--;
			else t++;
			a[i]=t;
		}
		for(int i=2;i<=s.size()-1;i++){
			int ok=1;
			for(int j=0;j+i<s.size();j+=i){
				for(int k=0;k<i;k++){
					if(s[j+k]!=s[k]){
						ok=0;
						break;
					}
				}
				if(!ok)break;
				int tc=s.size()-i-j;
				for(int k=0;k<i-1;k++){
					if(a[k]<=c[tc]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
