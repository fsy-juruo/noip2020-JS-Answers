#include<bits/stdc++.h>
using namespace std;

const int maxn=55;
const int maxm=405;
int n,m;
vector<pair<int,int> >ans;
vector<int>vec;
int a[maxn][maxm],b[maxn],len[maxn];

void work(int x,int y){
	if(x==y){
		int z=0;
		while(len[z]==m||z==x)z++;
		ans.push_back(make_pair(x,n));
		ans.push_back(make_pair(z,x));
		ans.push_back(make_pair(n,z));
		swap(a[x][m-1],a[z][m-1]);
		x=z;
	}
	for(int i=1;i<=m-len[y];i++)ans.push_back(make_pair(y,n));
	ans.push_back(make_pair(x,y));
	ans.push_back(make_pair(n,x));
	for(int i=2;i<=m-len[y];i++)ans.push_back(make_pair(n,y));
	swap(a[x][m-1],a[y][len[y]]);
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
		scanf("%d",&a[i][j]),a[i][j]--;
	while(true){
		vec.clear();
		for(int i=0;i<n;i++){
			while(len[i]<m&&a[i][len[i]]==i)len[i]++;
			if(len[i]!=m)vec.push_back(i);
		}
		if(vec.empty())break;
		int x=vec[rand()%int(vec.size())];
		work(x,a[x][m-1]);
	}
	printf("%d\n",int(ans.size()));
	for(int i=0;i<int(ans.size());i++)printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}
