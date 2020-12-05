#include <bits/stdc++.h>
using namespace std;

long long answer1[1010], answer2[1010];
int n, m, d[1010], a[1010][1010], start, o[20], input[20], tep = 0, tep1 = 0;
bool out[1010], in[1010];

long long gcd (long long a, long long b){
	if (b == 0){
		return a;
	}
	else {
		return gcd (b, a % b);
	}
}

void work2 (int s, long long ans){
	if (out[s]){
		if (answer1[s] == 0 && answer2[s] == 0){
			answer1[s] = 1;
			answer2[s] = ans;
		}
		else {
			answer1[s] = answer2[s] + answer1[s] * ans;
			answer2[s] = ans * answer2[s];
		}
	}
	else{
		ans *= d[s];
		for (int i = 1; i <= d[s]; i ++){
			work2 (a[s][i], ans);
		}
	}
}

int main (){
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		scanf("%d", &d[i]);
		if (d[i] == 0){
			out[i] = 1;
			tep ++;
			o[tep] = i;
		}
		else {
			for (int j = 1; j <= d[i]; j ++){
				scanf ("%d", &a[i][j]);
				in[a[i][j]] = 1;www
			}
		}
	}
	for (int i = 1; i <= n; i ++){
		if (!in[i]){
			start = i;
			tep1 ++;
			input[tep1] = i;
		}
	}
	for (int i = 1; i <= m; i ++){
		work2 (input[i], 1);
	}
	for (int i = 1; i <= tep; i ++){
		long long f = gcd (answer1[o[i]], answer2[o[i]]);
		cout << answer1[o[i]] / f << " " << answer2[o[i]] / f;
		cout << endl;
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
