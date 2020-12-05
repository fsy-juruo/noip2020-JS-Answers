#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
template <typename T>
void read(T &x)
{
	T f = 1; x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	x *= f;
}
template <typename T>
void write(T x)
{
	if (x < 0){
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar((char)(x % 10 + '0'));
}
template <typename T>
void writeln(T x, char ch = '\n')
{
	write(x); putchar(ch);
}
struct node{
	long long mth, son;
};
long long gcd(long long aa, long long bb)
{
	if (bb == 0) return aa;
	else return gcd(bb, aa % bb);
}
int n, m, d, x;
vector <int> a[MAXN];
queue <int> q;
int ins[MAXN];
node num[MAXN];
node calc(node st, node pos)
{
	if (pos.son == 0)
	{
		pos.mth = st.mth;
		pos.son = st.son;
		return pos;
	}
	long long g = gcd(st.mth, pos.mth);
	long long mot = st.mth / g * pos.mth / g * g;
	long long sn = pos.mth / g * st.son + st.mth / g * pos.son;
	g = gcd(mot, sn); 
	node ret;
	ret.mth = mot / g; ret.son = sn / g; 
	return ret;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n); read(m);
	for (int i = 1; i <= n; i++)
	{
		read(d);
		for (int j = 1; j <= d; j++)
		{
			read(x);
			a[i].push_back(x);
			ins[x]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		q.push(i);
		num[i].mth = 1; num[i].son = 1;
	}
	node pr;
	while (!q.empty())
	{
		int s = q.front();
		q.pop();
		long long pk = a[s].size();
		for (int i = 0; i < pk; i++)
		{
			int v = a[s][i]; pr.son = num[s].son; pr.mth = num[s].mth * pk;
			long long g = gcd(pr.son, pr.mth); pr.son /= g; pr.mth /= g;
			num[v] = calc(pr, num[v]);
			ins[v]--;
			if (ins[v] == 0) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!a[i].size())
		{
			cout << num[i].son<< " " << num[i].mth << '\n'; 
		}
	}
	return 0;
}
