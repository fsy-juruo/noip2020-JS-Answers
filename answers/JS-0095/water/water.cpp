#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-48,ch=getchar();
	return s*f;
}vector<int> to[100001];
queue<int> q;
int r[100001],s[100001][2],n,m;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}void add(int x,int a,int b){
	int c=s[x][1]*b/(gcd(s[x][1],b));
	s[x][0]*=(c/s[x][1]);s[x][1]=c;
	a*=(c/b);s[x][0]+=a;c=gcd(s[x][0],s[x][1]);
	s[x][0]/=c;s[x][1]/=c;
}void bfs(){
	for(int i=1;i<=n;++i){
		if(r[i]==0){
			s[i][0]=1;q.push(i);
		}s[i][1]=1;
	}while(!q.empty()){
		int x=q.front();q.pop();
		int a=s[x][0],b=s[x][1],l=to[x].size();
		if(l==0)continue;
		if(a%l==0)a/=l;
		else b*=l;
		for(int i=0;i<l;++i){
			int t=to[x][i];
			--r[t];add(t,a,b);
			if(r[t]==0)q.push(t);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	int d,x;
	for(int i=1;i<=n;++i){
		d=read();
		for(int j=1;j<=d;++j){
			x=read();to[i].push_back(x);
			++r[x];
		}
	}bfs();
	for(int i=1;i<=n;++i){
		if(!to[i].size()){
			printf("%d",s[i][0]);
			printf(" ");
			printf("%d",s[i][1]);
			printf("\n");
		}
	}return 0;
}
