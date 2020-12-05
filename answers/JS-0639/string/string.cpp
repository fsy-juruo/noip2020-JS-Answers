#include <bits/stdc++.h>
using namespace std;

char s[1003];
int sk[27];

int main()
{
	long long t,i,j,i1,k,bs,i2,f1,f2,i3,n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(i1=1;i1<=t;i1++)
	{
		bs=0;
	
		memset(sk,0,sizeof(sk));
		cin>>s;
		n=strlen(s);
		for(i=0;i<=n-3;i++)
			for(j=i+1;j<=n-2;j++)
			{
					memset(sk,0,sizeof(sk));
					f1=0;
				f2=0;
					k=j+1; 
				for(i2=0;i2<=i;i2++)
				{
					sk[int(s[i2])-96]++;
				}
				for(i3=1;i3<=26;i3++)
					{
						if(sk[i3]%2==1)
						f1++;
					}
				memset(sk,0,sizeof(sk));
				for(i2=k;i2<=n-1;i2++)
				{
					sk[int(s[i2])-96]++;
			
				}
				for(i3=1;i3<=26;i3++)
					{
						if(sk[i3]%2==1)
						f2++;
					}
				if(f1<=f2) 
				{
					bs++;
				}
			}
			cout<<bs<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
