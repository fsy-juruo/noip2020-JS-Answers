// I spent 10min debugging fastpow??????????
// I'm idiot
//                       --- Zzzyt

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000007ll
typedef long long ll;

#define MAXN 1048576
#define HA 19260817ll

int n;
char s[MAXN+100];
int sum[MAXN+100][27];
ll hsh[MAXN+100];

inline int getsum(int l,int r,char c){
	return sum[r][c]-sum[l-1][c];
}

ll fastpow(ll x,ll a){
	if(a==0)return 1ll;
	if(a==1)return x;
	ll tmp=fastpow(x,a/2);
	tmp=(tmp*tmp)%INF;
	if(a&1){
		return (tmp*x)%INF;
	}
	return tmp;
}

inline ll gethsh(int l,int r){
	return (hsh[r]-(hsh[l-1]*fastpow(HA,r-l+1))%INF+INF)%INF;
}

int curfa[27];
ll cntfa[28];

void solver1(){
	for(int i=1;i<=n;i++){
		s[i]-='a';
		for(int j=0;j<26;j++){
			sum[i][j]=sum[i-1][j];
		}
		sum[i][s[i]]++;
		hsh[i]=hsh[i-1]*HA+s[i];
		hsh[i]%=INF;
	}
	int fa=0;
	memset(curfa,0,sizeof(curfa));
	memset(cntfa,0,sizeof(cntfa));
	ll ans=0;
	for(int i=2;i<n;i++){
		curfa[s[i-1]]^=1;
		if(curfa[s[i-1]]){
			fa++;
		}
		else{
			fa--;
		}
		cntfa[fa]++;
		ll curhsh=gethsh(1,i);
		for(int j=1;;j++){
			int ed=i*j;
			int st=ed-i+1;
			if(ed>=n){
				break;
			}
			if(gethsh(st,ed)!=curhsh){
				break;
			}
			int fc=0;
			for(int k=0;k<26;k++){
				fc+=getsum(ed+1,n,k)&1;
			}
			for(int i=0;i<=fc;i++){
				ans+=cntfa[i];
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int TT=0;TT<T;TT++){
		scanf("%s",s+1);
		n=strlen(s+1);
		solver1();
	}
	
	return 0;
}

