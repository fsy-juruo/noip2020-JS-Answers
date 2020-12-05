#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define maxm 2000005
#define LL long long
#define inf 0x3f3f3f3f
#define mod 1000000007
//#define local
void file(string ss){freopen((ss+".in").c_str(),"r",stdin);freopen((ss+".out").c_str(),"w",stdout);}
template<typename Tp> void read(Tp &x){
	x=0;int fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-'){fh=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x*10)+c-'0';c=getchar();}x*=fh;
}
int n,m;
int a[505][505],tt[505];
int ans[maxn][2],tot;
int stk[maxn],stp;

void push(int x,int v){
	a[x][++tt[x]]=v;
}
int pop(int x){
	int ret=a[x][tt[x]];a[x][tt[x]]=0;--tt[x];
	return ret;
}

void mv(int fr,int to){
	++tot;
	ans[tot][0]=fr;ans[tot][1]=to;
	push(to,pop(fr));
}

void mmove(int frm,int nm,int to){
	stp=0;
	int ps1=-1,ps2=-1;
	for(int j=to;j;--j){
		if(j!=frm&&tt[j]<m){
			if(ps1==-1)ps1=j;
			else if(ps2==-1)ps2=j;
		}
	}
	int flg=0;
	if(ps2==-1){
		for(int j=1;j<to;++j){
			if(j==frm)continue;
			mv(j,to);
			ps2=j;
			break;
		}
		flg=1;
	}
	for(int j=1;j<=to;++j){
		if(j==frm)continue;
		while(nm){
			if(tt[j]>=m||(j==ps2&&tt[j]>=m-1))break;
			stk[++stp]=j;--nm;
			mv(frm,j);
		}
	}
	mv(frm,ps2);
	while(stp&&stk[stp]==to){
		mv(to,frm);--stp;
	}
	if(flg){
		mv(to,frm);
		mv(ps2,to);
		mv(frm,ps2);
	}
	else mv(ps2,to);
}
void solve(int p){
	if(p==1)return;
	for(int i=1;i<=p;++i){
		for(int j=tt[i];j>0;--j){
			if(a[i][j]==p){
				mmove(i,tt[i]-j,p+1);++j;
			}
		}
	}
	for(int i=1;i<p;++i){
		while(tt[p]){
			if(tt[i]>=m)break;
			mv(p,i);
		}
	}
	solve(p-1);
}


int b[505];
signed main(){
	#ifndef local
		file("ball");
	#endif
	srand(19260817);
	read(n);read(m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			read(a[i][j]);
		}
		tt[i]=m;
	}
	for(int i=1;i<=n;++i)b[i]=i;
	random_shuffle(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=b[a[i][j]];
		}
	}
	solve(n);
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

