#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int maxn = 600;
struct MyStack{
	int dat[maxn], _top;
	MyStack(){
		_top = 0;
	}
	bool empty(){
		return _top == 0;
	}
	int size(){
		return _top;
	}
	void pop(){
		_top --;
	}
	int top(){
		return dat[_top - 1];
	}
	int &operator[](int index){
		return dat[index];
	}
	void push(int x){
		dat[_top ++] = x;
	}
};
int n, m, k, col[maxn], len[maxn], sizall[maxn], cstack[maxn];
vector<pii> ans, ans2;
MyStack stk[maxn];
priority_queue<int> nonfull;
inline bool move(int x, int y){
	if(stk[x].size() < 1) return false;
	if(stk[y].size() >= m) return false;
	stk[y].push(stk[x].top());
	stk[x].pop();
	ans.push_back(make_pair(x, y));
	return true;
}
void printstacks(){
	for(int i=1; i<=n+1; i++){
		for(int j=0; j<stk[i].size(); j++) printf("%d ", stk[i][j]);
		puts("");
	}
	puts("");
}
void pushdown(int k){
	//	from: [bottom] true true false true false false
	//	to:   [bottom] true true true false false false
	int tmpstk = (k == 1 ? 2 : 1);
	int siz = 0;
	for(int i=len[k]; i<stk[k].size(); i++) if(stk[k][i] == col[k]) siz ++;
	for(int i=1; i<=siz; i++) move(tmpstk, n + 1);
	for(int i=stk[k].size()-1; i>=len[k]; i--){
		if(stk[k][i] == col[k]) move(k, tmpstk);
		else move(k, n + 1);
	}
	for(int i=1; i<=siz; i++) move(tmpstk, k);
	while(stk[n + 1].size() > siz) move(n + 1, k);
	for(int i=1; i<=siz; i++) move(n + 1, tmpstk);
}
void pushup(int k, int color){
	//	from: [bottom] true col false col false false
	//	to:   [bottom] true false false false col col
	int tmpstk = (k == 1 ? 2 : 1);
	int siz = 0, pos = -1;
	for(int i=0; i<stk[k].size(); i++) 
		if(stk[k][i] == color){
			siz ++;
			if(pos == -1) pos = i;
		}
	if(pos == -1) return;
	for(int i=1; i<=siz; i++) move(tmpstk, n + 1);
	for(int i=stk[k].size()-1; i>=pos; i--){
		if(stk[k][i] == color) move(k, tmpstk);
		else move(k, n + 1);
	}
	while(stk[n + 1].size() > siz) move(n + 1, k);
	for(int i=1; i<=siz; i++) move(tmpstk, k);
	for(int i=1; i<=siz; i++) move(n + 1, tmpstk);
}
void pushdownall(){
	for(int i=1; i<=n; i++) pushdown(i);
}
void movemultiple(int x, int y, int cnt){
	for(int i=1; i<=cnt; i++) move(x, y);
}
bool zipans(){
	//	check ans: (x1, y1), (x2, y2) that y1 == x2
	//	target: (x1, y2)
	//	check ans: (x1, y1) that x1 == y1
	//	target: delete it!
	bool ret = false;
	ans2.clear();
	for(int i=0; i<ans.size(); i++){
		if(i > 0 && ans2[ans2.size() - 1].second == ans[i].first){
			ans2[ans2.size() - 1].second = ans[i].second;
			ret = true;
		}
		else{
			ans2.push_back(ans[i]);
		}
	}
	ans.clear();
	for(int i=0; i<ans2.size(); i++){
		if(ans2[i].first == ans2[i].second){
			ret = true;
			continue;
		}
		ans.push_back(ans2[i]);
	}
	return ret;
}
int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	k = 0;
	for(int i=1; i<=n; i++){
		while(!stk[i].empty()) stk[i].pop();
		for(int j=1; j<=m; j++){
			int x; scanf("%d", &x);
			if(j == 1){
				col[i] = x; len[i] = 1;
			}
			else if(col[i] == x && len[i] == j - 1) len[i] ++;
			stk[i].push(x);
		}
		if(cstack[col[i]] != 0){
			if(len[cstack[col[i]]] < len[i]){
				col[cstack[col[i]]] = 0;
				len[cstack[col[i]]] = 0;
				cstack[col[i]] = i;
			}
		}
		else{
			cstack[col[i]] = i;
		}
	}
	if(n == 1){
		puts("0");
		return 0;
	}
	int pos = 1;
	for(int i=1; i<=m; i++){
		if(cstack[i] == 0){
			while(pos <= n && col[pos] != 0) pos ++;
			col[pos] = i;
			cstack[i] = pos;
		}
	}
	pushdownall();
	for(int i=1; i<=n; i++){
		int siz = 0;
		for(int j=0; j<stk[i].size(); j++){
			if(stk[i][j] == col[i]) siz ++;
		}
		for(int j=i+1; j<=n; j++){
			pushup(j, col[i]);
		}
		movemultiple(i, n + 1, stk[i].size() - siz);
		for(int j=i+1; j<=n; j++){
			while(stk[j].size() > 0 && stk[j].top() == col[i]) move(j, i);
		}
		int pos = i + 1;
		while(!stk[n + 1].empty()){
			while(stk[pos].size() >= m) pos ++;
			move(n + 1, pos);
		}
	}
	while(zipans()) ;
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}


