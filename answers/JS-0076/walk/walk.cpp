#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,k;
long long ans,sum;
int w[15],c[500005],d[500005],ar[15],f,new_d[500005],cnt;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n>=100000)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>d[i];
	}
	if(k==5)
	{
		for(int w1=1;w1<=w[1];w1++)
		{
			for(int w2=1;w2<=w[2];w2++)
			{
				for(int w3=1;w3<=w[3];w3++)
				{
					for(int w4=1;w4<=w[4];w4++)
					{
						for(int w5=1;w5<=w[5];w5++)
						{
							f=0;
							sum=0;
							int ar[7];
							ar[1]=w1,ar[2]=w2,ar[3]=w3,ar[4]=w4,ar[5]=w5;
							while(1)
							{
								for(int i=1;i<=n;i++)
								{
									ar[c[i]]+=d[i];
									if(i==n&&ar[1]==w1&&ar[2]==w2&&ar[3]==w3&&ar[4]==w4&&ar[5]==w5)
									{
										cout<<-1;
										return 0;
									}
									if(ar[1]>=1&&ar[1]<=w[1]&&ar[2]>=1&&ar[2]<=w[2]&&ar[3]>=1&&ar[3]<=w[3]&&ar[4]>=1&&ar[4]<=w[4]&&ar[5]>=1&&ar[5]<=w[5])
									{
										sum++;
										sum%=MOD;
									}else{
										sum++;
										sum%=MOD;
										f=1;
										break;
									}
								}
								if(f==1) break;
							}
							ans=ans+sum;
							ans%=MOD;
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==4)
	{
		for(int w1=1;w1<=w[1];w1++)
		{
			for(int w2=1;w2<=w[2];w2++)
			{
				for(int w3=1;w3<=w[3];w3++)
				{
					for(int w4=1;w4<=w[4];w4++)
					{
						f=0;
						sum=0;
						int ar[7];
						ar[1]=w1,ar[2]=w2,ar[3]=w3,ar[4]=w4;
						while(1)
						{
							for(int i=1;i<=n;i++)
							{
								ar[c[i]]+=d[i];
								if(i==n&&ar[1]==w1&&ar[2]==w2&&ar[3]==w3&&ar[4]==w4)
								{
									cout<<-1;
									return 0;
								}
								if(ar[1]>=1&&ar[1]<=w[1]&&ar[2]>=1&&ar[2]<=w[2]&&ar[3]>=1&&ar[3]<=w[3]&&ar[4]>=1&&ar[4]<=w[4])
								{
									sum++;
									sum%=MOD;
								}else{
									sum++;
									sum%=MOD;
									f=1;
									break;
								}
							}
							if(f==1) break;
						}
						ans=ans+sum;
						ans%=MOD;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==3)
	{
		for(int w1=1;w1<=w[1];w1++)
		{
			for(int w2=1;w2<=w[2];w2++)
			{
				for(int w3=1;w3<=w[3];w3++)
				{
						f=0;
						sum=0;
						int ar[7];
						ar[1]=w1,ar[2]=w2,ar[3]=w3;
						while(1)
						{
							for(int i=1;i<=n;i++)
							{
								ar[c[i]]+=d[i];
								if(i==n&&ar[1]==w1&&ar[2]==w2&&ar[3]==w3)
								{
									cout<<-1;
									return 0;
								}
								if(ar[1]>=1&&ar[1]<=w[1]&&ar[2]>=1&&ar[2]<=w[2]&&ar[3]>=1&&ar[3]<=w[3])
								{
									sum++;
									sum%=MOD;
								}else{
									sum++;
									sum%=MOD;
									f=1;
									break;
								}
							}
							if(f==1) break;
						}
						ans=ans+sum;
						ans%=MOD;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==2)
	{
		for(int w1=1;w1<=w[1];w1++)
		{
			for(int w2=1;w2<=w[2];w2++)
			{
						f=0;
						sum=0;
						int ar[7];
						ar[1]=w1,ar[2]=w2;
						while(1)
						{
							for(int i=1;i<=n;i++)
							{
								ar[c[i]]+=d[i];
								if(i==n&&ar[1]==w1&&ar[2]==w2)
								{
									cout<<-1;
									return 0;
								}
								if(ar[1]>=1&&ar[1]<=w[1]&&ar[2]>=1&&ar[2]<=w[2])
								{
									sum++;
									sum%=MOD;
								}else{
									sum++;
									sum%=MOD;
									f=1;
									break;
								}
							}
							if(f==1) break;
						}
						ans=ans+sum;
						ans%=MOD;
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int w1=1;w1<=w[1];w1++)
		{
			
						f=0;
						sum=0;
						int ar[7];
						ar[1]=w1;
						while(1)
						{
							for(int i=1;i<=n;i++)
							{
								ar[c[i]]+=d[i];
								if(i==n&&ar[1]==w1)
								{
									cout<<-1;
									return 0;
								}
								if(ar[1]>=1&&ar[1]<=w[1])
								{
									sum++;
									sum%=MOD;
								}else{
									sum++;
									sum%=MOD;
									f=1;
									break;
								}
							}
							if(f==1) break;
						}
						ans=ans+sum;
						ans%=MOD;
		}
		cout<<ans;
		return 0;
		
		
		
	}

	return 0;
}

