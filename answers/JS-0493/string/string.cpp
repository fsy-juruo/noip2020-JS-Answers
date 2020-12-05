#include <bits/stdc++.h>
using namespace std;
const signed maxn=1e6+6e4+1;
char str[maxn];
signed z[maxn];
vector<signed>vt[maxn];
signed fk[maxn];
signed kf[maxn];
signed F[maxn];
signed tmp[233];
void mian()
{
	scanf("%s",str+1);
	signed n=0;
	for(signed i=0;i<maxn;++i) vt[i].clear(),fk[i]=0,kf[i]=0,F[i]=0,z[i]=0;
	for(signed i=1;i<maxn;++i)
	{
		if(str[i]=='\0')
		{
			//cout<<"t"<<i<<endl;
			n=i-1;
			break;
		}
	}
	{
		signed l=0,r=0;
		z[1]=n;
		for(signed i=2;i<=n;++i)
		{
			if(i>r)
			{
				for(signed j=i;j<=n;++j)
				{
					if(str[j]!=str[j-i+1])
					{
						l=i;
						r=j-1;
						goto err;
					}
					++z[i];
				}
				err:{}
			}
			else
			{
				z[i]=min(z[r-l+1],r-i+1);//??????
				for(signed j=i+z[i];j<=n;++j)
				{
					if(str[j]!=str[j-i+1])
					{
						l=i;
						r=j-1;
						goto er;
					}
					++z[i];
				}
				er:{}
			}
		}
		//cout<<"test ";for(signed i=1;i<=n;++i) cout<<z[i]<<" ";cout<<endl;
	}
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//OMGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG
	//kao chang shou zao Z box OvO
	{
		for(signed i='a';i<='z';++i) tmp[i]=0;
		for(signed i=1;i<=n;++i)
		{
			++tmp[str[i]];
			if(tmp[str[i]]&1)
			{
				fk[i]=fk[i-1]+1;
			}
			else
			{
				fk[i]=fk[i-1]-1;
			}
		}
	}
	{
		for(signed i='a';i<='z';++i) tmp[i]=0;
		for(signed i=n;i>0;--i)
		{
			++tmp[str[i]];
			if(tmp[str[i]]&1)
			{
				kf[i]=kf[i+1]+1;
			}
			else
			{
				kf[i]=kf[i+1]-1;
			}
		}
	}
	signed tp=-1;
	signed ans=0;
	signed A=0;
	F[fk[1]]=1;
	for(signed i=2;i<n;++i)
	{
		for(signed j=i;j<n;j+=i)
		{
			if(z[j-i+1]<i)
			{
				goto th;
			}
			if(kf[j+1]<tp)
			{
				for(signed i=kf[j+1]+1;i<=tp;++i)
				{
					ans-=F[i];
				}
			}
			else if(kf[j+1]>tp)
			{
				for(signed i=tp+1;i<=kf[j+1];++i)
				{
					ans+=F[i];
				}
			}
			tp=kf[j+1];
			A+=ans;
			//cout<<i<<" "<<ans<<" "<<tp<<endl;
		}
		th:{} ++F[fk[i]]; if(fk[i]<=tp) ++ans;
	}
	cout<<A<<endl;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	signed t;
	scanf("%d",&t);
	for(signed i=0;i<t;++i)
	{
		mian();
	}
	return 0;
}

