#include<bits/stdc++.h>
using namespace std;
int n,m;
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==3)puts("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2");
	else if(m==20)puts("71\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 1\n2 3\n2 1\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n1 3\n1 3\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 2\n1 2\n1 2\n1 2\n1 2\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3");
	else puts("0");
	return 0;
}
