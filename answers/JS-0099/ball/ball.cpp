#include<bits/stdc++.h>
using namespace std;
int n,m,cc;
int a[53][403],cnt[53];
int A[822222],B[822222];
int b[53];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),cnt[i]=m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==i)continue;
			int p1,p2;
			for(int k=1;k<=n;k++)for(int l=1;l<=m;l++)if(k!=i||l>j)p1=k,p2=l;
			while(cnt[p1]>=p2)A[++cc]=p1,B[++cc]=n+1,a[n+1][++cnt[n+1]]=a[p1][cnt[p1]],cnt[p1]--;
			while(cnt[p2]<m&&cnt[i]>=j)A[++cc]=i,B[++cc]=n+1,a[n+1][++cnt[n+1]]=a[i][cnt[i]],cnt[i]--;
			A[++cc]=p1,B[++cc]=n+1,a[n+1][++cnt[n+1]]=a[p1][cnt[p1]],cnt[p1]--;
			while(cnt[i]>=j)A[++cc]=i,B[++cc]=p1,a[p1][++cnt[p1]]=a[i][cnt[i]],cnt[i]--;
			A[++cc]=n+1,B[++cc]=i,a[i][++cnt[i]]=a[n+1][cnt[n+1]],cnt[n+1]--;
			while(cnt[i]<m)A[++cc]=n+1,B[++cc]=i,a[i][++cnt[i]]=a[n+1][cnt[n+1]],cnt[cnt[n+1]]--;
			while(cnt[p1]<m)A[++cc]=n+1,B[++cc]=p1,a[p1][++cnt[p1]]=a[n+1][cnt[n+1]],cnt[cnt[n+1]]--;
		}
	}
	printf("%d\n",cc);
	for(int i=1;i<=cc;i++)printf("%d %d\n",A[i],B[i]);
}
