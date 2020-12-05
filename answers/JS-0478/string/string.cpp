#include<bits/stdc++.h>
#include<string.h>
#define ll long long
#define gc() getchar()
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=gc();int neg=1;
	for(;!isdigit(c);c=gc())if(c=='-')neg=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+c-'0';
	x*=neg;
}
int n;
map<string,bool>vis;
ll solve(string in,bool s){
	if(s==false){
		ll ret=0;
		int len=in.size();
		for(int i=1;i<len-1;i++){
			for(int j=1;i+j<len;j++){
				int ji[40]={0};
				int jia=0,jib=0,jic=0;
				int k=len-i-j;
//				printf("%d %d %d\n",i,j,k);
				if(k<=0)continue;
				
				string a,b,c;
				int pos=0;
				for(int aa=0;aa<=i-1;aa++,pos++){a+=in[pos];ji[in[pos]-'a'+1]^=1;}
				for(int l=1;l<='z'-'a'+1;l++){if(ji[l])jia++;ji[l]=0;}
				for(int bbb=0;bbb<=j-1;bbb++,pos++){b+=in[pos];ji[in[pos]-'a'+1]^=1;}
				for(int l=1;l<='z'-'a'+1;l++){if(ji[l])jib++;ji[l]=0;}
				for(int cc=0;cc<=k-1;cc++,pos++){c+=in[pos];ji[in[pos]-'a'+1]^=1;}
				for(int l=1;l<='z'-'a'+1;l++){if(ji[l])jic++;ji[l]=0;}
				
				string tmp=a+b;
				int tmplen=tmp.size();
				//if(!vis[a]){
				//	vis[a]=1;
//					cout<<tmp;
					int cnt=0;int tpos=tmplen;
					do{
						cnt++;
						if(tpos+tmplen>len)break;
						for(int t=0;t<tmplen;t++,tpos++){
							tmp[t]=in[tpos];
						}
//						cout<<"							tmp:"<<tmp<<endl;
					}while(tmp==a+b);
//					cout<<"				cnt:"<<cnt<<endl;
					for(;cnt>1;cnt--){
						if(len-tmplen*cnt<=0){
//							cout<<" - cnt = "<<cnt<<" len = "<<len<<" tmplen*cnt = "<<tmplen*cnt<<" restc == null"<<endl;
							continue;
						}
						string restc;
						int jicc[40]={0};
						int jiccc=0;
						for(tpos=tmplen*cnt;tpos<len;tpos++){restc+=in[tpos];jicc[in[tpos]-'a'+1]^=1;}
						for(int l=1;l<='z'-'a'+1;l++){if(jicc[l])jiccc++;jicc[l]=0;}
//						cout<<a<<"+"<<b<<" x "<<cnt<<"		restc:"<<restc<<" "<<jia<<":"<<jiccc<<"		times:"<<ret<<endl;
						//if(a==b&&a==restc&&b==restc)continue;
						if(jia>jiccc)continue;
						ret++;
//						cout<<"ret+++++++++++++++++++++++++++++++++++++++++"<<endl;
					}		
				//}
				
				//if(a==b&&a==c&&b==c)continue;
				if(jia>jic)continue;
				ret++;
//				cout<<"times:"<<ret<<endl;
				
//				if(jia<=jic);
//				if(a==b&&a.size()>1){
//					
//				}
				
//				cout<<a<<" "<<b<<" "<<c<<"	times:"<<ret<<endl;
			}
		}
		return ret;
	}
//	else{
//		ll ret=0;
//		int len=in.size();
//		for(int i=1;i<len-1;i++){
//			for(int j=1;i+j<=len;j++){
//				int ji[40]={0};
//				int jia=0,jib=0,jic=0;
////				printf("true %d %d\n",i,j);
//				ret++;
//				
//				string a,b,c;
//				int pos=0;
//				for(int aa=0;aa<=i-1;aa++,pos++){a+=in[pos];ji[in[pos]-'a'+1]^=1;}
//				for(int l=1;l<='z'-'a'+1;l++){if(ji[l])jia++;ji[l]=0;}
//				
//				string tmp=a;
//				int cnt=0;int tpos=a.size();
//				while(tmp==a){
//					for(int t=0;t<a.size();t++,tpos++){
//						tmp[t]=in[tpos];
//					}
//					cnt++;
//				}
//				if(cnt>1&&a.size()>1){
//					cout<<"	"<<cnt<<"	";
//					ret*=solve(a,true);
//				}
//				
//				for(int bbb=0;bbb<=j-1;bbb++,pos++){b+=in[pos];ji[in[pos]-'a'+1]^=1;}
//				for(int l=1;l<='z'-'a'+1;l++){if(ji[l])jib++;ji[l]=0;}
//				
////				if(jia<=jic);
////				if(a==b&&a.size()>1){
////					
////				}
//				
//				cout<<a<<jia<<"		"<<b<<jib<<"		"<<c<<jic<<endl;
//			}
//		}
//		cout<<"++"<<ret<<endl;
//		return ret;
//	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(n);
	string in;
	while(n--){
		cin>>in;
		printf("%lld\n",solve(in,false));
//		int len=in.size();
//		for(int i=1;i<len-1;i++){
//			for(int j=1;i+j<len;j++){
//				int ji[40]={0};
//				int jia=0,jib=0,jic=0;
//				int k=len-i-j;
//				printf("%d %d %d	",i,j,k);
//				if(k<=0)continue;
//				string a,b,c;
//				int pos=0;
//				for(int aa=0;aa<=i-1;aa++,pos++){
//					a+=in[pos];
//					ji[in[pos]-'a'+1]^=1;
//				}
//				for(int l=1;l<='z'-'a'+1;l++){
//					if(ji[l])jia++;
//					ji[l]=0;
//				}
//				for(int bbb=0;bbb<=j-1;bbb++,pos++){
//					b+=in[pos];
//					ji[in[pos]-'a'+1]^=1;
//				}
//				for(int l=1;l<='z'-'a'+1;l++){
//					if(ji[l])jib++;
//					ji[l]=0;
//				}
//				for(int cc=0;cc<=k-1;cc++,pos++){
//					c+=in[pos];
//					ji[in[pos]-'a'+1]^=1;
//				}
//				for(int l=1;l<='z'-'a'+1;l++){
//					if(ji[l])jic++;
//					ji[l]=0;
//				}
//				cout<<a<<jia<<"		"<<b<<jib<<"		"<<c<<jic<<endl;
//			}
//		}
	}
	return 0;
}

