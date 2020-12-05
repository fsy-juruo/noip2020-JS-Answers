#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	if(n==2){
		int sum=0;
		a[1][0]=a[2][0]=m;
		if(a[1][m]==a[2][m]){
			int ans=0,k=a[1][m];
			while(sum!=m){
				while(a[1][a[1][0]]==k)a[1][0]--,sum++;
				while(a[2][a[1][0]]==k)a[2][0]--,sum++;
			}
		}
	}
} 
