#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
const ll SS=1<<20+10;//1e6
const ll SS1=1000+10;
const ll N=50+5,M=400+5;
const ll p=131;
char s[SS1];
ll zimu[30],cntzm=0,v[30];
ll t;
ll cnta,cntc;
ll zma[30],zmc[30];

ll Hash[SS1],mult[SS1],smul[SS1];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%s",s+1);
		cntzm=0;cnta=0;cntc=0;
		memset(zimu,0,sizeof(zimu));
		memset(zma,0,sizeof(zma));
		memset(zmc,0,sizeof(zmc));
		ll len=strlen(s+1);
		for(int i=1;i<=len;i++)
			zimu[s[i]-'a'+1]=1;
		for(int i=1;i<=26;i++)
			if(zimu[i])cntzm++;
			
		mult[0]=1;smul[0]=1;
		for(int i=1;i<=len;i++){
			Hash[i]=Hash[i-1]*13331+s[i]-'a'+1;
			mult[i]=mult[i-1]*13331;
			smul[i]=smul[i-1]+mult[i];
		}
		
		ll ans=0;
		if(len<1002){
			for(int ic=len;ic>1;ic--){
				
				if(zmc[s[ic]-'a'+1]==0){
					cntc=cntc+1;
					zmc[s[ic]-'a'+1]=1;
				}
				else{
					cntc=cntc-1;
					zmc[s[ic]-'a'+1]=0;
				}
				ll lenxh=ic-1;
				memset(zma,0,sizeof(zma));
				cnta=0;
				
				for(int ia=1;ia<ic-1;ia++){
					if(zma[s[ia]-'a'+1]==0){
						cnta=cnta+1;
						zma[s[ia]-'a'+1]=1;
					}
					else{
						cnta=cnta-1;
						zma[s[ia]-'a'+1]=0;
					}
					if(cnta>cntc)continue;
					
					for(int ib=ia+1;ib<ic;ib++){
						if((lenxh%ib)!= 0)continue;
						ll numxh=lenxh/ib;
						bool pandu=true;
						for(int i=1;i<=numxh;i++){
							/*
							if(Hash[ib]*smul[i]!=Hash[i*ib]){
								pandu=false;
								break;
							}
							*/
							for(int j=1;j<=ib;j++){
								if(s[j]!=s[(i-1)*ib+j]){
								pandu=false;
		
								break;
							}
							}
							if(pandu==false)break;
							/*
							if(Hash[ib]!=Hash[i*ib]-Hash[(i-1)*ib]){
								pandu=false;
								break;
							}
							*/	
							
						}
						if(pandu){
							ans++;
						}
						
					}
				}
			}
			printf("%lld\n",ans);
		}
		
		/*
		if(cntzm==1){
			for(int ic=len;ic>1;ic--){
			
			}
		}
		if(cntzm==2){
			
		}
		*/
		
	}

	return 0;
}

