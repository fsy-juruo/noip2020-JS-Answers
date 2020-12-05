#include<bits/stdc++.h>
using namespace std;
string str;
set <int> chs;
int len,cnt1[27],cnt2[27];
long long ans;
void dfs1(int dep,int num1,int num2)
{
	int i,num3,lims;
	switch (dep)
	{
		case 1:
			for (i=1;i<=len-2;i++)
				dfs1(2,i,0);
			break;
		case 2:
			for (i=1;i<=len-num1-1;i++)
				dfs1(3,num1,i);
			break;
		default:
			lims=len/(num1+num2);
			num3=len-num1-num2;
			for (i=1;i<=lims;i++)
			{
				if (!num3)
					break;
				if ((num1%2==0)||num3%2)
					ans++;
				num3-=num1;
				num3-=num2;
			}
			return;
	}
}
void dfs2(int dep,int num1,int num2)
{
	int i,j,num3,lims,p1=0,p2;
	string st1,st2,st3,st4,stp,stq;
	switch (dep)
	{
		case 1:
			for (i=1;i<=len-2;i++)
				dfs2(2,i,0);
			break;
		case 2:
			for (i=1;i<=len-num1-1;i++)
				dfs2(3,num1,i);
			break;
		default:
			lims=len/(num1+num2);
			num3=len-num1-num2;
			st1=str.substr(0,num1);
			st2=str.substr(num1,num2);
			stp=st1;
			stp+=st2;
			memset(cnt1,0,sizeof(cnt1));
			for (i=0;i<num1;i++)
				cnt1[st1[i]-96]++;
			for (i=1;i<=26;i++)
				if (cnt1[i]%2)
					p1++;
			for (i=1;i<=lims;i++)
			{
				if (!num3)
					break;
				if (i*(num1+num2)+num3>len)
					break;
				st3=str.substr(i*(num1+num2),num3);
				memset(cnt2,0,sizeof(cnt2));
				p2=0;
				for (j=0;j<num3;j++)
					cnt2[st3[j]-96]++;
				for (j=1;j<=26;j++)
					if (cnt2[j]%2)
						p2++;
				if (p1<=p2)
					ans++;
				if ((i+1)*(num1+num2)>len)
					break;
				st4=str.substr(i*(num1+num2),num1+num2);
				if (st4!=stp)
					break;
				num3-=num1;
				num3-=num2;
			}
			return;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int T,i;
	cin>>T;
	while (T--)
	{
		cin>>str;
		len=str.size();
		chs.clear();
		for (i=0;i<len;i++)
			chs.insert(str[i]);
		ans=0;
		if (chs.size()==1)
		{
			dfs1(1,0,0);
			cout<<ans<<'\n';
		}
		else
		{
			dfs2(1,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
