#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
int a[1111][1111];
int main(){
	#ifndef lpcak
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	#endif
	int n,m,r=0,r2=0;
	ios::sync_with_stdio(0);
	cin>>n>>m;F(i,1,n)F(j,1,m)cin>>a[i][j];
	if(n==1){cout<<"0\n";return 0;}
//	if(n==2){
//		bool sw32=0;int mx=-im,mn=im;
//		F(i,1,2)F(j,1,m)
//			mx=max(mx,a[i][j]),mn=min(mn,a[i][j]);
//		F(i,1,2)F(j,1,m)
//			if(a[i][j]==mn)a[i][j]=1;
//			else a[i][j]=2;
//		F(i,1,m/2)
//			a[3][i]=a[1][m-i+1],a[1][m-i+1]=0;
//		F(i,1,m/2)
//			a[3][i+m/2]=a[2][m-i+1],a[2][m-i+1]=0;
//		G(i,m/2*2,1)lst[++r]=a[3][i];
//		F(i,1,m/2*2)a[3][i]=0;
//		F(i,m-m/2,m)a[2][i]=2;
//		F(i,m-m/2,m)a[1][i]=1;
//		F(i,1,m)a[3][i]=a[2][m-i+1];
//		F(i,1,m)a[2][i]=a[1][m-i+1];
//		F(i,1,m)a[1][i]=0;
//		F(i,1,m-m/2)a[1][i]=a[2][m-i+1];
//		F(i,1,m/2)a[1][i+m-m/2]=a[3][m-i+1];
//		if((m&1)&&(a[3][m/2+1]==1))sw32=1;
//		int cnt2=m/2+sw32,cnt3=m/2-sw32;
//		G(i,m,1)lst2[++r2]=a[1][i]+1;
//		cout<<m/2*4+m*4+sw32<<"\n";
//		F(i,1,m/2)cout<<"1 3\n";
//		F(i,1,m/2)cout<<"2 3\n";
//		F(i,1,r)cout<<"3 "<<lst[i]<<"\n";
//		
//	}
	return 0;
}
