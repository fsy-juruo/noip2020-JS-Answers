#include <bits/stdc++.h>
using namespace std;
int a[52][401], t[52], n, m;
int main(){
	freopen ("ball.in","r",stdin);
	freopen ("ball.out","w",stdout);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		t[i]=m, a[i][0]=-1;
		for (int j=1; j<=m; j++) cin >> a[i][j];
	}
	for (int i=1; i<=m; i++) a[n+1][i]=-1;
	t[n+1]=0;
	int ans=0; queue<int> s;
	if (a[1][m]==1) for (int i=m; a[1][i]==1; i--){t[1]--, t[3]++;swap(a[1][i], a[3][t[3]]);s.push(1);s.push(3);ans++;}
	if (a[2][m]==1) for (int i=m; a[2][i]==1; i--){t[2]--, t[3]++;swap(a[2][i], a[3][t[3]]);s.push(2);s.push(3);ans++;}
	while (t[3]!=m){
		while (t[1]!=m){
			if (a[2][t[2]]==2){t[2]--, t[1]++;swap(a[2][t[2]+1], a[1][t[1]]);s.push(2);s.push(1);ans++;}
			if (a[2][t[2]]==1){t[2]--, t[3]++;swap(a[2][t[2]+1], a[3][t[3]]);s.push(2);s.push(3);ans++;}
		}
		while (t[2]!=m){
			if (a[1][t[1]]==2){t[1]--, t[2]++;swap(a[1][t[1]+1], a[2][t[2]]);s.push(1);s.push(2);ans++;}
			if (a[1][t[1]]==1){t[1]--, t[3]++;swap(a[1][t[1]+1], a[3][t[3]]);s.push(1);s.push(3);ans++;}
		}
	}
	cout << ans+m+t[2] << endl;
	while (!s.empty()){
		cout << s.front() << ' ';
		s.pop();
		cout << s.front() << endl;
		s.pop();
	}
	for (int i=1; i<=t[2]; i++) cout << "2 1" << endl;
	for (int i=1; i<=m; i++) cout << "3 2" << endl;
	return 0;
}
