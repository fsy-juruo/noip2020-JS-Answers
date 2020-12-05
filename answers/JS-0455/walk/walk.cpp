#include<cstdio>
using namespace std;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int f,n,k,cnt,c[1000000],d[1000000],w[10],a[15],i,j;
	cnt=f=0;
	for(i=0;i<15;i+=1) a[i]=1;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i+=1) scanf("%d",&w[i]);
	for(i=1;i<=n;i+=1) scanf("%d%d",&c[i],&d[i]);
	if(k==1){
		for(i=1;i<=w[1];i+=1){
			f=0;
			while(1){
				for(j=1;j<=n;j+=1){
					a[c[j]]+=d[j];
					cnt+=1;
					if(a[c[j]]>w[c[j]] || a[c[j]]<1){
						f=1;
						break;
					}
				}
				if(f==1) break;
			}
			a[1]=i;
		}
	}
	else if(k==2){
		for(i=1;i<=w[1];i+=1){
			for(int ii=1;ii<=w[2];ii+=1){
				f=0;
				while(1){
					for(j=1;j<=n;j+=1){
						a[c[j]]+=d[j];
						cnt+=1;
						if(a[c[j]]>w[c[j]] || a[c[j]]<1){
							f=1;
							break;
						}
					}
					if(f==1) break;
				}
				a[2]=ii;
			}
			a[1]=i;
		}
	}
	printf("%d",cnt);
	return 0;
}
