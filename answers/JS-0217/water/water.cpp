#include<bits/stdc++.h>
using namespace std;
int n,m,d,a,p[100001],q[100001];
bool b[100001],s;
vector<int> v[100001];
void w(int x,int y){
	if(!v[x].size()){
		p[x]=p[x]*y+q[x];
		q[x]*=y;
		return;
	}
	for(int i=0;i<v[x].size();i++)
		w(v[x][i],y*v[x].size());
}
void hj(int x,int y){
	for(int i=2;i<=x;i++){
		if(x%i==0&&y%i==0)
		    hj(x/i,y/i);
		if(s)
		    return;
	}
	printf("%d %d\n",x,y);
	s=true;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		q[i]=1;
		for(int j=1;j<=d;j++){
		    scanf("%d",&a);
		    b[a]=true;
		    v[i].push_back(a);
		}
	}
	for(int i=1;i<=n;i++)
		if(!b[i]){
			m--;
			w(i,1);
			if(!m)
			    break;
		}
	for(int i=1;i<=n;i++)
	    if(!v[i].size()){
	    	hj(p[i],q[i]);
	    	s=false;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
