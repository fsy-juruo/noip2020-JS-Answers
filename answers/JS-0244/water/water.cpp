#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100100][6],b[100010],c[11],k,num[100010][2],cc,ccc;
int abs(int x,int y){
	while(x%y!=0){
		int t;
		t=x;
		x=y;
		y=t%y;
	}
	return y;
}
void jia(int aa,int aaa,int bb,int bbb){
	if(aa==0){
		cc=bb;
		ccc=bbb;
	}else if(bb==0){
		cc=aa;
		ccc=aaa;
	}else{
		cc=aa*bbb+aaa*bb;
		ccc=aaa*bbb;
		int z=abs(cc,ccc);
		cc/=z;
		ccc/=z;	
	}
	return;
}
void dfs(int x,int y,int z){
	num[x][1]=y;
	num[x][2]=z;
	if(b[x]==0)return;
	int w=abs(y,b[x]*z);
	y/=w;
	z=z*b[x]/w;
	num[x][1]=0;
	num[x][2]=1;
	for(int i=1;i<=b[x];i++){
		jia(y,z,num[a[x][i]][1],num[a[x][i]][2]);
		dfs(a[x][i],cc,ccc);
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0){
			k++;
			c[k]=i;
		}
		if(i<=m){
			num[i][1]=1;
			num[i][2]=1;
		}
		for(int j=1;j<=b[i];j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		dfs(i,1,1);
	}
	for(int i=1;i<=k;i++){
		cout<<num[c[i]][1]<<" "<<num[c[i]][2]<<endl;
	}
	return 0;
}
