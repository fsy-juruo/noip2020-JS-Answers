#include<bits/stdc++.h>
#define r register
using namespace std;
int n,m,aq[52][401],num[52],way[820001][2],cnt;
inline int read(){
	r int w=1,x=0; r char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}return w*x;
}
inline void dfs(r int k){
	if(cnt==8) return;
	bool flag=0;
	for(r int i=1;i<=n+1;i++){
		if(!num[i]) continue;
		if(num[i]!=m){
			flag=1; break;
		}
		for(r int j=2;j<=m;j++)
			if(aq[i][j]!=aq[i][1]){
				flag=1;
				break;
			}
	}
	if(!flag){
		cout<<cnt<<endl;
		for(r int i=1;i<=cnt;i++)
			printf("%d %d\n",way[i][0],way[i][1]);
		exit(0);
	}
	for(r int i=1;i<=n+1;i++)
		if(i!=k&&num[i]!=m){
			way[++cnt][0]=k; way[cnt][1]=i;
			aq[i][++num[i]]=aq[k][num[k]]; aq[k][num[k]--]=0; 
			for(r int j=1;j<=n+1;j++)
				if(num[j]&&j!=i) dfs(j);
			cnt--;
			aq[k][++num[k]]=aq[i][num[i]]; aq[i][num[i]--]=0;
		}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);	
	n=read(); m=read();
	for(r int i=1;i<=n;i++)
		for(r int j=1;j<=m;j++)
			aq[i][j]=read();
	for(r int i=1;i<=n;i++) num[i]=m;
	dfs(1);
	return 0;
}
