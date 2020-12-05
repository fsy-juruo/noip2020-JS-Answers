#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
const int maxn=100007;
using namespace std;
vector<int>tu[maxn];
queue<int>q;
long long jg[maxn][3];
int m,n,k;
int ru[maxn],chu[maxn],xu[maxn];
long long gcd(long long a,long long b) {
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
void work1() {
	while(q.size()) {
		int x=q.front();
		q.pop();
		if(!chu[x]&&!ru[x]) {
			xu[++k]=x;
			continue;
		}
		for(int i=0; i<tu[x].size(); i++) {
			int a=tu[x][i];
			ru[a]--;
			if(ru[a]==0) q.push(a);
			if(jg[a][2]==0) jg[a][2]+=jg[x][2]*chu[x];
			else {
				jg[a][1]=jg[a][1]*(jg[x][2]*chu[x])+jg[x][1]*jg[a][2];
				jg[a][2]*=(jg[x][2]*chu[x]);
				long long b=gcd(jg[a][2],jg[a][1]);
				jg[a][1]/=b;
				jg[a][2]/=b;
			}
		}
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(chu,0,sizeof(chu));
	memset(ru,0,sizeof(ru));
	memset(jg,0,sizeof(jg));
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		int ge;
		scanf("%d",&ge);
		jg[i][1]=1;
		for(int j=1; j<=ge; j++) {
			int con;
			scanf("%d",&con);
			tu[i].push_back(con);
			ru[con]++;
			chu[i]++;
		}
	}
	for(int i=1; i<=n; i++) {
		if(ru[i]==0) q.push(i),jg[i][2]=1;
	}
	work1();
	sort(xu+1,xu+k+1);
	for(int i=1;i<=k;i++)
	{
		printf("%lld %lld\n",jg[xu[i]][1],jg[xu[i]][2]);
	}
	return 0;
}

