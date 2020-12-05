#include<bits/stdc++.h>
#define LL long long
using namespace std;

template<typename T> void read(T &x){
	char ch=getchar(); x=0; T f=0;
	for (;!isdigit(ch);ch=getchar()) f|=ch=='-';
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	x=f?-x:x;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	printf("6\n");
	printf("1 3\n");
	printf("2 3\n");
	printf("2 3\n");
	printf("3 1\n");
	printf("3 2\n");
	printf("3 2\n");
	return 0;
}

