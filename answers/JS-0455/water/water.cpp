#include<cstdio>
#include<algorithm>
using namespace std;
int cccc(int a,int b){
	int aa,bb;
	aa=max(a,b);
	bb=a+b-aa;
	while(1){
		if(aa==bb) return aa;
		else{
			aa-=bb;
			if(aa<bb) swap(aa,bb);
		}
	}
}
int main(){	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int f,n,m,i,j,xxx,yyy,zzz,p[100005],q[100005],qq[100005],d,cnt;
	d=f=xxx=yyy=zzz=cnt=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i+=1){
		p[i]=0;
		q[i]=1;
	}
	for(i=1;i<=m;i+=1) p[i]=1;
	for(i=1;i<=n;i+=1){
		scanf("%d",&d);
		if(d==0){
			cnt+=1;
			qq[cnt]=i;
		}
		else{
			q[i]=q[i]*d;
			for(j=1;j<=d;j+=1){
				scanf("%d",&f);
				p[f]=p[f]*q[i]+p[i]*q[f];
				q[f]=q[f]*q[i];
			}
			p[i]=0;
			q[i]=1;
		}
	}
	for(i=1;i<=cnt;i+=1){
		xxx=cccc(p[qq[i]],q[qq[i]]);
		yyy=p[qq[i]]/xxx;
		zzz=q[qq[i]]/xxx;
		printf("%d %d\n",yyy,zzz);
	}
	return 0;
}
