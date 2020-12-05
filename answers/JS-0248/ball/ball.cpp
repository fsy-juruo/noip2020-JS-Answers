#include<bits/stdc++.h>
using namespace std;
#define prt(x) cerr<<#x<<" = "<<x<<endl
#define fgx cerr<<"------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define pii pair<int,int>
#define mpt make_pair
#define fr first
#define sc second
inline int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-1;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
#define M 120
#define INF 1000000000
int n,m,N,sta[M][M],top[M];
namespace btf{
	int stat[M][M],topt[M],Rest;
	bool Hvd[M];
	vector<pii >que,ans;
	inline void Fakemove(int x,int y){
		int col=stat[x][topt[x]];
		--topt[x],stat[y][++topt[y]]=col,que.pb(mpt(x,y));
	}
	inline void Realmove(int x,int y){
		int col=sta[x][top[x]];
		--top[x],sta[y][++top[y]]=col,ans.pb(mpt(x,y));
		//cerr<<"Real: "<<x<<" "<<y<<endl;
	}
	inline bool Judge(int x){
		que.clear();
		/*prt(x);fgx;
		for(int i=1;i<=n;i++,puts(""))
			for(int j=1;j<=topt[i];j++)
				printf("%d ",stat[i][j]);
		system("pause");*/
		while(true){
			int mn=INF,fi,fj;
			for(int i=1;i<=n;i++)
				for(int j=topt[i];j;--j) if(stat[i][j]==x){
					//printf("%d %d\n",i,j);
					int Need=topt[i]-j;
					if(Need<mn) mn=Need,fi=i,fj=j;
				}
			//prt(mn),prt(fi),prt(fj);
			if(mn==INF) return true;
			for(int i=1;i<=n;i++) if(!Hvd[i]&&(i^fi)){
				while(topt[i]<m&&topt[fi]>fj) Fakemove(fi,i);				
			}
			if(topt[fi]>fj) return false;
			Fakemove(fi,N);
		}
	}
	inline void moveall(int x,int y){
		for(int i=1;i<=n;i++)
			if(top[y]&&!Hvd[i]&&top[i]<m) Realmove(y,i);
		while(top[x]) Realmove(x,y);
		return;
	}
	inline void solve(){
		ans.clear(),Rest=n;
		while(Rest){
			for(int i=1;i<=n;i++){
				memcpy(stat,sta,sizeof(stat)),memcpy(topt,top,sizeof(topt));
				if(!Hvd[i]&&Judge(i)){
					//prt(i);
					//for(int j=0,TP=que.size();j<TP;j++)
						//cerr<<"que: "<<que[j].fr<<" "<<que[j].sc<<endl;
					for(int j=0,TP=que.size();j<TP;j++)
						Realmove(que[j].fr,que[j].sc);
					moveall(N,i),Hvd[i]=true,--Rest; break;
				}
			}
		}
		printf("%d\n",(int)ans.size());
		for(int i=0,TP=ans.size();i<TP;i++)
			printf("%d %d\n",ans[i].fr,ans[i].sc);
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read(),N=n+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) sta[i][j]=read();
	for(int i=1;i<=n;i++) top[i]=m;
	btf::solve();
	return 0;
}
