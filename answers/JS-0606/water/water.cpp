#include<bits/stdc++.h>
using namespace std;
int p[100010],q[100010],p1[10010],q1[100010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    	p[i]=1,q[i]=1,p1[i]=1,q1[i]=1;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	scanf("%d",&x);
    	if(x){
		   for(int j=1;j<=x;j++)
    	  {
    		int a;
    		scanf("%d",&a);
    		if(p[a]){
    		p1[a]=p[a]*q[i]*x+p[i]*q[a];
    		q1[a]=q[a]*q[i]*x;
    		p[a]=p1[a];
    		q[a]=q1[a];
			}
    		else {
    			p[a]=p[i];
    			q[a]=q[i]*x;
			     }
		  }
		  p[i]=0,q[i]=0,p1[i]=0,q1[i]=0;
		}
		else continue;
	}
	for(int i=1;i<=n;i++)
	{
		int flag;
		if(p[i])
			for(int j=1;j<=p[i];j++)
		    {
		    	if(p[i]%j==0&&q[i]%j==0)flag=j;
			}
		p[i]/=flag,q[i]/=flag;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i])printf("%d %d\n",p[i],q[i]);
	}
	return 0;
}
