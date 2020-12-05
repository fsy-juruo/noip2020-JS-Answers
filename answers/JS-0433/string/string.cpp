#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mem(x,v) memset(x,v,sizeof(x))

const int N=1048576+5;
const int inf=1e9+7;
const int mod=998244353;

const ull base1=131;
const ull base2=19260817;

ll ans,n,pre[30];
char s[N];
ull pw1[N],pw2[N],hs1[N],hs2[N],pv1[30],pv2[30];
bitset <26> a,b,c;

bool equ(int l,int r,int pw){
	int len=r-l+1;
	return hs1[r]-hs1[l-1]*pw1[len]==pv1[pw]&&
		   hs2[r]-hs2[l-1]*pw2[len]==pv2[pw];
}

void solve(){
	for(int i=0;i<26;i++)a[i]=b[i]=s[i]=0,pre[i]=0;
	pre[26]=0,ans=n=0;
	scanf("%s",s+1);
	for(int i=1;s[i];i++)
		a[s[i]-'a'].flip(),n++,
		hs1[i]=hs1[i-1]*base1+s[i]-'a',
		hs2[i]=hs2[i-1]*base2+s[i]-'a';
	a[s[1]-'a'].flip();
	for(int i=1;i<n;i++){
		if(i==1)continue;
		int d=0,r=i,dec=0;
		pv1[0]=hs1[i],pv2[0]=hs2[i];
		while(d>=0){
			int nwr=r+(i<<d);
			if(nwr>=n){
				dec=1,d--;
				continue;
			} if(equ(r+1,nwr,d)){
				r=nwr;
				if(dec==0)
					pv1[d+1]=pv1[d]*pw1[i<<d]+pv1[d],
					pv2[d+1]=pv2[d]*pw2[i<<d]+pv2[d],d++;
				else d--;
			} else dec=1,d--;
		} ll v=r/i;
		b[s[i-1]-'a'].flip();
		a[s[i]-'a'].flip();
		ll numa=a.count(),numb=b.count();
		for(int i=numb;i<=26;i++)pre[i]++;
		ans+=(v+1>>1)*pre[numa];
		
		if(r==d)continue;
		c=a^b,c[s[i]-'a'].flip(); ll numc=c.count(); 
		ans+=(v>>1)*pre[numc];
	} cout<<ans<<endl;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t; cin>>t;
	pw1[0]=pw2[0]=1;
	for(int i=1;i<N;i++)pw1[i]=pw1[i-1]*base1,pw2[i]=pw2[i-1]*base2;
	while(t--)solve();
	return 0;
}
