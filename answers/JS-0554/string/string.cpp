#include<bits/stdc++.h>
using namespace std;
int Ys[40010][600];
int Pre[1010],Las[1010];
bool Alph[30];
void Getys(int x)
{
	for(int i=1;i*i<=x;++i)
	{
		if(x%i==0)
		{
			Ys[x][++Ys[x][0]]=i;
			if(i*i!=x&&i!=1)Ys[x][++Ys[x][0]]=x/i;
		}
	}
}
void Getpre(string st)
{
	memset(Alph,0,sizeof(Alph));
	Pre[0]=1,Alph[st[0]-96]=1;
	for(int i=1;i<st.size();++i)
	{
		if(Alph[st[i]-96]==0)
		{
			Pre[i]=Pre[i-1]+1;
			Alph[st[i]-96]=1;
		}else
		{
			Pre[i]=Pre[i-1]-1;
			Alph[st[i]-96]=0;
		}
	}
}
void Getlas(string st)
{
	memset(Alph,0,sizeof(Alph));
	for(int i=st.size()-1;i>=0;--i)
	{
		if(Alph[st[i]-96]==0)
		{
			Las[i]=Las[i+1]+1;
			Alph[st[i]-96]=1;
		}else
		{
			Las[i]=Las[i+1]-1;
			Alph[st[i]-96]=0;
		}
	}
}
bool check(int l,int tL,string st,string AB)
{
	for(int i=0;i<l;i+=tL)
		if(st.substr(i,tL)!=AB)return false;
	return true;
}

void work()
{
	string st;
	cin>>st;
	memset(Pre,0,sizeof(Pre)),memset(Las,0,sizeof(Las));

	
	int Length=st.size();
	long long ans=0;
	if(st.size()<=1000)
	{
		Getpre(st),Getlas(st);	
		for(int l=Length-1;l>=2;--l)
		{
			string C=st.substr(l,Length-l);
			
			int Left=l;

			for(int i=1;i<=Ys[Left][0];++i)
			{
				int tL=Left/Ys[Left][i];
				string AB=st.substr(0,tL);
				if(check(l,tL,st,AB))
				{
					for(int j=0;j<tL-1;++j)
					{
						if(Pre[j]<=Las[l])
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}else
	{
		for(int i=1;i<Length-1;++i)
		{
			int Hav=Length-i;
			for(int j=1;j<=Ys[Hav][0];++j)
			{
				int Tl=Hav/Ys[Hav][j];
				if(i%2)ans+=Tl-1;
				else ans+=Tl/2-1+Tl%2;
			}
		}
		cout<<ans<<endl;
	}
	
}
int main()
{
	freoepn("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=40000;++i)
	{
		Getys(i);	
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;++i)
	{
		work();		
	}	
	return 0;
}

