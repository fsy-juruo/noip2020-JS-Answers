#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define x0 xasdsajldk
#define x1 xklasjdklsa
#define y0 ysjaldksla
#define y1 yaklsdnwad
const ll INF=0x3f3f3f3f,N=1e5+5,jz=233,mo=1e9+7;
int n,m;
string s;
ll a[N];
int b[N][30];
ll c[N];
ll mi[N];
ll calc(int l,int r)
{
	int i;
	ll sum=0;
	for(i=0;i<26;i++)
	{
		if((b[r][i]-b[l-1][i])%2==1)
		{
			sum++;
		}
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,k,T;
	cin>>T;
	while(T--)
	{
		cin>>s;
		n=s.size();
		for(i=0;i<s.size();i++)
		{
			c[i+1]=s[i]-'a';
			for(j=0;j<26;j++)
			{
				b[i+1][j]=b[i][j]+(c[i+1]==j);
			}
		}
		mi[0]=1;
		for(i=1;i<=n;i++)
		{
			mi[i]=mi[i-1]*jz;
		}	
		for(i=1;i<=n;i++)
		{
			a[i]=(a[i-1]*jz%mo+c[i])%mo;
		}
//		for(i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		ll ans=0;
		for(i=n;i>=3;i--)
		{
	//		i=n;
			ll js_C=calc(i,n);
			m=i-1;
			int len=0;
			for(j=1;j<=m;j++)
			{
				if(m%j!=0) continue;
				ll has=a[j]%mo;
				bool f=1;
				for(k=1;k<=m/j;k++)
				{
	//				cout<<has<<" "<<(a[k*j]-a[(k-1)*j]+mo)%mo<<endl;
					if((a[k*j]-a[(k-1)*j]*mi[j]%mo+mo)%mo!=has)
					{
						f=0;
						break;
					}
				//	has=(has*mi[j])%mo;
				}
				if(f==1)
				{
					len=j;
					break;
				}
			}
	//		cout<<len<<endl;
			for(j=1;j<m;j++)
			{
				ll js_A=calc(1,j);
	//			cout<<js_A<<" "<<js_C<<endl;
				if(js_A>js_C) continue;
				for(k=1;k<=m/len;k++)
				{
					if(k*len<=j||m%(k*len)!=0) continue;
					ans++;
				}
			}
	//		cout<<ans<<endl;
	//		cout<<len<<endl;
		}
		cout<<ans<<endl;		
	}
	return 0;
}
/*
nnrnnro
*/
