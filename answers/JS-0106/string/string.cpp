#include<bits/stdc++.h>
using namespace std;
string s[6],r,u;
int l[2][27];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b,c,d,e,i,t,v,w,z;
	bool f;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	cin>>s[i];
	for(i=1;i<=t;i++)
	{
		v=0;
		c=s[i].length();
		for(a=0;a<=c-1;a++)
		{
			l[1][s[i][a]-'a']^=1;
			if(l[1][s[i][a]-'a']==1)
			l[1][26]++;
			else
			l[1][26]--;
		}	
		for(a=0;a<=c-3;a++)
		{
			r+=s[i][a];
			l[0][r[a]-'a']^=1;
			if(l[0][r[a]-'a']==1)
			l[0][26]++;
			else
			l[0][26]--;
			l[1][r[a]-'a']^=1;
			if(l[0][r[a]-'a']==1)
			l[1][26]++;
			else
			l[1][26]--;
			u=r;
			w=l[1][26];
			for(b=a+1;b<=c-2;b++)
			{
				r+=s[i][b];
				f=true;
				z=r.length();
				for(d=1;d<=c/z;d++)
				{
					for(e=(d-1)*z;e<d*z;e++)
					{
						if(r[e-(d-1)*z]!=s[i][e])
						{
							d--;
							f=false;
							break;
						}
					}
					if(!f)
					break;
					for(e=(d-1)*z;e<=d*z;e++)
					{
						if(l[0][r[a]-'a']==1)
						l[1][26]++;
						else
						l[1][26]--;
					}
					if(l[1][26]>=l[0][26])
					v++;
				}
			}
			r=u;
			l[1][26]=w;
		}
		cout<<v<<endl;
		r="\0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
