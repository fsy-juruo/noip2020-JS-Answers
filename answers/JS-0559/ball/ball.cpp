//REMEMBER TO ENABLE freopen(). - blackfrog
#include<bits/stdc++.h>
#define len(x) Ballset[x].size()
using namespace std;
int n,m;
vector<pair<int, int> > rec;
int Ballset[51][400]; //0 is empty;0 can make(0:bottom)
int complete[51];
void motion(int p1,int p2) {
	rec.push_back(make_pair(p1,p2));
	return;
}
void submit() {
	cout<<rec.size()<<endl;
	for(int i=0;i<rec.size();i++) {
		cout<<rec[i].first<<" "<<rec[i].second<<endl;
	}
	return;
}
void exchange(int b1,int p1,int b2,int p2) { //ballset,place;place1~m,ballset0~n
	int andrea = Ballset[b1][p1];
	Ballset[b1][p1]=Ballset[b2][p2];
	Ballset[b2][p2]=andrea;
	int dep1=m-p1; //top=0,bot=m
	int dep2=m-p2;
	for(int i=1;i<=dep2;i++) motion(b2,n+1);
	for(int i=1;i<=dep1;i++) motion(b1,b2);
	motion(n+1,b1);
	motion(b2,n+1);
	for(int i=1;i<dep1;i++) motion(b2,b1);
	motion(n+1,2);
	for(int i=1;i<dep2;i++) motion(n+1,b2);
	return;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n>>m;
	int temp;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<m;j++) {
			cin>>Ballset[i][j];
		}
	}
	for(int i=1;i<=n;i++) {
		for(int l=0;l<m;l++) {
			if(Ballset[i][l]==i) {
				complete[i]++;
			} else break;
		}
		//cerr<<"Complete "<<i<<"="<<complete[i]<<endl;
	}
	for(int i=1;i<=n;i++) {
		for(int l=0;l<m;l++) {
			if((Ballset[i][l]!=i) && (complete[Ballset[i][l]]<m)) {
				//cerr<<"Running Exchange on "<<i<<" "<<l<<" "<<Ballset[i][l]<<" "<<complete[Ballset[i][l]]<<endl;
				int awa=Ballset[i][l],qwq=i;
				exchange(i,l,Ballset[i][l],complete[Ballset[i][l]]);
				//CHECK complete[Ballset[i][l]]
				complete[awa]=0;
				complete[qwq]=0;
				for(int l=0;l<m;l++) {
					if(Ballset[awa][l]==awa) {
						complete[awa]++;
					} else break;
				}
				for(int l=0;l<m;l++) {
					if(Ballset[qwq][l]==qwq) {
						complete[qwq]++;
					} else break;
				}
				/*for(int i=1;i<=n;i++) {
					for(int j=0;j<m;j++) {
						cerr<<Ballset[i][j]<<" ";
					}
					cerr<<endl;
				}*/
			}
		}
	}
	/*for(int i=1;i<=n;i++) {
		for(int j=0;j<m;j++) {
			cerr<<Ballset[i][j]<<" ";
		}
		cerr<<endl;
	}*/
	submit();
	return 0;
}
