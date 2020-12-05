#include<bits/stdc++.h>
using namespace std;
int n,a[200005][30],ans,h[25];
struct c{
	bool x;string y;
}f[200005];
string s;
bool pp(int x,int y,int z){
	int b=0,c=0;
	for(int i=1;i<=26;i++){
		if((a[z][i]-a[y][i])%2) c++;
		if(a[x][i]%2) b++;
	}
	if(b<c) return true;return false;
}
int find(int x){
	for(int i=0;i<=20;i++){
		if(h[i]>=x) return x-1;
	}
}
int main( ){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=20;i++) h[i]=(1<<i);
	for(int i=1;i<=n;i++){
		cin>>s;string x,y="";
		for(int j=1;j<=s.size();j++) f[j].x=0;
		for(int j=1;j<=(s.size())/2;j++){
			y+=s[j-1];if(f[j].x) continue;
			for(int k=j;k<s.size()-j;k+=j){
				x="";
				for(int l=k;l<k+j;l++){
					x+=s[l];
				}
				if(x==y){
					f[k+j].x=1;
					f[k+j].y=y;
					//cout<<x<<" "<<y<<" "<<j<<" "<<k<<endl;
				} else{
					break;
				}
			}
			
		}
		//for(int j=1;j<=s.size();j++){cout<<f[j].x<<" "<<f[j].y<<endl;}
		for(int j=0;j<s.size();j++)
			a[j][s[j]-'a'+1]=a[j-1][s[j]-'a'+1]+1;
		int xs=0,ys=0,z=0;string yy;
		for(int j=1;j<=s.size();j++){
			if(f[j].x){
				xs=j;y=1;yy=f[j].y;z=int(yy.size());
				if(f[j].y.size()!=1){
					while(xs%z!=0){
						xs=xs/z;ys=ys*z;
					}
				}else{
					xs=1;ys=j;
				}
				//cout<<xs<<" "<<ys<<endl;
				for(int k=1;k<=ys;k++){
					if(pp(k,j,s.size()-1)) ans++;
				}
				/*for(int k=0;k<find(j/(f[j].y.size()));k++){
					if(pp(k,j,s.size()-1)) ans++;
				}*/
			} else{ 
				for(int k=0;k<j;k++){
					if(pp(k,j,s.size()-1)) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
