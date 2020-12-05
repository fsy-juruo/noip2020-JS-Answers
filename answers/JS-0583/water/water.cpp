#include<bits/stdc++.h>
#define N 100001
using namespace std;
int n,m,indeg[N]={},q[N]={},h,t,outdeg[N]={},b;
vector<int> s[N];
vector<int> dot;
struct T{
	int x,y; //T=x/y;
};
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
T operator + (T a,T b){
	T c;
	c.x=a.x*b.y+a.y*b.x;
	c.y=a.y*b.y;
	int k=gcd(c.x,c.y);
	c.x/=k,c.y/=k;
	return c;
} 
void Put(T a){
	printf("%d %d\n",a.x,a.y);
}
T w[N];
int main(){
	freopen("water.in","r",stdin);freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>outdeg[i];
		if(!outdeg[i])dot.push_back(i);
		for(int j=1;j<=outdeg[i];j++){
			cin>>b;
			indeg[b]++;
			s[i].push_back(b);
		}
	}
	for(int i=1;i<=n;i++)
		w[i].x=0,w[i].y=1;
	h=t=1;
	for(int i=1;i<=m;i++)
		q[t++]=i,w[i].x=w[i].y=1;
	while(h<=t){
		int a=q[h++];
		for(int i=0;i<s[a].size();i++){
			b=s[a][i];
			T tmp;
			tmp.x=w[a].x,tmp.y=w[a].y*outdeg[a];
			w[b]=w[b]+tmp;
			indeg[b]--;
			if(indeg[b]==0)q[++t]=b;
		}
	}
	for(int i=0;i<dot.size();i++)
	Put(w[dot[i]]);
	return 0;
}

