#include<bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,s=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			f=-f;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return f*s;
}
void write(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
}
int t,tot,ans;
string s;
int suan[30];
queue<int>q;
char a[1100000];
char b[1100000];
char c[1100000];
int naa[30];
int nac[30];
int cnta,cntc;
int tott=-1,tottt=-1;
void dfs(int x)
{
	int z=x;
	for(int i=0;i<s.size()-(tott+tottt+1);i=i+tott+tottt)
	{
		int tt=0;
		for(int j=i;j<i+tott;j++)
		{
			if(a[tt]!=s[j])
			{
				return;
			}
			tt++;
		}
		t=0;
		int m;
		for(int j=i+tott;j<i+tott+tottt;j++)
		{
			if(b[tt]!=s[j])
			{
				return;
			}
			t++;
			m=j;
		}
		if(s.size()-1<=m)
		{
			return;
		}
		else
		{
			for(int i=0;i<=26;i++)
			{
				nac[i]=0;
			}
			cntc=0;
			for(int i=m+1;i<s.size();i++)
			{
				nac[s[i]-'a'+1]++;
				if(nac[s[i]-'a'+1]%2==0)
				{
					cntc--;
					//cout<<a[0]<<endl;
					/*cout<<z<<endl;
					for(int k=0;k<=tott;k++)
					{
						cout<<a[k];
					}
					cout<<endl;
					for(int k=0;k<=tottt;k++)
					{
						cout<<b[k];
					}
					cout<<endl;*/
				}
				else
				{
					cntc++;
					//cout<<a[0]<<endl;
					/*cout<<z<<endl;
					for(int k=0;k<=tott;k++)
					{
						cout<<a[k];
					}
					cout<<endl;
					for(int k=0;k<=tottt;k++)
					{
						cout<<b[k];
					}
					cout<<endl;*/
				}
		}
				if(cnta<=cntc)
				{
					ans++;
				}
		}
		z++;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	t=read();
	for(int xunhuan1=1;xunhuan1<=t;xunhuan1++)
	{
		cnta=0;
		cntc=0;
		getline(cin,s);
		tot=s.size();
		ans=0;
		if(tot<3)
		{
			q.push(0);
			continue;
		}
		for(int i=0;i<=26;i++)
		{
			naa[i]=0;
		}
		tott=-1;
		for(int i=0;i<s.size()-2;i++)
		{
			tott++;
			a[tott]=s[tott];
			naa[s[tott]-'a'+1]++;
			if(naa[s[tott]-'a'+1]%2==0)
			{
				cnta--;
			}
			else
			{
				cnta++;
			}
			tottt=-1;
			for(int j=i+1;j<s.size()-1;j++)
			{
				tottt++;
				b[tottt]=s[j];
				/*for(int k=0;k<=tott;k++)
				{
					cout<<a[k];
				}
				cout<<endl;
				for(int k=0;k<=tottt;k++)
				{
					cout<<b[k];
				}
				cout<<endl;*/
				dfs(1);
			}
		}
		q.push(ans);
	}
	while(!q.empty())
	{
		write(q.front());
		putchar('\n');
		q.pop();
	}
	return 0;
}

