#include<cstdio>
#include<algorithm>

#define _N 100001
#define _K 6

#define _P 1000000007

#define lc(x) child[0][x]
#define rc(x) child[1][x]

#define int long long

int n,k;

int w[_K];

int c[_N],d[_N];

int x[_K];
int newx[_K];

int ncnt;
int root[_K];
int tree[_N*_K<<2];
int child[2][_N*_K<<2];

int cycle[_K];
int boardmx[_K];
int boardmn[_K];

void push_up(int x)
{
	tree[x]=std::min(tree[lc(x)],tree[rc(x)]);
}

void build(int& x,int l,int r)
{
	x=++ncnt;
	if(l==r)
	{
		tree[x]=0x3f3f3f3f;
		return;
	}
	int mid=(l+r)>>1;
	build(lc(x),l,mid);
	build(rc(x),mid+1,r);
	push_up(x);
}
void modify(int x,int l,int r,int p,int k)
{
	if(l==r)
	{
		tree[x]=std::min(tree[x],k);
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)
	{
		modify(lc(x),l,mid,p,k);
	}
	else
	{
		modify(rc(x),mid+1,r,p,k);
	}
	push_up(x);
}
int query(int x,int l,int r,int nl,int nr)
{
	if(nl<=l&&r<=nr)
	{
		return tree[x];
	}
	int ans=0x3f3f3f3f;
	int mid=(l+r)>>1;
	if(nl<=mid)
	{
		ans=std::min(ans,query(lc(x),l,mid,nl,nr));
	}
	if(nr>mid)
	{
		ans=std::min(ans,query(rc(x),mid+1,r,nl,nr));
	}
	return ans;
}

int calc()
{
	int res=0;
	int round=0x3f3f3f3f;
	int tmp=0x3f3f3f3f;
	for(int i=1;i<=k;i++)
	{
		if(cycle[i]>0)
		{
			round=std::min(round,(w[i]-x[i]-boardmx[i]<0?-cycle[i]:w[i]-x[i]-boardmx[i])/cycle[i]+1);
		}
		else if(cycle[i]<0)
		{
			round=std::min(round,(x[i]+boardmn[i])/-cycle[i]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		newx[i]=x[i]+round*cycle[i];
	}
	for(int i=1;i<=k;i++)
	{
		int k=query(root[i],0,100000<<1,0,100000-newx[i]);
		if(k!=0x3f3f3f3f)
		{
			tmp=std::min(tmp,k);
		}
		k=query(root[i],0,100000<<1,100000+w[i]-newx[i]+1,100000<<1);
		if(k!=0x3f3f3f3f)
		{
			tmp=std::min(tmp,k);
		}
	}
	return (n*round%_P+tmp)%_P;
}

void print_calc()
{
	printf("pos: ");
	for(int i=1;i<=k;i++)
	{
		printf("%lld ",x[i]);
	}
	puts("");
	printf("res: %lld\n",calc());
}

void print_cycle()
{
	printf("cycle: ");
	for(int i=1;i<=k;i++)
	{
		printf("%lld ",cycle[i]);
	}
	puts("");
}

int dfs(int v)
{
	if(v==k+1)
	{
//		print_calc();
		return calc();
	}
	int ans=0;
	for(int i=1;i<=w[v];i++)
	{
		x[v]=i;
		ans=(ans+dfs(v+1))%_P;
	}
	return ans;
}

void simulate()
{
	for(int i=1;i<=n;i++)
	{
		cycle[c[i]]+=d[i];
		boardmx[c[i]]=std::max(boardmx[c[i]],cycle[c[i]]);
		boardmn[c[i]]=std::min(boardmn[c[i]],cycle[c[i]]);
		modify(root[c[i]],0,100000<<1,100000+cycle[c[i]],i);
	}
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&w[i]);
		build(root[i],0,100000<<1);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&c[i],&d[i]);
	}
	simulate();
//	print_cycle();
	printf("%lld\n",dfs(1));
	return 0;
}
