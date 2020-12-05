#include<bits/stdc++.h>
#define N 1200000
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int T,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	srand(time(0));
	T=read();
	while(T--){
		getline(cin,s);
		int x=rand()%1000+1;
		printf("%d\n",x);
	}
	return 0;
}

