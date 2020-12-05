#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char w=0,ch=0;
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int bal[55][405];
bool vis[55],kh[55];
int n,m;
void deal(){
	int now;/*
	for(int i=1;i<=n;i++)if(vis[i]==false)vis[i]=true,now=i;
	for(int i1=1;i1<=n+1;i1++)//枚举列数 
	{
		int first=0,cnt=0;
		for(int i2=1;bal[i1][i2]!=0;i2++)//枚举球 
		{
			if(bal[i1][i2]==now)cnt++;
			if(bal[i1][i2]==now&&cnt=1)first=i2,
		}
		if(first!=0){
			int kong;
			for(int i2=1;i2<=n+1;i2++)if(bal[i2][1]==0)kong=i2,i2=100;//枚举空行 
			//step1
			int workh;
			for(int i2=1;i2<=n+1;i2++)if(kh[i2]!=0)workh=i2,i2=100;
			
			for(int i2=1;i2<=cnt;i2++)
			{
				cout<<workh<<" "<<kh<<endl;
				bal[kh][i2]=bal[workh][m+1-i2];
				bal[workh][m+1-i2]=0;
				
				
			}
			//step2
			for(int i2=1;i2<=first;i2++)
			{
				
				if(bal[kh][i2+cnt]!=now)cout<<i1<<" "<<kh<<endl,
				    bal[kh][i2+cnt]=bal[i1][m+1-i2];
				
				else cout<<i1<<" "<<workh<<endl,
					bal[workh][m-cnt+i2]=bal[i1][m+1-i2]
				bal[i1][m+1-i2]=0;
				
				
			}
			//step3
			int ji=0;
			for(int i2=m;i2>=1;i2--)
			{
				if(bal[kh][i2]==0)continue;
				ji++;
				cout<<kh<<" "<<i1<<endl;
				
				    bal[i1][first+ji]=bal[kh][i2];
				    bal[kh][i2]=0;
				
				
			}
			//step4
			int ji=0;
			for(int i2=m;i2>=1;i2--)
			{
				if(bal[kh][i2]==0)continue;
				ji++;
				cout<<workh<<" "<<kh<<endl;
				
				    bal[kh][ji]=bal[workh][i2];
				    bal[work][i2]=0;
				
				
			}
			
			
			
			
		}
		
		
		
	}
	
	*/
	
	
	
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)bal[i][j]=read();
	deal();
	cout<<"CCF's ball's difficult and complicated!!!"<<endl;
	return 0;
}

