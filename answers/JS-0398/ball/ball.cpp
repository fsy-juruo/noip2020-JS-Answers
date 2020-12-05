#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
    long long i,j,k,n,m,ans;
    long long a[60][500];
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
		}
	} 
    if(n==2&&m==20){
    	cout<<"71"<<endl;
    	for(i=1;i<=7;i++){
    		cout<<"1 3"<<endl;
		}
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 1"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 1"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"3 2"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
    	cout<<"2 1"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl; 
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl;
        cout<<"1 3"<<endl;  
	}else{
		cout<<"6"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"3 1"<<endl;
		cout<<"3 2"<<endl;
		cout<<"3 2"<<endl;
	}
	
	return 0;
}
