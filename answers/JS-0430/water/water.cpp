#include <bits/stdc++.h>
const int INF = 1e9 + 7;

class F {
	unsigned long long p, q;
	
	public:
	
	F() {
		p = 0;
		q = 1;
	}
	
	F(int x) {
		p = x;
		q = 1;
	}
	
	F(int x, int y) {
		p = x;
		q = y;
		normalize();
	}
	
	void normalize() {
		int gcd = std::__gcd(p, q);
		p = p / gcd;
		q = q / gcd;
	}
	
	void operator = (const int n) {
		p = n;
		q = 1;
	}
	
	F operator + (const F x) {
		F result;
		if (x.q == this->q) {
			result.q = x.q;
			result.p = x.p + this->p;
		} else {
			int gcd = std::__gcd(x.q, this->q);
			int new_q = x.q / gcd * this->q;
			result.q = new_q;
			result.p = (x.p * this->q / gcd) + (this->p * x.q / gcd);
		}
		normalize();
		return result;
	}
	
	F operator / (const int x) {
		F result = F(this->p, this->q);
		result.q *= x;
		result.normalize();
		return result;
	}
	
	void print() {
		normalize();
		printf("%lld %lld\n", (long long)(p), (long long)(q));
	}
};

class Solver1 {
	const static int N = 100005;
	
	int node_c, receive_c;
	int receive[N];
	std::vector<int> g[N];
	bool is_receive[N];
	F answer[N];
	
	public:
	
	Solver1 (int new_node_c, int new_receive_c) {
		node_c = new_node_c;
		receive_c = new_receive_c;
	}
	
	void input() {
		int u, v;
		memset(is_receive, true, sizeof is_receive);
		for (int i = 1; i <= node_c; i += 1) {
			scanf("%d", &u);
			for (int j = 1; j <= u; j += 1) {
				scanf("%d", &v);
				g[i].push_back(v);
				is_receive[v] = false;
			}
		}
	}
	
	void initialize() {
		int cnt = 0;
		for (int i = 1; i <= node_c; i += 1) {
			if (is_receive[i]) {
				cnt += 1;
				receive[cnt] = i;
			}
		}
	}
	
	void dfs(int at, F water) {
		if (g[at].size() == 0) {
			answer[at] = answer[at] + water;
			return ;
		}
		
		F divided = water / (int)(g[at].size());
		for (int i = 0; i < (int)(g[at].size()); i += 1) {
			dfs(g[at][i], divided);
		}
	}
	
	void solve() {
		F one = 1;
		for (int i = 1; i <= receive_c; i += 1) {
			dfs(i, one);
		}
	}
	
	void print() {
		for (int i = 1; i <= node_c; i += 1) {
			if (g[i].size() == 0) {
				answer[i].print();
			}
		}
	}
};

int node_c, receive_c;

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	scanf("%d%d", &node_c, &receive_c);
	if (514 == 514) {
		Solver1 solver = Solver1(node_c, receive_c);
		solver.input();
		solver.initialize();
		solver.solve();
		solver.print();
	}
	return 0;
}

