#include<bits/stdc++.h>

using namespace std;

template <class T>
inline void read(T &n)
{
	n=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	n*=f;
}

const int S=32680;

int T,n,m;
int l,ans,a,b,c;
string s;

int tot[S],ftot[S];

int tmp[27];
void predoit()
{
	memset(tmp,0,sizeof(tmp));
	tot[0]=1;
	++tmp[s[0]-'a'];
	for(int i=1;i<l;++i)
	{
		++tmp[s[i]-'a'];
		if(tmp[s[i]-'a']%2)
			tot[i]=tot[i-1]+1;
		else
			tot[i]=tot[i-1]-1;
	}
	
//	cout<<"???"<<endl;
	
	memset(tmp,0,sizeof(tmp));
	ftot[l-1]=1;
	++tmp[s[l-1]-'a'];
	for(int i=l-2;i>=0;--i)
	{
		++tmp[s[i]-'a'];
		if(tmp[s[i]-'a']%2)
			ftot[i]=ftot[i+1]+1;
		else
			ftot[i]=ftot[i+1]-1;
	}
}

bool check(int tt,int t,int ct)
{
	for(int i=1;i<ct;++i)
		for(int j=0;j<tt;++j)
			if(s[j]!=s[i*tt+j])
				return false;
	return true;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	read(T);
	
	while(T--)
	{
		ans=0;
		cin>>s;
		l=s.length();
//		cout<<l<<endl;
		
//		if(l<=1000)
//		{
			predoit();
			
	//		cout<<"!!!"<<endl;
			
			for(int c=1;c<=l;++c)
			{
				int t=l-c;
				for(int i=1;i<=t/2;++i)
				{
					if(t%i!=0)
						continue;
					int tt=t/i;
					if(!check(tt,t,i))
						continue;
					for(int a=1;a<=tt-1;++a)
						if(tot[a-1]<=ftot[l-c])
							++ans;
				}
			}
//		}
//		else
//			ans=ak[l-1000+1];
		
		printf("%d\n",ans);
	}
	
	return 0;
}
