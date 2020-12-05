#include<bits/stdc++.h>
#define re register
using namespace std;
int t,sh[1100000],ni[1100000],v[1100000][6],v2[1100000][6],ans;
int hqy[1100];
char x[1100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;for(re int i=0;i<=26;++i)hqy[i]=0;
		int s=1;x[s]=getchar();while(x[s]=='\n')x[s]=getchar();
		while(x[s]!='\n'){s++;x[s]=getchar();}
		x[s]='\0';s--;v[1][t]=s;
		bool kkk[200];for(re int i='a';i<='z';++i)kkk[i]=0;
		for(re int i=1;i<=s;++i){
			kkk[x[i]]^=1;
			if(kkk[x[i]])sh[i]=sh[i-1]+1;
			else sh[i]=sh[i-1]-1;
			hqy[sh[i]]++;
		}
		for(re int i='a';i<='z';++i)kkk[i]=0;
		for(re int i=s;i>=1;--i){
			kkk[x[i]]^=1;
			if(kkk[x[i]])ni[i]=ni[i+1]+1;
			else ni[i]=ni[i+1]-1;
		}
		bool m=false;
		int k=1;int lf;
		for(int i=2;i<=s;++i)
		{
			if(!m){
				if(x[i]==x[1]){m=1;lf=i;v[i][t]=1;}
				continue;
			}
			if(x[i]==x[i-lf+1])v[lf][t]++;
			else{
				m=0;i--;
				for(re int j=2;j<=i-lf+1;++j)if(v[j][t]){
					lf+=j-1;
					i=min(i,lf+v[j][t]-1);
					m=1;
					v[lf][t]=i-lf+1;
					break;
				}
			}
		}
		if(m)for(re int i=lf+1;i<=s;++i)v[i][t]=min(v[i-lf+1][t],s-i+1);
		for(re int i=2;i<=s/2+1;++i)
		{
			if(v[i][t]>=(i-1))v2[i][t]=v[i][t]/(i-1);
		}
		if(s%2==0)v2[s/2+1][t]=0;
		hqy[sh[s]]--;
		for(re int i=s-1;i>=2;--i)
		{
			hqy[sh[i]]--;
			int u1=0,u2;
			for(int j=ni[i+1];j>=0;--j)u1+=hqy[j];
			u2=i-1-u1;
			ans+=u1*(v2[i+1][t]+1);
			ans+=u2*(int(v2[i+1][t]+1)/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}

