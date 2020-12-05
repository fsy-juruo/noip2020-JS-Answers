#include<bits/stdc++.h>
using namespace std;
 
int n, m;
int color[55][405], cnt[55];
inline int read(){
	char c=getchar();
	int x = 0, y = 1;
	while(c<'0' || c>'9'){
		if (c == '-') y = -1;
		c = getchar();
	}
	while( c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c=getchar();
	}
	return x * y;
}

pair<int, int> a[55][405];
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read();
	m = read();
	
	for(int i = 1; i <= n ;++i){
		for(int j = 1; j <= m; ++j){
			color[i][j] = read();
		}
	}
	
	if (n == 1){
		printf("%d", 0);
		return 0;
	}
	
	if(n == 2){
		for(int i = 1; i <= n; ++i){
			int cnt[i] = 1;
			a[i][1].second = 1;
			a[i][1].first = color[1][m];
			for(int j = m - 1; j >= 1; --j){
				if (color[i][j] == color[i][j + 1]) a[i][cnt[i]].second++;
				else{
					cnt[i]++;
					a[i][cnt[i]] == make_pair(color[i][j], 1);
				}
			}
		}
		int k1 = 1, k2 = 1, p1 = 1, p2 = 2;
		if(a[1][1].first == a[2][1].first){
			ans += a[1][1].second + a[2][1].second;
		}
		else(if a[p2][1].second >= a[p1][1].second){
			swap(p1,p2);
			ans += a[p1][1].second + a[2][1].second;
		}
		
		cout << ans;
	}
	return 0;
}
