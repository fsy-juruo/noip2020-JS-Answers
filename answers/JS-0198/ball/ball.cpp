#include<bits/stdc++.h>
#include<stack>
using namespace std;

int n,m,a[55][405],top[55],b[55],M[55],vis[55],ans[1000005][3],cnt;

void dfs(){
	int flag=1;
	for (int i=1;i<=n;i++){
		int co=a[i][top[i]];
		if (co!=a[i][top[i]-1]||co!=vis[i]){
			if (top[b[co]]<m&&b[co]!=i) {
				a[b[co]][++top[b[co]]]=co;
				ans[++cnt][1]=i;ans[cnt][2]=b[co];
//				cout<<i<<" "<<b[co]<<endl;
				flag=0;
			}
			else 
			for (int j=n+1;j>=1;j--){
				if (j!=i&&top[j]<m){
					a[j][++top[j]]=co;
					ans[++cnt][1]=i;ans[cnt][2]=j;
//					cout<<i<<" "<<j<<endl;
					flag=0;
					break;
				}
			}
			top[i]--;
		}
	}
	if (!flag) dfs();
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int x;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int flag=1;
		for (int j=1;j<=m;j++){
			scanf("%d",&x);
			a[i][++top[i]]=x;
			if (flag&&x!=a[i][top[i]-1]){
				flag=0;
				if (x-1>M[a[i][top[i]-1]]) b[a[i][top[i]-1]]=i,M[a[i][top[i]-1]]=x-1;
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (b[i]) vis[b[i]]=i;
	}
	int l1=1,l2=1;
	while (l1<=n&&l2<=n){
		while (b[l1]&&l1<=n) l1++;
		while (vis[l2]&&l2<=n) l2++;
		vis[l2]=l1;b[l1]=l2;
		l1++;l2++;
	}
	dfs();
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++){
		cout<<ans[i][1]<<" "<<ans[i][2]<<endl;
	}
	return 0;
}
