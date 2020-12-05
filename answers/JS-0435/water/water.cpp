#include<bits/stdc++.h>
#define N 100001
//test1~8
using namespace std;
int n,m,i,d[N],x;
bool use[N];
int fenmu[N],fenzi[N];
vector<int> next[N];
priority_queue<int> q;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void add(int a,int b){
	int a1=fenzi[a],a2=fenmu[a],b1=fenzi[b],b2=fenmu[b]*next[b].size();
	a1=a1*b2+b1*a2;
	a2=a2*b2;
	int g=gcd(a1,a2);
	if(g!=0)a1/=g,a2/=g;
	fenzi[a]=a1,fenmu[a]=a2;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
		fenmu[i]=1;
		for(int j=1;j<=d[i];j++){
			scanf("%d",&x);
			next[i].push_back(x);
		}
	}
	for(i=1;i<=m;i++){
		fenmu[i]=fenzi[i]=1;
		q.push(i);
		use[i]=1;
	}
	while(!q.empty()){
		while(next[q.top()].size()==0){
			q.pop();
			use[x]=1;
		}
		int x=q.top();
		q.pop();
		use[x]=0;
		for(int j=0;j<next[x].size();j++){
			add(next[x][j],x);
			if(use[next[x][j]]!=1){
				q.push(next[x][j]);
				use[next[x][j]]=1;
			}
		}
		fenzi[x]=0;
	}
	for(i=1;i<=n;i++){
		if(next[i].size()==0)cout<<fenzi[i]<<" "<<fenmu[i]<<endl;
	}
	return 0;
}

