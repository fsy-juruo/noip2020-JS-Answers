#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;
int n,m;
int d[maxn];
vector<int> GV[maxn];
int indegree[maxn],outdegree[maxn];
long long p[maxn],q[maxn];
queue<int> qq;

long long gcd(long long x,long long y){
	if(y==0)  return x;
	else return gcd(y,x%y);
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		for(int j=1;j<=d[i];j++){
			int tmp;
			cin>>tmp;
			GV[i].push_back(tmp);
			outdegree[i]++,indegree[tmp]++;
		} 
		p[i]=0,q[i]=1;
	}
	for(int i=1;i<=m;i++){
	   p[i]=q[i]=1;	
	   qq.push(i);
	}
	while(!qq.empty()){
		int nowp=qq.front();
		qq.pop();
		for(int i=0;i<=d[nowp]-1;i++){
			int to=GV[nowp][i];
			long long tpnowp=p[nowp],tqnowp=q[nowp],tpto=p[to],tqto=q[to];
			tqnowp*=d[nowp];
			tpto*=tqnowp,tqto*=tqnowp,tpnowp*=q[to],tqnowp*=q[to];
			tpto+=tpnowp;
			long long tgcd=gcd(tpto,tqto);
			p[to]=tpto/tgcd,q[to]=tqto/tgcd;
			indegree[to]--;
			if(indegree[to]==0)  qq.push(to);
		}
	}
	for(int i=1;i<=n;i++)
		if(outdegree[i]==0)  cout<<p[i]<<' '<<q[i]<<endl;
	return 0;
}
