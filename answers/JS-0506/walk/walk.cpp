#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,a[11],c[1000100],d[1000100],dw[11],up[11],len[11],res,qwq[11];
vector<int>v,u;
bool cheimp(){
	for(int i=0;i<m;i++)if(v[i])return false;
	for(int i=0;i<m;i++)if(dw[i]>up[i])return false;
	return true;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d",&a[i]),up[i]=a[i]-1,dw[i]=0,len[i]=a[i];
	v.resize(m);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y),x--,v[x]+=y;
		c[i]=x,d[i]=y;
		if(v[x]>=0)up[x]=min(up[x],a[x]-v[x]-1);
		else dw[x]=max(dw[x],-v[x]);
	}
	if(cheimp()){puts("-1");return 0;}
	for(int i=0;i<m;i++)up[i]=a[i]-1,dw[i]=0,len[i]=a[i];
	u.resize(m);
	for(int i=1;i<=2*n;i++){
		if(i>n)c[i]=c[i-n],d[i]=d[i-n];
		u[c[i]]+=d[i];
		if(u[c[i]]>=0)up[c[i]]=min(up[c[i]],a[c[i]]-u[c[i]]-1);
		else dw[c[i]]=max(dw[c[i]],-u[c[i]]);
		int TTT=max(0,up[c[i]]-dw[c[i]]+1);
		if(TTT<len[c[i]]){
			bool ok=true;
			int tmp=i;
			for(int j=0;j<m;j++){
				if(j==c[i])continue;
				if(len[j]<=0){tmp=ok=0;break;}
				tmp=1ll*tmp*len[j]%mod;
			}
			(res+=tmp)%=mod;
			if(i>n){
				for(int j=0;j<m;j++)qwq[j]=len[j];
				int ini=i;
				while(ok){
					(ini+=n)%=mod;
					tmp=ini;
					for(int j=0;j<m;j++){
						qwq[j]-=abs(v[j]);
						if(qwq[j]<=0){tmp=ok=0;break;}
						if(j==c[i])continue;
						tmp=1ll*tmp*qwq[j]%mod;
					}
					(res+=tmp)%=mod;
				}				
			}
			len[c[i]]=TTT;
		}
	}
	printf("%d\n",res);
	return 0;
}
