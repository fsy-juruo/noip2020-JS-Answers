#include <stdio.h>
#include <vector>
using namespace std;

class num{
	private:
		long long upper,under;
		long long gcd(long long x,long long y)
		{
			long long z=x%y;
			while(z!=0)
			{
				x=y;
				y=z;
				z=x%y;
			}
			return y;
		}
		num yue_fen(num x)
		{
			long long g=gcd(x.under,x.upper);
			x.under/=g;
			x.upper/=g;
			return x;
		}
	public:
		num operator /(const int &x)
		{
			num ans;
			ans.upper=this->upper;
			ans.under=this->under*x;
			return yue_fen(ans);
		}
		num operator +(const num &x)
		{
			num ans;
			ans.upper=this->upper*x.under+this->under*x.upper;
			ans.under=this->under*x.under;
			return yue_fen(ans);
		}
		void set(long long x)
		{
			this->upper=x;
			this->under=1;
		}
		num()
		{
			this->upper=0;
			this->under=1;
		}
		void print()
		{
			printf("%lld %lld\n",this->upper,this->under);
			return;
		}
};

class queue{
	private:
		int a[100010];
		int _front,_end;
	public:
		queue()
		{
			_front=_end=0;
			return;
		}
		bool empty()
		{
			return _front>=_end;
		}
		int front()
		{
			if(!this->empty())
				return a[_front];
			return -1;
		}
		void push(int x)
		{
			a[_end++]=x;
			return;
		}
		void pop()
		{
			if(!this->empty())
				_front++;
			return;
		}
};

int n;
vector<int> to[100010];
queue q;
int indg[100010];
num f[100010];

int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++)
	{
		int d;
		scanf("%d",&d);
		for(int j=0;j<d;j++)
		{
			int x;
			scanf("%d",&x);
			to[i].push_back(x);
			indg[x]++;
		}
	}
	for(int i=1;i<=n;i++)
		if(indg[i]==0)
		{
			q.push(i);
			f[i].set(1);
		}
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		num ad=f[p]/to[p].size();
		for(vector<int>::iterator it=to[p].begin();it!=to[p].end();it++)
		{
			f[*it]=f[*it]+ad;
			indg[*it]--;
			if(indg[*it]==0)
				q.push(*it);
		}
	}
	for(int i=1;i<=n;i++)
		if(to[i].empty())
			f[i].print();
	return 0;
}
