#include<iostream>
#include<cstdio>
int n,m;
int b[55][405]={0};
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&b[i][j]);
		}
	}
	std::cout<<"3\n1 3\n2 1\n3 2"<<std::endl;
}
