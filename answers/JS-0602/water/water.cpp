#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
bool h[101000];
vector<int> v[101000];
struct Node{
	long long fm,fz;
}wa[101000];
long long read(){
	long long xx=0,ff=1;
	char ch=getchar();
	while (!isdigit(ch)){
		if (ch=='-')ff=-1;
		ch=getchar();
	}
	while (isdigit(ch)){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return ff*xx;
}
long long gcd(long long x,long long y){
	if (x<y)swap(x,y);
	if (x%y==0)return y;
	return gcd(x%y,y);
}
long long lgs(long long x,long long y){
	return gcd(x,y)*(x/gcd(x,y))*(y/gcd(x,y));
}
void add(long long node,long long dep){
	 wa[node].fz=(lgs(wa[node].fm,dep)/wa[node].fm)*wa[node].fz+lgs(wa[node].fm,dep)/dep;
	 wa[node].fm=lgs(dep,wa[node].fm);
}
void dfs(long long node,long long dep){
	if (v[node].size()==0){
	    add(node,dep);
	    return ;
	}
	h[node]=1;
	for (int i=0;i<v[node].size();i++)
	   if (!h[v[node][i]])
	   	dfs(v[node][i],dep*v[node].size());
	h[node]=0;
	return ;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++){
		int d=read();
		while (d--){
			long long u=read();
			v[i].push_back(u);
		}
	}
	for (int i=1;i<=n;i++)
		wa[i].fm=1,wa[i].fz=0;
	for (int i=1;i<=m;i++)
	   dfs(i,1);
	for (int i=1;i<=n;i++)
	   if (v[i].size()==0)cout<<wa[i].fz/gcd(wa[i].fz,wa[i].fm)<<" "<<wa[i].fm/gcd(wa[i].fz,wa[i].fm)<<endl;
	return 0;
}
