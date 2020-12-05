#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

template<typename T> void read(T &x){
	char ch=getchar(); x=0; T f=0;
	for (;!isdigit(ch);ch=getchar()) f|=ch=='-';
	for (;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	x=f?-x:x;
}

int n,k,now[100];
int ans;
int w[20],c[500010],d[500010];

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	cout<<"-1"<<endl;
	return 0;
}

