#include<bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define pd priority_queue
using namespace std;
template<typename Tp>
void read(Tp &x){
	x = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	x *= f;
}
template<typename Tp> void Cmax(Tp &x, Tp y) { if(y > x) x = y;}
template<typename Tp> void Csum(Tp &x, Tp y) { x = (x + y); }
typedef long long LL;
const int N = (1 << 20) + 40;
char S[N];
int T, n, ans;
int check(int x){
	int js = 1;
	for(int j = x; j + x < n; j += x){
		for(int p = 1; p <= x; ++p){
			if(S[j + p] != S[p])
				return js;
		}
		js++;
	}
	return js;
}
bool Hash[30];
bool check2(int x, int y){
	for(int i = 1; i <= x; ++i)
		Hash[S[i] - 'a'] ^= 1;
		int js = 0, js2 = 0;
	for(int j = 0; j < 26; ++j)
		js += Hash[j], Hash[j] = 0;
	for(int i = y; i <= n; ++i)
		Hash[S[i] - 'a'] ^= 1;
	for(int j = 0; j < 26; ++j)
		js2 += Hash[j], Hash[j] = 0;
	if(js > js2)
		return false;
	return true;
}
void Work(int lena, int lenb){
	int tot = lena + lenb;
	int p = check(tot);
	for(int i = 1; i <= p; ++i){
		if(check2(lena, tot * i + 1))
			ans++;
	}
}
void init(){
	read(T);
	while(T--){
		ans = 0;
		scanf("%s", S + 1);
		n = strlen(S + 1);
		for(int i = 1; i < n; ++i)
			for(int j = 1; j + i < n; ++j)
				Work(i, j);
		printf("%d\n", ans);
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
