#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 55;
const int MAXM = 405;

int n,m,cnt;
int col[MAXN][MAXM],num[MAXN];
vector<pii> ans;

void Move(int x,int y){
	col[y][++num[y]] = col[x][num[x]--];
	ans.push_back(make_pair(x,y));
}


void Print(){
	for(int i = 1;i <= n;i++){
		cout << i << " : ";
		for(int j = 1;j <= num[i];j++)
			cout << col[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void Move(int x,int y,int tar){
	int org = num[tar];
	while(num[x] > y){
		for(int i = 1;i <= n;i++){
			if(x == i)
				continue;
			if(num[i] < m){
				while(num[i] < m && num[x] > y)
					Move(x,i);
				break;
			}
		}
	}
	int tmp = 0;
	for(int i = 1;i <= n;i++){
		if(i == x || i == tar)
			continue;
		if(num[i] < m){
			tmp = i;
			break;
		}
	}
	if(!tmp){
		for(int i = n;i >= 1;i--){
			if(i != x && i != tar){
				for(int j = 1;j <= n;j++){
					if(j != x && num[j] < m){
						Move(i,j);
						Move(x,i);
						Move(j,x);
						break;
					}
				}
				tmp = i;
				break;
			}
		}
	}else
		Move(x,tmp);
	int t = num[tar];
	for(int i = t;i > org;i--){
		for(int j = 1;j <= n;j++){
			if(j != tar && j != tmp && num[j] < m){
				Move(tar,j);
				break;
			}
		}
	}
	Move(tmp,tar);
}

int Find(int x,int id){
	for(int i = num[x];i >= 1;i--){
		if(col[x][i] == id)
			return i;
	}
	return 0;
}

bool Check(int id){
	for(int i = 1;i <= n;i++){
		if(i == id){
			if(num[i] != 0)
				return 0;
			continue;
		}
		if(num[i] != m)
			return 0;
		for(int j = 2;j <= m;j++){
			if(col[i][j] != col[i][1])
				return 0;
		}
	}
	return 1;
}

void Solve(int id,int tar){
	if(id == n)
		return;
	for(int i = 1;i <= n;i++){
		if(i == tar)
			continue;
		while(Find(i,id))
			Move(i,Find(i,id),tar);
	}
	for(int i = 1;i <= n;i++){
		if(i == tar)
			continue;
		while(num[i]){
			for(int j = 1;j <= n;j++){
				if(tar == j || i == j)
					continue;
				if(num[j] < m){
					while(num[j] <= m && num[i])
						Move(i,j);
					break;
				}
			}
		}
		if(Check(i))
			return;
		Solve(id + 1,i);
		break;	
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++)
			scanf("%d",&col[i][j]);
		num[i] = m;
	}
	n += 1;
	Solve(1,n);
	printf("%d\n",(int)ans.size());
	for(int i = 0;i < (int)ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}

