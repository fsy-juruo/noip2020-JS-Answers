#include<bits/stdc++.h>
using namespace std;
inline void read(long long &x)
{
	char ch;long long f=1;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f;
}
inline void write(long long x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);putchar(x%10+'0');
}
inline void writeln(long long x,char ch)
{
	write(x);
	putchar(ch);
}
struct node{
	long long p,q;
};
pair<long long,long long> f[100001];
node sum[100001];
node make_node(long long x,long long y)
{
	node a;
	a.p=x,a.q=y;
	return a;
}
long long gcd(long long a,long long b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
node Plus(node a,node b)
{
	node ans;
	if(a.q==b.q)
	{
		ans.q=a.q;
		ans.p=a.p+b.p;
		long long g=gcd(ans.p,ans.q);
	    ans.q/=g,ans.p/=g;
	}
	else
	{
		long long g=gcd(a.q,b.q),l=a.q*b.q/g;
		ans.q=l;
		ans.p=a.p*l/a.q+b.p*l/b.q;
		long long p=gcd(ans.p,ans.q);
		ans.p/=p,ans.q/=p;
	}
	return ans;
}
node divide(node a,long long b)
{
	node ans=a;
	if(a.p%b==0)
	{
		ans.p/=b;
	}
	else ans.q*=b;
	return ans;
} 
vector<long long> v[200001];
long long visit[200001];
priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > q;
long long n,m,x,c,a[200001],y;
void solve()
{
	long long jd,rd;
	while(!q.empty())
	{
		jd=q.top().second;
		rd=q.top().first;
		q.pop();
		if(!visit[jd])break;
	}
	//if(rd!=0)cout<<"马老师,发生肾摸事了"<<endl;
//	cout<<jd<<' '<<f[jd].first<<endl;
	if(visit[jd])return;
	visit[jd]=1;
	long long s=v[jd].size();
	if(s==0)
	{
		solve();
		return;
	}
	node f1=divide(sum[jd],s);
	sum[jd].p=0;
	for(long long i=0;i<s;i++)
	{
	    sum[v[jd][i]]=Plus(sum[v[jd][i]],f1);
	    f[v[jd][i]].first--;
	    q.push(f[v[jd][i]]);
	} 
//	for(long long i=1;i<=n;i++)
//	{
//		cout<<sum[i].p<<','<<sum[i].q<<' ';
//	}
//	cout<<endl;
	solve();
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	f[i].second=i;
	}
    for(int i=1;i<=n;i++)
    {
    	read(x);
    	if(x==0)
    	{
    		c++;
    		a[c]=i;
		}
    	for(int j=1;j<=x;j++)
    	{
    		read(y);
    		v[i].push_back(y);
    		f[y].first++;
		}
	}
//	cout<<"QwQ"<<endl;
	for(int i=1;i<=n;i++)
	{
		sum[i].q=1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
		//	cout<<i<<' '<<v[i][j]<<endl;
			sum[v[i][j]]=Plus(sum[v[i][j]],make_node(1,v[i].size()));
		//	cout<<"?"<<endl;
			f[v[i][j]].first--;		
		}
	}
	
	for(int i=m+1;i<=n;i++)
	{
	//	cout<<i<<' '<<f[i].first<<endl;
		q.push(f[i]);
	}
//		for(int i=1;i<=n;i++)
//	{
//		cout<<sum[i].p<<','<<sum[i].q<<' ';
//	}
//	cout<<endl;
	solve();
	for(int i=1;i<=c;i++)
	{
		cout<<sum[a[i]].p<<' '<<sum[a[i]].q<<endl;
	}
	return 0;
}

