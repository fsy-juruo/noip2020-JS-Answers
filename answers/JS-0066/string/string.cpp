#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
ll readll()
{
	char c=getchar(); ll neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c)
{
	writeint(x); putchar(c); return;
}
void Writell(ll x,char c)
{
	writell(x); putchar(c); return;
}
const ll mod=998244353;
const int maxlen=(1<<20)+5;
const int maxlet=35;
char s[maxlen];
ll val[maxlen],p1233[maxlen];
int times[maxlet],lim[maxlen];
vector<int> queries[maxlen];
ll tot[maxlet];
void add(int pos,ll val)
{
	while(pos<=26)
	{
		tot[pos]+=val;
		pos+=pos&(-pos);
	}
	return;
}
ll query(int pos)
{
	ll res=0;
	while(pos)
	{
		res+=tot[pos];
		pos-=pos&(-pos);
	}
	return res;
}
void fl()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int main()
{
//	printf("%.24lf\n",(sizeof(lim)+sizeof(maxlen)+sizeof(maxlet)+sizeof(mod)+sizeof(p1233)+sizeof(s)+sizeof(times)+sizeof(tot)+sizeof(val)+sizeof(p1233)*20)/1024.0/1024.0);
	fl();
	int t=readint();
	p1233[0]=1;
	for(int i=1;i<=(1<<20);i++)
		p1233[i]=p1233[i-1]*1233%mod;
	while(t--)
	{
		scanf("%s",s);
		int n=(int)strlen(s);
		for(int i=1;i<=n;i++)
			val[i]=(val[i-1]*1233+(s[i-1]-'a'+1))%mod;
		for(int i=0;i<26;i++)
			times[i]=0;
		for(int i=n;i>=1;i--)
		{
			times[s[i-1]-'a']^=1;
			if(times[s[i-1]-'a']&1)
				lim[i]=lim[i+1]+1;
			else lim[i]=lim[i+1]-1;
		}
		for(int i=1;i<=n;i++)
			queries[i].clear();
		for(int rounds=2;rounds<n;rounds++)
		{
			ll type=val[rounds];
			for(int c=1;c*rounds<n;c++)
			{
				ll cur=val[c*rounds]-val[(c-1)*rounds]*p1233[rounds]%mod;
				cur+=(cur<0)*mod; cur-=(cur>=mod)*mod;
				if(cur!=type) break;
				queries[rounds-1].push_back(lim[c*rounds+1]+1);
			}
		}
		for(int i=1;i<=26;i++)
			tot[i]=0;
		for(int i=0;i<26;i++)
			times[i]=0;
		int odds=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			times[s[i-1]-'a']^=1;
			if(times[s[i-1]-'a']&1)
				odds++;
			else odds--;
			add(odds+1,(ll)1);
			for(int j=0;j<(int)queries[i].size();j++)
				ans+=query(queries[i][j]);
		}
		Writell(ans,'\n');
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/

