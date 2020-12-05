#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p[100010][100],son[100010],summ,sumz,nowm[100010],nowz[100010];
bool re[100010];
int reci[100010],otto[100010],cntr,cnto;
int gcd(int tt,int jj){
	if(tt==0)return jj;
	return gcd(jj%tt,tt);
}
void fadd(int n,int m,int a,int b){
    summ=m*b;
    sumz=n*b+m*a;
    int moo=gcd(summ,sumz);
    summ=summ/moo;
    sumz=sumz/moo;
    return;
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>son[i];
    	if(son[i]==0){
    		cnto++;
    		otto[cnto]=i;
		}
    	for(int j=1;j<=son[i];j++){
    		cin>>p[i][j];
    		re[p[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!re[i]){
			cntr++;
			reci[cntr]=i;
			nowz[i]=1;
		}
		nowm[i]=1;
	}
	/*for(int i=1;i<=cntr;i++)cout<<reci[i]<<" ";
	cout<<endl;
	for(int i=1;i<=cnto;i++)cout<<otto[i]<<" ";
	cout<<endl;*/
	for(int t=1;t<=10;t++){
	//	for(int i=1;i<=n;i++)cout<<nowz[i]<<" "<<nowm[i]<<endl;
	//	cout<<endl;
		for(int i=1;i<=n;i++){
			if((nowz[i]!=0)&&(son[i])){
				for(int j=1;j<=son[i];j++){
					fadd(nowz[i],nowm[i]*son[i],nowz[p[i][j]],nowm[p[i][j]]);
					nowz[p[i][j]]=sumz;nowm[p[i][j]]=summ;
				}
				nowz[i]=0;nowm[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(nowz[i])cout<<nowz[i]<<" "<<nowm[i]<<endl;
	}
	return 0;
}
