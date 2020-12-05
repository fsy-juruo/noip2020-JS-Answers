#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, clo[52], dep[52], vh[52], js[52];
struct nod{
	int x, y;
}a[820010];
vector <int> s[52];
void fenpei(int x){
	memset(js,0,sizeof(js));
	int l = s[x].size();
	for(int i = 0; i < l; i++){
		js[s[x][i]]++;
	}
	int id, maxn = 0;
	for(int i = 1; i <= n; i++){
		if(!vh[i] && js[i] > maxn){
			id = i;
			maxn = js[i];
		}
	}
	vh[id] = 1;
	clo[x] = id;
}
bool check(int x){
	for(int i = 1; i <= m; i++)
		if(s[x][i-1] != clo[x]) return true;
	return false;
}
void work(int x){
	while(check(x)){
		for(int i = m; i >= dep[x]; i--){
			cnt++;
			a[cnt].x = x;
			a[cnt].y = n+1;
			s[n+1].push_back(s[x][i-1]);
			s[x].pop_back();
		}
		int minv = 0, id;
		for(int i = x + 1; i <= n; i++){
			for(int j = m; j >= 1; j--){
				if(s[i][j-1] == clo[x]){
					if(j > minv){
						minv = j;
						id = i;
					}
				}
			}
		}
		for(int i = m; i > minv; i--){
			cnt++;
			a[cnt].x = id;
			a[cnt].y = n+1;
			s[n+1].push_back(s[id][i-1]);
			s[id].pop_back();
		}
		cnt++;
		a[cnt].x = id;
		a[cnt].y = x;
		s[x].push_back(clo[x]);
		s[id].pop_back();
		while(s[x].size() < m){
			cnt++;
			a[cnt].x = n+1;
			a[cnt].y = x;
			s[x].push_back(s[n+1][s[n+1].size()-1]);
			s[n+1].pop_back();
		}
		while(s[id].size() < m){
			cnt++;
			a[cnt].x = n+1;
			a[cnt].y = id;
			s[id].push_back(s[n+1][s[n+1].size()-1]);
			s[n+1].pop_back();
		}
		for(int j = 0; j < m; j++){
			if(s[x][j] != clo[x]){
				dep[x] = j + 1;
				break;
			}
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	memset(dep,0x3f,sizeof(dep));
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		for(int j = 1, t; j <= m; j++){
			scanf("%d",&t);
			s[i].push_back(t);	
		}
		fenpei(i);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < m; j++)
			if(s[i][j] != clo[i]){
				dep[i] = j+1;
				break;
			}
	}
	for(int i = 1; i <= n; i++)
		work(i);
	printf("%d\n",cnt);
	for(int i = 1; i <= cnt; i++)
		printf("%d %d\n", a[i].x, a[i].y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
