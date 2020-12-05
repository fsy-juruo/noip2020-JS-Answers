#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e6 + 5; 
const int MAXS = 30;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int BASE1 = 131;
const int BASE2 = 37;

int n,oddNum,ch,T;
ll ans;
int cnt[MAXS],hashVal1[MAXN],hashVal2[MAXN],pow1[MAXN],pow2[MAXN],sufNum[MAXN];
char s[MAXN];

namespace BIT{
	#define OFFSET 1
	
	int SIZE;
	int c[MAXS];
	
	void Init(){
		memset(c,0,sizeof(c));
	}
	
	void Resize(int _SIZE){
		SIZE = _SIZE + OFFSET;
	}
	
	void Modify(int x){
		x += OFFSET;
		while(x <= SIZE){
			c[x] += 1;
			x += (x & -x);
		}
	}
	
	int Query(int x){
		x += OFFSET;
		int res = 0;
		while(x){
			res += c[x];
			x -= (x & -x);
		}
		return res;
	}
	
	#undef OFFSET
}

int sub1(int x,int y){
	x -= y;
	if(x < 0)
		x += MOD1;
	return x;
}

int sub2(int x,int y){
	x -= y;
	if(x < 0)
		x += MOD2;
	return x;
}

int GetHash1(int l,int r){
	return sub1(hashVal1[r],1ll * hashVal1[l - 1] * pow1[r - l + 1] % MOD1);
}

int GetHash2(int l,int r){
	return sub2(hashVal2[r],1ll * hashVal2[l - 1] * pow2[r - l + 1] % MOD2);
}

void InitHash(){
	pow1[0] = pow2[0] = 1;
	for(int i = 1;i <= n;i++){
		pow1[i] = 1ll * pow1[i - 1] * BASE1 % MOD1;
		pow2[i] = 1ll * pow2[i - 1] * BASE2 % MOD2;
		hashVal1[i] = (1ll * hashVal1[i - 1] * BASE1 % MOD1 + (int)(s[i] - 'a')) % MOD1;
		hashVal2[i] = (1ll * hashVal2[i - 1] * BASE2 % MOD2 + (int)(s[i] - 'a')) % MOD2;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",s + 1);
		n = strlen(s + 1);
		memset(cnt,0,sizeof(cnt));
		oddNum = ans = 0;
		for(int i = n;i >= 1;i--){
			ch = s[i] - 'a' + 1;
			cnt[ch] += 1;
			if(cnt[ch] & 1)	oddNum += 1;
			else oddNum -= 1;
			sufNum[i] = oddNum;
		}
		InitHash();
		memset(cnt,0,sizeof(cnt));
		cnt[s[1] - 'a' + 1] += 1;
		oddNum = 1;
		BIT::Init(); 
		BIT::Resize(26);
		BIT::Modify(oddNum);
		for(int len = 2;len <= n;len++){
			int val1 = GetHash1(1,len);
			int val2 = GetHash2(1,len);
			for(int r = len;r < n;r += len){ // [1,r]
				if(val1 != GetHash1(r - len + 1,r) || val2 != GetHash2(r - len + 1,r))
					break;
				ans += BIT::Query(sufNum[r + 1]);
			}
			ch = s[len] - 'a' + 1;
			cnt[ch] += 1;
			if(cnt[ch] & 1) oddNum += 1;
			else oddNum -= 1;
			BIT::Modify(oddNum);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
 
