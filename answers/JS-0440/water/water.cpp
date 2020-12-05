#include <bits/stdc++.h>
using namespace std;
struct topp{
	int p,q;
}a[100010];
int n,m;
vector<int> b;
void des(int i,int x,int y){
	a[y].p=a[i].p*a[y].q+a[y].p*x*a[i].q;
	a[y].q=a[i].q*x*a[y].q;
	//cout<<a[i].p<<"     "<<a[i].q<<endl;
	for(int j=2;j<=a[y].p;++j){
		if(a[y].p%j==0 && a[y].q%j==0){
			a[y].p/=j;
			a[y].q/=j;
			j--;
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x,y;
		//cout<<"asdad  "<<i<<endl;
		if(i<=m){
			a[i].p=1;a[i].q=1;
			cin>>x;
			for(int j=1;j<=x;++j){
				cin>>y;
				if(a[y].p==0){
					a[y].p=1;
					a[y].q=x;
				}
				else {
					des(i,x,y);
				}
				//cout<<i<<' '<<x<<' '<<y<<" "<<a[y].p<<"   "<<a[y].q<<endl;
			}
		}
		else {
			cin>>x;
			if(x==0){
				b.push_back(i);
			}
			else {
				for(int j=1;j<=x;++j){
					cin>>y;
					if(a[y].p==0){
						a[y].p=a[i].p;
						a[y].q=a[i].q*x;
					}
					else {
						des(i,x,y);
					}
					//cout<<i<<' '<<x<<' '<<y<<" "<<a[y].p<<"   "<<a[y].q<<endl;
				}
			}
		}
	}
	for(int i=0;i<b.size();++i){
		cout<<a[b[i]].p<<" "<<a[b[i]].q<<endl;
	}
	return 0;
}
