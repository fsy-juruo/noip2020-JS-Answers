#include<bits/stdc++.h>
using namespace std;
int f_read(void)
{
	char c;
	while(!('0'<=c&&c<='9'))
		c=getchar();
	int res=0,t=1;
	if(c=='-')
	{
		t=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int TEST,n;
long long ans;
string s,c,sam,a;
char ch;
int f(string k)
{
	map<char,int> cnt;
	int ret=0;
	cnt.clear();
	for(int i=0;i<k.size();i++)
		cnt[k[i]]++;
	for(map<char,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		ret+=((it->second)%2);
	return ret;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	TEST=f_read();
	while(TEST--)
	{
		n=0;
		ans=0;
		cin>>s;
		n=s.size();
		s=' '+s;
//		cout<<"CHECK 1\n";
		for(int i=1;i<=n;i++)
			for(int j=1;j*j<=(n-i);j++)
			{
//				cout<<"CHECK 2\n";
				if((n-i)%j!=0)
					continue;
//				cout<<"CHECK 3\n";
				sam="";
				bool ok=true;
//				cout<<"CHECK 4\n";
				for(int k=1;k<=j;k++)
					sam[k]=s[k];
//				cout<<"CHECK 5\n";
				for(int k=1;k<=n&&ok;k+=j)
					for(int l=k;l<=k+j-1;l++)
						if(s[l]!=sam[l-k+1])
						{
							ok=false;
							break;
						}
//				cout<<"CHECK 6\n";
				if(ok)
				{
//					cout<<"CHECK 7\n";
					for(int k=n;k>=(n-i+1);k--)
						c[n-k+1]=s[k];
//					cout<<"CHECK 8\n";
					for(int k=1;k<j;k++)
					{
						for(int l=1;l<=k;l++)
							a[l]=s[l];
						if(f(a)<f(c))
							ans++;
					}
				}
				int jj=(n-i)/j;
//				cout<<"CHECK 3\n";
				sam="";
				ok=true;
//				cout<<"CHECK 4\n";
				for(int k=1;k<=jj;k++)
					sam[k]=s[k];
//				cout<<"CHECK 5\n";
				for(int k=1;k<=n&&ok;k+=jj)
					for(int l=k;l<=k+jj-1;l++)
						if(s[l]!=sam[l-k+1])
						{
							ok=false;
							break;
						}
//				cout<<"CHECK 6\n";
				if(ok)
				{
//					cout<<"CHECK 7\n";
					for(int k=n;k>=(n-i+1);k--)
						c[n-k+1]=s[k];
//					cout<<"CHECK 8\n";
					for(int k=1;k<jj;k++)
					{
						for(int l=1;l<=k;l++)
							a[l]=s[l];
						if(f(a)<f(c))
							ans++;
					}
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
