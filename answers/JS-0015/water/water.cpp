#include<bits/stdc++.h>
using namespace std;
#define nn 100005
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!='-' and (ch>'9' or ch<'0')) ch=getchar();
	if(ch=='-') f=-f,ch=getchar();
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}

const int lim=10000;
struct big{
	vector<int> v;
	void pure(){
		for(int i=0;i<v.size();i++){
			if(v[i]>=lim) {
				if(i==v.size()-1) v.push_back(v[i]/lim);
				else v[i+1]+=v[i]/lim;
				v[i]%=lim;
			}
		}
		while(v.size()>1 and v[v.size()-1]==0) v.pop_back();
	}
	void out(){
		if(v.size()==0) putchar('0');
		else{
			int s=v.size();
			printf("%d",v[s-1]);
			for(int i=s-2;i>=0;i--){
				int t=lim/10;
				while(t) {
					putchar('0'+v[i]/t%10);
					t/=10;
				}
			}
		}
	}
	int size(){
		return v.size();
	}
};
big operator+(big x,big y){
	if(x.size()>y.size()) swap(x,y);
	for(int i=0;i<x.size();i++) y.v[i]+=x.v[i];
	y.pure();return y;
}
big operator/(big x,int y){
	for(int i=(int)x.size()-1;i>=0;i--) {
		if(i) x.v[i-1]+=x.v[i]%y*lim;
		x.v[i]/=y;
	}
	x.pure();return x;
}
big operator*(big x,int y){
	for(int i=0;i<x.size();i++) x.v[i]*=y;
	x.pure();return x;
}
int operator%(big x,int y){
	for(int i=(int)x.size()-1;i>=0;i--) {
		if(i==0 and x.v[0]%y) return x.v[0]%y;
		if(i) x.v[i-1]+=x.v[i]%y*lim;
		x.v[i]/=y;
	}
	return 0;
}
big base;
big cap[nn];
vector<int> flow[nn];
int deg[nn];
signed main(){
	freopen("water.in","r",stdin);freopen("water.out","w",stdout);
	base.v.push_back(1);
	for(int i=0;i<11;i++) base=base*4*3*5;
	
	int n=read(),m=read();
	for(int i=1;i<=n;i++) cap[i].v.push_back(0);
	for(int i=0;i<m;i++) {
		int x=i+1;
		cap[x]=cap[x]+base;
	}
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read();deg[x]++;
			flow[i].push_back(x);
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	while(q.size()){
		int x=q.front();q.pop();if(!flow[x].size()) continue;
		
		big e=cap[x]/(int)(flow[x].size());
		for(int i=0;i<flow[x].size();i++){
			int y=flow[x][i];
			deg[y]--;if(deg[y]==0) q.push(y);
			cap[y]=cap[y]+e;
		}
	}
	
	
	for(int i=1;i<=n;i++) if(flow[i].size()==0){
		int s3=11,s2=22,s5=11;
		while(s3 and cap[i]%3==0) cap[i]=cap[i]/3,s3--;
		while(s2 and cap[i]%2==0) cap[i]=cap[i]/2,s2--;
		while(s5 and cap[i]%5==0) cap[i]=cap[i]/5,s5--;
		cap[i].out();putchar(' ');
		big td;td.v.push_back(1);
		while(s3--) td=td*3;
		while(s2--) td=td*2;
		while(s5--) td=td*5;
		td.out();puts("");
	}
	return 0;
}
