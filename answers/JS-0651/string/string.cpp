#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+10;
char s[N];
int fail[N],re[N],pre[N],pfo[N],sfo[N];
bool use[26];
int readInt(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
int readString(){
	int len=1;
	s[1]=getchar();
	while(s[1]<'a'||s[1]>'z') s[1]=getchar();
	while(s[len]>='a'&&s[len]<='z'){len++; s[len]=getchar();}
	return len-1;
}
int main(){
//	freopen("string4.in","r",stdin);
//	freopen("test.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=readInt();
	for(int tp=1;tp<=t;tp++){
		int len=readString();
		unsigned long long ans=0;
		fail[1]=0;
//		re[1]=0;
		for(int i=2;i<=len;i++){
			if(s[fail[i-1]+1]==s[i]){
				fail[i]=fail[i-1]+1;
//				re[i]=re[fail[i]]+1;
			}
			else if(s[1]==s[i]){
				fail[i]=1;
//				re[i]=1;
			}
			else fail[i]=0;
		}
		for(int i=1;i<=len;i++){
			int j=i;
			while(j+1-fail[j+1]==i&&j<len){
				j++;
				pre[j]=j;
			}
			pre[i]=j;
			for(int k=2;k<=j/i/2;k++){
				pre[i*k]=j/i/k*i*k;
			}
			i=j;
		}
		for(int i=0;i<26;i++) use[i]=0;
		pfo[0]=sfo[len+1]=0;
		for(int i=1;i<=len;i++){
			int ch=s[i]-'a';
			use[ch]=!use[ch];
			if(use[ch]) pfo[i]=pfo[i-1]+1;
			else pfo[i]=pfo[i-1]-1;
		}
		for(int i=0;i<26;i++) use[i]=0;
		for(int i=len;i>=1;i--){
			int ch=s[i]-'a';
			use[ch]=!use[ch];
			if(use[ch]) sfo[i]=sfo[i+1]+1;
			else sfo[i]=sfo[i+1]-1;
		}
		for(int i=2;i<len;i++){
			for(int j=i;j<=pre[i]&&j<len;j+=i){
				for(int k=1;k<i;k++){
					if(sfo[j+1]>=pfo[k]) ans++;
				}
			}
		}
		printf("%llu\n",ans);
	}
	
	return 0;
}
