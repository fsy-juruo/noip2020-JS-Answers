#include<bits/stdc++.h>
using namespace std;
int d[100001][6],end[100001],l=1;
long long a[100001],b[100001];
int yyc(int x,int y){
	if(x%y==0){
		return y;
	}
	return yyc(y,x%y);
}
void in(int x,int y,int id){
	
	for(int i=1;i<=d[id][0];i++){
		in(x,y*d[id][0],d[id][i]);
	}
	if(d[id][0]==0){
		a[id]=a[id]*y+x*b[id];
		b[id]*=y;
		int p=yyc(a[id],b[id]);
		a[id]/=p;
		b[id]/=p;
	}
	return ;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i][0];
		a[i]=0;
		b[i]=1;
		for(int j=1;j<=d[i][0];j++){
		cin>>d[i][j];
		}
		if(d[i][0]==0){
			end[l]=i;
			l++;
		}
	}
	sort(end+1,end+l);
	for(int i=1;i<=m;i++){
		in(1,1,i);
	}
	for(int i=1;i<l;i++){
		cout<<a[end[i]]<<' '<<b[end[i]]<<endl;
	}
	return 0;
}


