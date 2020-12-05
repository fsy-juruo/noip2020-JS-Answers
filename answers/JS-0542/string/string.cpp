#include<bits/stdc++.h>
using namespace std;
int T,tot[210],tota[210],ct;
string s;
long long ans;
int check(int a,int b)
{
	for(int i=0;i<b/a;i++)
	 for(int j=0;j<a;j++) if(s[i]!=s[b/a*j+i]) return 1;
	return 0;
}
void doit(int ed)
{
	for(int j=1;j<=floor(sqrt(ed));j++) 
	{
	if(ed%j==0)	
	{
		if(!check(j,ed)) 
		{
		memset(tota,0,sizeof(tota));int lt=0;
		for(int k=0;k<ed/j-1;k++)
		{
			tota[s[k]]++;
			if(tota[s[k]]&1) lt++;else lt--;
			if(lt<=ct){
			ans++;
			} 
		}	
		}
		if(ed/j==ed||ed/j==j) continue;
		if(check(ed/j,ed)) continue;
		memset(tota,0,sizeof(tota));int lt=0;
		for(int k=0;k<j-1;k++)
		{
			tota[s[k]]++;
			if(tota[s[k]]&1) lt++;else lt--;
			if(lt<=ct){
			ans++;
			} 
		}
	}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ct=0;ans=0;
		cin>>s;memset(tot,0,sizeof(tot));
		for(int i=s.size()-1;i>=2;i--)
		{
			tot[s[i]]++;
			if(tot[s[i]]&1) ct++;else ct--;
			doit(i);
		}
		cout<<ans<<endl;
	}
	return 0;
}

