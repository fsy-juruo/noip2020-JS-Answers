#include<bits/stdc++.h>
using namespace std;
//test1~12
int pd(string s){
	int cnt[27]={},ans=0;
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]%2==1)ans++;
	}
	return ans;
}

int inline fuck(string s){
	int i,j,ans=0;bool flag=0;
	for(i=1;i<s.size()-1;i++){
		for(j=i+1;j<s.size();j++){
			string s1=s.substr(0,i),s2=s.substr(0,j);
			int rep=0;
			while((rep+1)*j<s.size()){
				rep++;
				string s4=s.substr(rep*j,j),s3=s.substr(rep*j);
				if(s4!=s2)rep=2e9;
				if(pd(s1)>pd(s3))continue;
				ans++;					
			}
		}
	}	
	return ans;	
}
//优化不会 awa
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;string s;
	cin>>n;
	if(n<2000){
		for(int i=1;i<=n;i++){
			cin>>s;
			cout<<fuck(s)<<endl;
		}	
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>s;
		}
	}
	return 0;
}

