#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
void readint(int &x){
	int sign = 1; x = 0; char c = getchar();
	while(c != '-' && (c < '0' || c > '9')) c = getchar();
	if(c == '-') sign = -1, c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	x *= sign;
}
void put_positive_ll(ll x){
	if(!x) return ;
	put_positive_ll(x / 10ll);
	putchar('0' + x % 10ll);
}
void putll(ll x){
	if(x == 0) putchar('0');
	if(x < 0) putchar('-'), x = -x;
	put_positive_ll(x);
}
ll lmt = 1000000000;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

struct BigInt{
	int len;
	ll val[10];
	void operator =(ll b){
		if(b == 0){
			len = 0;
			return ;
		}
		len = 1;
		val[0] = b;
	}
};
void putBigInt(BigInt a){
	if(a.len == 0) putchar('0');
	for(int i = a.len - 1; i >= 0; i--) putll(a.val[i]);
}
BigInt operator +(BigInt a, BigInt b){
	BigInt res;
	memset(res.val, 0, sizeof(res.val));
	res.len = qmax(a.len, b.len);
	ll add = 0;
	rep(i, res.len){
		res.val[i] = a.val[i] + b.val[i] + add;
		add = res.val[i] / lmt;
		res.val[i] %= lmt;
	}
	if(add > 0) res.val[res.len] = add, res.len++;
	return res;
}
BigInt operator *(BigInt a, BigInt b){
	BigInt res;
	res.len = a.len + b.len;
	memset(res.val, 0, sizeof(res.val));
	rep(i, a.len){
		rep(j, b.len){
			res.val[i+j] += a.val[i] * b.val[j];
		}
	}
	rep(i, res.len){
		res.val[i + 1] += (res.val[i] / lmt);
		res.val[i] %= lmt;
	}
	while(res.len > 0 && res.val[res.len - 1] == 0) res.len--;
//	putBigInt(a), putchar('*'); putBigInt(b), putchar('='); putBigInt(res); puts("");
	return res;
}
BigInt operator *(BigInt a, ll b){
	rep(i, a.len){
		a.val[i] *= b;
		a.val[i + 1] += a.val[i] / lmt;
		a.val[i] %= lmt;
	}
	if(a.val[a.len] > 0) a.len++;
	return a;
}
pair<BigInt, ll> divide(BigInt a, ll b){
	ll rem = 0;
	BigInt res;
	memset(res.val, 0, sizeof(res.val));
	res.len = a.len - 1;
	for(int i = a.len - 1; i >= 0; i--){
		res.val[i] = (rem + a.val[i]) / b;
		rem = (rem + a.val[i]) % b;
		rem *= lmt;
	}
	if(res.val[res.len] > 0) res.len++;
	return make_pair(res, rem);
}
int p[5] = {2, 3, 5};
struct frac{
	BigInt num, dev;
	void Cancel(){
		rep(pi, 3){
			pair<BigInt, ll> r1, r2;
			while(1){
				r1 = divide(num, p[pi]);
				r2 = divide(dev, p[pi]);
				if(r1.second != 0 || r2.second != 0) break;
				num = r1.first, dev = r2.first;
			}
		}
	}
};
void putfrac(frac a){
	putBigInt(a.num); putchar('/'); putBigInt(a.dev); puts("");
}
frac operator *(frac a, frac b){
	frac ret;
	ret.dev = a.dev * b.dev;
	ret.num = a.num * b.num;
	ret.Cancel();
	return ret;
}
frac operator +(frac a, frac b){
	frac ret;
	ret.dev = a.dev * b.dev;
	ret.num = a.num * b.dev + b.num * a.dev;
	ret.Cancel();
	return ret;
}

int n, m;
vector<int> v[100100];
int deg[100100];
frac dp[100100];

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	readint(n), readint(m);
	rep(i, n){
		int num;
		readint(num);
		rep(j, num){
			int to;
			readint(to);
			to--;
			v[i].push_back(to);
			deg[to]++;
		}
	}
	rep(i, n) dp[i].dev = 1, dp[i].num = 0;
	queue<int> q;
	rep(i, m){
		dp[i].num = 1;
		q.push(i);
	}
	while(!q.empty()){
		int now = q.front(); q.pop();
//		cout << now << endl;
//		putfrac(dp[now]);
		if((int)v[now].size() == 0) continue;
		frac val = dp[now];
		val.dev = val.dev * (ll)v[now].size();
		val.Cancel();
		rep(i, (int)v[now].size()){
//			putfrac(val);
			dp[v[now][i]] = dp[v[now][i]] + val;
			deg[v[now][i]]--;
			if(deg[v[now][i]] == 0) q.push(v[now][i]);
		}
	}
//	cout << "???" << endl;
	rep(i, n){
		if((int)v[i].size() == 0){
			putBigInt(dp[i].num);
			putchar(' ');
			putBigInt(dp[i].dev);
			puts("");
		}
	}
	return 0;
}
