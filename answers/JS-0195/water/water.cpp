#include<bits/stdc++.h>
using namespace std;
int gys(long long x,long long y){
	int ans=1;
	if(x%2==0&&y%2==0){
		ans*=2;
		ans*=gys(x/2,y/2);
	}else if(x%3==0&&y%3==0){
		ans*=3;
		ans*=gys(x/3,y/3);
	}else if(x%5==0&&y%5==0){
		ans*=5;
		ans*=gys(x/5,y/5);
	}else if(x%7==0&&y%7==0){
		ans*=7;
		ans*=gys(x/7,y/7);
	}else if(x%11==0&&y%11==0){
		ans*=11;
		ans*=gys(x/11,y/11);
	}else if(x%13==0&&y%13==0){
		ans*=13;
		ans*=gys(x/13,y/13);
	}else if(x%17==0&&y%17==0){
		ans*=17;
		ans*=gys(x/17,y/17);
	}else if(x%19==0&&y%19==0){
		ans*=19;
		ans*=gys(x/19,y/19);
	}else if(x%23==0&&y%23==0){
		ans*=23;
		ans*=gys(x/23,y/23);
	}else if(x%29==0&&y%29==0){
		ans*=29;
		ans*=gys(x/29,y/29);
	}else if(x%31==0&&y%31==0){
		ans*=31;
		ans*=gys(x/31,y/31);
	}
	return ans;
}
struct tt{
	long long to[1010];
	long long th;
}v[1010];
queue<int>q;
struct nn{
	long long fir,sec;
}tap[1010];
bool t[1010];
long long n,m;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x==0)continue;
		while(x--){
			int k;
			cin>>k;
			t[k]=1;
			v[i].th++;
			v[i].to[k]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			tap[i].fir=1;
			tap[i].sec=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int z=q.front();
//		cout<<z<<"!!!!!!!!!"<<endl;
		q.pop();
		int flag=0;
		for(int i=1;i<=n;i++){
			if(v[z].to[i]==1){
				flag=1;
				q.push(i);
				if(tap[i].fir==0){
					tap[i].fir=tap[z].fir;
					tap[i].sec=tap[z].sec*v[z].th;
					
				}else{
					tap[i].fir=tap[i].fir*v[z].th*tap[z].sec+tap[i].sec*tap[z].fir;
					tap[i].sec*=v[z].th*tap[z].sec;
					int g=gys(tap[i].fir,tap[i].sec);
					tap[i].fir/=g;
					tap[i].sec/=g;
				}
				
				
			}
		}
		if(flag==1)tap[z].fir=0;
	}
	for(int i=1;i<=n;i++){
		if(tap[i].fir!=0){
			int g=gys(tap[i].fir,tap[i].sec);
			tap[i].fir/=g;
			tap[i].sec/=g; 
			cout<<tap[i].fir<<" "<<tap[i].sec<<endl;
		}
	}
	return 0;
}
