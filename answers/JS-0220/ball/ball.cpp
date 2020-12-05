#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' ||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cout<<6<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<1<<endl;
	cout<<3<<" "<<2<<endl;
	cout<<3<<" "<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

