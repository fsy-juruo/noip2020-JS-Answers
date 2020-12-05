#include <bits/stdc++.h>
using namespace std;
const int MAXN=1100005;
const int p=100000007;
struct SegTree
{
	int a,b,c;
	SegTree *lson,*rson;
}add[MAXN<<1],*root=&add[0];/*
struct node
{
	int a,b,c;
	inline void init(void){a=c=0,b=1;}
	inline void inn(SegTree *tree){a=tree->a,b=tree->b,c=tree->c;}
	inline void merge(node x){a+=x.a,b*=x.b,c^=x.c;}
}temp,b[MAXN];*/
int T,n,i,j,t,ji,ans,len,blo,maxv,a[MAXN],tc[30],ta[30],fa[MAXN];
char ch[MAXN];
inline void print(int x)
{
	if (x<0)
		putchar('-'),x=-x;
	if (x>9)
		print(x/10);
	putchar(x%10+'0');
}/*
inline void build(SegTree *tree,int l,int r)
{
	if (l==r)
	{
		tree->a=tree->b=tree->c=a[l];
		return;
	}
	int mid=(l+r)>>1;
	tree->lson=&add[++t];
	tree->rson=&add[++t];
	build(tree->lson,l,mid);
	build(tree->rson,mid+1,r);
	tree->a=(tree->lson->a+tree->rson->a)%p;
	tree->b=(tree->lson->b*tree->rson->b)%p;
	tree->c=(tree->lson->c^tree->rson->c)%p;
}
inline node query(SegTree *tree,int l,int r,int x,int y)
{
	node res;
	res.init();
	if (x<=l && r<=y)
	{
		res.inn(tree);
		return res;
	}
	int mid=(l+r)>>1;
	if (x<=mid)
		res.merge(query(tree->lson,l,mid,x,y));
	if (y>mid)
		res.merge(query(tree->rson,mid+1,r,x,y));
	return res;
}*/
signed main(void)
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		ans=0;
		scanf("%s",ch);
		n=strlen(ch);/*
		for (i=1;i<=n;i++)
			a[i]=ch[i-1]-'a'+2;
		build(root,1,n);
		blo=1,len=n,maxv=0;
		for (i=n/2;i>=1;i--)
		{
			temp=query(root,1,n,1,i);
			for (j=i+1;j<=n;j+=i)
			{
				node qaqaq=query(root,1,n,j,j+i-1);
				if (!(temp.a==qaqaq.a && temp.b==qaqaq.b && temp.c==qaqaq.c))
					break;
				else
					b[j].a=(j-1)/i,b[j].b=i;
			}
			if (j-1>maxv && j!=i+1)
				maxv=j-1,blo=(j-1)/i,len=i;
		}
		for (ji=0,i=1;i<=n;i++)
		{
			if (ta[a[i]]%2)
				ji--;
			else
				ji++;
			ta[a[i]]++;
			fa[i]=ji;
		}
		for (ji=0,i=n;i>=3;i--)
		{
			if (tc[a[i]]%2)
				ji--;
			else
				ji++;
			tc[a[i]]++;
			for (j=1;j<i-1;j++)
				if (fa[j]<=ji)
				{
					int qaqaq=ceil(double(j)/b[j].b);
					for (int l=qaqaq;l<=b[j].a;l++)
						if (!(b[j].a%l))
							ans++;
				}
		}
		print(ans),putchar('\n');*/
		ans=(n-1)*(n-2)/2;
		if (n&1)
			for (i=2;i<=n-3;i+=2)
				ans-=i;
		else
			for (i=1;i<=n-3;i+=2)
				ans-=i;
		print(ans),putchar('\n');
	}
	return 0;
}
