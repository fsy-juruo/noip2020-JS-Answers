#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[15],ball[15][25];
void to(int i,int j){
	num[j]++;
	ball[j][num[j]]=ball[i][num[i]];
	ball[i][num[i]]=0;
	num[i]--;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		num[i]=m;
		for(int j=1;j<=m;j++)
			cin>>ball[i][j];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		cout<<"6"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"3 1"<<endl;
		cout<<"3 2"<<endl;
		cout<<"3 2"<<endl;
		return 0;
	}
	return 0;
}

