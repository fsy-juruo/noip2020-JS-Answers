#include <bits/stdc++.h>
using namespace std;

int n,m,a[60][410],top[60],vh[60],dp[60][410],ans[820010][2];
bool f=false;

bool check2(){
	for(int i=1;i<=n+1;++i){
		if(top[i]>0&&top[i]<m)return false;
		if(top[i]==0)continue;
		int x=a[i][1];
		for(int j=2;j<=top[i];++j)
			if(a[i][j]!=x)return false;
	}
	return true;
}

void DFS(int step){
	if(step>82000)return;
	if(check2()){
		cout<<step-1<<endl;
		for(int i=1;i<step;++i)
			cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
		f=true;
		return;
	}
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=n+1;++j){
			if(i!=j&&top[i]>0&&top[j]<m){
				a[j][++top[j]]=a[i][top[i]--];
				ans[step][0]=i;
				ans[step][1]=j;
				DFS(step+1);
				if(f)return;
			}
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		top[i]=m;
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	}
	DFS(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
