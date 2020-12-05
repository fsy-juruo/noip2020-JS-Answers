#include<bits/stdc++.h>
using namespace std;
int t;
string s;
bool f[26];
int a[2000001];
int b[2000001];
bool check(int x,int y){
	for(int i=x;i<(int)(s.size())-y;i++)
	if(s[i]!=s[i-x])
	return false;
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>s;
		for(int i=0;i<26;i++)
		f[i]=false;
		int now=0;
		for(int i=0;i<(int)(s.size());i++){
			if(f[(s[i]-'a')])
			now--;
			else
			now++;
			f[(s[i]-'a')]=!f[(s[i]-'a')];
			a[i]=now;
		}
		now=0;
		for(int i=0;i<26;i++)
		f[i]=false;
		for(int i=(int)(s.size())-1;i>=0;i--){
			if(f[(s[i]-'a')])
			now--;
			else
			now++;
			f[(s[i]-'a')]=!f[(s[i]-'a')];
			b[i]=now;
		}
		long long ans=0;
		for(int i=1;i<(int)(s.size());i++){
			for(int j=1;j<=(int)(s.size())-i;j++)
			for(int k=1;k<=(int)(s.size())-i-j;k++){
				if(((int)(s.size())-i-j-k)%(i+j))
				continue;
				if(!check(i+j,k))
				continue;
				if(a[i-1]>b[(int)(s.size())-k])
				continue;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

