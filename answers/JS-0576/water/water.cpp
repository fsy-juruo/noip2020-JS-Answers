#include<bits/stdc++.h>
#include<algorithm>
#define N 100010
#define gc getchar()
#define ll long long
using namespace std;
int n,m,s=0;
int fi[N*5],to[N*5],ne[N*5];
int ru[N],chu[N];
ll f[N][2];
bool sai[N];
queue<int> q;
inline int r(){
	int x=0;
	char c=gc;
	while(!isdigit(c))c=gc;
	while(isdigit(c))x=(x<<1)+(x<<3)+c-48,c=gc;
	return x;
}
inline void link(int u,int v){
	to[++s]=v;
	ne[s]=fi[u];
	fi[u]=s;
}
inline ll gcd(ll a,ll b){
	if(a==0)return b;
	else return gcd(b%a,a);
}
void bfs(int t){
	q.push(t);
	while(!q.empty()){
		int x=q.front();
		if(sai[x]==1){
			q.pop();
			continue;
		}
		else sai[x]=1;
		for(int i=fi[x];i!=0;i=ne[i]){
			register int j=to[i];
//			cout<<j<<" ";
			if(f[j][0]==0&&f[j][1]==0){
				f[j][0]=f[x][0];
				f[j][1]=f[x][1]*chu[x];
			}else{
				f[j][0]=f[j][0]*f[x][1]*chu[x]+f[j][1]*f[x][0];
				f[j][1]*=f[x][1]*chu[x];
			}
			register ll a=gcd(f[j][0],f[j][1]);
			f[j][0]/=a;
			f[j][1]/=a;
//			cout<<j<<" "<<f[j][0]<<" "<<f[j][1]<<" "<<a<<endl;
			q.push(j);
		}
//		cout<<endl;
		q.pop();
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=r(),m=r();
	int x,y;
	for(int i=1;i<=n;i++){
		x=r();
		for(int j=1;j<=x;j++){
			y=r();
			link(i,y);
			ru[y]++;
			chu[i]++;
		}
	}
	int t;
	for(int i=1;i<=n;i++){
		if(ru[i]==0){
			t=i;
			f[t][0]=1;
			f[t][1]=1;
			bfs(t);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(chu[i]==0)printf("%lld %lld\n",f[i][0],f[i][1]);
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
4 15
11 15
10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0

*/
