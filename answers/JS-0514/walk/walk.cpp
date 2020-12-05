#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const int maxk = 15;
int n,k,l,tot;
int c[maxn],d[maxn],fx[maxk],w[maxk];

int main(){
	freopen("walk.in","r",stdin);
 	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
	}
	bool flag = false;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		fx[c[i]] += d[i];
		if(abs(fx[c[i]])>=w[c[i]])
			flag = true;
	}
	for(int i=1;i<=k;i++)
		if(fx[c[i]]!=0)
			flag = true;
	if(flag==false){
		printf("-1");
		return 0;
	}else{
		if(k==1){
			for(int j=1;j<=w[1];j++){
				fx[1]=0;
				bool tnt = false;
				int h=1;
				while(!tnt){
					tot ++;
					tot %= mod;
					fx[c[h]] += d[h];
					if(fx[1]+j<=0 || fx[1]+j>w[1])
						tnt = true;
					if(h==n) h=0;
					h++;
				}
			}
		}else{
			printf("-1");
			return 0;
		}
	}
	printf("%d",tot);
	return 0;
}
