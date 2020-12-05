#include<bits/stdc++.h>
using namespace std;
struct pr{
	int a,b;
};
struct qup{
	int step;
	stack<int> st[55];
	pr ep[10005];
};
int qone(stack<int> s,int m){
	if(s.size()<m) return 0;
	int f=-1;
	stack<int> r=s;
	while(!r.empty()){
		int x=r.top();
		r.pop();
		if(f==-1) f=x;
		else if(f!=x) return 0;
	}
	return 1;
}
int qall(int n,int m,qup x){
	for(int i=1;i<=n;i++) if(!qone(x.st[i],m)) return 0;
	return 1;
}
void doit(int n,int m,qup start){
	queue<qup> q;
	q.push(start);
	while(!q.empty()){
		qup x=q.front();
		q.pop();
		if(qall(n,m,x)){
			printf("%d\n",x.step);
			for(int i=1;i<=x.step;i++) printf("%d %d\n",x.ep[i].a,x.ep[i].b);
			return ;
		}
		for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++){
			if(i==j) continue;
			if(x.st[i].size()==0) continue;
			if(x.st[j].size()==m) continue;
			qup y=x;pr z;int s=y.st[i].top();
			z.a=i;z.b=j;
			y.st[i].pop();
			y.st[j].push(s);
			y.ep[++y.step]=z;
			q.push(y);
		}
	}
}
qup start;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		int x;
		scanf("%d",&x);
		start.st[i].push(x);
	}
	doit(n,m,start);
	return 0;
}
