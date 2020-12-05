#include<bits/stdc++.h>
#define R register
using namespace std;

int n,m,k;
string a,b,c,s,ab;
int ls,la,lb,lc,lab,lz,t,l,ans,T;
int h[1000];
int sa,sb;
bool f;

inline bool pd(string x,string y)
{
	sa=0;
	memset(h,0,sizeof(h));
	for (R int i=0;i<x.size();i++)
	{
		h[x[i]]++;
	}
	for (R int i='a';i<='z';i++)
	{
		if (h[i]%2==1) sa++;
	}
	sb=0;
	memset(h,0,sizeof(h));
	for (R int i=0;i<y.size();i++)
	{
		h[y[i]]++;
	}
	for (R int i='a';i<='z';i++)
	{
		if (h[i]%2==1) sb++;
	}
	
	if (sa<=sb) return true;
	else return false;
	
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> T;
	while (T--)
	{
		a="";b="";c="";ab="";ans=0;
		cin >> s;ls=s.size();
		for (R int ic=ls-1;ic>=1;ic--)
		{
			c=s[ic]+c;lc=c.size();lz=ls-lc;ab="";
			
			ab+=s[0];
			for (R int iab=1;iab<lz;iab++)
			{
				
				
				lab=iab+1;ab+=s[iab];
				if (lz%lab!=0) continue;
				if (lab*2>lz&&lab!=lz) continue;
				
//				判断ab是否符合 
				
				t=lz/lab;f=true;l=0;
				for (R int i=iab+1;i<=lz-1;i++)
				{
					l++;l%=lab;if (l==0) l=lab;
					if (s[i]!=s[l-1])
					{
						f=false;break;
					}
				}
				if (f==false) 
				{
					continue;
				}
				
//				ab符合要求,找符合要求的a 

				a="";
				for (R int ia=0;ia<iab;ia++)
				{
					a+=s[ia];
					if (pd(a,c)==true)
					{
						ans++;
//						cout << "-------" << endl;
//						cout << lab << endl;
//						cout << a << endl;
//						cout << ab << endl;
//						cout << c << endl;
					}
				}
				
			}
		}
		cout << ans << endl;
	}
	return 0;
}

