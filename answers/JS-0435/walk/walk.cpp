#include<bits/stdc++.h>
#define MOD 1000000007
#define N 500005
using namespace std;

int w[11]={1},p,c[N],d[N],i,now[11],n,k,start[11];
bool flag=true;
	
bool check1(){
	for(int i=1;i<=k;i++){
		if(now[i]>w[i]||now[i]<1)return 0;
	}
	return 1;
}
bool check2(){
	for(int i=1;i<=k;i++){
		if(now[i]<=w[i])return 1; 
	}
	return 0;
}
void add(){
	start[1]++;
	int i=1;
	while(start[i]>w[i])start[i]=1,start[i+1]++,i++;
	if(start[k+1]==1)flag=false;	
}
void same(){
	for(int i=1;i<=k;i++)now[i]=start[i];
}

int move(){
	int cnt=1,cnt2=0;
	while(check1()!=0){
		if(cnt2>=1e8){cout<<"-1\n";return 0;}
		now[c[cnt]]+=d[cnt];
		if(cnt>=n)cnt=1;
		cnt++;
		cnt2=(cnt2+1)%MOD;
	}
	return cnt2;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	long long ans=0,cnt=1;
	cin>>n>>k;
	for(i=1;i<=k;i++)cin>>w[i],start[i]=1;
	for(i=1;i<=n;i++)scanf("%d %d",&c[i],&d[i]);
	if(k<=5){
		while(check2()==1){
			same();
			ans+=move()%MOD;
			add();
			if(flag==false)break;		
		}
		cout<<ans-1<<endl; 
	}
	else cout<<"-1"<<endl;
	return 0;
}

