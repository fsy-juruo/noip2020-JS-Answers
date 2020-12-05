#include <bits/stdc++.h>
using namespace std;
char str[1048580];
string s;
int n;
int tac;
int z[1048580];
int num[30];
int pre[1048580],suf[1048580];
long long res;
int seg[1048580];
void addi(int x)
{
	x++;
	while (x<=1048578) seg[x]++,x+=x&(-x);
}
int sum(int x)
{
	x++;
	int r=0;
	while (x>0) r+=seg[x],x-=x&(-x);
	return r;
}
void Zalgor()
{
	z[0]=n;
	int l=0,r=-1;
	for (int i=1;i<n;i++)
	{
		z[i]=0;
		if (i>r)
		{
			while (i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
			if (z[i] && i+z[i]-1>r) l=i,r=i+z[i]-1;
		}
		else
		{
			z[i]=min(z[i-l],r-i+1);
			while (i+z[i]<n && s[i+z[i]]==s[z[i]]) z[i]++;
			if (z[i] && i+z[i]-1>r) l=i,r=i+z[i]-1;
		}
		//cout <<i<<" "<<z[i]<<" "<<l<<" "<<r<<" ##\n";
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&tac);
	while (tac--)
	{
		scanf("%s",str);
		s=str;
		n=s.size();
		res=0;
		for (int i=0;i<26;i++) num[i]=0;
		for (int i=0;i<=n+2;i++) seg[i]=0;
		int rt=0;
		for (int i=0;i<n;i++)
		{
			if (num[s[i]-'a']%2==0) rt++;
			else rt--;
			pre[i]=rt;
			num[s[i]-'a']++;
			//cout <<i<<" "<<pre[i]<<" ##\n";
		}
		for (int i=0;i<26;i++) num[i]=0;
		rt=0;
		for (int i=n-1;i>=0;i--)
		{
			if (num[s[i]-'a']%2==0) rt++;
			else rt--;
			suf[i]=rt;
			num[s[i]-'a']++;
		}
		Zalgor();
		for (int i=2;i<n;i++)
		{
			//cout <<i<<" -----------------------\n";
			addi(pre[i-2]);
			//cout <<pre[i-2]<<" ##\n";
			int ed=-1,t=0;
			for (int j=0;j<n;j+=i)
			{
				//cout <<"Z: "<<j<<" "<<z[j]<<" ##\n";
				if (z[j]>=i) ed=j+i-1,t++;
				else break;
			}
			//long long tr=0;
			long long lim=suf[ed+1];
			long long nm=((t+1)/2);
			if (ed==n-1) nm--;
			res+=1ll*sum(lim)*nm;
			//tr+=1ll*sum(lim)*nm;
			if (ed-i>=0)
			{
				long long lim=suf[ed-i+1];
				res+=1ll*sum(lim)*(t/2);
				//tr+=1ll*sum(lim)*(t/2);
			}
			//cout <<i<<" "<<ed<<" "<<tr<<" ######\n";
		}
		printf("%lld\n",res);
	}
	return 0;
}
