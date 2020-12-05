#include<bits/stdc++.h>
#define MAXN ((int)(1048999))
using namespace std;
int next[MAXN];
char c[MAXN];
int s[MAXN][27];
int fr[MAXN];
int bk[MAXN];
int n;
int e[MAXN][27];//e[i][j]=\sum_{k=1}^i{[fr[i]<=j]}
void kmp(){//我真的不记得了啊 
	next[0]=next[1]=0;
	for(int i=2;i<=n;i++){
		next[i]=-1;
		int ans=next[i-1];
		while(c[i]!=c[ans+1]){
			if(ans==0){
				next[i]=0;
				break;
			}
			ans=next[ans];
		}
		if(next[i]!=0)next[i]=ans+1;
	}
}
vector<int > g;
int vis[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		scanf("%s",c+1);
		n=strlen(c+1);
		kmp();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=26;j++){
				s[i][j]=s[i-1][j]+(c[i]-'a'==j-1?1:0);
			}
			if(s[i][c[i]-'a'+1]&1)fr[i]=fr[i-1]+1;else fr[i]=fr[i-1]-1;
		}
		for(int i=1;i<=26;i++)s[n][i]=0;
		for(int i=n;i>=1;i--){
			for(int j=1;j<=26;j++){
				s[i][j]=s[i+1][j]+(c[i]-'a'==j-1?1:0);
			}
			if(s[i][c[i]-'a'+1]&1)bk[i]=bk[i+1]+1;else bk[i]=bk[i+1]-1;
		}
		for(int i=0;i<=26;i++){
			for(int j=1;j<=n;j++){
				e[j][i]=e[j-1][i]+(fr[j]<=i?1:0);
			}
		}
		for(int i=n;i>=1;i--){
			int fc=bk[i];
			ans+=e[i-2][fc];
		}
		for(int i=2;i<=n;i++){
			if((i)%(i-next[i])==0){
				int ax=i/(i-next[i]);//ax is xh times
				if(!vis[i-next[i]])
				g.push_back(i-next[i]);//g labeled the xh pos
				vis[i-next[i]]=ax;//vis[p]=q is s[1..p]s[1..p]...(q times)
			}
		}
		for(int i=0;i<g.size();i++){
			int u=g.at(i),v=vis[u];
			for(int j=1;j<=v;j++){
				for(int rp=2;rp*j<=v;rp++){
					if(rp*j*u==n)break;
					int wz=rp*j*u+1;
//					printf("%d %d:%d\n",j,rp,e[j*u-1][bk[wz]]);
					ans+=e[j*u-1][bk[wz]];
				}
			}
		}
		printf("%lld\n",ans);
		g.clear();
		if(t==0)return 0;
		for(int i=1;i<=n;i++){fr[i]=bk[i]=0;}
		for(int i=0;i<=26;i++){
			for(int j=1;j<=n;j++){
				e[j][i]=0;
			}
		}
		for(int i=1;i<=n;i++)c[i]=NULL,next[i]=0;
	}
}
