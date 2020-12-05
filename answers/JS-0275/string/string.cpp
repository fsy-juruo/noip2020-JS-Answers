#include<bits/stdc++.h>
using namespace std;
string str;
int h[114514],x,bo=1;
int pd(int a,int b,int c,int d){
	//cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	int s1=0,s2=0;
	for(int i=a;i<=b;i++){
		h[str[i]]++;
	//	cout<<str[i]<<' ';
	}//cout<<endl;
	for(int j='a';j<='z';j++){
		if(h[j]%2==1){
			s1++;
			//cout<<char(j)<<endl;
		}
		h[j]=0;
	}
	for(int i=c;i<=d;i++){
		h[str[i]]++;
	}
	for(int j='a';j<='z';j++){
		if(h[j]%2==1)s2++;
		h[j]=0;
	}
	//cout<<s1<<' '<<s2<<endl;
	if(s1<=s2)return 1;
	return 0;
}
int f(int e,int n){
	if(n==1)return e;
	if(e%n!=0)return -1;
	int t=e/n;
	for(int i=1;i<=t;i++){
		char c=str[i];
		for(int j=0;j<n;j++){
			if(bo)break;
			if(str[j*t+i]!=c)return -1;
		}
	}
	//cout<<e<<' '<<n<<endl;
	return e/n;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		int s=0;
		cin>>str;
		x=str.size();
		for(int i=x;i>=1;i--){
			str[i]=str[i-1];
		}
		for(int i=2;i<=x;i++){
			if(str[i]!=str[i-1]){
				bo=0;
				break;
			}
		}
		//cout<<str<<endl;
		for(int i=1;i<=x-2;i++){
			int e1=x-i,e2;
			for(int j=1;j<=x/2;j++){
				e2=f(e1,j);
				if(e2!=-1){
					//cout<<e2<<endl;
					for(int g=1;g<e2;g++){
						//cout<<g<<' '<<e1<<' '<<pd(1,g,e1+1,x)<<endl;
						if(pd(1,g,e1+1,x))s++;
					}
				}
				//cout<<e2<<' '<<j<<endl;
			}
			
		}
		cout<<s<<endl;
	}
return 0;
}

