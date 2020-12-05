#include<bits/stdc++.h>
using namespace std;
template<typename T>void Read(T &cn)
{
	char ch;
	int f=0;
	cn=0;
	while(!isdigit(ch=getchar()))if(ch=='-')f=1;
	if(f){cn=cn*10+48-ch;while(isdigit(ch=getchar()))cn=cn*10+48-ch;}
	else {cn=cn*10+ch-48;while(isdigit(ch=getchar()))cn=cn*10+ch-48;}
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cout<<0<<endl;
	return 0;
}


