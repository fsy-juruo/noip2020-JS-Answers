#include <bits/stdc++.h>
using namespace std;
const int modNum = 1000000007;
const int MAXN = 500100;

int n,k;
long long w[11];
long long ans;
long long loc[11];
long long mov[11];
long long maxm[11]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
long long minm[11]={0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f,0x3f3f3f3f};
bool op;

struct move{
	int c,d;
}m[MAXN];

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

long long num;

void walk(int x){
	if(op)
		return;
	if(x == k){
		for(int i = 1; i <= w[x]; i++){
			loc[x] = i;
			bool p = true;
			bool flag = true;				
			long long loc1[11]={0,0,0,0,0,0,0,0,0,0,0};
			memcpy(loc1, loc, sizeof(loc));
			ans++;
			while(p){
				for(int j = 1; j <= k; j++){
					if(loc1[j] + minm[j] <= 0 || loc1[j] + maxm[j] > w[j]){
						p = false;
						break;
					}
				}
				if(p){
					for(int j = 1; j <= k; j++)
						loc1[j] += mov[j];
					ans += n;
					ans %= modNum;
				}
			}
			while(flag){
				for(int j = 1; j <= n; j++)
					if(loc1[m[j].c] + m[j].d > 0 && loc1[m[j].c] + m[j].d <= w[m[j].c]){
						loc1[m[j].c] += m[j].d;
						(++ans) %= modNum;
					}
					else{
						flag = false;
						break;
					}
			}
			
		}
	}
	else{
		for(int i = 1; i <= w[x]; i++){
			loc[x] = i;
			walk(x+1);
		}
	}
	
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n = read(), k = read();
	for(int i = 1; i <= k; i++)
		w[i] = read();
	for(int i = 1; i <= n; i++){
		m[i].c = read(), m[i].d = read();
		mov[m[i].c] += m[i].d;
		maxm[m[i].c] = max(maxm[m[i].c], mov[m[i].c]);
		minm[m[i].c] = min(minm[m[i].c], mov[m[i].c]);
	}
	op = true;
	for(int i = 1; i <= k; i++)
		if(mov[i] != 0 || 1 + maxm[i] > w[i] || w[i] + minm[i] <= 0)
			op = false;
	walk(1);
	if(op)
		printf("-1\n");
	else 
		printf("%d\n", ans);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
/*
2 2
4 4
2 1
1 1
*/
