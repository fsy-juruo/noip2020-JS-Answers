#include<bits/stdc++.h>
#define filename "string"
#define reg register
#define ll long long
#define il inline

using namespace std;

template <typename T> void fi(T &x) {
	T f = 1, c = getchar(); x = 0;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}

int T, len;
char c[1100010];
char ts1c, ts2c;
bool ts1m, ts2m;
ll ans;

int main() {
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	fi(T);
	while(T) {
		-- T;
		scanf("%s", c);
		ts1c = c[0];
		ts1m = ts2m = 1;
		ans = 0;
		for(len = 1; c[len] != '\0'; ++ len ) {
			if(c[len] != ts1c) {
				ts1m = 0;
				if(ts2m) {
					ts2c = c[len];
				}
			}
			if(!ts1m && c[len] != ts2c) {
				ts2m = 0;
			}
		}
		if(ts1m) {
			for(reg int i = 2; i < len; ++ i ) {
				for(reg int j = 1; i * j < len; ++ j ) {
					if((len - i * j) % 2) {
						ans += i - 1;
					}
					else {
						ans += (i - 1) / 2;
					}
				}
			}
		}
		else if(ts2m) {
			
		}
		else {
			
		}
		printf("%lld\n", ans);
	}
	return 0;
}


