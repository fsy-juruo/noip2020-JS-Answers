#include<bits/stdc++.h>
using namespace std;
vector<int>v[110];
int h[110];
void atob(int a,int b){
	v[b].push_back(v[a].back());
	v[a].pop_back();
}
vector<pair<int,int> >ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	int em=n+1;
	for(int i=1;i<n;i++){
		for(int cnt=1;cnt<=m;cnt++){
			int mi=0,mj=0;
			for(int j=1;j<=n+1;j++){
				if(j!=em){
					for(int k=0;k<v[j].size();k++){
						if(v[j][k]==i){
							mi=j;
							mj=k+1;
							break;
						}
					}
					if(mi)break;
				}
			}
			int mid=0;
			for(int j=1;j<=n;j++){
				if(j!=mi&&j!=em){
					mid=j;
					break;
				}
			}
			int flg=0;
			if(v[mid].size()==m){
				ans.push_back(make_pair(mid,em));
				atob(mid,em);
				flg=1;
			}
			int xx=v[mi].size()-mj;
			for(int j=1;j<=xx;j++){
				ans.push_back(make_pair(mi,em));
				atob(mi,em);
			}
			ans.push_back(make_pair(mi,mid));
			atob(mi,mid);
			for(int j=1;j<=xx;j++){
				ans.push_back(make_pair(em,mid));
				atob(em,mi);
			}
			if(flg){
				ans.push_back(make_pair(em,mi));
				atob(em,mi);
			}
			ans.push_back(make_pair(mid,em));
			atob(mid,em);
//			cout<<"=="<<mi<<" "<<mj<<" "<<mid<<" "<<em<<endl;
			if(flg){
				ans.push_back(make_pair(mi,mid));
				atob(mi,mid);
			}
//			for(int i1=1;i1<=n+1;i1++){
//				for(int j1=0;j1<v[i1].size();j1++){
//					cout<<v[i1][j1]<<" ";
//				}
//				cout<<endl;
//			}
		}
		h[em]=i;
		for(int j=1;j<=n;j++){
			if(!h[j]){
				em=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(!h[j]&&j!=em){
				for(int k=v[j].size();k<m;k++){
					ans.push_back(make_pair(em,j));
					atob(em,j);
				}
			}
		}
//		cout<<"=="<<em<<endl;
//		for(int i1=1;i1<=n+1;i1++){
//			for(int j1=0;j1<v[i1].size();j1++){
//				cout<<v[i1][j1]<<" ";
//			}
//			cout<<endl;
//		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
