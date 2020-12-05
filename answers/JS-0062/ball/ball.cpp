#include<bits/stdc++.h>
using namespace std;
int a[51][401],n,m,f[830000],t[830000],s,e,h[52],flag=0;
bool vis[55];
bool move(int f1,int t1){	
	for(int i=1;i<=n+1;i++){
		if(h[i]<m&&i!=f1&&i!=t1){
			a[i][h[i]+1]=a[f1][h[f1]];
			h[i]++;
			a[f1][h[f1]]=0;
			h[f1]--;
			f[++s]=f1;
			t[s]=i;
			return true;
		}
	}
	return false;
}
void hanno(int x,int y,int p){//颜色 目标位置 已经放了几个 
	if(a[y][p]==x){
		hanno(x,y,p+1);
		return;
	}
	int a1,b;
	bool f1=1;
	for(int i=n+1;i>=e+1;i--){
		for(int j=m;j>=1;j--){
			if(a[i][j]==x&&i!=y){
				a1=i,b=j;	
				f1=0;
				break;
			}
		}
		if(f1==0)break;
	}
	while(b<h[a1]){
		if(move(a1,y)==0){
			flag=1;
			return;
		}
	}
	while(a[y][p]!=0){
		if(move(y,a1)==0){
			flag=1;
			return;
		}
	}
	f[++s]=a1;
	t[s]=y;
	a[y][p]=x;
	h[y]++;
	a[a1][h[a1]]=0;
	h[a1]--;
	if(p==m){
		e++;
		if(e==n){
			cout<<s<<endl;
			for(int i=1;i<=s;i++){
				cout<<f[i]<<' '<<t[i]<<endl;
			}
			flag=0;
		}
	}
	else hanno(x,y,p+1);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	srand(time(NULL));
	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		h[i]=m;
	}
	for(int i=1;i<=n;i++){
		int j;
		int o=rand()%n+1;
		while(vis[o]==1)o=rand()%n+1;
		vis[o]=1;
		hanno(i,o,1);
	}
	while(flag==1){
		for(int i=1;i<=n;i++)vis[i]=0;
		s=1;
		e=0;
		for(int i=1;i<=n;i++){
			int j;
			int o=rand()%n+1;
			while(vis[o]==1)o=rand()%n+1;
			vis[o]=1;
			hanno(i,o,1);
		}
	}
	
return 0;

}

