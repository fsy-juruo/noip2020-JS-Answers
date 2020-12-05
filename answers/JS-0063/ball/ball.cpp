#include<bits/stdc++.h>
using namespace std;
stack<int> s[55];
int a[55],b[55];
int ans1[100005],ans2[100005];
int n,m;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	//checker<"ball.in"><"ball.out">
	cin>>n>>m;
	int x;
	bool flag=true;
	for(int i=1;i<=n;i++){
		flag=true;
		for(int j=1;j<=m;j++){
			cin>>x;s[i].push(x);
			if(j==1){
				a[i]=x;
			}
			if(a[i]!=x)flag=false;
			if(flag&&a[i]==x)b[i]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<b[i]<<endl;
		flag=true;
		int sum=m-b[i];
		//cout<<sum<<endl;
		while(sum--){
			int x=s[i].top();
			if(sum==(m-b[i]-1))a[n+1]=x;
			s[i].pop();
			s[n+1].push(x);
			ans1[++ans]=i;ans2[ans]=n+1;
			//cout<<i<<" "<<n+1<<endl;
			if(s[n+1].size()>m){
				sum++;
				flag=false;
				while(!s[n+1].empty()){
					int y=s[n+1].top();
					for(int j=1;j<=i;j++){
						if(a[j]==y){
							s[n+1].pop();
							flag=true;
							ans1[++ans]=n+1;ans2[ans]=j;
							//cout<<n+1<<" "<<j<<endl;
							break;
						}
					}
					if(!flag)break;
				}
				//if(!flag)break;
			}
		}
		//cout<<ans<<endl;
	}
	int len=s[n+1].size();
	//cout<<len<<endl;
	flag=true;
	while(!s[n+1].empty()){
		//int x=s[n+1].top();
		for(int j=1;j<=n;j++){
			if(x==a[j]){
				s[n+1].pop();
				ans1[++ans]=n+1;ans2[ans]=j;
				break;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}
