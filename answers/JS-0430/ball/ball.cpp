#include <bits/stdc++.h>
const int INF = 1e9 + 7;

class Stack {
	const static int MAXSIZE = 25;
	
	int data[MAXSIZE];
	
	public:
	
	int max_size;
	int sum;
	int size;
	
	Stack() {
		size = 0;
		sum = 0;
	}
	
	void set_max_size(int new_max_size) {
		max_size = new_max_size;
	}
	
	inline int size_left() {
		return max_size - size;
	}
	
	inline bool is_all(int target) {
		//printf("%d: %d == %d -> %d\n", target, target * size, sum, (target * size == sum));
		return (target * size == sum && size > 0);
	}
	
	// return (distance, count)
	std::pair<int, int> get_target(int target) {
		std::pair<int, int> result;
		int p = size, cnt = 0;
		while (data[p] != target && p >= 1) {
			p -= 1;
		}
		result.first = size - p;
		while (data[p] == target && p >= 1) {
			cnt += 1;
			p -= 1;
		}
		result.second = cnt;
		return result;
	}
	
	bool add(int x) {
		if (size + 1 > max_size) {
			return false;
		}
		size += 1;
		data[size] = x;
		sum += x;
		return true;
	}
	
	inline int top() {
		return data[size];
	}
	
	inline void pop() {
		sum -= data[size];
		size -= 1;
	}
};

class Solver1 {
	const static int N = 5;
	const static int M = 25;
	
	int color_c, num, pole_c;
	Stack stacks[N];
	std::vector< std::pair<int, int> > answer;
	
	public:
	
	Solver1 (int new_color_c, int new_num) {
		color_c = new_color_c;
		pole_c = color_c + 1;
		num = new_num;
		for (int i = 0; i < N; i += 1) {
			stacks[i].set_max_size(num);
		}
	}
	
	void input() {
		int u;
		for (int i = 1; i <= color_c; i += 1) {
			for (int j = 1; j <= num; j += 1) {
				scanf("%d", &u);
				stacks[i].add(u);
			}
		}
	}
	
	void initialize() {
		// TODO
	}
	
	inline bool check() {
		for (int i = 1; i <= pole_c; i += 1) {
			if (stacks[i].size % num != 0) {
				return false;
			}
		}
		
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= pole_c; i += 1) {
			if (stacks[i].is_all(1)) {
				cnt1 += 1;
			}
			if (stacks[i].is_all(2)) {
				cnt2 += 1;
			}
		}
		
		return ((cnt1 == 1) && (cnt2 == 1));
	}
	
	void solve() {
		int target_2 = 3;
		int moving = 1;
		int target = stacks[1].top();
		std::pair<int, int> p;
		
		//printf("%d\n", check());
		while (!check()) {
			//printf("%d\n", check());
			if (target == 2) {
				while (stacks[moving].top() == target) {
					if (!stacks[target_2].add(stacks[moving].top())) {
						break;
					}
					answer.push_back(std::make_pair(moving, target_2));
					stacks[moving].pop();
				}
				p = stacks[moving].get_target(target);
				if (p.first <= stacks[3 - moving].size_left()) {
					for (int i = 1; i <= p.first; i += 1) {
						stacks[3 - moving].add(stacks[moving].top());
						stacks[moving].pop();
						answer.push_back(std::make_pair(moving, 3 - moving));
					}
				} else {
					for (int i = 1; i <= p.first + p.second; i += 1) {
						if (!stacks[target_2].add(stacks[3 - moving].top())) {
							break;
						}
						stacks[3 - moving].pop();
						answer.push_back(std::make_pair(3 - moving, target_2));
					}
					for (int i = 1; i <= p.first + p.second; i += 1) {
						if (!stacks[3 - moving].add(stacks[moving].top())) {
							break;
						}
						stacks[moving].pop();
						answer.push_back(std::make_pair(moving, 3 - moving));
					}
					while (!stacks[target_2].is_all(target)) {
						if (!stacks[moving].add(stacks[target_2].top())) {
							break;
						}
						stacks[target_2].pop();
						answer.push_back(std::make_pair(target_2, moving));
					}
					moving = 3 - moving;
				}
			}
		}
	}
	
	void print() {
		printf("%d\n", answer.size());
		for (int i = 0; i < answer.size(); i += 1) {
			printf("%d %d\n", answer[i].first, answer[i].second);
		}
	}
};

int color_c, num;

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	scanf("%d%d", &color_c, &num);
	if (color_c == 2) {
		Solver1 solver = Solver1(color_c, num);
		solver.input();
		solver.initialize();
		solver.solve();
		solver.print();
	} else {
		puts("0");
	}
	return 0;
}

