#include <bits/stdc++.h>
using namespace std;
int a,al[100],jn2[1048586],jn3[1048586],jn1;
long long ans;
string b;
void check(int y)
{
	int i=0;
	if(y>b.length()/2+1)
	{
		for(int k=0;k<y;k++)
		{
	//		cout<<j<<" "<<k<<" "<<jn2[k]<<" "<<jn1<<endl;
			if(jn2[k]<=jn3[y+1])
			ans++;
		}
	}
	else
	{
		for(i=y+1;i<b.length()-1;i++)
		{
			if(b[i]!=b[i%(y+1)])
			break;
		}
		for(i=i/(y+1)*(y+1);i>=y+1;i-=(y+1))
		for(int k=0;k<y;k++)
		{
		//	cout<<i<<" "<<k<<" "<<jn2[k]<<" "<<jn1<<endl;
			if(jn2[k]<=jn3[i])
			ans++;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++)
	{
		ans=0;
		cin>>b;
		for(int j=0;j<=26;j++)
		al[j]=0;
		jn2[0]=1;
		al[b[0]-'a'+1]++;
		for(int j=1;j<b.length();j++)
		{
			al[b[j]-'a'+1]++;
			if(al[b[j]-'a'+1]%2==0)
			jn2[j]=jn2[j-1]-1;
			else
			jn2[j]=jn2[j-1]+1;
		}
		for(int j=0;j<=26;j++)
		al[j]=0;
		jn3[b.length()]=0;
		for(int j=b.length()-1;j>=0;j--)
		{
			al[b[j]-'a'+1]++;
			if(al[b[j]-'a'+1]%2==0)
			jn3[j]=jn3[j+1]-1;
			else
			jn3[j]=jn3[j+1]+1;
		}
		for(int j=1;j<b.length()-1;j++)
		{
			check(j);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
