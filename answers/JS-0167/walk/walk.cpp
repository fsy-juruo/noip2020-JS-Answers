#include<bits/stdc++.h>
using namespace std;
int n,k,n1,n2,n3,n4,n5;
int modd=1000000007;
int weizhi[10];
int w[500010][2];
int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return f*s;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	if(k==5)
	{
		int ans=0;
		n1=read();
		n2=read();
		n3=read();
		n4=read();
		n5=read();
		for(int i=1;i<=n;i++)
		{
			w[i][0]=read();
			w[i][1]=read();
		}
		for(int a=1;a<=n1;a++)
		{
			for(int b=1;b<=n2;b++)
			{
				for(int c=1;c<=n3;c++)
				{
					for(int d=1;d<=n4;d++)
					{
						for(int e=1;e<=n5;e++)
						{
							weizhi[1]=a;
							weizhi[2]=b;
							weizhi[3]=c;
							weizhi[4]=d;
							weizhi[5]=e;
							for(int z=1;;z++)
							{
								if(z==n+1)
								{
									z=1;
								}
								weizhi[w[z][0]]+=w[z][1];
								ans++;
								ans=ans%modd;
								if(w[z][0]==1 && (weizhi[w[z][0]]<0 || weizhi[w[z][0]]>n1))
								{
									break;
								}
								else if(w[z][0]==2 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n2))
								{
									break;
								}
								else if(w[z][0]==3 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n3))
								{
									break;
								}
								else if(w[z][0]==4 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n4))
								{
									break;
								}
								else if(w[z][0]==5 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n5))
								{
									break;
								}
							}
						}
					}
				}
			}
		}
		write(ans%modd);
	}
	else if(k==4)
	{
		int ans=0;
		n1=read();
		n2=read();
		n3=read();
		n4=read();
		for(int i=1;i<=n;i++)
		{
			w[i][0]=read();
			w[i][1]=read();
		}
		for(int a=1;a<=n1;a++)
		{
			for(int b=1;b<=n2;b++)
			{
				for(int c=1;c<=n3;c++)
				{
					for(int d=1;d<=n4;d++)
					{
							weizhi[1]=a;
							weizhi[2]=b;
							weizhi[3]=c;
							weizhi[4]=d;
							for(int z=1;;z++)
							{
								if(z==n+1)
								{
									z=1;
								}
								weizhi[w[z][0]]+=w[z][1];
								ans++;
								ans=ans%modd;
								if(w[z][0]==1 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n1))
								{
									break;
								}
								else if(w[z][0]==2 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n2))
								{
									break;
								}
								else if(w[z][0]==3 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n3))
								{
									break;
								}
								else if(w[z][0]==4 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n4))
								{
									break;
								}
							}
					}
				}
			}
	}
	write(ans%modd);
}
	else if(k==3)
	{
		int ans=0;
		n1=read();
		n2=read();
		n3=read();
		for(int i=1;i<=n;i++)
		{
			w[i][0]=read();
			w[i][1]=read();
		}
		for(int a=1;a<=n1;a++)
		{
			for(int b=1;b<=n2;b++)
			{
				for(int c=1;c<=n3;c++)
				{
					
							weizhi[1]=a;
							weizhi[2]=b;
							weizhi[3]=c;
							for(int z=1;;z++)
							{
								if(z==n+1)
								{
									z=1;
								}
								weizhi[w[z][0]]+=w[z][1];
								ans++;
								ans=ans%modd;
								if(w[z][0]==1 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n1))
								{
									break;
								}
								else if(w[z][0]==2 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n2))
								{
									break;
								}
								else if(w[z][0]==3 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n3))
								{
									break;
								}
								
							}
				}
			}
	}
	write(ans%modd);
}	else if(k==2)
	{
		int ans=0;
		n1=read();
		n2=read();
		for(int i=1;i<=n;i++)
		{
			w[i][0]=read();
			w[i][1]=read();
		}
		for(int a=1;a<=n1;a++)
		{
			for(int b=1;b<=n2;b++)
			{
					
							weizhi[1]=a;
							weizhi[2]=b;
							for(int z=1;;z++)
							{
								if(z==n+1)
								{
									z=1;
								}
								weizhi[w[z][0]]+=w[z][1];
								ans++;
								ans=ans%modd;
								if(w[z][0]==1 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n1))
								{
									break;
								}
								else if(w[z][0]==2 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n2))
								{
									break;
								}
								
							}
			}
	}
	write(ans%modd);
}	else if(k==1)
	{
		int ans=0;
		n1=read();
		for(int i=1;i<=n;i++)
		{
			w[i][0]=read();
			w[i][1]=read();
		}
		for(int a=1;a<=n1;a++)
		{
					
							weizhi[1]=a;
							for(int z=1;;z++)
							{
								if(z==n+1)
								{
									z=1;
								}
								weizhi[w[z][0]]+=w[z][1];
								ans++;
								ans=ans%modd;
								if(w[z][0]==1 && (weizhi[w[z][0]]<1 || weizhi[w[z][0]]>n1))
								{
									break;
								}
								
							}
	}
	write(ans%modd);
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			int x;
			x=read();
		}
		for(int i=1;i<=n;i++)
		{
			int x,y;
			x=read();
			y=read();
		}
		write(-1);
	}
	return 0;
}

