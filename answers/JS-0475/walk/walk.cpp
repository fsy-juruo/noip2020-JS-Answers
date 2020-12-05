#include <iostream>
#include <cstring>
#include <cstdio>
#define getBinN(bin, n) ((bin >> n) & 1)
#define toggleBinN(bin, n) (bin = bin ^ (1 << n))
using namespace std;

int n, k;
int steps[500002][2];
int preps[500002][12];
int w[12];
int maxs[500002];
int mins[12][500002];

inline int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main() {
	
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	cin >> n >> k;
	
	// wi
	for (int i = 0; i < k; ++ i) {
		cin >> w[i];
	}
	
	memset(preps[0], 0, sizeof(preps[0]));
	memset(maxs, 0, sizeof(maxs));
	memset(mins, 0x3f, sizeof(mins));
	
	for (int i = 0; i < n; ++ i) {
		cin >> steps[i][0] >> steps[i][1];
		if (i != 0) {
			for (int wd = 0; wd < k; ++ wd) {
				preps[i][wd] = preps[i - 1][wd];
			}
		}
		preps[i][steps[i][0]] += steps[i][1];
		maxs[i] = max(maxs[i], abs(steps[i][1]));
		mins[steps[i][0]][preps[i][steps[i][0]]] = min(mins[steps[i][0]][preps[i][steps[i][0]]], i);
	}
	
	for (int i = 0; i < k; ++ i) {
		if (maxs[i] >= w[i] || preps[n - 1][i] != 0) {
			goto MAIN_SEGMENT;
		}
	}
	
	cout << -1 << endl;
	return 0;
	
	MAIN_SEGMENT: true;
	
	long long sum = 0;
	
	for (int j = 0; j < k; ++ j) {
		for (int i = 0; i < w[j]; ++ i) {
			int curr = w[j] - i;
			SEGMENT_2:
			if (w[j] - i < maxs[j]) {
				while (mins[j][curr] == 0x3f && curr < w[j] + 1200) {
					curr ++;
				}
				sum += mins[j][curr];
				sum %= 1000000007;
			} else {
				sum += n;
				sum %= 1000000007;
				curr -= preps[n - 1][j];
				goto SEGMENT_2;
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
	
}
