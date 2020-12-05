#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define REP(i,n) for(int i=0;i<n;i++)
#define REPA(i,n) for(int i=1;i<=n;i++)
#define FRN(i,l,r) for(int i=l;i<r;i++)
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii >
#define SZ(v) ((int)(v).size())
#define fill(v,a) memset((v),a,sizeof(v))
#define all(v) (v).begin(),(v).end()
using namespace std;
/*
#check time limit
#check memory limit
#check bound in for
#check bound in arry
#check name name name name name name name name
#check long long limit
//
/*********************************************************/
//do remember, read all first then choose to program     //
//                     easy first                        //
//            write down on paper first                  //
//long long in read,long long in middle,long long at last//
/*********************************************************/
const int INF=1<<30;
const ll mod=1e9+7;
int n,k;
int w[10];
int dis[10][500050]={0},first_appear_l[10][500050],first_appear_r[10][500050],tot_move[10]={0},left_move[10]={0},right_move[10]={0},move_size[10]={0};

vi v[10];
int main(void){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	REP(i,k){
		scanf("%d",w+i);
	}
	int c,d;
	REP(i,k){
		left_move[i]=0;
		right_move[i]=0;
		move_size[i]=1;
		first_appear_l[i][0]=first_appear_r[i][0]=0;
	}
	REP(i,n){
		scanf("%d%d",&c,&d);
		c--;
		dis[c][move_size[c]]=dis[c][move_size[c]-1]+d;
		if(dis[c][move_size[c]]>right_move[c])right_move[c]=dis[c][move_size[c]];
		if(dis[c][move_size[c]]<left_move[c])left_move[c]=dis[c][move_size[c]];
		if(dis[c][move_size[c]]>0){
			if(first_appear_r[c][dis[c][move_size[c]]]==0)first_appear_r[c][dis[c][move_size[c]]]=move_size[c];
		}
		else if(dis[c][move_size[c]]<0){
			if(first_appear_l[c][-dis[c][move_size[c]]]==0)first_appear_l[c][-dis[c][move_size[c]]]=move_size[c];
		}
		move_size[c]++;
	}
	REP(i,k){
		move_size[i]--;
		tot_move[i]=dis[i][move_size[i]];
		left_move[i]=abs(left_move[i]);
	}
	bool flag=1;
	REP(i,k)if(tot_move[i]!=0)flag=0;
	if(flag){
		REP(i,k){
			if(left_move[i]+right_move[i]<w[i]){
				printf("-1");
				return 0;
			}
		}
	}
	REP(i,k){
		if(left_move[i]+right_move[i]>=w[i]){
			if(right_move[i]>=w[i]&&left_move[i]>=w[i]){
				REP(j,w[i]){
					v[i].pb(min(first_appear_l[i][j+1],first_appear_r[i][w[i]-j]));
				}
			}
			else if(right_move[i]>=w[i]){
				for(int j=w[i]-1;j>=left_move[i];j--)v[i].pb(first_appear_r[i][w[i]-j]);
				REP(j,left_move[i])v[i].pb(min(first_appear_l[i][j+1],first_appear_r[i][w[i]-j]));
			}
			else if(left_move[i]>=w[i]){
				REP(j,w[i]-right_move[i])v[i].pb(first_appear_l[i][j+1]);
				for(int j=w[i]-right_move[i];j<w[i];j++)v[i].pb(min(first_appear_l[i][j+1],first_appear_r[i][w[i]-j]));
			}
			else{
				int k91=left_move[i]+right_move[i]-w[i];
				REP(j,left_move[i]-k91)v[i].pb(first_appear_l[i][j+1]);
				for(int j=w[i]-1;j>=left_move[i];j--)v[i].pb(first_appear_r[i][w[i]-j]);
				for(int j=left_move[i]-k91;j<left_move[i];j++)v[i].pb(min(first_appear_l[i][j+1],first_appear_r[i][w[i]-j]));
			}
		}
		else{
			if(tot_move[i]<0){
				REP(j,left_move[i]){
					v[i].pb(first_appear_l[i][j+1]);
					int k102=(w[i]-j-1-right_move[i])/(-tot_move[i]);
					REPA(k103,k102)v[i].pb(first_appear_l[i][j+1]+k103*move_size[i]);
				}
				for(int j=w[i]-1;j>=w[i]-right_move[i];j--)v[i].pb(first_appear_r[i][w[i]-j]);
			}
			else if(tot_move[i]==0){
				REP(j,left_move[i])v[i].pb(first_appear_l[i][j+1]);
				for(int j=w[i]-1;j>=w[i]-right_move[i];j--)v[i].pb(first_appear_r[i][w[i]-j]);
				REP(j,w[i]-left_move[i]-right_move[i])v[i].pb(INF);
			}
			else{
				REP(j,left_move[i])v[i].pb(first_appear_l[i][j+1]);
				for(int j=w[i]-1;j>=w[i]-right_move[i];j--){
					v[i].pb(first_appear_r[i][w[i]-j]);
					int k111=(j-left_move[i])/tot_move[i];
//					cout<<j<<' '<<k111<<endl;
					REPA(k112,k111)v[i].pb(first_appear_r[i][w[i]-j]+k112*move_size[i]);
				}
			}	
		}
	}
//	REP(i,k)cout<<left_move[i]<<' ';
//	cout<<endl;
//	REP(i,k)cout<<right_move[i]<<' ';
//	cout<<endl;
//	REP(i,k)cout<<tot_move[i]<<' ';
//	cout<<endl;
	REP(i,k)sort(all(v[i]));
//	REP(i,k){
//		REP(j,SZ(v[i]))cout<<v[i][j]<<' ';
//		cout<<endl;
//	}
//	cout<<endl;
	ll ans=0;ll cnt[10]={0},add;
	int it[10],_cnt=0;
	REP(i,k){
		REP(j,k)it[j]=0;
		REP(I,SZ(v[i])){
			add=w[i]-I;
			_cnt=1;
			REP(j,k)if(i!=j){
				while(v[j][it[j]]<v[i][I])it[j]++;
				add=add*(w[j]-it[j])%mod;
				if(v[j][it[j]]==v[i][I])_cnt++;
			}
			ans=(ans+add)%mod;
			if(_cnt!=1)cnt[_cnt]++;
//			cout<<I<<':';
//			REP(j,k)if(i!=j)cout<<it[j]<<' ';
//			cout<<endl;
		}
	}
//	cout<<ans<<endl;
	ans=ans+100*mod;
	REPA(i,k){
///		cout<<cnt[i]<<' ';
		ans=ans-cnt[i]+cnt[i]/i;
	}
//	cout<<endl;
	ans=ans%mod;
	printf("%lld",ans);
	return 0;
}

