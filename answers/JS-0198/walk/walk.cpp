#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int n,k,w[15],lmt[15][2000005],a[15],dx[15],sum[15][2000005],minn=0x7fffffff,M[15];
int dfs(int x){
	if (x==k){
		if (minn>=lmt[x][M[x]]){
			return sum[x][w[x]]%mod;
		}
		else{
			int L=1,R=M[x]-1;
			while (L<R){
				int mid=((L+R)>>1)+1;
				if (lmt[x][mid]<=minn) L=mid;
				else R=mid-1;
			}
			int l=L;
			L=M[x]+1,R=w[x];
			while (L<R){
				int mid=((L+R)>>1)+1;
				if (lmt[x][mid]<=minn) L=mid;
				else R=mid-1;
			}
			int r=L;
			return ((r-l+1)*minn%mod+((sum[x][l]+sum[x][w[x]])%mod-sum[x][r-1])%mod)%mod;
		}
	}
	if (x==k+1) return 0;
	int tmp,ans=0;
	for (int i=1;i<=w[x];i++){
		dx[x]=i;
		tmp=minn;
		minn=min(minn,lmt[x][i]);
		ans=(ans+dfs(x+1))%mod;
		minn=tmp;
	}
	return ans;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++){
		cin>>w[i];
	}
	int c,d;
	memset(lmt,0x7f,sizeof(lmt));
	for (int i=1;i<=n;i++){
		cin>>c>>d;
		a[c]+=d;
		lmt[c][a[c]]=min(lmt[c][a[c]],i);
	}
	int flag=0;
	for (int i=1;i<=n;i++){
		if (a[c]!=0) flag=1;
	}
	if (!flag){
		cout<<-1;
		return 0;
	}
	for (int i=1;i<=k;i++){
		for (int j=1;j<=w[i];j++){
			lmt[i][j]=min(lmt[i][j],lmt[i][j-w[i]-1]);
		}
		for (int j=1;j<=w[i]/2;j++){
			swap(lmt[i][j],lmt[i][w[i]+1-j]);
		}
		M[i]=1;
		for (int j=1;j<=w[i];j++){
			if (lmt[i][j]>n) lmt[i][j]=n;
			else lmt[i][j]--;
			sum[i][j]=sum[i][j-1]+lmt[i][j];
			if (lmt[i][M[i]]<lmt[i][j]) M[i]=j;
		}
	}
//	for (int i=1;i<=k;i++){
//		for (int j=1;j<=w[i];j++){
//			cout<<lmt[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	for (int i=1;i<=k;i++){
//		cout<<M[i]<<" ";
//	}

	cout<<dfs(1);
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
