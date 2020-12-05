#include <bits/stdc++.h>

using namespace std;
const int N = 100005;
long long d[N], a[N][15], val_fz[N], val_fm[N], fz, fm;
long long gcd(long long a, long long b){
	if (a == 0) return b;
	else return gcd(b % a, a);
}

long long gbx(long long a, long long b){
	return (a * b / gcd(a, b));
}

void add(long long a, long long b,long long c, long long d){
	fm = a * d + b * c, fz = b * d;
	long long x = gcd(fm, fz);
	fm = fm / x;
	fz = fz / x;
}
vector<int> kkksc03;
int main(){
	freopen("water.in", "r", stdin);freopen("water.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for (long long i = 0; i < n; i++){
		val_fz[i] = 0;
		val_fm[i] = 1;
	}
	for (int i = 0; i < m; i++) val_fz[i] = 1;
	for (int i = 0; i < n; i++){
		cin >> d[i];
		if (d[i] == 0) kkksc03.push_back(i);
		else{
			for (int j = 0; j < d[i]; j++)
			cin >> a[i][j];
			if (val_fz[i] != 0){
				for (int j = 0; j < d[i]; j++){
					add(val_fz[a[i][j]], val_fm[a[j][j]], val_fz[i], (val_fm[i] * d[i]));
					val_fz[a[i][j]] = fz, val_fm[a[i][j]] = fm;
					fz = 0, fm = 0; 
				}
			}
		}
	}
	for (int i = 0; i < kkksc03.size(); i++){
		cout << val_fz[kkksc03[i]] << " " << val_fm[kkksc03[i]] << endl;
	}
	return 0;
}
