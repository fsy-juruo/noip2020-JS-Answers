#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "string"
const int MAXN=(1<<20)+114514;
int T;
string str;
int qzh[30],hzh[30],n,qm[MAXN],hm[MAXN];
LL ans=0;

inline int read(){
	int xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}

bool check(int fr,int cz){
	for(int i=0;i<cz;++i) if(str[i]!=str[fr+i]) return false;
	return true;
}



int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	T=read();
	for(int tt=1;tt<=T;++tt) {
		cin>>str;
		n=str.size();
		int ji=0;
		ans=0;
		memset(qzh,0,sizeof(qzh));
		memset(hzh,0,sizeof(hzh));
		memset(qm,0,sizeof(qm));
		memset(hm,0,sizeof(hm));
		for(int j=0;j<n;++j){
//			cout<<str[j]-'a'<<" "<<ji<<endl;
			++qzh[str[j]-'a'];
			if(qzh[str[j]-'a']&1) ++ji;
			else --ji;
			qm[j]=ji;
		}
		ji=0;
		for(int j=n-1;j>=0;--j){
			++hzh[str[j]-'a'];
			if(hzh[str[j]-'a']&1) ++ji;
			else --ji;
			hm[j]=ji;
		}
//		for(int i=0;i<n;++i) cout<<qm[i]<<" ";
//		cout<<endl;
//		for(int i=0;i<n;++i) cout<<hm[i]<<" ";
//		cout<<endl;
		int xhj=0,bj=0,jnhc=2;
		for(int j=2;j<=n/2;++j){
			if(str[j]==str[0]){
				bool bj=true;
				for(int k=1;k<j;++k){
					if(str[j+k]!=str[k]){bj=false;break;}
				}
				if(bj) {xhj=j;break;}
			}
		}
		if(xhj&&(str[0]!=str[1]||xhj>2)){
			for(int i=3;i<=n/xhj;++i) {
				if(!check((i-1)*xhj,xhj)){
					break;
				}
				++jnhc;
			}
			for(int i=0;i<n-2;++i) {
				for(int j=i+1;j<n-1;++j){		
					if(j>1&&(j+1)%xhj==0) for(int k=1;(j+1)*k<=jnhc*xhj&&(j+1)*k<n;++k) {if(qm[i]<=hm[(j+1)*k]) ++ans;}
					else if(qm[i]<=hm[j+1]) ++ans;		
//					cout<<i<<" "<<j<<" "<<ans<<endl;	
				}
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=0;i<n;++i) {xhj=1;jnhc=i;if(str[i]!=str[0])break;}
			if(jnhc<4) jnhc=0,xhj=0;
	//		cout<<jnhc<<" "<<xhj<<endl;
			if(!xhj)
			for(int i=0;i<n-2;++i) {
				for(int j=i+1;j<n-1;++j){		
						if(qm[i]<=hm[j+1]) ++ans;				
				}
			}
			else{
				for(int i=0;i<n-2;++i) {
					for(int j=i+1;j<n-1;++j){		
						if(j<jnhc) for(int k=1;(j+1)*k<=jnhc&&(j+1)*k<n;++k) {if(qm[i]<=hm[(j+1)*k]) ++ans;}
						else if(qm[i]<=hm[j+1]) ++ans;		
//						cout<<i<<" "<<j<<" "<<ans<<endl;		
					}
				}
			}
			cout<<ans<<endl;
		}
	//	cout<<jnhc<<" "<<xhj<<endl;
		
	}
	
	return 0;
}

