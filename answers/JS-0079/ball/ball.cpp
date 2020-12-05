#include<bits/stdc++.h>
using namespace std;
const int N=820005;
int ans[820005][2],m,n;
int b[55][405];
int f[55][55],q[55];
int cul(int x,int y,int p,int c){
	
}
int main()
{
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		scanf("%d",&b[i][j]);
		f[i][b[i][j]]=1;
	}
	int ep=n+1,last=0,t=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
	    if(f[j][i]){
		    t++;
		    q[t]=j;
	    }
	    int st=q[1];
	    for(j=2;j<=t;j++)
	    ep=cul(st,q[j],ep,i);
	}
	return 0;
}
