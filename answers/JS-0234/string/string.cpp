#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll powmod(ll a,ll b,ll p){
	ll res=1;
	for(;b;b>>=1){
		if(b&1)res=res*a%p;
		a=a*a%p;
	}
	return res;
}
ll gcd(ll a,ll b){
	ll r;
	while(b>0){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int t;
char c[1001];
ll a[1001][27];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--){
		scanf("%s",(c+1));
		ll n=strlen(c+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=26;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			a[i][c[i]-'a'+1]++;
			for(int j=1;j<=26;j++){
				a[i][j]+=a[i-1][j];
			}
		}
		ll ans=0;
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j;k<=n-1;k+=j){
					if((k%j)==0){
						ll flag=0;
						for(int m=j+1;m<=k;m+=k){
							for(int qwq=1;qwq<=j;qwq++){
								if(c[m+qwq-1]!=c[qwq]){
									flag=1;
									break;
								}
							}
							if(flag)break;
						}
						if(flag)continue;
						ll atot=0,btot=0;
						for(int l=1;l<=26;l++){
							if((a[i][l]%2)==1)atot++;
							if((a[n][l]-a[k][l])%2==1)btot++;
						}
						if(atot<=btot){
							ans++;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
