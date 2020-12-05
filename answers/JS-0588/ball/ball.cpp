#include<bits/stdc++.h>
using namespace std;
inline void read(int &x) {
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
}
int n,m,k,mb,cnt,c[405],d[405];
stack<int> a[55];
queue<int>q1,q2;
set<int>s;
int main() {
//	freopen("ball.in","r",stdin);
//	freopen("ball.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			read(k);
			a[i].push(k);
			s.insert(k);
		}
	while(s.size()) {
		c[++cnt] = *s.begin();
		s.erase(s.bigin());
	}
	while(!a[1].empty())
		if(a[1].top() == c[1]) {
			++cnt;
			a[3].push(a[1].top());
			a[1].pop();
			q1.push(1);
			q2.push(3);
		} else break;
	while(!a[2].empty())
		if(a[2].top() == c[1]) {
			++cnt;
			a[3].push(a[2].top());
			a[2].pop();
			q1.push(2);
			q2.push(3);
		} else break;
	while(a[3].size() < n || a[3].top() != c[1]) {
		while(!a[2].empty() && a[2].top() == c[2]){
			if(a[1].size < n)
				++cnt;
				a[1].push(a[1].top());
				a[2].pop();
				q1.push(2);
				q2.push(3);
			} else break;
	}
	while(!a[1].empty()) {
		++cnt;
		a[2].push(a[1].top());
		a[1].pop();
		q1.push(1);
		q2.push(2);
	}
	cout << cnt;
	while(!q1.empty())
		printf("%d %d\n",q1.front(),q2.front());
	return 0;
}
