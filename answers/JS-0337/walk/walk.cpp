#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int w[11];
int c[500011];
int d[500011];
int b[11];
int e[11];
int f[11]; 
int a[11];
int h[11];
int n,k;
long long ans=0;
bool flag=false;
bool flg=false;
void tryit(int dep){
	if (flg){
		return;
	}
	if (dep>k){
		int ming=MOD;
		for (int ii=1;ii<=k;ii++){
			if (b[ii]>0){
				if (flag&&(b[ii]!=0)){
					int g=(w[ii]-e[ii]-a[ii])/b[ii];
					if ((w[ii]-e[ii]-a[ii])%b[ii]){
						g++;
					}
					if (g<0){
						g=0;
					}
					ming=min(ming,g);
				}
				if (!flag){
					if (w[ii]<a[ii]+e[ii]){
						flag=true;
					}
				}
			}
			else {
				if (flag&&(b[ii]!=0)){
					int g=(a[ii]+f[ii])/(-b[ii]);
					if ((a[ii]+f[ii])%(-b[ii])){
						g++;
					}
					if (g<0){
						g=0;
					}
					ming=min(ming,g);
				}
				if (!flag){
					if (a[ii]+f[ii]<=0){
						flag=true;
					}
				}
			}
		}
		if (!flag){
			ans=-1;
			flg=true;
			return;
		}
		ans+=ming*n;
		ans%=MOD;
		for (int ii=1;ii<=k;ii++){
			h[ii]=a[ii]+ming*b[ii];
		}
		for (int ii=1;ii<=n;ii++){
			++ans;
			h[c[ii]]+=d[ii];
			if ((h[c[ii]]>w[c[ii]])||(h[c[ii]]==0)){
				break;
			}
		}
		ans%=MOD;
	}
	else {
		for (int xi=1;xi<=w[dep];xi++){
			a[dep]=xi;
			tryit(dep+1);
			if (flg){
				return;
			}
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	
	memset(b,0,sizeof(b));
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	for (int i=1;i<=k;i++){
		scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		b[c[i]]+=d[i];
		if (b[c[i]]>0){
			e[c[i]]=max(e[c[i]],b[c[i]]);
		}
		else {
			f[c[i]]=min(f[c[i]],b[c[i]]);
		}
	}
	for (int i=1;i<=k;i++){
		if (b[i]!=0){
			flag=true;
		}
	}
	tryit(1);
	cout<<ans<<endl;
	return 0;
}

