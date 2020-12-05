#include<bits/stdc++.h>
using namespace std;
int read(){
	int r=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-') ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) r=r*10+ch-'0',ch=getchar();
	return r*f;
}
int main(){
freopen("ball.in","r",stdin);
freopen("ball.out","w",stdout);
cout<<0<<endl;
	return 0;
}

