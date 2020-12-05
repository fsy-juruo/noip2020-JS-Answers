#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,k,sum;
int w[100000001];
int c[500001],d[500001];
bool flag;
int solve1(int x){
	long long cnt=0;
	int xx=x;
	for(int i=0;;i++){
		if(xx==x&&i/n>0){
			flag=true;
			return 0;
		}
		if((xx+d[i%n]>=1)&&(xx+d[i%n]<=w[1])){
			xx+=d[i%n];
			cnt++;
		}
		else{
			cnt++;
			break;
		}	
	}
//	cout<<cnt<<'\n';
	return cnt;
}
int solve2(int x,int y){
	long long cnt=0;
	int xx=x,yy=y;
	for(int i=0;;i++){
		if(xx==x&&yy==y&&i/n>0){
			flag=true;
			return 0;
		}
		if(c[i%n]==1){
			if((xx+d[i%n]>=1)&&(xx+d[i%n]<=w[1])){
				xx+=d[i%n];
				cnt++;
			}
			else{
				cnt++;
				break;
			}
		}
		if(c[i%n]==2){
			if((yy+d[i%n]>=1)&&(yy+d[i%n]<=w[2])){
				yy+=d[i%n];
				cnt++;
			}
			else{
				cnt++;
				break;
			}
		}
	}
//	cout<<cnt<<'\n';
	return cnt;
}
int solve3(int x,int y,int z){
	long long cnt=0;
	int xx=x,yy=y,zz=z;
	for(int i=0;;i++){
		if(xx==x&&yy==y&&zz==z&&i/n>0){
			flag=true;
			return 0;
		}
		if(c[i%n]==1){
			if((x+d[i%n]>=1)&&(x+d[i%n]<=w[1])){
				x+=d[i%n];
				cnt++;
			}
			else{
				cnt++;
				break;
			}
		}
		if(c[i%n]==2){
			if((y+d[i%n]>=1)&&(y+d[i%n]<=w[2])){
				y+=d[i%n];
				cnt++;
			}
			else{
				cnt++;
				break;
			}
		}
		if(c[i%n]==3){
			if((z+d[i%n]>=1)&&(z+d[i%n]<=w[3])){
				z+=d[i%n];
				cnt++;
			}
			else{
				cnt++;
				break;
			}
		}
	}
//	cout<<cnt<<'\n';
	return cnt;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
		cin>>c[i]>>d[i];
	if(k==1){
		for(int i=1;i<=w[1];i++){
			sum+=solve1(i)%MOD;
			if(flag){
				cout<<-1;
				return 0;
			}
		}
	}
	if(k==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				sum+=solve2(i,j)%MOD;
				if(flag){
					cout<<-1;
					return 0;
				}
			}
		}
	}
	if(k==3){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int l=1;l<=w[3];l++){
					sum+=solve3(i,j,l)%MOD;
					if(flag){
						cout<<-1;
						return 0;
					}
				}
			}
		}
	}
	cout<<sum%MOD<<'\n';
	return 0;
}
/*
3 1
3
1 1 
1 1
1 -1

3 2
3 3
1 1
2 -1
1 1
*/
