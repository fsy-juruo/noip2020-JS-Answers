#include <bits/stdc++.h>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
vector<pii> ans;
bool vis[55];
stack<int> a[55];
int des,spa;
int deplowest(int col){
	int mn=1e9,poi=-1;
	for(int i=1;i<=n+1;i++){
		vector<int> v;
		if(!vis[i]&&i!=des){
			while(!a[i].empty()&&a[i].top()!=col){
				//cout<<1;
				v.push_back(a[i].top());
				a[i].pop();
			}
			//cout<<111;
			int t=v.size();
			for(int j=t-1;j>=0;j--){
				a[i].push(v[j]);
			}
			if(t==a[i].size()){
				//cout<<"111";
				continue;
			}
			else{
				if(t<mn){
					poi=i;
					mn=t;
				}
			}
		}
	}
	return poi;
}
int findmaxball(){
	int ball[55];
	memset(ball,0,sizeof(ball));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			if(vis[j]){
				continue;
			}
			int mm=a[j].size();
			while(!a[j].empty()&&a[j].top()==i){
				a[j].pop();
				ball[i]++;
			}
			if(mm!=0){
				while(a[j].size()<mm){
					a[j].push(i);
				}
			}
			
		}
	}
	int mx=0,poi=-1;
	for(int i=1;i<=n;i++){
		if(ball[i]>mx){
			poi=i;
			mx=ball[i];
		}
	}
	return poi;
}
void throwaway(int x){
	for(int i=1;i<=n+1;i++){
		if(a[i].size()<m&&i!=des&&!vis[i]&&i!=x){
			ans.push_back(pii(x,i));
			a[i].push(a[x].top());
			a[x].pop();
			return;
		}
	}
}
void solve(int col){
	for(int i=1;i<=n+1;i++){
		if(a[i].empty()){
			des=i;
			break;
		}
	}
	for(int i=1;i<=n+1;i++){
		if(!vis[i]&&i!=des&&a[i].top()==col){
			ans.push_back(pii(i,des));
			a[des].push(a[i].top());
			a[i].pop();
			
		}
	}
	while(a[des].size()!=m){
		int goal=deplowest(col);
		while(a[goal].top()!=col){
			throwaway(goal);
		}
		ans.push_back(pii(goal,des));
		a[des].push(a[goal].top());
		a[goal].pop();
		//cout<<a[des].size()<<" ";
	}
	vis[des]=1;
	for(int i=1;i<=n;i++){
		if(i!=des&&!vis[i]){
			while(!a[i].empty()){
				throwaway(i);
			}
			return;
		}
	}
}
stack<int> a1,a2,a3;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	/*
	if(n==2){
		int tmp,cnt1=0,cnt2=0;
		for(int i=0;i<m;i++){
			cin>>tmp;
			a1.push(tmp);
			if(tmp==1){
				cnt1++;
			}
		}
		for(int i=0;i<m;i++){
			cin>>tmp;
			a2.push(tmp);
			if(tmp==1){
				cnt2++;
			}
		}
		if(cnt2>cnt1){
			for(int i=0;i<m;i++){
				ans.push_back(pii(2,3));
				a3.push(a2.top());
				a2.pop();
			}
			for(int i=0;i<m;i++){
				ans.push_back(pii(1,2));
				a2.push(a1.top());
				a1.pop();
			}
			for(int i=0;i<m;i++){
				ans.push_back(pii(3,1));
				a1.push(a3.top());
				a3.pop();
			}
		}	
		int cnt=m-cnt1;
		while(cnt--){
			ans.push_back(pii(2,3));
			a3.push(a2.top());
			a2.pop();
		}
		cnt=m-cnt1;
		while(cnt){
			if(a1.top()==2){
				ans.push_back(pii(1,2));
				a1.pop();
				a2.push(2);
				cnt--;
			}
			else{
				ans.push_back(pii(1,3));
				a1.pop();
				a3.push(1);
			}
		}
		while(!a3.empty()&&a3.top()==1){
			ans.push_back(pii(3,1));
			a1.push(1);
			a3.pop();
		}
		while(!a2.empty()){
			if(a2.top()==1){
				ans.push_back(pii(2,1));
				a1.push(1);
				a2.pop();
			}
			else{	
				
				if(a3.size()<m){
					ans.push_back(pii(2,3));
					a3.push(2);
					a2.pop();
				}
				else{
					ans.push_back(pii(2,1));
					a1.push(2);
					a2.pop();
				}
			}
		}
		while(!a3.empty()&&a3.top()==2){
			ans.push_back(pii(3,2));
			a2.push(2);
			a3.pop();
		}
		while(!a1.empty()){
			if(a1.top()==2){
				ans.push_back(pii(1,2));
				a1.pop();
				a2.push(2);
				cnt--;
			}
			else{
				ans.push_back(pii(1,3));
				a1.pop();
				a3.push(1);
			}
		}
		while(!a3.empty()){
			ans.push_back(pii(3,1));
			a1.push(1);
			a3.pop();
		}
	}
	//cout<<findmaxball()<<endl;
	else{*/
		for(int i=1;i<=n;i++){
			int tmp;
			for(int j=0;j<m;j++){
				scanf("%d",&tmp);
				a[i].push(tmp);
			}
		}
		for(int t=1;t<=n;t++){
			//cout<<a[4].empty()<<endl;
			//cout<<findmaxball()<<endl;
			int tmp=findmaxball();
			//cout<<tmp<<" ";
			solve(tmp);
		}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}
/*
3 3
1 3 3
2 2 1
2 3 1
*/
