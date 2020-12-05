#include<bits/stdc++.h>
using namespace std;
///////////////////////
int gys(int a,int b){
	int x,y,z,i,j,k,ans=1;
	x=max(a,b);
	for(i=1;i<=sqrt(x);i++){
		y=a%i;
		z=b%i;
		if(y==0&&z==0){
			ans=i;
		}
	}
	return ans;
}
//gys 为找公因数 测试完毕 没有问题 
//////////////////////// 
int main(){
    freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    int i,j,k=1,n,m;
    long long a[10100][8];
    long long b[10100][2]={0};
    long long c[10100];
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	cin>>a[i][0];
    	for(j=1;j<=a[i][0];j++){
    		cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		if(a[i][0]==0){
			c[k]=i;
			k++;
		}
	}
	b[1][1]=1;
	b[1][2]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=a[i][0];j++){
			int ax=b[i][1];
			int bx=b[i][2]*a[i][0];
			int f;
			if(b[a[i][j]][1]==0&&b[a[i][j]][2]==0){
				b[a[i][j]][1]=ax;
				b[a[i][j]][2]=bx;
			}else{
			b[a[i][j]][1]=b[a[i][j]][1]*bx+b[a[i][j]][2]*ax;
			b[a[i][j]][2]=bx*b[a[i][j]][2];	
			}
			/////////////////////
			f=gys(b[a[i][j]][1],b[a[i][j]][2]);
			b[a[i][j]][1]=b[a[i][j]][1]/f;
			b[a[i][j]][2]=b[a[i][j]][2]/f;
			//约分 
			/////////////////////
		}
	}
	for(i=1;i<=k-1;i++){
		int f=gys(b[c[i]][1],b[c[i]][2]);
		b[c[i]][1]=b[c[i]][1]/f;
		b[c[i]][2]=b[c[i]][2]/f;
		cout<<b[c[i]][1]<<" "<<b[c[i]][2]<<endl;
	}
	return 0;
}
