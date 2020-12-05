#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#define N 1100000
#define ll long long
using namespace std;
int cnt[N][27],nxt[N];
int T,n,tot;
ll ans;
bool tf[26];
string s;
void get(string &s){
	char ch=getchar();
	while(ch<'a'||ch>'z')ch=getchar();
	s="";
	while(ch>='a'&&ch<='z')s.push_back(ch),ch=getchar();
}
void kmp(){
	nxt[0]=0;
	for(int i=1,j=0;i<n;i++){
		while(j>0&&s[j]!=s[i])j=nxt[j-1];
		if(s[j]==s[i])j++;
		nxt[i]=j;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		get(s);
		n=s.size(),tot=0;
		memset(tf,false,sizeof(tf));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++){
			if(tf[s[i]-'a'])tot--;
			else tot++;
			tf[s[i]-'a']^=1;
			for(int j=0;j<=26;j++)cnt[i+1][j]=cnt[i][j];
			cnt[i+1][tot]++;
		}
		for(int i=0;i<=n;i++){
			for(int j=1;j<=26;j++)cnt[i][j]+=cnt[i][j-1];
		}
		kmp();
		tot=ans=0;
		memset(tf,false,sizeof(tf));
		for(int i=n-1;i>=2;i--){
			if(tf[s[i]-'a'])tot--;
			else tot++;
			tf[s[i]-'a']^=1;
			ans+=cnt[i-1][tot];
			int len=nxt[i-1];
			while(2*len>=i){
				if(i%(i-len)==0&&i-len>1)ans+=cnt[i-len-1][tot];
				len=nxt[len-1];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
