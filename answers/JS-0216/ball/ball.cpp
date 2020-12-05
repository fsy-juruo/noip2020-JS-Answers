#include<bits/stdc++.h>
const int mas=820000;
using namespace std;
int n,m,sum,ans;
stack<int> a[51];
int d[51];
void 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1,x;j<=m;j++){
			cin>>x;
			if(j==1) d[i]=x;  
			a[i].push(x);
		}
	}
	dfs();
 return 0;
 }
 

