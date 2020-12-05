#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,btp[8196];
char c[1058576];
int z[1058576];
ll ans;
int Btp(int x){return btp[x>>13]+btp[x&((1<<13)-1)];}
void Z(){
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n&&c[r-l]==c[r])r++;
			z[i]=r-l,r--;
		}else{
			if(z[i-l]<r-i+1)z[i]=z[i-l];
			else{
				l=i;
				while(r<n&&c[r-l]==c[r])r++;
				z[i]=r-l,r--;
			}
		}
	}
}
int bit[28];
void upd(int id){
	for(;id<28;id+=(id&-id))bit[id]++;
}
int got(int id){
	int ret=0;for(;id>0;id-=(id&-id))ret+=bit[id];return ret;
}
void solve(){
	ans=0;
	int msk=0,msk1=0;
	for(int i=0;i<n;i++)c[i]-='a',msk^=(1<<c[i]),z[i]=0;
	for(int i=0;i<27;i++)bit[i]=0;
	Z();msk1=(1<<c[0]);
	for(int i=2;i<n;i++){
		upd(Btp(msk1)+1),msk1^=(1<<c[i-1]);
		int num1=got(Btp(msk1^msk)+1),num0=got(Btp(msk)+1);
		int p1=0,p0=0;
		for(int j=0,k=i-1,t=1;k<n-1;j+=i,k+=i,t^=1){
			if(j==0||z[j]>=i){
				if(t==1)p1++;
				else p0++;
			}else break;
		}
		ans+=1ll*p1*num1+1ll*p0*num0;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	btp[0]=0;
	for(int i=1;i<(1<<13);i++)btp[i]=btp[i-(i&-i)]+1;
	scanf("%d",&T);
	while(T--){
		scanf("%s",c);
		n=strlen(c);
		solve();
	}
}
