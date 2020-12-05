#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
void read(int &x)
{
	char c;int s=0,f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f*=-1;
	s=(c&15);while((c=getchar())>='0'&&c<='9')s=s*10+(c&15);
	x=s*f;
}
int n,m,i,j,k,a[55][405],tp[55],ct[55],sum[55],lst,v1[55],v2[55];
vector<pair<int,int> > ans;
void upd(int x,int y)
{
	ans.push_back(make_pair(x,y));
	a[y][++tp[y]]=a[x][tp[x]--];
}
void fnd_not(int x)
{
	int i;
	fz1(i,n+1)if(!v2[i]&&i!=x){
		return;
	}
}
void dec(int x)
{
	int i;
	fz1(i,n+1)if(!v2[i]&&i!=x&&tp[i]<m){
		upd(x,i);return;
	}
	upd(x,lst);
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);lst=n+1;
	fz1(i,n){
		tp[i]=m;
		fz1(j,m){
			read(a[i][j]);
		}
	}
	v2[lst=n+1]=1;
	int _;fz1(_,n-1){
		fz1(j,n){
			sum[j]=0;
		}
		fz1(j,n+1){
			fz1(k,tp[j]-1){
//				if(a[j][k]!=a[j][k+1]){
					sum[a[j][k]]+=(tp[j]-k);
//				}
			}
		}
		int t=0;
		fz1(i,n)if(!v1[i]&&(!t||sum[i]<sum[t])){
			t=i;
		}
//		for(;;){
			fd1(i,m){
				fz1(j,n)if(!v2[j]&&tp[j]>=i&&a[j][i]==t){
					while(tp[j]>i){
						dec(j);
					}
					if(tp[lst]&&a[lst][tp[lst]]!=t){
						int a1=0,a2=0;
						fz1(k,n)if(!v2[k]&&k!=j){
							a1=k;if(tp[k]<m)a2=k;
						}
						if(!a2){
							a2=a1;
							upd(a2,lst);
						}
						upd(j,a2);
						while(tp[lst]&&a[lst][tp[lst]]!=t) upd(lst,j);
						upd(a2,lst);
					}
					else upd(j,lst);
//					break;
				}
//				if(j<=n)break;
			}
//			if(i==0)break;
//		}
		v1[t]=1;t=0;
		fz1(i,n)if(!v2[i]&&(!t||tp[i]<tp[t])){
			t=i;
		}
		v2[t]=1;
		fz1(i,n)while(!v2[i]&&tp[i]<m) upd(t,i);
		lst=t;
	}
	printf("%d\n",ans.size());
	fz0k(i,ans.size()){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
