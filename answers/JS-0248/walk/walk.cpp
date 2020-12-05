#include<bits/stdc++.h>
using namespace std;
#define fgx cerr<<"------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define pii pair<LL,LL>
#define mpt make_pair
#define fr first
#define sc second
inline int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-1;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
#define M 100020
#define mod 1000000007
int n,K,w[M],c[M],d[M],mxw;
namespace btf{
	int nw[M],chs[M],ans;
	inline bool Jud(){
		if(n<=5&&K<=5&&mxw<=3) return true;
		if(n<=100&&K<=3&&mxw<=10) return true;
		return false;
	}
	inline void Goal(){
		for(int i=1;i<=K;i++) nw[i]=chs[i];
		for(int i=1;i<=n;i++){
			nw[c[i]]+=d[i],ans++;
			for(int j=1;j<=K;j++) if(nw[j]<1||nw[j]>w[j]) return;
		}
		bool flg=false;
		for(int i=1;i<=K;i++)
			if(nw[i]^chs[i]){flg=true; break;}
		if(!flg){puts("-1");exit(0);}
		while(true){
			for(int i=1;i<=n;i++){
				nw[c[i]]+=d[i],ans++;
				for(int j=1;j<=K;j++) if(nw[j]<1||nw[j]>w[j]) return;
			}
		} return;
	}
	inline void deb(){
		for(int i=1;i<=K;i++)
			printf("%d ",chs[i]);
		puts(""),printf("ANS:%d\n",ans);
		//system("pause");
	}
	inline void DFS(int dep){
		if(dep>K){Goal();return;}
		for(int i=1;i<=w[dep];i++)
			chs[dep]=i,DFS(dep+1);
	}
	inline void solve(){DFS(1),printf("%d\n",ans);}
}
#define L 1000020
namespace sub1{
	LL MX; pii sta[L],l[L],nl[L]; LL top,pos[L]; bool F[L];
	inline void solve(){
		MX=w[1],sta[++top]=mpt(0,0);
		LL mx=0ll,mn=0ll,nowd=0ll;
		for(LL i=1;i<=n;i++){
			nowd+=d[i],pos[i]=nowd;
			if(nowd>mx) mx=nowd,sta[++top]=mpt(i,nowd);
			else if(nowd<mn) mn=nowd,sta[++top]=mpt(i,nowd);
		}
		LL rgt=MX-mx,lft=1ll-mn;
		bool fg=true;
		if(rgt<1ll||rgt>MX) fg=false;
		if(lft<1ll||lft>MX) fg=false;
		if(fg&&lft<=rgt&&!nowd){puts("-1");return;}
		LL lst=top; for(LL i=1;i<=top;i++) l[i]=sta[i];
		LL dat=nowd,Hvl=0ll;
		while(true){
			Hvl++;
			for(LL i=1;i<=lst;i++){
				LL x=l[i].fr,cur=Hvl*pos[n]+pos[x],HvGo=(LL)Hvl*n+x;
				if(cur>mx) mx=cur,sta[++top]=mpt(HvGo,cur),F[i]=true;
				else if(cur<mn) mn=cur,sta[++top]=mpt(HvGo,cur),F[i]=true;
				else F[i]=false;
			} LL Top=0ll;
			for(LL i=1;i<=lst;i++) if(F[i])
				nl[++Top]=l[i];
			lst=Top; for(LL i=1;i<=lst;i++) l[i]=nl[i];
			if(mn<-MX||mx>MX) break;
		} LL ans=0ll,Mn=0ll,Mx=0ll;
		//fgx;
		//for(LL i=1;i<=top;i++)
			//printf("%lld %lld\n",sta[i].fr,sta[i].sc);
		//printf("%lld\n",MX);
		for(LL i=1;i<=top;i++){
			//printf("GO:%lld %lld\n",Mn,Mx);
			LL rgt=MX-Mx,lft=1ll-Mn;
			if(rgt<1ll||rgt>MX) break;
			if(lft<1ll||lft>MX) break;
			//printf("%lld %lld %lld\n",sta[i].fr,lft,rgt);
			if(i>1&&lft<=rgt){
				LL x=rgt-lft+1ll,y=sta[i].fr-sta[i-1].fr;
				x%=mod,y%=mod,x=x*y%mod;
				ans=(ans+x)%mod;
				//ans+=(LL)(rgt-lft+1ll)*(sta[i].fr-sta[i-1].fr);
			}
			Mn=min(Mn,sta[i].sc),Mx=max(Mx,sta[i].sc);
		}
		printf("%lld\n",ans);
	}
}
#define M2 1000020
namespace sub2{
	#define L2 5000020
	struct ND{LL fr; int xx,yy;};
	LL MXX,MXY; ND sta[L2],l[L2],nl[L2]; LL top;
	pii pos[M2]; bool F[L2];
	inline void solve(){
		//printf("%d\n",sizeof(sta)+sizeof(l)+sizeof(nl)>>20);
		MXX=w[1],MXY=w[2],sta[++top]=(ND){0ll,0,0};
		LL mxX=0ll,mnX=0ll,
		mxY=0ll,mnY=0ll,X=0ll,Y=0ll;
		for(LL i=1;i<=n;i++){
			if(c[i]==1)X+=d[i]; else Y+=d[i];
			pos[i]=mpt(X,Y); bool fg=false;
			if(X>mxX) mxX=X,fg=true;
			if(X<mnX) mnX=X,fg=true;
			if(Y>mxY) mxY=Y,fg=true;
			if(Y<mnY) mnY=Y,fg=true;
			if(fg) sta[++top]=(ND){i,X,Y};
		}
		LL lst=top; for(LL i=1;i<=top;i++) l[i]=sta[i];
		LL datX=X,datY=Y,Hvl=0ll;
		bool fg=true;
		LL rgtX=MXX-mxX,lftX=1ll-mnX;
		LL rgtY=MXY-mxY,lftY=1ll-mnY;
		if(rgtX<1ll||rgtX>MXX) fg=false;
		if(lftX<1ll||lftX>MXX) fg=false;
		if(rgtY<1ll||rgtY>MXY) fg=false;
		if(lftY<1ll||lftY>MXY) fg=false;
		if(fg&&lftX<=rgtX&&lftY<=rgtY&&!datX&&!datY){puts("-1");return;}
		while(true){
			Hvl++;
			for(LL i=1;i<=lst;i++){
				LL x=l[i].fr,curX=Hvl*X+pos[x].fr,curY=Hvl*Y+pos[x].sc,HvGo=(LL)Hvl*n+x;
				bool fg=false;
				if(curX>mxX) mxX=curX,F[i]=fg=true;
				if(curX<mnX) mnX=curX,F[i]=fg=true;
				if(curY>mxY) mxY=curY,F[i]=fg=true;
				if(curY<mnY) mnY=curY,F[i]=fg=true;
				if(fg) sta[++top]=(ND){HvGo,curX,curY};
			} LL Top=0ll;
			for(LL i=1;i<=lst;i++) if(F[i])
				nl[++Top]=l[i];
			lst=Top; for(LL i=1;i<=lst;i++) l[i]=nl[i];
			if(mnX<-MXX||mxX>MXX) break;
			if(mnY<-MXY||mxY>MXY) break;
		} LL ans=0ll,MnX=0ll,MxX=0ll,
		MnY=0ll,MxY=0ll;
		//for(LL i=1;i<=top;i++)
			//printf("%lld %d %d\n",sta[i].fr,sta[i].xx,sta[i].yy);
		for(LL i=1;i<=top;i++){
			LL rgtX=MXX-MxX,lftX=1ll-MnX;
			LL rgtY=MXY-MxY,lftY=1ll-MnY;
			if(rgtX<1ll||rgtX>MXX) break;
			if(lftX<1ll||lftX>MXX) break;
			if(rgtY<1ll||rgtY>MXY) break;
			if(lftY<1ll||lftY>MXY) break;
			if(i>1&&lftX<=rgtX&&lftY<=rgtY){
				LL dx=rgtX-lftX+1ll,dy=rgtY-lftY+1ll,
				dd=sta[i].fr-sta[i-1].fr;
				dx%=mod,dy%=mod,dd%=mod,dx=dx*dy%mod;
				dd=dd*dx%mod,ans=(ans+dd)%mod;
			}
			MnX=min(MnX,(LL)sta[i].xx),MxX=max(MxX,(LL)sta[i].xx);
			MnY=min(MnY,(LL)sta[i].yy),MxY=max(MxY,(LL)sta[i].yy);
		}
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),K=read();
	for(int i=1;i<=K;i++) w[i]=read(),mxw=max(mxw,w[i]);
	for(int i=1;i<=n;i++) c[i]=read(),d[i]=read();
	if(btf::Jud()){btf::solve();return 0;}
	if(K==1){sub1::solve();return 0;}
	if(K==2){sub2::solve();return 0;}
	puts("-1");
	return 0;
}
