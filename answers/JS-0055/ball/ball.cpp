#include<bits/stdc++.h>
using namespace std;
stack<int> st[55];
int bot[55],last[55],ans;
queue<int> fr,to;
void mov(int a,int b){
	st[b].push(st[a].top());
	st[a].pop();
	fr.push(a);
	to.push(b);
	++ans;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int c;
			scanf("%d",&c);
			if(j==1) bot[i]=c;
			st[i].push(c);
		}
	}
	if(n==2){
		for(int i=1;i<=m;++i){
			mov(2,3);
			while(st[1].size()>i){
				if(st[1].top()==bot[1]&&st[2].size()<m){
					mov(1,2);
				}else mov(1,3);
			}
			mov(2,1);
			while(st[1].size()<m){
				mov(3,1);
			}
			while(!st[3].empty()){
				mov(3,2);
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i){
		printf("%d %d\n",fr.front(),to.front());
		fr.pop(),to.pop();
	}
	return 0;
}
