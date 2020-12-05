// 硬搜也要搜出来
// 100%的TimeOut 
// 测试中发现部分情况下存在RunTimeError 
// 来不及了　不改了
/*
	
	--YFZ 
	
*/ 
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 405;

struct dd{
	int x, y;
	dd(){}
	dd(int xx, int yy){
		x = xx; y = yy;
	}
};

int n, m;
int co[N][M];
queue<dd> cmd;

int size(int x){
	for(int i = 1;i <= M; i++){
		if(co[x][i] == 0){
			return (i - 1);
		}
	}
}

bool check(){
	for(int i = 1; i <= n; i++){
		int c = co[i][1];
		for(int j = 1; j <= size(i); j++){
			if(co[i][j] != c){
				return false;
			}
		}
	}
	return true;
}

bool dfs(){
	if(check()){
		return true;
	}
	for(int i = 1; i <= n + 1; i++){
		for(int j = 1; j <= n + 1; j++){
			if(i == j){
				continue;
			}
			cout << i << " " << j << endl;
			if(size(i) > 0 && size(j) < m){
					co[j][size(j) + 1] = co[i][size(i)];
					co[i][size(i)]  = 0;
					cmd.push(dd(i, j));
					if(dfs()){
						return true;
					}
					co[i][size(i)] = co[j][size(j) + 1];
					co[j][size(j) + 1] = 0;
					cmd.pop();
			}	
		}
	}
}


int main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	memset(co, 0, sizeof(co));
	cin >> n >> m;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			cin >> co[i][j];
		}
	}
	dfs();
	cout << cmd.size() << endl;
	while(!cmd.empty()){
		dd now = cmd.front();
		cmd.pop();
		cout << now.x << " " << now.y << endl;
	}
	return 0;
}
