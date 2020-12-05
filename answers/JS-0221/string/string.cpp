#include<bits/stdc++.h>
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-48;
	sum*=p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>9){
		write(sum/10);
		sum%=10;
	}
	putchar(sum+48);
}
void writek(int sum){
	write(sum);
	putchar(' ');
}
void writeln(int sum){
	write(sum);
	putchar('\n');
}
int ksm(int a,int b,int c){
	int sum=1%c;
	while(b){
		if(b&1){
			sum=sum*a%c;
		}
		b>>=1;
		a*=a;
	}
}
int T,ans,i,j,k,l,num[210],numi[210],sumi[1050000],sum[1050000];
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--){
		ans=0;
		cin>>st;
		int n=st.size();
		st=' '+st;
//		cout<<"FUCK"<<endl;
		for(l='a';l<='z';l++){
			numi[l]=0;
			num[l]=0;
		}
		for(i=1;i<=n;i++){
			sum[i]=sumi[i]=0;
		}
		for(l=1;l<=n;l++){
			if(numi[st[l]]){
				sumi[l]=sumi[l-1]-1;
			}
			else{
				sumi[l]=sumi[l-1]+1;
			}
			numi[st[l]]^=1;
//			cout<<numi[st[l]]<<' ';
		}
		for(k=n;k>=1;k--){//k how many jishu from n!!!
			if(num[st[k]]){
				sum[k]=sum[k+1]-1;
			}
			else{
				sum[k]=sum[k+1]+1;
			}
			num[st[k]]^=1;
		}
//		for(i=1;i<=n;i++){
//			cout<<sum[i]<<' ';
//		}
////		cout<<endl;
//		for(i=1;i<=n;i++){
//			cout<<sumi[i]<<' ';
//		}
//		cout<<endl;
		
		for(i=2;i<n;i++){//len0	
			for(j=i;j<n;j+=i){//checklen
//				cout<<j<<endl;
				if(j+i>=n){
					break;
				}
				bool f=true;
				for(k=1;k<=i;k++){
					if(st[k]!=st[j+k]){
						f=false;
						break;
					}
				}
//				cout<<f<<endl;
				if(!f){
					break;
				}//j the end of the last
			}
//			if(j>=n){
//				j-=i;
//			}
//			cout<<i<<' '<<j<<endl;
			for(;j>=i;j-=i){//j the end of now
				for(k=1;k<i;k++){
					if(sumi[k]<=sum[j+1]){
						ans++;
					}
				}				
			}
		}
		writeln(ans);
	}
	return 0;
}
/*
1
nnrnnr
*/
