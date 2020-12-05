#include<bits/stdc++.h>
#define int long long
#define N 100007
#define M 500007
using namespace std;
int n,m,chu[N],ru[N],v[M],Next[M],head[M],tot,w1[N],w2[N];
queue<int> q;
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return;
}
inline void addedge(int x,int y){
	v[++tot]=y;Next[tot]=head[x];head[x]=tot;
	return;
}
inline int gcd(int x,int y){
	if(y==0)return x;
	else return gcd(y,x%y);
}
inline void add(int &x,int &y,int x_,int y_){
	if(x==0){
		x=x_;
		y=y_;
		return;
	}
	int cx1=x,cy1=y,cx2=x_,cy2=y_,g;
	cx1*=y_;cy1*=y_;
	cx2*=y;cy2*=y;
	cx1+=cx2;
	g=gcd(cx1,cy1);
	x=cx1/g;
	y=cy1/g;
	return;
}
inline void init(){
	int  x;
	read(n);read(m);
	for(int i=1;i<=n;i++){
		read(chu[i]);
		for(int j=1;j<=chu[i];j++){
			read(x);
			addedge(i,x);
			ru[x]++;
		}
	}
	return;
}
inline void work(){
	int x;
	for(int i=1;i<=n;i++)
	if(!ru[i])q.push(i),w1[i]=1,w2[i]=1;
	while(q.size()){
		x=q.front();q.pop();
		for(int i=head[x];i;i=Next[i]){
			add(w1[v[i]],w2[v[i]],w1[x],w2[x]*chu[x]);
			ru[v[i]]--;
			if(!ru[v[i]])q.push(v[i]);
		}
	}
	return;
}
inline void put(){
	int g;
	for(int i=1;i<=n;i++)
	if(!chu[i]){
		g=gcd(w1[i],w2[i]);
		cout<<w1[i]/g<<" "<<w2[i]/g<<endl;
	}
	return;
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	init();
	work();
	put();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
