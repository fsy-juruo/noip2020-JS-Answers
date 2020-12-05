#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
template <typename T>
inline void read(T &x) {
	x = 0; T f = (T) 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp) {
	write(x); putchar(sp);
}

const int maxN = 60, maxM = 410;
struct Coor {
	int x, y;
	void init(int _x, int _y) {x = _x, y = _y;}
};
//struct Event {
//	int Origin, Target;
//	void i
//};
std::set<int> can;
std::vector<Coor> col[maxN];
Coor Stk[maxN];
int n, m, valid[maxN], tp = 0, bls[maxN][maxM]; // wxq ak ioi
// option A: 
void Move(int x, int y) { // Move x -> y 
	writesp(x, ' '); writesp(y, '\n');
	valid[y]++; valid[x]--;
	if(valid[x] == m - 1) can.insert(x);
	if(valid[y] == m) can.erase(y);
}

//void AddEvent(int b, int P) {
//	Stk[++tp].init(b, P);
//}
//void RollBack() {
//	Coor E = Stk[tp--];
//	Move(E.y, E.x);
//}
//void SwapBall(int a, int x, int b, int y) { // Swap (a,x) <=> (b,y)
//	// clear b
//	int PosTarget = 0;
//	_per(i, m, y) {
//		int P = 0;
//		std::set<int> :: iterator it;
//		for(it = can.begin(); it != can.end(); ++it) {
//			if(*it != b) {
//				P = *it;
//				break;
//			}
//		}
//		Move(b, P); AddEvent(b, P);
//		if(i == y) PosTarget = P;
//	} 
//	// clear a
//	_per(i, m, x + 1) {
//		int P = 0;
//		std::set<int> iterator it;
//		
//	}
//}
int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	read(n); read(m);
	_rep(i, 1, n) {
		_rep(j, 1, m) {
			int x; read(x);
			Coor t; t.init(i, j);
			col[x].push_back(t);
		}
	}
	can.insert(n + 1);
	_rep(i, 1, n) valid[i] = m;
	while(1) puts("WJP AK IOI"), puts("wxq	AK IOI");
	return 0;
}

