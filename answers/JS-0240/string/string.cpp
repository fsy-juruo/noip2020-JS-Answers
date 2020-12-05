#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod1=10017;
const int mod2=900000033;
const int base=233;
const int N=1000005;
ll has1[N],has2[N];
ll bas1[N],bas2[N];
void hsh(string s){
	bas1[0]=1,bas2[0]=1;
	for(int i=1;i<=s.size();i++){
		bas1[i]=bas1[i-1]*base%mod1;
		bas2[i]=bas2[i-1]*base%mod2;
	}
	for(int i=1;i<=s.size();i++){
		has1[i]=has1[i-1]*base%mod1+s[i-1];
		has2[i]=has2[i-1]*base%mod2+s[i-1];
	}
}
int cp(int l1,int r1,int l2,int r2){
	if(((has1[r1]-has1[l1-1]*bas1[r1-l1+1]%mod1)==(has1[r2]-has1[l2-1]*bas1[r2-l2+1]%mod1))&&((has2[r1]-has2[l1-1]*bas2[r1-l1+1]%mod2)==(has2[r2]-has2[l2-1]*bas2[r2-l2+1]%mod2))){
		return 1;
	}
	return 0;
}
long long alp[N];
void mem(){
	memset(has1,0,sizeof(has1));
	memset(has2,0,sizeof(has2));
	memset(bas1,0,sizeof(bas1));
	memset(bas2,0,sizeof(bas2));
	memset(alp,0,sizeof(alp));
}

int ct1(ll x){
	int sum=0;
	while(x!=0){
		if(x&1)sum++;
		x>>=1;
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mem();
		string s;
		cin>>s;
		int n=s.size();
		hsh(s);
		for(int i=0;i<n;i++)
			alp[i+1]=alp[i]^(1ll<<(s[i]-'a'));
		int ans=0;
		for(int i=2;i<n;i++){		//l:ab
			for(int k=1;i*k<n;k++){
//				
				int flg=1;
				for(int p=1;p<=i;p++){
					if(s[p-1]!=s[(k-1)*i+p-1]){
						flg=0;
						break;
					}
				}
				if(flg==0)break;
				
//				if(!cp(1,i,(k-1)*i+1,k*i))break;

				for(int j=1;j<i;j++){
					if(ct1(alp[j])<=ct1(alp[n]^alp[k*i])){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
