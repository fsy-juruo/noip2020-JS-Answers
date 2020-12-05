#include<bits/stdc++.h>

using namespace std;

const int MAXN=( 1<<20 ) + 5 ; 
string s;
int T,n;

int sum[MAXN][26];
int f[MAXN],ans[MAXN];

void print()
{
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j!=26;++j)
			{
				if(sum[i][j]!=0)
				{
					cout<<i<<' '<<char(j+'a')<<' '<<sum[i][j]<<endl;
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
		memset(f,0,sizeof(f));
		memset(sum,0,sizeof(sum));
		memset(ans,0,sizeof(ans));
		cin>>s;
		n=s.size();
		s=" "+s;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j!=26;++j)
			{
				sum[i][j]=sum[i-1][j];
			}
			++sum[i][s[i]-'a'];
		}
		

		
		int cnt=0;
		for(int i=0;i!=26;++i)
		{
			if(sum[n][i]) ++cnt;
		}
		/*
		if(cnt==1)
		{
			int tot=0;
			for(int i=1;i<n-1;++i)
			{
				if(( i&1 ) tot+=(n-i-1);
				
				else 
				{
					
				}
				 
			}
			
			
			
			continue;
		}
	
		*/
		string tmp;
		tmp.push_back(s[1]);
		for(int i=2;i<n;++i)
		{
			if(i<=(n-1)/2)
			{
				tmp.push_back(s[i]);
				int j;
				for(j=i+1;j<n;j=j+i)
				{
					//cout<<s.substr(j,i)<<endl;
					string ss=s.substr(j,i);
					if(tmp!=ss) break;
				}
				f[i]=j-1;
			}
			else 
			{
				f[i]=i;
			}
			
		}
		/*
		for(int i=2;i<n;++i)
		{
			cout<<"f["<<i<<"]="<<f[i]<<endl;
		}
		*/
		for(int i=2;i<n;++i) 
		{
			int lim=0,jiaoji=0;
			for(int j=0;j<26;++j)
			{
				if( (sum[n][j]-sum[f[i]][j]) & 1 ) ++lim;
				if( (sum[i][j]+sum[n][j]-sum[f[i]][j]) &1 ) ++jiaoji;
			}
			/*
			cout<<"*******"<<endl;
			cout<<"i="<<i<<endl;
			
			cout<<"lim="<<lim<<endl;
			cout<<"jiaoji="<<jiaoji<<endl;
			*/
			bool flag=0;
			int len=i;
			
			vector<int> vv;
			vv.push_back(1);
			int cnt_A_odd=1;
			for(int j=2;j<len;++j)
			{
				
				
				if(sum[j-1][s[j]-'a'] & 1 ) 
				{
					--cnt_A_odd;
				}
				else ++cnt_A_odd;
				vv.push_back(cnt_A_odd);
			//	cout<<s.substr(1,j)<<' '<<cnt_A_odd<<endl;
				
			} 
			
			sort(vv.begin(),vv.end());
			/*
			for(int j=0;j<vv.size();++j)
			{
				cout<<vv[j]<<' ';
			}
			cout<<endl;
			*/
			int v[2]{0,0}; 
			v[0]=upper_bound(vv.begin(),vv.end(),lim)-vv.begin();
			v[1]=upper_bound(vv.begin(),vv.end(),jiaoji)-vv.begin();
			if(v[0]<0) v[0]=0;
			if(v[1]<0) v[1]=0;
		//	cout<<"v[0]="<<v[0]<<endl;
		//	cout<<"v[1]="<<v[1]<<endl;
			for(int j=f[i];j>=i;j-=len)
			{
			//	cout<<"v["<<flag<<"]="<<v[flag] <<endl;
				ans[i]+=v[flag];
				flag^=1;
			}
			
			
		}
		int tot=0;
		for(int i=2;i<n;++i)
		{
			tot+=ans[i];
		}
		cout<<tot<<endl;

	}
	return 0;
}
//1 nnrnnr

