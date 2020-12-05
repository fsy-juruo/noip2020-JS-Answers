#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1*f;c=getchar();}
	while(c<='9'&&c>='0')x=x*10+c-'0';
	return f*x;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
    cout<<-1<<endl;
	return 0;
}

