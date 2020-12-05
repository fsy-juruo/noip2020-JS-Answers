#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())
		if(ch=='-')
			f*=-1;
	for(; isdigit(ch);ch=getchar())
		s*=10,s+=ch-'0';
	return s*f;
}
const int N=1100000;
string st;
int t;
int tg[200];
int jsgs(string sr)
{
	memset(tg,0,sizeof(tg));
	int sum=0;
	for(int i=0;i<sr.size();i++)
		tg[sr[i]]++;
	for(int i='a';i<='z';i++)
		if(tg[i]%2==1)
			sum++;
	return sum;
}
bool zhengchu(int a,int b)
{
	if(a<b) swap(a,b);
	int c=a/b;
	if(c*b!=a) return 0;
	return 1;
}
bool judge(string s,int lc)
{
	int len=s.size();
	for(int i=0;i<st.size()-lc;i+=len)
	{
		string sr=st.substr(i,len);
		if(sr!=s) return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--)
	{
		int ans=0;
		cin>>st;
		for(int i=st.size()-1;i>=2;i--)
		{
			string sr=st.substr(i,st.size()-i);
			int gs1=jsgs(sr);
			for(int j=0;j<i-1;j++)
			{
				string sr2=st.substr(0,j+1);
				int gs2=jsgs(sr2);
				//cout<<sr<<' '<<sr2<<endl;
				//cout<<i<<' '<<j<<endl;
				//cout<<gs1<<' '<<gs2<<endl;
				if(gs2>gs1) continue;
				for(int k=j+1;k<i;k++)
				{
					if(!zhengchu(k+1,i)) continue;
					string sr3=st.substr(j+1,k-j);
					if(judge(sr2+sr3,st.size()-i))
					{
						ans++;
						//cout<<j<<' '<<k<<' '<<i<<endl;
						//cout<<sr2<<' '<<sr3<<' '<<sr<<endl;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

