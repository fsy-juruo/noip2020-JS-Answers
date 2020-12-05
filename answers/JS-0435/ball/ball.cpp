#include<bits/stdc++.h>
#define N 100001
using namespace std;
stack<int> pole[N];
void dfs();
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m,i,x;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>x;
			pole[i].push(x);
		}
	}
	return 0;
}

