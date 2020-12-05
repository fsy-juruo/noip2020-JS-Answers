#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long int 
using namespace std;

const ll mod1=19260817;
const ll mod2=19260421;
const ll maxn = 3000005;
string t;

struct atree {
	ll num[maxn];
	void cle() {
		memset(num, 0, sizeof(num));
	}
	ll lowbit(ll x) {
		return x&(-x);
	}
	void add(ll p, ll x) {
		if(p > maxn-5) return;
		num[p]+=x;
		add(p+lowbit(p), x);
		return;
	}
	ll count(ll p) {
		if(p <= 0) return 0;
		return num[p]+count(p-lowbit(p));
	}
} T;

ll cx[30], frnum[maxn], banum[maxn], p26_1[maxn], p26_2[maxn];

ll h1[maxn], h2[maxn];
bool isame(ll a, ll b, ll c, ll d) {//ab=cd
	/*cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	cout<<h1[b]-h1[a-1]<<' '<<(h1[d]-h1[c-1])*p26_1[c-a]%mod1<<endl;
	cout<<h2[b]-h2[a-1]<<' '<<(h2[d]-h2[c-1])*p26_2[c-a]%mod2<<endl;*/
	ll t1, t2;
	t1=((h1[b]-h1[a-1])%mod1*p26_1[c-a]%mod1+mod1)%mod1;
	t2=((h1[d]-h1[c-1])%mod1+mod1)%mod1;
	if(t1 != t2) return false;
	t1=((h2[b]-h2[a-1])%mod2*p26_2[c-a]%mod2+mod2)%mod2;
	t2=((h2[d]-h2[c-1])%mod2+mod2)%mod2;
	if(t1 != t2) return false;
	return true;
}

void clee() {
	memset(h1, 0, sizeof(h1));
	memset(h2, 0, sizeof(h2));
	memset(frnum, 0, sizeof(frnum));
	memset(banum, 0, sizeof(banum));
	T.cle();
	return;
}

void do_it() {
	cin>>t;
	ll i, j, s=t.size();
	ll tt, ans=0;
	h1[0]=0;
	memset(cx, 0, sizeof(cx));
	memset(p26_1, 0, sizeof(p26_1));
	memset(p26_2, 0, sizeof(p26_2));
	p26_1[0]=1; p26_2[0]=1;
	for(i=0; i < s; i++) {
		p26_1[i+1]=p26_1[i]*26%mod1;
		p26_2[i+1]=p26_2[i]*26%mod2;
		tt=t[i]-'a';
		cx[tt]++;
		if(cx[tt]%2 == 0) frnum[i+1]=frnum[i]-1;
		if(cx[tt]%2 == 1) frnum[i+1]=frnum[i]+1;
		h1[i+1]=(h1[i]*26%mod1+tt)%mod1;
		h2[i+1]=(h2[i]*26%mod2+tt)%mod2;
	}
	memset(cx, 0, sizeof(cx));
	for(i=s-1; i >= 0; i--) {
		tt=t[i]-'a';
		cx[tt]++;
		if(cx[tt]%2 == 0) banum[i+1]=banum[i+2]-1;
		if(cx[tt]%2 == 1) banum[i+1]=banum[i+2]+1;
	}
	/*for(i=1; i <= s; i++) cout<<frnum[i]<<' '; cout<<endl;
	for(i=1; i <= s; i++) cout<<banum[i]<<' '; cout<<endl;
	for(i=1; i <= s; i++) cout<<h1[i]<<' '; cout<<endl;
	for(i=1; i <= s; i++) cout<<h2[i]<<' '; cout<<endl;*/
	for(i=2; i <= s; i++) {
		//cout<<1<<endl;
		T.add(frnum[i-1]+1, 1);
		for(j=1; j+i <= s; j+=i) {
			if(isame(1, i, j, j+i-1)) {
				//frnum[i-1]<<' '<<banum[j+i]<<' '<<T.count(banum[j+i]+1)<<endl;
				ans+=T.count(banum[j+i]+1);
			}
			else break;
		}
	}
	cout<<ans<<endl;
	return;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll K, i;
	cin>>K;
	for(i=1; i <= K; i++) {
		clee();
		do_it();
	}
	return 0;
}

/*
1
mmlmmlo
*/
