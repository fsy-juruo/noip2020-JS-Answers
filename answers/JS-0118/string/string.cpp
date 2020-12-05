#include<bits/stdc++.h>
using namespace std;
const int MAXN=100007;
int t,n,ans;
int bua[50],ja;
int buc[50],jc;
char s[1050000];
int check(int ar,int cl)
{
	if(cl-ar<=1)return 0;
	if(cl-1<(ar<<1))return 1;
	int ans=0;bool flag;
	for(int i=1;i<=cl/(ar+1);i++)
	{
		if((cl-1)%i)continue;
		flag=1;
		int cd=(cl-1)/i;
		for(int j=cd+1;j<cl;j++)
		{
			if(s[j]!=s[j%cd==0?cd:j%cd])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			//cout<<ar<<' '<<i<<' '<<cl<<endl;
			++ans;
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;jc=0;
		memset(buc,0,sizeof(buc));
		cin>>s+1;
		n=strlen(s+1);
		//if(n>1000)
		for(int i=n;i>=1;i--)
		{
			++buc[s[i]-'a'];
			if(buc[s[i]-'a']&1)++jc;else --jc;
			memset(bua,0,sizeof(bua));ja=0;
			for(int j=1;j+1<i;j++)
			{
				++bua[s[j]-'a'];
				if(bua[s[j]-'a']&1)++ja;else --ja;
				if(ja>jc)continue;
				//cout<<i<<' '<<j<<' '<<ja<<' '<<jc<<endl;
				ans+=check(j,i);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

