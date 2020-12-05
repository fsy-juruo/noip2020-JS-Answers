#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MOD=1e9+7,MAXN=5e5+10,INF=0x3f3f3f3f3f3f3f3fll;
void file(string s){freopen((s+".in").c_str(),"r",stdin),freopen((s+".out").c_str(),"w",stdout);}
int read(){
	int a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*f;
}

int n,k;
int maxw[15];
int dir[MAXN],step[MAXN];

namespace sub1{
	int maxn[15],minn[15],npos[15];
	struct node{
		int x[12];
		node(){}
		void add(int c,int d){x[c]+=d;}
		void add(node b,int times){for(int i=1;i<=k;++i){x[i]+=b.x[i]*times;}}
		bool legal(){
			for(int i=1;i<=k;++i){if(x[i]>maxw[i]||x[i]<=0)return 0;}
			return 1;
		}
	}pos[1010];
	void build(){
		for(int i=1;i<=n;++i){
			pos[i]=pos[i-1];
			pos[i].add(dir[i],step[i]);
			for(int j=1;j<=k;++j){
				maxn[j]=max(maxn[j],pos[i].x[j]);
				minn[j]=min(minn[j],pos[i].x[j]);
			}
		}
/*		for(int i=1;i<=k;++i){
			cout<<maxn[i]<<' '<<minn[i]<<endl;
		}*/
	}
	void returnerror(){
		cout<<-1<<endl;
		exit(0);
	}
	int calcstep(){
		int re=INF;
		for(int i=1;i<=k;++i){
			if(maxn[i]+npos[i]>maxw[i]||minn[i]+npos[i]<1)return 0;
			if(pos[n].x[i]!=0){	
				if(pos[n].x[i]>0)re=min(re,(maxw[i]-npos[i]-maxn[i])/pos[n].x[i]+1); 
				else re=min(re,(npos[i]+minn[i])/abs(pos[n].x[i])+1); 
			}
//			cout<<i<<' '<<re<<' '<<maxw[i]<<' '<<npos[i]<<' '<<maxn[i]<<' '<<maxw[i]-npos[i]-maxn[i]+1<<' '<<pos[n].x[i]<<endl;
		}
		if(re==INF){
			returnerror();
		}
		return re;
	}
	int calc(){
		int re=0,totk=calcstep();
		node p;
		for(int i=1;i<=k;++i){
			p.x[i]=npos[i];
		}
		re+=totk*n;
//		cout<<"TOTK "<<totk<<endl;
		p.add(pos[n],totk);
		for(int i=1;i<=n;++i){
			p.add(dir[i],step[i]);
			re++;
			if(!p.legal()){
				return re;
			}
			
		}
		return re;
	}
	bool next_pos(){
		int kk=k;
		while(kk){
			npos[kk]++;
			if(npos[kk]>maxw[kk]){
				npos[kk]=1;
				kk--;
			}else{
				return 1;
			}
		}
		return 0;
	}
	void work(){
		build();
		for(int i=1;i<=k;++i){
			npos[i]=1;
		}
		int ans=0;
		do{
			ans=(ans+calc())%MOD;
//			cout<<ans<<endl;
		}while(next_pos());
		cout<<ans<<endl;
	}
}


signed main(){
	file("walk");
	n=read(),k=read();
	for(int i=1;i<=k;++i){
		maxw[i]=read();
	}
	for(int i=1;i<=n;++i){
		dir[i]=read(),step[i]=read();
	}
	if(n<=1e5){
		sub1::work();
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
/*
3 2 
3 3
1 1 
2 -1
1 1
*/
