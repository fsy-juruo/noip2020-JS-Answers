#include <bits/stdc++.h>
using namespace std;

int Top[11];
int Tow[11][200];
int n,m,tot;

struct Node{
	int x,y;
}ans[20000];

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n = read(), m = read();
	Top[1] = Top[2] = m;
	Top[3] = 0;
	for(int j = 1; j <= m; j++)
		cin >> Tow[1][j];	
	for(int i = Top[1]; i > 0; i--){

		ans[++tot].x = 1, ans[tot].y = 3;
		Top[3]++;
		Tow[3][Top[3]] = Tow[1][Top[1]];
		Top[1]--;
		
	}		
	for(int j = 1; j <= m; j++)
		Tow[2][j] = read();
	for(int i = Top[2]; i > 0; i--){

		ans[++tot] = Node{2,3};
		Top[3]++;
		Tow[3][Top[3]] = Tow[2][Top[2]];
		Top[2]--;
	}
	while(Top[3] >= 1){
		if(Tow[3][Top[3]] == 1){
			ans[++tot] = Node{3,1};	
			Top[1]++;		
			Tow[1][Top[1]] = Tow[3][Top[3]];
			Top[3]--;
		}
		if(Tow[3][Top[3]] == 2){
			ans[++tot] = Node{3,2};	
			Top[2]++;		
			Tow[2][Top[2]] = Tow[3][Top[3]];
			Top[3]--;
		}
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++)
		cout << ans[i].x << ' ' << ans[i].y << endl;
	return 0;
}
