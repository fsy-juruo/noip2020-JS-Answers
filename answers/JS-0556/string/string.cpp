/*
EI说过，希望都打上了注释
那么，我就多来些注释所带来的希望罢
EI ORZ
神仙墙上的所有神仙 ORZ
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP = INT_MAX
*/
#include<bits/stdc++.h>
#define reg register
#define ri reg int
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline void read(int&x){
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=x*10+c-'0';
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
inline bool G(char c){
	return c>='a' and c<='z';
}
inline void ReadString(string&s){
	reg char c;s="";
	for(c=getchar();!G(c);c=getchar());
	s+=c;
	for(c=getchar();G(c);c=getchar())s+=c;
}
const int mxn=1048606;
bool nisp[mxn];
int primes[mxn],cntprimes;
vector<int>have[mxn];
inline void makeprime(){
	nisp[0]=1,nisp[1]=1;
	for(int i=2;i<mxn;++i){
		if(!nisp[i]){
			primes[++cntprimes]=i;
			for(int j=i*2;j<mxn;j+=i)nisp[j]=1;
		}
	}
}
int n;
int cnt[26],F_C;//动态统计 
int dp[mxn][26];//表示考虑第i位时前缀Ａ的奇数个数小于等于ｊ的数量（前缀和）下标从１开始 
ll ans;
string s;
//双hash 
ll mul[]={241,281};
ll mod[]={998244353,1000000007};
ll hash[2][mxn];
ll pre[2][mxn];
ll Inv[2][mxn];
inline ll qp(ll x,ll y,ll md){
	ll rt=1;
	for(;y;y>>=1,(x*=x)%=md)if(y&1)(rt*=x)%=md;
	return rt;
}
inline ll inv(ll x,ll md){return qp(x,md-2,md);}
inline void Prep(int id){for(int i=1;i<=n;++i)hash[id][i]=(hash[id][i-1]+(s[i]-'a')*pre[id][i]%mod[id])%mod[id];}
inline ll Get(int l,int r,int id){
	ll t=hash[id][r]-hash[id][l-1];
	if(t<0)t+=mod[id];
	t=t*Inv[id][l-1]%mod[id];
	return t;
}
inline bool same(int l,int r,int a,int b){
	if(Get(l,r,0)!=Get(a,b,0))return 0;
	return Get(l,r,1)==Get(a,b,1);
}
inline void gethash(){
	Prep(0);
	Prep(1);
}
inline void makehave(){
	memset(hash,0,sizeof(hash));
	for(ri i=1;i<=n;++i)have[i].clear();
	gethash();
	for(ri i=2;i<=n;++i){
		for(ri j=i;j<=n;j+=i){
			if(!same(1,i,j-i+1,j))break;
			have[j].push_back(i);
		}
	}
}
inline void solve(){
	ReadString(s);n=s.size();F_C=0;
	s=" "+s;memset(dp,0,sizeof(dp));memset(cnt,0,sizeof(cnt));
	makehave();
	for(ri i=1;i<=n;++i){
		for(ri j=0;j<26;++j)dp[i][j]=dp[i-1][j];
		++cnt[s[i]-'a'];ri count=0;
		for(ri j=0;j<26;++j)count+=(int)(cnt[j]%2);
		++dp[i][count];
	}
	for(ri i=1;i<=n;++i)for(int j=1;j<26;++j)dp[i][j]+=dp[i][j-1];
	for(ri i=0;i<26;++i)F_C+=(int)(cnt[i]%2);
	for(ri i=1;i<n;++i){//  C is frome i+1 to n
		--cnt[s[i]-'a'];
		if(cnt[s[i]-'a']%2==1)++F_C;
		else --F_C;
		for(ri ff=0;ff<have[i].size();++ff){
			ri j=have[i][ff];//(A+B)'s len is j
			ans+=dp[j-1][F_C];//i-1 is because  B's size is at least 1
		}
	}
	printf("%lld\n",ans);
	ans=0;
}
inline void Prem(int id){
	pre[id][0]=1;
	for(ri i=1;i<mxn;++i)pre[id][i]=(pre[id][i-1]*mul[id])%mod[id];
	ll t=inv(mul[id],mod[id]);
	Inv[id][0]=1;
	for(ri i=1;i<mxn;++i)Inv[id][i]=(Inv[id][i-1]*t)%mod[id];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	Prem(0),Prem(1);
	makeprime();
	int T;read(T); 
	for(;T--;)solve();
	return 0;
}
