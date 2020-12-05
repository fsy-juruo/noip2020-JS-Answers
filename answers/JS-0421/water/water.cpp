#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
vector<int>v[100010];int deg[100010];
queue<int>q;
int co[100010];int len=0;

long long V[100010][2];
inline long long gcd(long long n,long long m){
	return (!m)?n:gcd(m,n%m);
}
inline void add(int p1,int sl,int p2){
	long long n1=V[p1][0];long long n2=V[p1][1];n2*=sl;
	long long n3=V[p2][0];long long n4=V[p2][1];
	long long nop=n2/gcd(n2,n4)*n4;
	long long sol=n3*(nop/n4)+n1*(nop/n2);
	long long temp=gcd(nop,sol);sol/=temp;nop/=temp;
	V[p2][0]=sol;V[p2][1]=nop;return;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;read(n);read(m);
	rep(i,1,n){
		int di;read(di);
		if(!di){co[++len]=i;}
		else{
			rep(j,1,di){
				int x;read(x);deg[x]++;
				v[i].push_back(x);
			}
		}
	}
	
	rep(i,1,n){V[i][0]=0;V[i][1]=1;}
	rep(i,1,n){if(!deg[i]){q.push(i);V[i][0]=1;V[i][1]=1;}}
	while(!q.empty()){
		int x=q.front();q.pop();int s=(int)v[x].size();
		rep(i,0,s-1){
			int nop=v[x][i];deg[nop]--;
			add(x,s,nop);
			if(!deg[nop])q.push(nop);
		}
	}
	rep(i,1,len){qwq(V[co[i]][0]);putchar(' ');write(V[co[i]][1]);}
	return 0;
}
