#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
int T,tai=1,len;
struct noe{
	int cnt;
	int type;//a->1 ...
};
noe a[1048579];
unsigned long long ans,del;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T){
		del=0;ans=0;
		tai=1;
		cin>>s;
		len=s.size();
		for(int i=0;i<s.size();++i){
			ch=s[i];
			int temp=0,j;
			for(j=i;j<s.size();++j){
				if(s[j] == ch) ++temp;
				else break;
			}
			a[tai].cnt=temp;
			a[tai].type=ch-'a'+1;
			++tai;
			i=j-1;
		}//tai=a.size+1
//		cout<<T<<endl;
//		for(int i=1;i<tai;++i){
//			cout<<a[i].type<<' '<<a[i].cnt<<endl;
//		}
		for(int i=1;i<=len-2;++i){
			int dw,w,cont,lun;//dw:假设的前dw个char的组   w:dw的备份   cont:记录w包含前cont组a 
			bool iscon,isplu,ispluss;//iscon:对于dw及当前组:若查出有不同点 为true 跳出该假设       isplu:对于当前比较组:若比较中有问题,为false 
		/*	if(2*i >= len){
				ans+=((len-i)*(len-i-1))/2;
		cout<<"SHIIII "<<i<<' '<<ans<<endl;
				continue;
			}*/
			for(int I=i+1;I<=len-1;++I){
				dw=I;
				w=dw;
				iscon=false;
				cont=0;
				for(int k=1;k<tai-1;++k){
					if(w > a[k].cnt){
						w-=a[k].cnt;
						++cont;
					}
					else break;
				}
				
		//cout<<" text:"<<i<<' '<<dw<<' '<<cont<<endl;
		
				if(dw == 2*i && cont == 0) continue;
				else if(dw == 2*i){
					ispluss=true;
					for(int k=1;k<=cont;k++){
						if(cont+k-2 > tai){
							ispluss=false;
							break;
						}
						if(a[k].cnt != a[cont+k-1].cnt){
							ispluss=false;
							break;
						}
						if(a[k].type != a[cont+k-1].type){
							ispluss=false;
							break;
						}
						++lun;
					}
					if(ispluss) continue;
				}
			/*	int chea[30],chec[30],couc=len-I,kkk;
				memset(chea,0,sizeof(chea));
				memset(chec,0,sizeof(chec));
				for(kkk=1;kkk<tai;++kkk){
					if(dw>a[kkk].cnt){
						dw-=a[kkk].cnt;
						chea[a[kkk].type]+=a[kkk].cnt;
					}
					else break;
				}
			//	cout<<dw<<endl;
				chea[a[kkk].type]+=dw-1;
				
				for(int KKK=0;KKK<=27;++KKK) cout<<chea[KKK];
				cout<<endl;
				for(kkk=tai-1;kkk>=1;--kkk){
					if(couc > a[kkk].cnt){
						couc-=a[kkk].cnt;
						chec[a[kkk].type]+=a[kkk].cnt;
					}
					else break;
				}
				chec[a[kkk].type]+=couc;
			//	cout<<couc<<endl;
				for(int KKK=0;KKK<=27;++KKK) cout<<chec[KKK];
				cout<<endl;

				int chet=0,chett=0;
				for(int DE=0;DE<=27;++DE){
					if(chea[DE] %2 !=0) ++chett;
					if(chec[DE] %2 !=0) ++chet;
				}
				if(chett > chet){
					++del;continue;
				}
		//cout<<"NM "<<chett<<' '<<chet<<endl;
				*/
				if(w!=0){
					ans++;
		//cout<<"GoOD "<<i<<' '<<dw<<' '<<ans<<endl;
					continue;
				}
				lun=1;
				for(int j=cont+1;j<tai-1;){
					isplu=true;
					for(int k=1;k<=cont;k++){
						if(j+k-2 > tai){
							isplu=false;
							break;
						}
						if(a[k].cnt != a[j+k-1].cnt){
							isplu=false;
							break;
						}
						if(a[k].type != a[j+k-1].type){
							isplu=false;
							break;
						}
						++lun;
					}
					ans+=isplu;
					if(isplu == false) break;
					else{
		//c//out<<"fff "<<i<<' '<<dw<<' '<<j<<' '<<ans<<endl;
						j+=cont;
					}
				}
		
		/*		if(2*dw >= len){//********************************************************
				ans+=(len-dw)-lun/2;
		cout<<"NICE "<<i<<' '<<dw<<' '<<ans<<endl;
					break;
				}*/
			}
		}
		cout<<ans-del<<endl;
		--T;
	}

	return 0;
}

