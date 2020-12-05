#include<bits/stdc++.h>
using namespace std;
int t,a[10000001],ans[6],x[30],y[30],xx,yy;
string s[5];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		cin>>s[i];
	for(register int i=1;i<=t;++i)
	{
		memset(a,0,sizeof(a));
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		int b=1;
		while(a[b]>=1 && a[b]<=26)
		{
			a[b]=s[i][b-1]-96;
			b++;			
		}
		b=b-1;
		for(register int j=1;j<=b-2;++j)
		{
			ans[i]+=b-j-1;
			x[a[j]]++;
			for(register int m=1;m<=26;++m)
				if (x[m]%2==1)
					xx++;
			for(register int k=1;k<=b-j-1;++k)
			{
				y[a[k]]++;
				for(register int n=1;n<=26;++n)
					if (y[n]%2==1)
						yy++;
				if (yy<xx)
					ans[i]--;
			}
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}

