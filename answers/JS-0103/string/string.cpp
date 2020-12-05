#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		int len=s.size();
		cout<<len*2;
		
    }
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
bool check5(int x,int y,int z,int p,int t){
	int a[11];a[1]=x;a[2]=y;a[3]=z;a[4]=p;a[5]=t;
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
int main(){	
    freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cin>>len;
		int fw,d,js=0;
		for(int i=1;i<=n;i++){
			cin>>fw>>d;
			js+=d;
			if((js>0)&&(!rmstep[js])){
				rmstep[js]=i;
			}
			if((js<0)&&(!lmstep[-1*js])){
				lmstep[-1*js]=i;
			}
		}
		for(int i=1;i<=len;i++){
			int ans1,ans2;
			int le=i;
			if(lmstep[le])ans1=lmstep[le];
			else{
				bool bk=0;
				ans1=0;
				while(!lmstep[le]){
					ans1+=n;
					if(js>=0){
					    bk=1;
					    break;
					}
					le-=js;
				}
				ans1+=lmstep[le];
				if(bk){
					ans1=0x3f3f3f3f;
				}
			}
			
			int ri=len-i+1;
			if(rmstep[ri])ans2=rmstep[ri];
			else{
				bool bk=0;
				ans2=0;
				while(!rmstep[ri]){
					ans2+=n;
					if(js<=0){
						bk=1;
						break;
					}
					ri-=js;
				}
				ans2+=rmstep[ri];
				if(bk){
					ans2=0x3f3f3f3f;
				}
			}
			ans+=min(ans1,ans2);
		}
		cout<<ans%mod;
		return 0;
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
	T4:1-3 纯暴力(ok) 4-6可尝试的优化(ok) 7-8 k=1(0k）
    T1:尝试AC（差不多ok）
    T2:几乎不可做 尝试1-4(难以尝试) 13-14（尝试失败）
    T3 完全不可做（没做）


	return 0;*/

