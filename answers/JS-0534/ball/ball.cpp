#include<bits/stdc++.h>
using namespace std;
struct op{
	int from;
	int to;
}aop;
vector<op> ops;
vector<vector<int> > zhu;
int n,m;
bool check(){
	int cnt=0;
	for(int i=0;i<=n;i++){
		if(!zhu[i].size()) cnt++;
		for(int j=0;j<zhu[i].size();j++)
			if(zhu[i][j]!=zhu[i][0]) 
				return false;
	}
	return cnt==1;
}  
bool dfs(int deep,int k){
	if(k>deep) return false;
	if(check()) return true;
	else{
		for(int fr=0;fr<=n;fr++){
			for(int to=0;to<=n;to++){
				if(fr!=to&&zhu[fr].size()>0&&zhu[to].size()<m){
					aop.from=fr+1;
					aop.to=to+1;
					ops.push_back(aop);
					zhu[to].push_back(zhu[fr][zhu[fr].size()-1]);
					zhu[fr].pop_back();
					if(dfs(deep,k+1)) return true;
					ops.pop_back();
					zhu[fr].push_back(zhu[to][zhu[to].size()-1]);
					zhu[to].pop_back();
				}
			}
		}
		return false;	
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int ba,maxdeep=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++){
		vector<int> azhu;
		for(int j=0;j<m&&i!=n;j++){
			scanf("%d",&ba);
			azhu.push_back(ba);
		}
		zhu.push_back(azhu);
	}
	if(check()) printf("0");
	else{
		while(!dfs(maxdeep,0))
			maxdeep++;
		printf("%d\n",maxdeep);
		for(int i=0;i<ops.size();i++)
			printf("%d %d\n",ops[i].from,ops[i].to);	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

