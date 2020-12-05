#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
inline int read(){
	int x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(int x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(int x,char ch){
	write(x),putchar(ch);
}
int a[55][405],h[55],u[820005],v[820005],ans,n,m;
stack<pair<int,int> >st[55];
pair<int,int> tmp;
inline bool ok(){
	int f=0;
	for(int i=1;i<=n+1;++i){
		if(st[i].size()>1)return 0;
		if(st[i].size()==0)f=1;
	}
	return f;
}
inline void mv(int p,int q){
	for(int i=1;i<=st[p].top().se;++i){
		u[++ans]=p;
		v[ans]=q;
	}
	h[p]-=st[p].top().se;
	h[q]+=st[p].top().se;
	if(st[q].size()){
		tmp=mp(st[p].top().fi,st[p].top().se+st[q].top().se);
		st[q].pop();
		st[p].pop();
		st[q].push(tmp);
	}
	else{
		tmp=st[p].top();
		st[p].pop();
		st[q].push(tmp);
	}
	if(ok()){
		writeln(ans,'\n');
		for(int i=1;i<=ans;++i){
			writeln(u[i],' ');
			writeln(v[i],'\n');
		}
		exit(0);
	}
	if(ans>=820000){
		puts("0");
		exit(0);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int g;
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		g=0;
		h[i]=m;
		for(int j=1;j<=m;++j){
			a[i][j]=read();
			if(a[i][j]==a[i][j-1]||j==1){
				++g;
			}
			else{
				st[i].push(mp(a[i][j-1],g));
				g=1;
			}
		}
		if(g)st[i].push(mp(a[i][m],g));
	}
	while(1){
		for(int i=1;i<=n+1;++i){
			if(h[i]<m){
				for(int j=1;j<=n+1;++j){
					if(j==i||st[j].empty())continue;
					if(st[i].size()==0){
						mv(j,i);
						break;
					}
					if(h[i]+st[j].top().se<=m&&st[i].top().fi==st[j].top().fi){
						mv(j,i);
						break;
					}
				}
			}
		}
	}
	return 0;
}
