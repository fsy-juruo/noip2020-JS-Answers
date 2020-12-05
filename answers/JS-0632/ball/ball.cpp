//Stay Determined, Be the Hollow Knight!
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
int n,m,a[55][405],ta[55][405],tk[55],k[55],cn[55];
vector <pair<int,int> > ans,tmp;
void pt(){
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=tk[i];j++){
			cout<<ta[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cn[i]=true;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			cin>>a[i][j];
		}
		k[i]=m;
	}
	for (int g=n+1;g>=3;g--){
		bool ok;
		for (int cc=1;cc<=n;cc++){
//			cout<<"           "<<cc<<endl;
			if (!cn[cc]) continue;
			ok=true;
			for (int i=1;i<=n+1;i++){
				for (int j=0;j<=m;j++) ta[i][j]=a[i][j];
				tk[i]=k[i];
			}
			tmp.clear();
			for (int i=1;i<=m;i++){
				int av=i-1;
				bool fd=false;
				for (int j=1;j<g;j++){
					int pos=-1;
					for (int l=tk[j];l>0;l--){
						if (ta[j][l]==cc){
							pos=l;
							break;
						}
					}
					if (pos==-1) continue;
//					pt();
//					cout<<i<<' '<<tk[j]<<' '<<pos<<endl;
//					cout<<cc<<' '<<j<<' '<<pos<<endl;
					if (tk[j]-pos<=av-(m-tk[j])){
						for (int sc=1;sc<=n;sc++){
							if (tk[j]==pos) break;
							while (tk[sc]<m && sc!=j){
//								cout<<g<<' '<<cc<<' '<<i<<' '<<j<<' '<<sc<<endl;
								tmp.pb(mp(j,sc));
								tk[sc]++;
								ta[sc][tk[sc]]=ta[j][tk[j]];
								tk[j]--;
								if (tk[j]==pos) break;
							}
						}
//						cout<<pos<<' '<<tk[j]<<endl;
						tmp.pb(mp(j,g));
						tk[g]++;
						ta[g][tk[g]]=ta[j][tk[j]];
						tk[j]--;
//						cout<<"         "<<j<<' '<<tk[j]<<endl;
						fd=true;
					}
					if (fd) break;
				}
//				if (cc==2) pt();
				if (!fd){
					ok=false;
					break;
				}
			}
			if (ok){
//				cout<<g<<' '<<cc<<endl;
				for (int i=0;i<tmp.size();i++){
					ans.pb(tmp[i]);
				}
				for (int i=1;i<=n+1;i++){
					for (int j=1;j<=m;j++){
						a[i][j]=ta[i][j];
					}
					k[i]=tk[i];
				}
				cn[cc]=false;
			}
		}
	}
	while (k[2]!=0){
		ans.pb(mp(2,1));
		k[2]--;
	}
	cout<<ans.size()<<endl;
	for (int i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<endl;
	}
	return 0;
}
