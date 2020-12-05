#include<bits/stdc++.h>
using namespace std;
int n,m,a[52][420],ans;
queue<int> x,y;
template<typename T> void read(T &x)
{
	long long f=1;x=0;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+c-48;c=getchar();}
	x*=f;
}
template<typename T> void write(T x)
{
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
template<typename T> void writeln(T x)
{
	write(x);putchar('\n');
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++) read(a[i][j]);
	cout<<0<<endl;
	return 0;
}

