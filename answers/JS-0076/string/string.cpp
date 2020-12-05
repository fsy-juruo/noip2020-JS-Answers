#include<bits/stdc++.h>
using namespace std;
int T;
string st,a,b,c,ab;
int sc,s,ss,ans;
int t[125],t1[125];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		s=0,ss=0;
		memset(t,0,sizeof(t));
		memset(t1,0,sizeof(t1));
		a="",b="",ab="";
		cin>>st;
		if(st.size()<=2)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<st.size()-2;i++)
		{
			a=a+st[i];
			for(int j=i+1;j<st.size()-1;j++)
			{
				b=b+st[j];
				ab=a+b;
				int count=0;
				sc=j+1;
				for(int k=j+1;k<st.size();k++)
				{
					if(ab[k%ab.size()]==st[k]) 
					{
						count++;
						if(count==ab.size()&&k!=st.size()-1) 
						{
							sc=k+1;
							count=0;
						}	
					}else break;
				}
				memset(t,0,sizeof(t));
				memset(t1,0,sizeof(t1));
				for(int k=sc;k<st.size();k++)
				{
					t[st[k]]++;
				}
				s=0;
				ss=0;
				for(int k=0;k<a.size();k++)
				{
					t1[a[k]]++;
				}
				for(int k=97;k<=122;k++)
				{
					if(t[k]%2==1) s++;
					if(t1[k]%2==1) ss++;
				}
				if(s>=ss) ans++;
				if(sc!=j+1)
				{
					sc-=ab.size();
					while(sc>=j+1)
					{
					memset(t,0,sizeof(t));
					memset(t1,0,sizeof(t1));
					for(int k=sc;k<st.size();k++)
					{
						t[st[k]]++;
					}
					s=0;
					ss=0;
					for(int k=0;k<a.size();k++)
					{
						t1[a[k]]++;
					}
					for(int k=97;k<=122;k++)
					{
						if(t[k]%2==1) s++;
						if(t1[k]%2==1) ss++;
					}
					if(s>=ss) ans++;
					sc-=ab.size();
					}
				}
			}
				b="";
		}
		cout<<ans<<endl;	
	}
	

	return 0;
}

