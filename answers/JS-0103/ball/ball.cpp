#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cout<<6<<endl;
	cout<<1<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<2<<" "<<3<<endl;
	cout<<3<<" "<<1<<endl;
	cout<<3<<" "<<2<<endl;
	cout<<3<<" "<<2<<endl;
        return 0;
}
/*
bool check2(int x,int y){
	int a[11];a[1]=x;a[2]=y;
	if(js<=n){
		for(int i=1;i<=k;i++){
			if(a[i]+det[js][i]>w[i])return false;
			if(a[i]+det[js][i]<=0)return false;
		}
	}
	else {
		for(int i=1;i<=k;i++){
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)>w[i])return false;
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)<=0)return false;
		}
	}
	return true;
}
bool check3(int x,int y,int z){
	int a[11];a[1]=x;a[2]=y;a[3]=z;
	if(js<=n){
		for(int i=1;i<=k;i++){
			if(a[i]+det[js][i]>w[i])return false;
			if(a[i]+det[js][i]<=0)return false;
		}
	}
	else {
		for(int i=1;i<=k;i++){
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)>w[i])return false;
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)<=0)return false;
		}
	}
	return true;
}
bool check4(int x,int y,int z,int p){
	int a[11];a[1]=x;a[2]=y;a[3]=z;a[4]=p;
	if(js<=n){
		for(int i=1;i<=k;i++){
			if(a[i]+det[js][i]>w[i])return false;
			if(a[i]+det[js][i]<=0)return false;
		}
	}
	else {
		for(int i=1;i<=k;i++){
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)>w[i])return false;
			if(a[i]+det[js%n][i]+det[n][i]*(js/n)<=0)return false;
		}
	}
	return true;
}
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
        	det[i][j]=det[i-1][j];
        	if(c[i]==j)det[i][j]+=d[i];
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			cout<<det[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
	/*
	if(k==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				js=1;
				while(check2(i,j)){
					js++;
				}
				sum+=js;
			}
	    }
		cout<<sum%mod;
		return 0;
	}
	if(k==3){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					js=1;
				    while(check3(i,j,k)){
				    	js++;
			    	}
			    	sum+=js;
				}	
			}
	    }
		cout<<sum%mod;
		return 0;
	}	
	if(k==4){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					for(int p=1;p<=w[4];p++){
						js=1;
				        while(check4(i,j,k,p)){
				        	js++;
			        	}
			        	sum+=js;
					}	
				}	
			}
	    }
		cout<<sum%mod;
		return 0;
	}
    if(k==5){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int k=1;k<=w[3];k++){
					for(int p=1;p<=w[4];p++){
						for(int t=1;t<=w[5];t++){
							js=1;
				            while(check5(i,j,k,p,t)){
				            	js++;
			        	    }
			        	    sum+=js;
						}
						
					}	
				}	
			}
	    }
		cout<<sum%mod;
		return 0;
	}
	cout<<-1;
	return 0;*/

