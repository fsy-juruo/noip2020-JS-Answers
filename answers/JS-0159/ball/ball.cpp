#include<bits/stdc++.h>
using namespace std;
const int N=55,M=410;
int n,m;
int ans,a,x;
int maxn,maxi;
bool flag,f[N];
int s[N][M];
int b[N],c[N];
int maxwi(){
	for(int i=1;i<=n;i++)
		if(!f[i]){
			a=1;flag=false;
			while(s[i][a]==s[i][a+1]) a++;
			if(a>maxn) maxn=a,maxi=i;
		}
	return maxi;
}
bool ju(int u){
	a=1;
	while(s[u][a]==s[u][a+1]) a++;
	if(a==m) return false;
	return true;
}
bool check(){
	for(int i=1;i<=n;i++) if(!f[i]) return true;
	return false;
}
void predo(int pur,int u){
	for(int i=1;i<=n;i++)
		if(!f[i]&&i!=u){
			x=0;b[i]=0;c[i]=0;
			for(int j=1;j<=m;j++)
			    if(s[i][j]==pur){
			    	if(!b[i]) b[i]=j;
			    	c[i]++;
				} 
		}
}
void ki(int u,int v){
	s[v][++s[v][0]]=s[u][s[u][0]--];
}
void my(int b,int c,int pur,int u,int j){
	ans+=4*m-2*a-2*b-c+2;
	for(int i=1;i<=m-a;i++) printf("%d %d\n",u,n+1),ki(u,n+1);
	for(int i=m;i>=b;i--)
		if(s[j][i]==pur) printf("%d %d\n",j,u),ki(j,u);
		else printf("%d %d\n",j,n+1),ki(j,n+1);
	for(int i=1;i<=m-b+1-c;i++) printf("%d %d\n",n+1,j),ki(n+1,j);
	for(int i=m-a;i>=a;i--) 
		if(s[n+1][i]==pur) printf("%d %d\n",n+1,u),ki(n+1,u);
		else printf("%d %d\n",n+1,j),ki(n+1,j);
}
void fill(int u){
	int pur=s[u][1];
	predo(pur,u);
	while(ju(u)){
		for(int i=1;i<=n;i++){
			if(!f[i]&&c[i]&&b[i]&&(m-a-b[i]-c[i]+1)<=0) 
			my(b[i],c[i],pur,u,i);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		s[i][0]=m;
		for(int j=1;j<=m;j++)
			scanf("%d",&s[i][j]);
	}
	while(check()) fill(maxwi());
	printf("%d\n",ans);
	return 0;
}
