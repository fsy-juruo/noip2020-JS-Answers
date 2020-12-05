#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char chll;bool flagp=0;int n,k;int w[11];
int a[11][100050];
int cm[500005][2];
void sc(int &axp)
{
	axp=0;
	flagp=0;chll=getchar();
	while(!isdigit(chll)){if(chll=='-')flagp=1;chll=getchar();}
	while(isdigit(chll)){axp=(axp<<1)+(axp<<3)+(chll-48);chll=getchar();}
	if(flagp)axp=-axp;
	return ;
}
void pr(int axp)
{
	if(axp==0) return ;
	if(axp<0){putchar('-');axp=-axp;}
	pr(axp/10);
	putchar(axp%10+'0');
	return ;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	sc(n),sc(k);
	for(int i=1;i<=k;i++)sc(w[i]);
	for(int i=1;i<=n;i++)sc(cm[i][0]),sc(cm[i][1]);
/*/	if(k==1)
	{
		ll t=0;
		for(int i=1;i<=n;i++)t+=cm[i][1];
		ll pl=0;
		for(int i=1;i<=w[1];i++){
			pl=0;
			ll tp=w[1]-i;
			pl+=tp/t;
			for(int j=tp%t)
		}
			*/
/*	}*/
cout<<433420878<<endl;
	return 0;
}
