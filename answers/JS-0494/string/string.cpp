#include <bits/stdc++.h>

#define LL long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

LL t,n,z[1200000],odd1[1200000],odd2[1200000],num[100],val[100],val2[100],ans;
string s;

void calcZ()
{
	int lb=0,ub=0;
	z[0]=n;
	repn(i,n-1)
	{
		if(i>ub)
		{
			int ii=i;
			while(ii<n&&s[ii]==s[ii-i]) ii++;
			z[i]=ii-i;
			if(z[i]>0)
			{
				lb=i;
				ub=ii-1;
			}
		}
		else
		{
			z[i]=z[i-lb];
			if(z[i]>=ub-i+1)
			{
				int ii=ub+1;
				while(ii<n&&s[ii]==s[ii-i]) ii++;
				z[i]=ii-i;
				lb=i;
				ub=ii-1;
			}
		}
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	rep(tn,t)
	{
		cin>>s;
		n=s.size();
		
		calcZ();
		
		LL cur=0;
		memset(num,0,sizeof(num));
		rep(i,n)
		{
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==1) cur++;
			else cur--;
			odd1[i]=cur;
		}
		cur=0;
		memset(num,0,sizeof(num));
		for(int i=n-1;i>=0;i--)
		{
			num[s[i]-'a']++;
			if(num[s[i]-'a']%2==1) cur++;
			else cur--;
			odd2[i]=cur;
		}
		memset(val,0,sizeof(val));
		memset(val2,0,sizeof(val2));
		int tmp,add;
		ans=0;
		for(int len=2;len<=n-1;len++)
		{
			val[odd1[len-2]]++;
			val2[odd1[len-2]/6]++;
			for(int j=0;j+len<n&&z[j]>=len;j+=len)
			{
				tmp=odd2[j+len];
				add=0;
				int k;
				for(k=tmp;k>=0&&k/6==tmp/6;k--) add+=val[k];
				if(k>=0) for(int p=k/6;p>=0;p--) add+=val2[p];
				ans+=add;
				//cout<<"A+b len:"<<len<<"    C start pos:"<<j+len<<"    val:"<<add<<' '<<tmp<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab


*/
