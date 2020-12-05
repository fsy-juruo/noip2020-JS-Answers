#include<bits/stdc++.h>
using namespace std;
long int n;
int k;
long long w[10]={ };
long  int nn[500000][2];
int step[100]={ };
int ans=0;
bool tf=true;
void as()
{
	int i=0;
	step[0]++;
	while (step[i]==10)
	{
		step[i]=0;
		step[i+1]++;
		i++;
	}
	if(step[ans]==0) ans++;
}
int main()
{
	int y=0;//指针 
	ifstream fin;
	fin.open("walk.in");
	fin>>n>>k;
	for(int i=0;i<k;i++)
	{
		fin>>w[i];
	}
	for (int i=0;i<n;i++)
	{
		fin>>nn[i][1]>>nn[i][2];
		nn[i][1]--;
	}
	if(k==1)
	{
		int z;//坐标 
		for(int i=0;i<w[0];i++)
		{
			z=i;
			while(true)
			{
				
				z+=nn[y][2];
				if(z<0||z>=w[0]) break;
				else as();
				y++;
			if(y==n) 
			{
				if(z==i) {
					tf=false;break;
				}
				else
				{
					y=0;
				}
			}
			}
		}
	}//1
	if(k==2)
	{
		int z[2];//坐标 
		for(int j=0;j<w[1];j++)
		{
			for(int i=0;i<w[0];i++)
		{
			z[0]=i;z[1]=j;
			y=0;
			while(true)
			{
				
				z[nn[y][1]]+=nn[y][2];
				as();
				if(z[nn[y][1]]<0||z[nn[y][1]]>=w[nn[y][1]]) break;
			 
				y++;
			if(y==n) 
			{
				if(z[0]==i&&z[1]==j) {
					tf=false;break;
				}
				else
				{
					y=0;
				}
			}
			}
		}
		}
	}//2
	if(k==3)
	{
		int z[3];//坐标 
		for(int p=0;p<w[2];p++)
		{
			for(int j=0;j<w[1];j++)
		{
			for(int i=0;i<w[0];i++)
		{
			z[0]=i;z[1]=j;z[2]=p;
			y=0;
			while(true)
			{
				
				z[nn[y][1]]+=nn[y][2];
				as();
				if(z[nn[y][1]]<0||z[nn[y][1]]>=w[nn[y][1]]) break;
			 
				y++;
			if(y==n) 
			{
				if(z[0]==i&&z[1]==j&&z[2]==p) {
					tf=false;break;
				}
				else
				{
					y=0;
				}
			}
			}
		}
		}
		}
	}//3
	if(k==4)
	{
		int z[4];//坐标 
		for(int h=0;h<w[3];h++)
		{
			for(int p=0;p<w[2];p++)
		{
			for(int j=0;j<w[1];j++)
		{
			for(int i=0;i<w[0];i++)
		{
			z[0]=i;z[1]=j;z[2]=p;z[3]=h;
			y=0;
			while(true)
			{
				
				z[nn[y][1]]+=nn[y][2];
				as();
				if(z[nn[y][1]]<0||z[nn[y][1]]>=w[nn[y][1]]) break;
			 
				y++;
			if(y==n) 
			{
				if(z[0]==i&&z[1]==j&&z[2]==p&&z[3]==h) {
					tf=false;break;
				}
				else
				{
					y=0;
				}
			}
			}
		}
		}
		}
		}
		
	}//4
	if(k==5)
	{
		int z[5];//坐标 
		for(int g=0;g<w[4];g++)
		{
			for(int h=0;h<w[3];h++)
		{
			for(int p=0;p<w[2];p++)
		{
			for(int j=0;j<w[1];j++)
		{
			for(int i=0;i<w[0];i++)
		{
			z[0]=i;z[1]=j;z[2]=p;z[3]=h;z[4]=g;
			y=0;
			while(true)
			{
				
				z[nn[y][1]]+=nn[y][2];
				as();
				if(z[nn[y][1]]<0||z[nn[y][1]]>=w[nn[y][1]]) break;
			 
				y++;
			if(y==n) 
			{
				if(z[0]==i&&z[1]==j&&z[2]==p&&z[3]==h&&z[4]==g) {
					tf=false;break;
				}
				else
				{
					y=0;
				}
			}
			}
		}
		}
		}
		}
		}
		
	}//5
	//
	//
	//
	ofstream fout;
	fout.open("walk.out");
	if(tf==0) fout<<-1;
	else
	{
		for(int i=ans;i>=0;i--)
	{
		fout<<step[i];
	}
	}
	
}
