#include<bits/stdc++.h>
using namespace std;

const int MAX_N=2e6+10;

// duoceyaoqingkong

typedef long long ll;

string s;
int T,N;
char buf[MAX_N];

vector <int> zfunction(){
	vector <int> z(int(s.size()),0);
	z[0]=(int)s.size();
	int j=1;
	for(int i=1;i<s.size();i++){
		int u=max(0,min(z[j]+j-i,z[i-j]));  
		while(s[u]==s[i+u]) u++;
		z[i]=u;
		if(z[j]+j>=z[i]+i) j=i; 
	}
	return z;
}

ll sum[30];
ll mask[MAX_N];

void solve(){
	//qing kong	
	for(int i=0;i<MAX_N;i++) mask[i]=0;
	for(int i=0;i<30;i++) sum[i]=0;
	scanf("%s",buf);
	s=(string)buf;
	for(int i=s.size()-1;i>=0;i--) mask[i]=ll(1ll<<int(s[i]-'a'))^mask[i+1];
	vector <int> z=zfunction();
	ll tot=1ll<<int(s[0]-'a'),ans=0;
	for(int len=2;len<s.size();len++){
		for(int i=__builtin_popcount(tot);i<=26;i++) sum[i]++;	
		tot^=1ll<<int(s[len-1]-'a');
		int i=(z[len]/len+1)*len;
		if(i>=s.size()) i-=len;
		ll nmsk1=mask[i],nmsk2=mask[i]^tot,s1,s2;
		if(i%(2*len)==0){
			s1=i/(2*len);
			s2=i/(2*len);
		}
		else{
			s1=i/(2*len)+1;
			s2=i/(2*len);
		}
		ans+=1ll*s1*sum[__builtin_popcount(nmsk1)];
		ans+=1ll*s2*sum[__builtin_popcount(nmsk2)];
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
