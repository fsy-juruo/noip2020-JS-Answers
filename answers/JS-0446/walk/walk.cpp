#include<bits/stdc++.h>
using namespace std;
long long modd=1e9+7;
long long n,k,w[1000010],c[1000010],d[100010],dd[100010],dd1[100010],dd2[100010],dd3[100010];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    cin>>w[i];
    for(int i=1;i<=n;i++)
    {
    	cin>>c[i]>>d[i];
	}
	if(k==1)
	{
		long long summ=0,minn=0,maxx=0,qw=0;
		for(int i=1;i<=n;i++)
		{
			qw+=d[i];
			dd[i]=dd[i-1]+d[i];
			minn=min(minn,dd[i]);
			maxx=max(maxx,dd[i]);
		}
		if(qw==0) {
			cout<<-1;return 0;
		}
		for(long long i=1;i<=w[1];i++)
		{
			if(qw<0)
			{
				qw=-qw;
				minn=-maxx;
				for(int i=1;i<=n;i++)
		        dd[i]=-dd[i];
			}		
			if(qw>0)
			{
				if(minn+i<0)
				{
					for(int j=1;j<=n;j++)
					if(dd[j]+i==0)
					{
						summ+=dd[j];
						break;
					}
				}
				else
				{
					long long t=(w[1]-i)/qw;
			        summ+=t*n%modd;
			        long long x=(w[1]-i)/qw*qw+i;
			        x=w[1]-x;
			        for(int j=1;j<=n;j++)
			        if(dd[j]>x)
			        {
			    	    summ+=dd[j];
			        	break;
				    }
				}	  
			}
		}
		cout<<summ;
		return 0;
	}
	else
	{
	if(n<=100&&k==3)
	{
		long long summ=0,qw1=0,qw2=0,qw3=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==1){
				qw1+=d[i];
			}
			if(c[i]==2){
				qw2+=d[i];
			}
			if(c[i]==3){
				qw3+=d[i];
			}
		}
		if(qw1==0&&qw2==0&&qw3==0) {
			cout<<-1;return 0;
		}
		for(long long i=1;i<=w[1];i++)
		for(long long j=1;j<=w[2];j++)
		for(long long k=1;k<=w[3];k++)
		{
			int qq1=i,qq2=j,qq3=k,cnt=1;
			while(qq1>0&&qq1<=w[1]&&qq2>0&&qq2<=w[2]&&qq3>0&&qq3<=w[3])
			{
				cnt++;
				summ++;
				if(cnt==n+1){
					cnt=1;
			    }
				if(c[cnt]==1){
			    	qq1+=d[cnt];
			    }
			    if(c[cnt]==2){
			    	qq2+=d[cnt];
		    	}
		    	if(c[cnt]==3){
		    		qq3+=d[cnt];
		    	}
			}
			summ=summ%modd;
		}
		cout<<summ;
		return 0;
	}
	else
	{
		if(n<=100&&k==2)
		{
		long long summ=0,qw1=0,qw2=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==1){
				qw1+=d[i];
			}
			if(c[i]==2){
				qw2+=d[i];
			}
		}
		if(qw1==0&&qw2==0) {
			cout<<-1;return 0;
		}
		for(long long i=1;i<=w[1];i++)
		for(long long j=1;j<=w[2];j++)
		{
			int qq1=i,qq2=j,qq3=k,cnt=1;
			while(qq1>0&&qq1<=w[1]&&qq2>0&&qq2<=w[2])
			{
				summ++;
				if(cnt==n+1){
					cnt=1;
			    }
				if(c[cnt]==1){
			    	qq1+=d[cnt];
			    }
			    if(c[cnt]==2){
			    	qq2+=d[cnt];
		    	}
			}
			summ=summ%modd;
		}
		cout<<summ;
		return 0;
	}
	else
	{
		if(k==4)
	{
		long long summ=0,qw1=0,qw2=0,qw3=0,qw4=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==1){
				qw1+=d[i];
			}
			if(c[i]==2){
				qw2+=d[i];
			}
			if(c[i]==3){
				qw3+=d[i];
			}
			if(c[i]==4){
				qw4+=d[i];
			}
		}
		if(qw1==0&&qw2==0&&qw3==0&&qw4==0) {
			cout<<-1;return 0;
		}
		for(long long i=1;i<=w[1];i++)
		for(long long j=1;j<=w[2];j++)
		for(long long k=1;k<=w[3];k++)
		for(long long l=1;l<=w[4];l++)
		{
			int qq1=i,qq2=j,qq3=k,qq4=l,cnt=1;
			while(qq1>0&&qq1<=w[1]&&qq2>0&&qq2<=w[2]&&qq3>0&&qq3<=w[3]&&qq4>0&&qq4<=w[4])
			{
				cnt++;
				summ++;
				if(cnt==n+1){
					cnt=1;
			    }
				if(c[cnt]==1){
			    	qq1+=d[cnt];
			    }
			    if(c[cnt]==2){
			    	qq2+=d[cnt];
		    	}
		    	if(c[cnt]==3){
		    		qq3+=d[cnt];
		    	}
		    	if(c[cnt]==4){
				qq4+=d[cnt];
			}
			}
			summ=summ%modd;
		}
		cout<<summ;
		return 0;
	}
	else
	if(k==5)
	{
		long long summ=0,qw1=0,qw2=0,qw3=0,qw4=0,qw5=0;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==1){
				qw1+=d[i];
			}
			if(c[i]==2){
				qw2+=d[i];
			}
			if(c[i]==3){
				qw3+=d[i];
			}
			if(c[i]==4){
				qw4+=d[i];
			}
			if(c[i]==5){
				qw5+=d[i];
			}
		}
		if(qw1==0&&qw2==0&&qw3==0&&qw4==0&&qw5==0) {
			cout<<-1;return 0;
		}
		for(long long i=1;i<=w[1];i++)
		for(long long j=1;j<=w[2];j++)
		for(long long k=1;k<=w[3];k++)
		for(long long l=1;l<=w[4];l++)
		for(long long p=1;p<=w[5];p++)
		{
			int qq1=i,qq2=j,qq3=k,qq4=l,qq5=p,cnt=1;
			while(qq1>0&&qq1<=w[1]&&qq2>0&&qq2<=w[2]&&qq3>0&&qq3<=w[3]&&qq4>0&&qq4<=w[4]&&qq5>0&&qq5<=w[5])
			{
				summ++;
				cnt++;
				if(cnt==n+1){
					cnt=1;
			    }
				if(c[cnt]==1){
			    	qq1+=d[cnt];
			    }
			    if(c[cnt]==2){
			    	qq2+=d[cnt];
		    	}
		    	if(c[cnt]==3){
		    		qq3+=d[cnt];
		    	}
		    	if(c[cnt]==4){
				qq4+=d[cnt];
			}
				if(c[cnt]==5){
				qq5+=d[cnt];
			}
			}
			}
			summ=summ%modd;
		cout<<summ;
		return 0;
	}
	}
	
	}
	
    }
	cout<<-1;return 0;
}
/*
5 4
 6 8 6 5
 3 1
 2 1
 1 1
 2 1
 2  1
*/
