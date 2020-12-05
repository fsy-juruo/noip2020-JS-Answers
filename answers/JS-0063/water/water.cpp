#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,m;
ull dz[10005],dm[10005];
vector<int> end;
vector<int> s[10005];
inline int read(){
	ull x=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=0;ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';ch=getchar();
	}
	if(flag)return x;
	return ~(x-1);
}
int gcd(ull x,ull y){
	if(x==0)return y;
	if(y==0)return x;
	if(x<y)swap(x,y);
	gcd(x%y,y);
}
int gcd2(ull x,ull y){
	return x*y/gcd(x,y);
}
void dfs(ull x,ull fa){
	ull len=s[x].size();
	ull zhim=dm[x]*len;
	ull zhiz=dz[x];
	if(len>0){
		dz[x]=0;
	}
	else{
		return;
	}	
	for(int i=0;i<len;i++){
		if(s[x][i]!=fa){
			dz[s[x][i]]=dz[s[x][i]]*zhim+zhiz*dm[s[x][i]];dm[s[x][i]]*=zhim;
			ull ans=gcd(dz[s[x][i]],dm[s[x][i]]);
			dz[s[x][i]]/=ans;dm[s[x][i]]/=ans;
			dfs(s[x][i],x);
		}
		else continue;
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	ull x,y;
	for(int i=1;i<=n;i++){
		dm[i]=1;
		x=read();
		if(x==0)end.push_back(i);
		else
		for(int j=1;j<=x;j++){
			y=read();s[i].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		dz[i]=1;dm[i]=1;
	}
	for(int i=1;i<=m;i++)dfs(i,0);
	ull len1=end.size();
	for(int i=0;i<len1;i++){
		ull ans=gcd(dz[end[i]],dm[end[i]]);
		cout<<dz[end[i]]/ans<<" "<<dm[end[i]]/ans<<endl;
	}
	return 0;
}
