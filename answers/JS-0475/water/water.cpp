#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct decimal {
	// sub / sup
	int sub;
	int sup;
	decimal() {
		sub = 0;
		sup = 1;
	}
	decimal(int _sub, int _sup) {
		sub = _sub;
		sup = _sup;
		to_gcd();
	}
	inline void to_gcd() {
		int tmp = gcd(sub, sup);
		sub = sub / tmp;
		sup = sup / tmp;
	}
	decimal operator+(decimal nx) {
		int tmp = gcd(sup, nx.sup);
		int self_sup_mul = nx.sup / tmp;
		int nx_sup_mul = sup / tmp;
		int _sub = nx.sub * nx_sup_mul + sub * self_sup_mul;
		int _sup = self_sup_mul * sup;
		return decimal(_sub, _sup);
	}
	decimal operator+=(decimal nx) {
		int tmp = gcd(sup, nx.sup);
		int self_sup_mul = nx.sup / tmp;
		int nx_sup_mul = sup / tmp;
		sub = nx.sub * nx_sup_mul + sub * self_sup_mul;
		sup = self_sup_mul * sup;
		to_gcd();
	}
	decimal operator/(int n) {
		int _sup = sup * n;
		return decimal(sub, _sup);
	}
	bool operator==(decimal nx) {
		return (sup == nx.sup && sub == nx.sub);
	}
	void print() {
		cout << sub << " " << sup << endl;
	}
};

struct Node {
	vector<int> children;
	decimal val;
};

int n, m;
vector<int> outputs(0);
vector<Node> nodes;

void deal(int n, decimal delta) {
	nodes[n].val += delta;
	if (nodes[n].children.size() == 0) return;
	decimal size = delta / nodes[n].children.size();
	for (int i = 0; i < nodes[n].children.size(); ++ i) {
		deal(nodes[n].children[i], size);
	}
}

int main() {
	
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	cin >> n >> m;
	
	nodes.resize(n + 1);

	for (int i = 1; i <= n; ++ i) {
		int num, tmp; cin >> num;
		nodes[i].children.resize(num);
		if (num == 0) outputs.push_back(i);
		for (int j = 0; j < num; ++ j) {
			cin >> tmp;
			nodes[i].children[j] = tmp;
		}
	}
	
	for (int i = 1; i <= m; ++ i) {
		deal(i, decimal(1, 1));
	}
	
	for (int i = 0; i < outputs.size(); ++ i) {
		nodes[outputs[i]].val.print();
	}
	
	return 0;
	
}
