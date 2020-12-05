#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[1050000][27],i,j,cta,ctc,k,ans,m;
string st;
void solve(int i)
{
	int l=i+1,q=0;
	for(int ii=1;ii<=l;ii++)
	{
		q=0;
		if(l%ii)continue;
		string ct=st.substr(0,l/ii);
		for(int jj=1;jj<=ii-1;jj++)
		{
			q|=ct!=st.substr(jj*(l/ii),l/ii);
		}
		if(!q){
			for(int jj=0;jj<l/ii-1;jj++){
				cta=0;
				for(int kk=1;kk<=26;kk++)cta+=a[jj][kk]&1;
				if(cta<=ctc)ans++;
			}
			
		}
	}
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		ans=0;
		memset(a,0,sizeof(a));
		cin>>st;
		a[0][st[0]-'a'+1]=1;
		for(i=1;i<=st.length()-1;i++){
			a[i][st[i]-'a'+1]++;
			for(j=1;j<=26;j++)a[i][j]+=a[i-1][j];
		}
		m=st.length();
		for(i=1;i<m-1;i++)
		{
			cta=0;ctc=0;
			for(k=1;k<=26;k++)ctc+=(a[m-1][k]-a[i][k])&1;
			solve(i);
		}
		cout<<ans<<'\n';
		/*for(i=0;i<=st.length()-1;i++)
		{
			for(j=1;j<=26;j++)cout<<a[i][j]<<' ';
			cout<<endl;
		}*/
		
	}
	return 0;
}
