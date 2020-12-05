#include<bits/stdc++.h>
#define int long long
#define bug cout<<"bug: "<<__LINE__<<endl
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=100005;
const int maxk=15;
const int mod=1e9+7;

int n,k;
int w[maxk];
int c[maxn],d[maxn];
int maxadd[maxk],add[maxk],minadd[maxk];
int pos[maxn];
bool flag=true;
int ans;

void calc(){
	int min_turn=inf;
//	bool flag1=true;
	for(int i=1;i<=k;i++){
		int posi=pos[i];
		if(add[i]==0){
			if(maxadd[i]+posi>w[i]){
				cout<<i<<endl;
				flag=false;
				min_turn=0;
			}
			if(minadd[i]+posi<1){
				flag=false;
				min_turn=0;
			}
		}
//		else if(maxadd[i]+pos[i]>w[i]){
//			flag=false;
//			min_turn=0;
//		}
//		else if(minadd[i]+pos[i]<1){
//			flag=false;
//			min_turn=0;
//		}
		else{
			flag=false;
			if(add[i]>0){
				if(minadd[i]+posi<1){
					min_turn=0;
				}
				else{
					int tturn;
					int nadd=(w[i]-posi+1-maxadd[i]);
					if(nadd<0){
						min_turn=0;
						continue;
					}
					if(nadd%add[i]==0){
						tturn=nadd/add[i];
					}
					else{
						tturn=nadd/add[i]+1;
					}
					min_turn=min(min_turn,tturn);
				}
			}
			if(add[i]<0){
				if(maxadd[i]+posi>w[i]){
					min_turn=0;
				}
				else{
					int tturn;
//					bug;
					int nadd=(posi-abs(minadd[i]));
//					cout<<"nadd: "<<nadd<<endl;
					if(nadd<0){
						min_turn=0;
						continue;
					}
					if(nadd%abs(add[i])==0){
						tturn=nadd/abs(add[i]);
					}
					else{
						tturn=nadd/abs(add[i])+1;
					}
					min_turn=min(min_turn,tturn);
				}
			}
		}
	}
//	cout<<"minturn: "<<min_turn<<endl;
	if(flag){
		return;
	}
	int tpos[maxk];
	for(int i=1;i<=k;i++){
		tpos[i]=pos[i];
	}
	for(int i=1;i<=k;i++){
		tpos[i]=tpos[i]+min_turn*add[i];
	}
	ans=(ans+min_turn*n)%inf;
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		tpos[c[i]]+=d[i];
		ans++;
		ans%=inf;
		if(tpos[c[i]]>w[c[i]] || tpos[c[i]]<1){
			break;
		}
	}
	return;
}

void getpos(int x){
	if(x==k+1){
//		bug;
		int pre=ans;
		calc();
//		for(int i=1;i<=k;i++){
//			cout<<pos[i]<<" ";
//		}
//		cout<<endl;
//		cout<<ans-pre<<endl;
		return;
	}
	for(int i=1;i<=w[x];i++){
		pos[x]=i;
		getpos(x+1);
		if(flag){
			return;
		}
	}
}

signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	int maxw=0;
	for(int i=1;i<=k;i++){
		cin>>w[i];
		maxw=max(maxw,w[i]);
	}
	if(maxw>100000){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tc,td;
		cin>>tc>>td;
		c[i]=tc;d[i]=td;
		add[tc]+=td;
		maxadd[tc]=max(maxadd[tc],add[tc]);
		minadd[tc]=min(minadd[tc],add[tc]);
	}
	getpos(1);
	if(flag){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
	return 0;
}

/*
3 2
3 3
1 1
2 -1
1 1
*/
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/

