#include<bits/stdc++.h>
using namespace std;


int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	long long n,m,fmj,fzj,q,fmz,fzz;
	int fm[100002]={1},fz[100002]={0};
	int p[100002];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	fm[i]=1;
	fz[i]=0;}
	for(int i=1;i<=m;i++)
	{
	
		fz[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		for(int j=1;j<=p[i];j++)
		{
			cin>>q;
			fmj=p[i]*fm[i]*fm[q];
			fzj=fz[i]*fm[q];
			fmz=fm[q]*p[i]*fm[i];
			fzz=fz[q]*p[i]*fm[i]+fzj;
			do{
				if(fmz%2==0&&fzz%2==0)
				{
					fmz/=2;
					fzz/=2;
				}				
				if(fmz%3==0&&fzz%3==0)
				{
					fmz/=3;
					fzz/=3;}
							
				if(fmz%5==0&&fzz%5==0)
				{
					fmz/=5;
					fzz/=5;
				}			
				if(fmz%7==0&&fzz%7==0)
				{
					fmz/=7;
					fzz/=7;
				}
			}while(fmz%2==0&&fzz%2==0||fmz%3==0&&fzz%3==0||fmz%5==0&&fzz%5==0||fmz%7==0&&fzz%7==0);
			fm[q]=fmz;
			fz[q]=fzz;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		cout<<fz[i]<<" "<<fm[i]<<endl;
	}
	return 0;
	
}
