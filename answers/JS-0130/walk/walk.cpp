#include <fstream>
#include <cstdlib>
using namespace std;

ifstream cin("walk.in");
ofstream cout("walk.out");
int n,k;
int w[15],c[500005],d[500005];
int cnt[15];
int beg[15],posi[15];
long long ans;
void walk(){
	int p=1;
	for(int i=1;i<=k;i++){
		posi[i]=beg[i];
	}
	while(1){
		posi[c[p]]+=d[p];
		ans++;
		if(ans==1000000007){
			ans=0;
		}
		//if(ans>1000000){
		//	cout<<-1<<endl;
		//	exit(0);
		//}
		if(posi[c[p]]>w[c[p]]||posi[c[p]]<=0)break;
		p++;
		if(p==n+1){
			p=1;
		}
	}
}
		
void dfs(int c){
	if(c==k+1){
		//cout<<"c="<<c<<endl;
		walk();
		//cout<<"ans="<<ans<<endl;
		return;
	}
	for(int i=1;i<=w[c];i++){
		beg[c]=i;
		dfs(c+1);
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

