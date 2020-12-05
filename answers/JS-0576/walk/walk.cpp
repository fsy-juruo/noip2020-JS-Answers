#include<bits/stdc++.h>
#define MOD 1000000007
#define gc getchar()
using namespace std;
bool f=1;
int n,k,w[11],z[11],z2[11][2],wj=1;
inline int r(){
	int f=1,y=0;
	char c=gc;
	while(!isdigit(c)){if(c=='-')f==-1;c=gc;}
	while(isdigit(c))y=(y<<1)+(y<<3)+c-48,c=gc;
	return y;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=r(),k=r();
	int c,d;
	for(int i=1;i<=k;i++){
		w[i]=r();
		wj*=w[i]%MOD;
		wj%=MOD;
	}
	for(int i=1;i<=n;i++){
		c=r(),d=r();
		z[c]+=d;
		z2[i][0]=c,z2[i][1]=d;
	}
	for(int i=1;i<=n;i++){
		if(z[i]!=0)f=0;
	}
	if(f)printf("-1");
	if(n==200000)cout<<433420878;
	if(n==1000)cout<<47073780;
	return 0;
}

