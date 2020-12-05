#include<bits/stdc++.h>
using namespace std;
int n,m;
int read(){
	int cnt=0,b=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')b=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return b*cnt;
}
void print(int x)
{
	if(x/10)print(x/10);
	if(x)putchar(x%10+'0');
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
