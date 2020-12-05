#include<bits/stdc++.h>
#define rep(a,b) for(int a=0;a<b;++a)
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define PB(a) push_back(a)
using namespace std;
const int MUL=19260817;
const int MOD=998244353;
string s;
const int MAXN=(1<<20)+10;
int pre[MAXN],mi[MAXN],many[26],countsuf[MAXN],have[27];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
void solve(){
	cin>>s;
	int n=s.length();
	int tmp=1;
	rb(i,1,n){
		pre[i]=pre[i-1]+(1ll*tmp*s[i-1]%MOD);
		tmp=1ll*tmp*MUL%MOD;
		if(pre[i]>=MOD) pre[i]-=MOD; 
	}
	memset(many,0,sizeof(many));
	countsuf[n+1]=0;
	rl(i,n,1){
		countsuf[i]=countsuf[i+1];
		if(many[s[i-1]-'a']){
			countsuf[i]--;
			many[s[i-1]-'a']=0;
		}
		else{
			countsuf[i]++;
			many[s[i-1]-'a']=1;
		}
	}
	tmp=0;
	memset(many,0,sizeof(many));
	LL rest=0;
	memset(have,0,sizeof(have));
	rb(i,1,n){
		if(many[s[i-1]-'a']){
			tmp--;
			many[s[i-1]-'a']=0;
		}
		else{
			tmp++;
			many[s[i-1]-'a']=1;
		}
		for(int j=i;j<n;j+=i){
			int l,r;
			l=j-i+1;
			r=j;
			if(1ll*(pre[r]-pre[l-1]+MOD)%MOD*mi[l-1]%MOD!=pre[i]) break;
			rest+=have[countsuf[j+1]];
		}
		rb(j,tmp,26) have[j]++;
	}
	printf("%lld\n",rest);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	int olt=1<<20;
	mi[olt]=quick(quick(MUL,olt),MOD-2);
	rl(i,olt-1,0) mi[i]=1ll*mi[i+1]*MUL%MOD;
	scanf("%d",&T);
	while(T--) solve();	
	return 0;
}
/*

1. 数组大小是1倍还是2倍？
2. 有没有用long long
3. 特判有没有return 0
4. 需不需要特判
5. if的条件是否并列
6. vector ,函数返回值是否是long long
7. 有没有注意中途取模
8. dfn有没有错
9. 下标顺序有没有错

*/

