#include <bits/stdc++.h>
using namespace std;

//when using pbds
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

#define pii pair<int,int>
#define ll long long
#define qi ios::sync_with_stdio(0)

template<typename T1,typename T2> ostream& operator<<(ostream& os,pair<T1,T2> p){
	os<<"["<<p.first<<","<<p.second<<"]";
	return os;
}

template<typename T> ostream& operator<<(ostream& os,vector<T> v){
	os<<"{";
	for(int i=0;i<v.size();i++){
		os<<v[i]<<" ";
	}
	os<<"}";
	return os;
}

int nextInt(){
	int ans=0;
	int neg=1;
	while(true){
		char c=getchar();
		if(c=='-'){
			neg=-1;
			break;
		}else if(isdigit(c)){
			ans=c-'0';
			break;
		}
	}

	while(true){
		char c=getchar();
		if(isdigit(c)){
			ans=ans*10+c-'0';
		}else{
			break;
		}
	}

	return ans*neg;
}

/**
NOIP TG 2020
By XGN from HHS

1. LL plz
2. array size plz
3. tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> plz
4. clear array for each test plz
5. DON'T SET UPPER BOUND FOR LAST ALGO PLZ

"If you should fail, I would f**k you"
--Hikari White
*/

const int MAXN=1050000;
const ll p=19260817;
const ll mod=1000000003;

char s[MAXN];

ll powP[MAXN];

ll preHsh[MAXN];

int occur[27];
int preOdd[MAXN];
int sufOdd[MAXN];
int n;

void calcPrefixHash(){
	ll hsh=0;
	for(int i=0;i<n;i++){
		hsh=(hsh*p+s[i]-'a')%mod;
		preHsh[i]=hsh;
	}
}

void calcPrefixOdd(){
	memset(occur,0,sizeof(occur));
	
	int odd=0;
	for(int i=0;i<n;i++){
		occur[s[i]-'a']++;
		if(occur[s[i]-'a']%2==0){
			odd--;
		}else{
			odd++;
		}
		
		preOdd[i]=odd;
	}
}

void calcSuffixOdd(){
	memset(occur,0,sizeof(occur));
	int odd=0;
	for(int i=n-1;i>=0;i--){
		occur[s[i]-'a']++;
		if(occur[s[i]-'a']%2==0){
			odd--;
		}else{
			odd++;
		}
		
		sufOdd[i]=odd;
	}
}


/*Hikari Offset Technique (HOT)
O1 update, O(delta) query [O(1) in this problem]

Under MIT License
By XGN from HHS
*/
namespace HOT{
	int adder[MAXN];
	int pointer=0;
	ll val=0;
	
	void init(){
		memset(adder,0,sizeof(adder));
		pointer=0;
		val=0;
	}
	
	void add(int pos,int v){
		adder[pos]+=v;
		if(pointer>=pos){
			val+=v;
		}
	}
	
	ll query(int pos){
		if(pos>=pointer){
			while(pointer<pos){
				pointer++;
				val+=adder[pointer];
				
			}
		}else{
			while(pointer>pos){
				val-=adder[pointer];
				pointer--;
				
			}
		}
		
		return val;
	}
}

void solve(){
	HOT::init();
	
	scanf("%s",s);
	n=strlen(s);
	
	calcPrefixHash();
	
	calcPrefixOdd();
	calcSuffixOdd();
	
//	for(int i=0;i<n;i++){
//		cout<<preOdd[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<sufOdd[i]<<" ";
//	}
//	cout<<endl;
	
	ll ans=0;
	for(int i=1;i<n;i++){ //last position of AB
		ll expHsh=preHsh[i];
		
		HOT::add(preOdd[i-1],1);
		
		for(int j=i+1;j<n;j+=i+1){ //start position of C
			if(expHsh==preHsh[j-1]){ 
				//nicely repeat
				ans+=HOT::query(sufOdd[j]);
			}else{
				break;
			}
			
			expHsh=(expHsh*powP[i+1]+preHsh[i])%mod;
		}
	}
	
	cout<<ans<<endl;
}

int main(){
	freopen("string.in","r",stdin);
	#ifndef XGN
		freopen("string.out","w",stdout);
	#endif
	
	powP[0]=1;
	for(int i=1;i<MAXN;i++){
		powP[i]=powP[i-1]*p%mod;
	}
	
	int T=nextInt();
	while(T--){
		solve();
	}
	return 0;
}

