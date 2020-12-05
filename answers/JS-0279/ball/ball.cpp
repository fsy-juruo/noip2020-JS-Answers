#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[60];
vector<int> ans1,ans2;
inline int back(int x){
	int ans=1;
	for(int i=v[x].size()-2;i>=0;i--){
		if(v[i]==v[i+1])
			ans++;
		else
			break;
	}
	return ans;
}
int cnt;
void add(int x,int y){
	ans1.push_back(x),ans2.push_back(y);
	v[y].push_back(v[x].back());
	v[x].pop_back();
	cnt++;
}
void dfs(){
	if(v[1].size()==0){
		int a=back(2),b=back(3);
		if(a>b){
			for(int i=1;i<=a;i++){
				add(2,1);
			}
		}else{
			for(int i=1;i<=b;i++){
				add(3,1);
			}
		}
	}else if(v[2].size()==0){
		int a=back(1),b=back(3);
		if(a>b){
			for(int i=1;i<=a;i++){
				add(1,2);
			}
		}else{
			for(int i=1;i<=b;i++){
				add(3,2);
			}
		}
	}else if(v[3].size()==0){
		int a=back(1),b=back(2);
		if(a>b){
			for(int i=1;i<=a;i++){
				add(1,3);
			}
		}else{
			for(int i=1;i<=b;i++){
				add(2,3);
			}
		}
	}else{
		if(v[1].back()==v[2].back()){
			int a=back(1),b=back(2);
			if(rand()%2){
				for(int i=1;i<=a&&v[2].size()<m;i++)
					add(1,2);
			}else{
				for(int i=1;i<=b&&v[1].size()<m;i++)
					add(2,1);
				
			}
		}else if(v[1].back()==v[3].back()){
			int a=back(1),b=back(3);
			if(rand()%2){
				for(int i=1;i<=a&&v[3].size()<m;i++)
					add(1,3);
			}else{
				for(int i=1;i<=b&&v[1].size()<m;i++)
					add(3,1);
			}
		}else{
			int a=back(2),b=back(3);
			if(rand()%2){
				for(int i=1;i<=a&&v[3].size()<m;i++)
					add(2,3);
			}else{
				for(int i=1;i<=b&&v[2].size()<m;i++)
					add(3,2);
			}
		}
	}
	bool flag=1;
	for(int i=1;i<=n+1;i++){
		if(v[i].size()!=0&&v[i].size()!=m)
			flag=0;
		for(int j=1;j<v[i].size();i++)
			if(v[i][j]!=v[i][j-1])
				flag=0;
	}
	if(flag){
		printf("%d\n",cnt);
		for(int i=0;i<ans1.size();i++)
			printf("%d %d\n",ans1[i],ans2[i]);
		exit(0);
	}
	dfs();
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	dfs();
	return 0;
}
