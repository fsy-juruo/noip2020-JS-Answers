#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define bug cerr<<">>>"<<__LINE__<<endl
//#define int long long
int sta[55][405],top[55],cnt,n,m;
int opx[820000],opy[820000];
void mv(int x,int y){
	sta[y][top[y]++]=sta[x][--top[x]];
	opx[cnt]=x; opy[cnt]=y;
	++cnt;
}
int maxpos(int x,int p){
	int mx=0,ans;
	for(int i=p;i<m;++i)
		if(sta[x][i]>mx)
			mx=sta[x][i],
			ans=i;
	return ans;
}
inline void srt(int x,int y){
	int br=(x==1?2:1);
	mv(br,y);
	for(int j=0;j<m;++j){
		int mp=maxpos(x,j);
		if(mp==j) continue;
		for(int k=m-1;k>mp;--k)
			mv(x,y);
		mv(x,br);
		for(int k=mp-1;k>=j;--k)
			mv(x,y);
		mv(br,x);
		while(top[y]>=2) mv(y,x);
	}
	mv(y,br);
}
void debug(){
	for(int i=1;i<=n+1;++i,cerr<<endl)
		for(int j=0;j<top[i];++j)
			cerr<<sta[i][j]<<' ';
	
	for(int i=1;i<=n+1;++i,cerr<<endl)
		cerr<<top[i];
}
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&sta[i][j]);
	for(int i=1;i<=n;++i)
		top[i]=m;
	for(int i=1;i<=n;++i)
		srt(i,n+1);
	for(int i=1;i<n-1;++i){
		for(int j=1;j<=n+1-i;++j)
			while(top[j] && sta[j][top[j]-1]==i)
				mv(j,n+2-i);
		for(int j=1;j<=n-i;++j){
			for(int v=sta[j][top[j]-1];v>i;--v)
				for(int k=j+1;k<=n+1-i;++k)
					while(top[k] && sta[k][top[k]-1]==v)
						if(top[j]<m) mv(k,j);
						else goto lb1;
			lb1:;
		}
		int sht[55],shtcnt=0;
		for(int j=1;j<=n-i;++j){
			sht[shtcnt++]=j;
			while(top[j]<m) mv(n+1-i,j);
		}
		for(int j=0;j<shtcnt;++j)
			srt(sht[j],n+1-i);
	}
	while(top[2] && sta[2][top[2]-1]==n-1)
		mv(2,3);
	while(top[1] && sta[1][top[1]-1]==n-1)
		mv(1,3);
	while(top[1] && sta[1][top[1]-1]==n)
		mv(1,2);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;++i)
		printf("%d %d\n",opx[i],opy[i]);
}
