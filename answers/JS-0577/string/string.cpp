#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0;
	char c=getchar();
	while(c=='\n'||c==' ')c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}	
	return x;
}
map<string,map<string,map<string,bool> > > map1;
int T,a1[26],a3[26];
long long ans;
string s;
void dfs(string s1,string s2,int i){
	if(i==s.size())return;
	string s3="";
	for(int ii=0;ii<s1.size();ii++){
		a1[s1[ii]-'a']++;
	}
	for(int ii=i;ii<s.size();ii++){
		a3[s[ii]-'a']++;
		s3=s3+s[ii];
	}
	int aa=0,cc=0;
	for(int ii=0;ii<26;ii++){
		if(a1[ii]%2==1)aa++;
		if(a3[ii]%2==1)cc++;
		a1[ii]=0;
		a3[ii]=0;
	}
	if(aa<=cc&&!map1[s1][s2][s3]){
		ans++;
//		return
		map1[s1][s2][s3]=1;
//		map1[s1][s3][s2]=1;
//		map1[s2][s1][s3]=1;
//		map1[s2][s3][s1]=1;
//		map1[s3][s2][s1]=1;
//		map1[s3][s1][s2]=1;
//		cout<<s1<<' '<<s2<<' '<<s3<<' '<<ans<<' '<<aa<<' '<<cc<<'\n';
	}
	for(int j=i;j<s.size();j++){
		int k=0;
		while(k<s1.size()){
			if(s1[k]!=s[j+k]){
				return;
			}
			k++;
		}
		j+=k;
		k=0;
		while(k<s2.size()){
			if(s2[k]!=s[j+k]){
				return;
			}
			k++;
		}
		j+=k;
		dfs(s1,s2,j);
		j--;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		cin>>s;
		string s1="",s2;
		for(int i=0;i<s.size();i++){
			s1=s1+s[i];
			s2="";
			for(int j=i+1;j<s.size();j++){
				s2=s2+s[j];
				dfs(s1,s2,j+1);
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}	
	return 0;
}

