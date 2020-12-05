#include<bits/stdc++.h>
using namespace std;
char chll;bool flagp=0;int tppop;
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
int a[3][500];
int tp[3];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;sc(n),sc(m);int x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)sc(a[i-1][j]);
	int w=a[0][1],v=a[1][1];
	for(int i=m;i>1;i--){
		a[2][m-i+1]=a[0][i];tp[0]++;
		
	}
	int q=1,s=m,e=m-1;
	for(int i=m-1;i>=1;i--)if(a[2][i]==w){tp[1]++;a[0][++q]=w;e--;
	}else break;
	
	for(int i=m;i>1;i--){
		e++,a[2][e]=a[1][i];tp[2]++;
		s--;
	}
	cout<<tp[0]+tp[1]+tp[2]+e<<endl;
	for(int i=1;i<=tp[0];i++)cout<<"1"<<" "<<3<<endl;
	for(int i=1;i<=tp[1];i++)cout<<3<<" "<<1<<endl;
	for(int i=1;i<=tp[2];i++)cout<<2<<" "<<3<<endl;
	for(int i=e;i>=1;i--)
	{
		cout<<3<<" "<<a[2][i]<<endl;
	}
	return 0;
}
