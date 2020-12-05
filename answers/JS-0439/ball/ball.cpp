#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int P=131;
stack<int>a[80],s1,s2;
struct node {
	stack<int>st[51];
	
};
bool operator (const &node x,const &node y) const {
	return x.st[1].top<y.st[1].top;
}
map<node,int>p;
queue<node>q;
int main () {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i].push(j);
	node l;
	for (int i=1;i<=n;i++) l.st[i]=a[i];
	p[l]=1;
	while (!q.empty()) {
		l=q.front();q.pop();
		for (int i=1;i<=n;i++)
			for (int j=1;j<i;j++) {
				swap(l.st[i],l.st[j]);
				if (!p[l]) q.push(l);
				swap(l.st[i],l.st[j]);
			}
	}
	return 0;
}

