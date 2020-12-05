#include<bits/stdc++.h>
using namespace std;
const int N=60,M=500;
int n,m,h[N][N],t[N],v[N],temh[N];
vector<int> a[N];
bool Check(){
	for(int i=1;i<=n+1;++i){
		for(int j=0;j<a[i].size();++j){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	for(int i=1;i<=n+1;++i)
		if(a[i].size()&&h[i][a[i][a[i].size()-1]] !=m) return false;
	return true;
}
int ct(){//找位于顶部最多同色的小球 
	memset(t,0,sizeof(t));
	int Max=0,ans;
	for(int i=1;i<=n+1;++i){
		if(v[i]||a[i].size()==0) continue;
		t[ a[i][a[i].size()-1] ]++;
		for(int j=a[i].size()-2;j>=0;--j){
			if(a[i][j]!=a[i][j+1]) break;
			t[a[i][a[i].size()-1]]++;
		}
		if(t[a[i][a[i].size()-1]]>Max){
			Max=t[a[i][a[i].size()-1]];
			ans=a[i][a[i].size()-1];
		}
	}
	return ans;
}
void Clear(int x){
	while(a[x].size()){
		for(int i=1;i<=n+1;++i){
			if(i==x) continue;
			while(a[i].size()<m&&a[x].size()){
				a[i].push_back(a[x].back());
				h[i][a[x].back()]++;
				h[x][a[x].back()]--;
				cout<<x<<" "<<i<<endl;
				a[x].pop_back();
			}
		}
	}
}
priority_queue< pair<int,int> > p;
void Put(int x,int y){
	while(a[x].size()<m){
		bool pan1=1;
		for(int i=1;i<=n+1;++i){
			if(h[i][y]&&v[i]==0){
				while(a[i][a[i].size()-1]==y){
					a[x].push_back(y);
					h[x][y]++;
					a[i].pop_back();
					h[i][y]--;
					cout<<i<<" "<<x<<endl;
					pan1=0;
				}
				p.push(make_pair(-a[i].size()+(h[i][y]==0 ? 1000 : 0) ,i));
			}
			if(pan1&&i==n+1){
				for(int j=1;j<=n+1;++j){
					if(j!=x&&a[j].size()<m&&h[j][y]){
						while(a[j][a[j].size()-1]!=y){
							a[x].push_back(a[j][a[j].size()-1]);
							h[x][a[j][a[j].size()-1]]++;
							h[j][a[j][a[j].size()-1]]--;
							a[j].pop_back();
							cout<<j<<" "<<x<<endl;
						}
						int jj;
						for(jj=1;jj<=n+1;++jj){
							if(jj!=j&&jj!=x) break;
						}
						while(a[x].size()<m&&a[jj][a[jj].size()-1]!=y){
							a[x].push_back(a[jj][a[jj].size()-1]);
							h[x][a[jj][a[jj].size()-1]]++;
							h[jj][a[jj][a[jj].size()-1]]--;
							a[jj].pop_back();
							cout<<jj<<" "<<x<<endl;
						}
						while(a[jj].size()<m&&a[j][a[j].size()-1]==y){
							a[jj].push_back(a[j][a[j].size()-1]);
							h[jj][a[j][a[j].size()-1]]++;
							h[j][a[j][a[j].size()-1]]--;
							a[j].pop_back();
							cout<<j<<" "<<jj<<endl;
						}
						while(a[j].size()<m&&a[x][a[x].size()-1]!=y){
							a[j].push_back(a[x][a[x].size()-1]);
							h[j][a[x][a[x].size()-1]]++;
							h[x][a[x][a[x].size()-1]]--;
							a[x].pop_back();
							cout<<x<<" "<<j<<endl;
						}
					}
				}
			}
		}//放一轮
		memset(temh,0,sizeof(temh));
		while(1&&p.size()){
			int temx=p.top().second;
			p.pop();
			temh[temx]=1;
			bool pan2=1;
			for(int i=1;i<=n+1&&a[temx].size()<m;++i){
				if(v[i]||temh[i]==1) continue;
				while(h[i][y]&&a[i][a[i].size()-1]!=y&&a[temx].size()<m){
					a[temx].push_back(a[i][a[i].size()-1]);
					h[temx][a[i][a[i].size()-1]]++;
					h[i][a[i][a[i].size()-1]]--;
					cout<<i<<" "<<temx<<endl;
					a[i].pop_back();
					
					pan2=0;
				}
			}
			if(pan2) break;
		}
		while(p.size()) p.pop();
		Check();
	}
}
int main(){
//	freopen("ball.in","r",stdin);
	freopen("ball,out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
			h[i][x]++;
		}
	}
	for(int i=n+1;i>1;--i){
		if(Check()) break;
		Clear(i);
		v[i]=1;
		Put(i,ct());
	}
	return 0;
}

