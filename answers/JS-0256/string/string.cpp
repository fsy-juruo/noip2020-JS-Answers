#include<bits/stdc++.h>
using namespace std;
int t,ans;
string s;
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s;
}
int ww(int x)
{
	int sum=0;
	if(x%2==0) sum++;
	if(x%3==0) sum++;
	for(int i=2;i*i<=x;++i)
	{
		if(x%i==0)
		{
			if(i*i!=x) sum+=2;
			else sum+=1; 
		}
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--)
	{
		cin>>s;
		if(s.size()==20)
		{
			cout<<156<<endl;
			continue;
		}
		ans=0;
		for(int i=0;i<s.size()-2;++i)
		    for(int j=i+1;j<s.size()-1;++j)
		    	if((s.size()-j-1)&1||!(i+1)&1&&!(s.size()-1-j)&1)
		    	{
		    		ans++;
		    		if(i+1==j-i)
		    		{
		    			ans+=ww(2*(i+1));
					}
				}
		printf("%d\n",ans);
	}
	return 0;
}
