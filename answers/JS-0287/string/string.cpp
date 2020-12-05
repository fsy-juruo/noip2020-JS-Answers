#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(x) cerr << #x << " = " << x << endl
template<typename T>void chkmin(T &a, T b){ a = min(a, b); }
template<typename T>void chkmax(T &a, T b){ a = max(a, b); }

const int MAXN = 1000 + 10;

int fread(void){
	char ch = getchar(); int ret = 0, opt = 1;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') opt = -1;
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return  ret * opt;
}
char s[MAXN];
int pre[MAXN], suf[MAXN], nxt[MAXN], n, bin[MAXN];
inline void init(void){
	scanf("%s", (s + 1)); n = strlen(s + 1);
	nxt[1] = 0;
	for(int i = 2, j = 0; i <= n; ++ i){
		while(j && s[j + 1] != s[i]) j = nxt[j];
		if(s[j + 1] == s[i]) ++ j;
		nxt[i] = j; 
	}
	memset(pre, 0, sizeof(pre)); memset(suf, 0, sizeof(suf));
	for(int i = 1; i <= n; ++ i){
		bin[s[i]] ++;
		if(bin[s[i]] % 2) pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1] - 1;
	}
	memset(bin, 0, sizeof(bin));
	for(int i = n; i >= 1; -- i){
		bin[s[i]] ++;
		if(bin[s[i]] % 2) suf[i] = suf[i + 1] + 1;
		else suf[i] = suf[i + 1] - 1; 
  	}
  	memset(bin, 0, sizeof(bin));
}

int d[MAXN][MAXN];
int tmp[MAXN], hav[MAXN];
void Div(int x){
	int ret = 0; int cnt = 0;
	memset(hav, 0, sizeof(hav));
	for(int i = 1; i * i <= x; ++ i){
		if((x % i) == 0){
			//ret += (i >= bnd);
			hav[i] = 1;
			if(i * i != x) hav[x / i] = 1;//ret += ((x / i) >= bnd);
		}
	} 
	for(int i = 1; i <= x; ++ i) d[x][i] = d[x][i - 1] + hav[i];
}

long long calc(int pos){
	int len = pos - nxt[pos];
	if(pos % len != 0) len = pos;
	long long ret = 0; int lst = 0;
	for(int i = len; i <= pos; i += len){
		if((pos % i) != 0) continue;
		
		for(int j = lst + 1; j <= i - 1; ++ j){
			if(pre[j] <= suf[pos + 1]) //ret += (double)log(pos) / (double)log(i);
				ret += d[pos/len][pos/len] - d[pos/len][i/len - 1]; //Div(pos / len, i / len);
		}
		lst = i - 1;
		
		//for(int j = 1; j < i; ++ j) if(pre[j] <= suf[pos + 1]) ret ++ ;
 	} return ret;
}
/*
int Right(int pos){
	int len = pos - nxt[pos];
	if(pos % len != 0) len = pos;
	int ret = 0, lst = 0;
	for(int i = len; i <= pos; i += len){
		if((pos % i) != 0) continue;
		
		for(int j = 1; j < i; ++ j) if(pre[j] <= suf[pos + 1]) ret ++;
 	} return ret;
}
	*/
long long ans;
inline void work(void){
	memset(d, 0, sizeof(d));
	for(int i = 1; i <= n; ++ i) Div(i);
	ans = 0;
	for(int i = n - 1; i >= 2; -- i){
		ans += calc(i);
	} printf("%lld\n", ans);
}

int main(){
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	int T = fread();
	while(T--)
	init(), work();
	fclose(stdin); fclose(stdout);
	return 0;
}

