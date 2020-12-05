#include<bits/stdc++.h>
#define rep2(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) rep2(i,0,n)
#define rep1(i,n) rep2(i,1,n+1)
#define pb push_back
#define mp make_pair
#define re(x) {cout<<x<<endl;return 0;}
#define all(x) x.begin(),x.end()
#define ll long long
//define x first
//define y second

using namespace std;
int t;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(cin>>t;t>0;t--)
	{
		ll ans=0;
		string s;
		cin>>s;
		rep1(i,s.size())
		{
			rep1(j,sqrt(i))
			{
				if(i%j==0)
				{
					bool ok=1;
					string ch=s.substr(0,i/j),tpp=s.substr(i,s.size()-i);
					for(int l=i/j;l<i;l+=i/j)
					{
						if(s.substr(l,i/j)!=ch) ok=0;
					}
					if(ok)
					{
						int a[200]={0},b2=0; 
						rep(l,tpp.size()) a[(int)(tpp[i])]++;
						rep(u,200) if(a[u]%2==1) b2++; 
						rep(o,ch.size())
						{
							int w[200]={0},b1=0;
							rep(l,o+1) w[(int)(ch[i])]++;
							rep(u,200) if(w[u]%2==1) b1++;
							if(b1<=b2) ans++;
						}
						
					}
					ok=1;
					ch=s.substr(0,j);
					for(int l=j;l<i;l+=j)
					{
						if(s.substr(l,j)!=ch) ok=0;
					}
					if(ok)
					{
						int a[200]={0},b2=0; 
						rep(l,tpp.size()) a[(int)(tpp[i])]++;
						rep(u,200) if(a[u]%2==1) b2++; 
						rep(o,ch.size())
						{
							int w[200]={0},b1=0;
							rep(l,o+1) w[(int)(ch[i])]++;
							rep(u,200) if(w[u]%2==1) b1++;
							if(b1<=b2) ans++;
						}}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;}
