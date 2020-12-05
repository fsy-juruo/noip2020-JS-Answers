#include<cstdio>
#include<cstring>

#define int long long

#define _N 1100000

#define _P 998244353

int T;

int slen=0;
char _s[_N];
int s[_N];
int hashs[_N];
int invs[_N];

int cnt1,cnt2,cnt3;
int charcnt[27];
int totcnt[27];
int nowcnt[27];
int cntnum[27];

int res2,res3;
int ans=0;

int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
		{
			res=res*x%_P; 
		}
		x=x*x%_P;
		y>>=1;
	}
	return res;
}

void hash()
{
	for(int i=1;i<=slen;i++)
	{
		hashs[i]=(hashs[i-1]*97%_P+s[i])%_P;
	}
	int pw=1;
	for(int i=0;i<=slen;i++)
	{
		invs[i]=qpow(pw,_P-2);
		pw=pw*97%_P;
	}
}

int gethash(int l,int r)
{
	return (hashs[r]-hashs[l-1]+_P)%_P*invs[l-1]%_P;
}

void match(int k)
{
	bool flag=false;
	res2=res3=0;
	int orihash=gethash(1,k);
	for(int l=1;l+k-1<slen;l+=k)
	{
		if(gethash(l,l+k-1)==orihash)
		{
			if(!flag)
			{
				res2++;
			}
			else
			{
				res3++;
			}
		}
		else
		{
			break;
		}
		flag=flag^1;
	}
}

void clear()
{
    memset(charcnt,0x00,sizeof(charcnt));
    memset(totcnt,0x00,sizeof(totcnt));
    memset(nowcnt,0x00,sizeof(nowcnt));
    memset(cntnum,0x00,sizeof(cntnum));
    ans=0;
}

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		clear();
	 	scanf("%s",_s);
		slen=strlen(_s);	
		for(int i=0;i<slen;i++)
		{
			s[i+1]=_s[i]-'a';
		}
		hash();
//		printf("%lld %lld",gethash(1,3),gethash(4,6));
		for(int i=1;i<=slen;i++)
		{
//			printf("%d ",s[i]);
			totcnt[s[i]]++;
		}
		nowcnt[s[1]]++;
		for(int i=3;i<=slen;i++)
		{
			nowcnt[s[i-2]]--;
			nowcnt[s[i-1]]++;
			charcnt[s[i-2]]++;
			cnt1=cnt2=cnt3=0;
			for(int j=0;j<26;j++)
			{
				if(charcnt[j]&1)
				{
					cnt1++;
				}
				if((totcnt[j]-charcnt[j]-nowcnt[j])&1)
				{
					cnt2++;
				}
				if((totcnt[j]-2*charcnt[j]-2*nowcnt[j])&1)
				{
					cnt3++;
				}
			}
			cntnum[cnt1]++;
			match(i-1);
			for(int j=0;j<=cnt2;j++)
			{
				ans+=res2*cntnum[j];
			}
			for(int j=0;j<=cnt3;j++)
			{
				ans+=res3*cntnum[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
