#include<bits/stdc++.h>
using namespace std;

char ch[100004];
int a[30];
int b1[10002];
int b2[10001];
int pp[1001][1001];

int pd(string ss,int x)
{
//	cout<<ss<<" "<<x<<endl;
	int n=ss.size();
	if (x%n>0) return -1;
	for (int i=1;i<=x;i++)
	{
		int t=i%n;
		if (t==0) t=n;
	//	cout<<"!! "<<i<<" "<<t<<" "<<ch[i]<<" "<<ss[t-1]<<endl;
		if (ch[i]!=ss[t-1]) return -1;
	}
	return 1;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while (T)
	{
		memset(a,0,sizeof(a));
		T--;
		scanf("%s",ch+1);
		int n=strlen(ch+1);
		string sa="";
		for (int i=1;i<=n;i++)
		{
			int c;
			c=ch[i]-'a'+1;
			a[c]++;
			int p=0;
			for (int j=1;j<=26;j++)
			{
				if (a[j]%2==1) p++;
			}
		//	cout<<i<<"   "<<p<<endl;
			b1[i]=p;
		}
		memset(a,0,sizeof(a));
		for (int i=n;i>=0;i--)
		{
			int c;
			c=ch[i]-'a'+1;
			a[c]++;
			int p=0;
			for (int j=1;j<=26;j++)
			{
				if (a[j]%2==1) p++;
			}
			b2[i]=p;
		//	cout<<i<<"  "<<b2[i]<<endl;			
		}
		long long ans=0;
		for (int i=n;i>=1;i--)
		{
			for (int j=1;j<i;j++)
			{
				pp[i][j]=pp[i][j-1];
				if (b1[j]<=b2[i]) pp[i][j]++; 
			//	cout<<i<<" "<<j<<" "<<pp[i][j]<<endl;
			}
		}
	//	cout<<n<<endl;
		for (int i=1;i<=n;i++)
		{
			sa=sa+ch[i];
			string sc="";
			for (int j=n;j>=i+1;j--)
			{
				sc=ch[j]+sc;//cout<<i<<" "<<j<<" "<<b1[i]<<" "<<b2[j]<<endl;
				//if (b1[i]>b2[j]) continue;
			//	cout<<i<<" "<<j<<" "<<sa<<" "<<ans<<endl;
				if (pd(sa,j-1)==1) ans=ans+pp[j][i-1];
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

