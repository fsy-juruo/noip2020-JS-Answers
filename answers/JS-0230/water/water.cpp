#include<bits/stdc++.h>
#define FILEIO(x) do{freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);}while(0)
using namespace std;
template<typename T>
void ri(T&x)
{
	x=0;
	int neg=1;
	char c=getchar();
	for (;!(isdigit(c)||c=='-');c=getchar());
	if (c=='-') neg=-1,c=getchar();
	for (;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=neg;
}
#ifdef MYDBG
#define DEBUG(x) cerr<<#x<<":"<<x<<" "
#define DEBUGL(x) cerr<<#x<<":"<<x<<endl
#else
#define DEBUG(x)
#define DEBUGL(x)
#endif
#define ALL(x) (x).begin(), (x).end()
const int MAXN=1<<18;
typedef long long ll;
vector<int> G[MAXN];
int degIn[MAXN];
ll gcd(ll x,ll y)
{
    return y==0?x:gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
    return x/gcd(x,y)*y;
}
struct Q
{
    ll x,y;
    Q(ll _x=0,ll _y=1){x=_x,y=_y;}
    void normalize()
    {
        ll t=gcd(x,y);
        x/=t;
        y/=t;
    }
    Q&operator+=(const Q& o)
    {
        x=x*(lcm(o.y,y)/y)+o.x*(lcm(o.y,y)/o.y);
        y=lcm(o.y,y);
        normalize();
        return *this;
    }
    Q&operator*=(const Q&o)
    {
        x*=o.x;
        y*=o.y;
        normalize();
        return *this;
    }
    Q&operator/=(const Q&o)
    {
        x*=o.y;
        y*=o.x;
        normalize();
        return *this;
    }
};
Q w[MAXN];
int main()
{
	FILEIO("water");
	int n;
	ri(n);
	int m;
	ri(m);
	vector<int> outNode;
	for (int i=0;i<n;i++)
    {
        int k;
        ri(k);
        if (k==0) outNode.push_back(i);
        for (int j=0;j<k;j++)
        {
            int x;
            ri(x);
            --x;
            G[i].push_back(x);
            degIn[x]++;
        }
    }
    queue<int> q;
    for (int i=0;i<n;i++)
    {
        if (degIn[i]==0) q.push(i),w[i]=Q(1);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        Q tmpW=w[u];
        tmpW/=Q(G[u].size());
        for (int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            w[v]+=tmpW;
            degIn[v]--;
            if (degIn[v]==0) q.push(v);
        }
    }
    for (int i=0;i<outNode.size();i++)
    {
        printf("%lld %lld\n",w[outNode[i]].x,w[outNode[i]].y);
    }
	return 0;
}
