#include <bits/stdc++.h>
using namespace std;

int n,k;
int w[510000];
int c[510000],d[510000];
int ans=0;
void readp(){
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
}

void point_2(){
	for(int i=1;i<=w[1];i++)
		for(int j=1;j<=w[2];j++){
			int a=i,b=j;
			int cnt=1;
			int ansx=0;
			while(a>0&&a<=w[1]&&b>0&&b<=w[2]){
				if(c[cnt]==1){
					a+=d[cnt];
				}
				else{
					b+=d[cnt];
				}
				cnt++;
				ansx++;
				if(cnt>n)
					cnt=1;
			}
			ans+=ansx;
		}
	cout<<ans<<endl;
}
/*void fen_30(){
	if(k==1)
		point_1();
	else if(k==2)
		point_2();
	else if(k==3)
		point_3();
	else if(k==4)
		point_4();
	else
		point_5();
	
}*/

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	readp();
	if(k==2)
		point_2();
	else
		cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
