#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long step=0;
int c[N],d[N],w[N];
int k,n;
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	bool flag=true;
	if(k==1){
	for(int i=1;i<=n;i++)
	{
		int l=1;
		for(int j=1;;j++){
			if(j==n+1) j=1;
			int s=l;
			if(j!=1&&s==i){
				flag=false;
				break;
			}
			s+=c[j]+d[j];
			if(s<=w[1]&&s>=1){
				l=s;
				step++;
			}
			else break;
		}
	}
	}
	if(k==2){
		for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++){
			int l=i,r=j;
			for(int x=1;;x++)
			{
			    step++;
			   	if(x==n+1) x=1;
			   	int l2=l,r2=r;
			   	if(x!=1&&l2==i&&r2==j){
				    flag=false;
					break;
				}
			   	if(c[x]==1) l2+=d[x];
			   	else r2+=d[x];
			   	if(l2>=1&&l2<=w[1]&&r2>=1&&r2<=w[2]) l=l2,r=r2;
				else break;
			}
		}
	}
	if(((k==1||k==2)&&!flag)||k>=3) cout<<"-1"<<endl;
	else if((k==1||k==2)&&flag)cout<<step<<endl;
	return 0;
}
