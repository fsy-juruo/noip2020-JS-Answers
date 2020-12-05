#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+5;
const long long inf=0x3f3f3f3f;
long long c[30],a[30],xhj[30],ans,len,tlen,pos,flag,fflag,sum,jsa,jsc,sss[30];
string s,t;
void init()
{
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	memset(xhj,0,sizeof(xhj));
	memset(sss,0,sizeof(sss));
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long T;
	cin>>T;
	while(T--)
	{
		init();
		ans=0;
		cin>>s;
		len=s.size();
		for(long long i=0;i<=len-1;i++)
			sss[s[i]-'a']++;
		fflag=0;
		for(long long i=0;i<=25;i++)
		{
			if(sss[i]==len)
			{
				fflag=1;
				break;
			}
		}
//		if(fflag==1)
//		{
//			cout<<"11111111"<<endl;
//			if(len%2==0)
//			{
//				for(long long i=1;i<=len-2;i++)
//				{
//					if(i%2==1)
//					{
//						long long x=len-i-1;
//						ans+=(x-2)/2+1;
//					}
//					else
//					{
//						long long x=len-i-1;
//						ans+=x;
//					}
//				}
//			}
//			else
//			{
//				for(long long i=1;i<=len-2;i++)
//				{
//					if(i%2==1)
//					{
//						long long x=len-i-1;
//						ans+=(x-1)/2+1;
//					}
//					else
//					{
//						long long x=len-i-1;
//						ans+=x;
//					}
//				}
//			}
//			cout<<ans<<"\n";
//			continue;
//		}
		for(long long i=1;i<len-1;i++)
		{
			for(long long j=1;j+i<len;j++)
			{
				init();
				t="";
				for(long long k=0;k<=i+j-1;k++)
				{
					t+=s[k];
					xhj[s[k]-'a']++;
				}
//				cout<<"t:"<<t<<endl;/////////////
				for(long long k=i+j;k<=len-1;k++)
					c[s[k]-'a']++;
//				cout<<"c"<<endl;
//				for(long long k=0;k<=25;k++)
//					cout<<c[k]<<" ";
//				cout<<endl;
				for(long long k=0;k<=i-1;k++)
					a[s[k]-'a']++;
//				cout<<"a"<<endl;
//				for(long long k=0;k<=25;k++)
//					cout<<a[k]<<" ";
//				cout<<endl;
				tlen=t.size();
				pos=i+j,flag=0,sum=0;
				while(1)
				{
					for(long long k=pos;k<=pos+tlen-1;k++)
					{
						if(s[k]!=t[k-pos])
						{
							flag=1;
							break;
						}
					}
					if(flag==1)
						break;
					sum++;
					pos=pos+tlen;
				}
				if((sum+1)*tlen==len)
					sum--;
//				cout<<sum<<endl;//////////
//				cout<<"a"<<endl;
//				for(long long k=0;k<=25;k++)
//					cout<<a[k]<<" ";
//				cout<<endl;
//				cout<<"c"<<endl;
//				for(long long k=0;k<=25;k++)
//					cout<<c[k]<<" ";
//				cout<<endl;
//				cout<<"xhj"<<endl;
//				for(long long k=0;k<=25;k++)
//					cout<<xhj[k]<<" ";
//				cout<<endl;
				for(long long xh=0;xh<=sum;xh++)
				{
					jsa=0,jsc=0;
					for(long long k=0;k<=25;k++)
					{
						if(a[k]%2==1)
							jsa++;
						if(c[k]%2==1)
							jsc++;
					}
					if(jsa<=jsc)
					{
						ans++;
//						cout<<i<<" "<<j<<endl;
					}
					for(long long k=0;k<=25;k++)
						c[k]-=xhj[k];
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
in
3
nnrnnr
zzzaab
mmlmmlo

2
nnrnnr
zzzaab
*/
