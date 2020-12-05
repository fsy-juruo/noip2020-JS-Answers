#include<bits/stdc++.h>
using namespace std;
int n,m;
int du,duu;
struct nde{
	int num;
	int cou;// = bes.size
	vector <int> bes;
};
nde a[100002],temp,te;
bool isnp[100002];//isnp[i] == 1 => isn't jin
int cnt;

void dfs(int bi){
	cout<<bi;
	if(a[bi].cou == 0){
		
		return ;
	}
	int nms=a[bi].cou;
	
	for(int i=0;i<nms;++i){
		cout<<"->";
		dfs(a[bi].bes[i]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&du);
		a[i].num=i; a[i].cou=du;
		for(int j=0;j<du;++j)//vec start from 0
		{
			scanf("%d",&duu);
			a[i].bes.push_back(duu);
			isnp[duu]=1;
		}
	}
		for(int i=1;i<=n;++i){
		temp=a[i];
		cout<<temp.num<<' '<<temp.cou<<' ';
		for(int j=0;j<temp.cou;++j) cout<<temp.bes[j]<<' ';
		cout<<endl;
	}
	
//	cout<<a[1].bes[1]<<endl;
	for(int i=1;i<=n;++i){
		if(isnp[i] == 0){
			
			dfs(i);
			
		}
	}
	
	return 0;
}

//Ë¼Â·´íÎó!!! 

//	for(int i=1;i<=n;++i) cout<<isnp[i]<<' ';
