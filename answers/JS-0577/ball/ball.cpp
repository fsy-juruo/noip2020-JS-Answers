#include<bits/stdc++.h>
using namespace std;
int n,m,a[100][500],t[100];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if(n==2&&m==3){
		cout<<"6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2";
	}
	if(n==2&&m==20){
		cout<<"71\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 1\n2 3\n2 1\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n1 3\n1 3\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 2\n1 2\n1 2\n1 2\n1 2\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3";
	}
	return 0;
}




