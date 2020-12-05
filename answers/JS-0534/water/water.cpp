#include<bits/stdc++.h>
using namespace std;
struct fen{
	long long fenzi;
	long long fenmu;
	fen(){
		fenzi=0;
		fenmu=1;
	}
}f;
int gcd(long long i,long long j){
	return i%j?gcd(j,i%j):j;
}
fen ps(fen i,fen j){
	long long l=i.fenmu*j.fenmu/gcd(i.fenmu,j.fenmu);
	long long z=i.fenzi*l/i.fenmu+j.fenzi*l/j.fenmu;
	fen t;
	t.fenmu=l/gcd(l,z);
	t.fenzi=z/gcd(l,z);
	return t;
}
fen div(fen i,int j){
	if(!(i.fenzi%j))
		i.fenzi/=j;
	else
		i.fenmu*=j;
	return i;
}
void print(fen i){
	printf("%lld %lld",i.fenzi,i.fenmu);
}
map<int,fen> node;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,edge,con;
	vector<int> out;
	scanf("%d%d",&n,&m);
	fen f1,f2;
	for(int i=1;i<=n;i++){
		scanf("%d",&edge);
		if(i<=m){
			f.fenzi=1;
			f.fenmu=1;
			node[i]=f;
			f.fenmu=edge;
			for(int j=0;j<edge;j++){
				scanf("%d",&con);
				node[con]=ps(node[con],f);
			}
		}
		else if(edge){
			for(int j=0;j<edge;j++){
				scanf("%d",&con);
				node[con]=ps(node[con],div(node[i],edge));
			}	
		}
		else{
			out.push_back(i);
		}
	}
	int i=0;
	print(node[out[i]]);
	for(int i=1;i<out.size();i++){
		printf("\n");
		print(node[out[i]]);	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

