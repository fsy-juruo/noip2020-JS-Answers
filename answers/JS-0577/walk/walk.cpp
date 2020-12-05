#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,y=1;
	char c=getchar();
	while(c=='\n'||c==' ')c=getchar();
	if(c=='-'){
		y=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}	
	return x*y;
}
int n,k;
long long ans,ms=10e9+7,w[15],a[15],b[15],ad[15],xad[15],iad[15],c[500005],d[500005];
bool ff[1000];
void dfs(int v){
	if(v>k){
		bool f=0;
		for(int i=1;i<=k;i++){
			b[i]=a[i];
		}
//		for(int i=1;i<=k;i++){
//			if(!ff[i])continue;
//			if(b[i]+xad[i]>w[i]||b[i]+iad[i]<1){
//				f=1;
//				break;
//			}
//		}
//		if(!f){
//			long long ps=INT_MAX;
//			for(int i=1;i<=k;i++){
//				if(ad[i]>0){
//					ps=min(ps,(w[i]-b[i])/ad[i]);	
//				}
//				if(ad[i]<0){
//					ps=min(ps,(1-b[i])/ad[i]);	
//				}
//			}
//			if(ps==INT_MAX){
//				cout<<-1;
//				exit(0);
//			}
//			ps--;
//			ans=(ans+ps*n)%ms;
//			for(int i=1;i<=k;i++){
//				b[i]+=ps*ad[i];
//			}
//		}
		while(1){
			for(int i=1;i<=n;i++){
				b[c[i]]+=d[i];
				ans++;
				if(ans==ms)ans=0;
				if(b[c[i]]>w[c[i]]||b[c[i]]<1){
					return;
				}
			}
			bool f1=1;
			for(int i=1;i<=k;i++){
				if(a[i]!=b[i]){
					f1=0;
					break;
				}
			}
			if(f1){
				cout<<-1;
				exit(0);
			}
		}
		return;
	}
	for(int i=1;i<=w[v];i++){
		a[v]=i;
		dfs(v+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=k;i++){
		w[i]=read();
	}
	memset(iad,0x3f,sizeof(iad));
	memset(xad,-0x3f,sizeof(xad));
	for(int i=1;i<=n;i++){
		c[i]=read();
		d[i]=read();
//		ff[c[i]]=1;
//		ad[c[i]]+=d[i];
//		xad[c[i]]=max(xad[c[i]],ad[c[i]]);
//		iad[c[i]]=min(iad[c[i]],ad[c[i]]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}




