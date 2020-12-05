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

int n,m;

struct State{
	int han[55][405];
	int height[55];
	
	ll hash(){
		ll hsh=0;
		const ll p=19260817;
		const ll p2=998244353;
		for(int i=0;i<n+1;i++){
			for(int j=0;j<height[i];j++){
				hsh=hsh*p+han[i][j];
			}
			hsh=hsh*p2+height[i];
		}
		
		return hsh;
	}
	
	void print(){
		for(int i=0;i<n+1;i++){
			for(int j=0;j<height[i];j++){
				cout<<han[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};

set<ll> st;
bool ok(State s){
	int done=0;
	for(int i=0;i<n+1;i++){
		if(s.height[i]!=m){
			continue;
		}
		bool bad=false;
		for(int j=0;j<m-1;j++){
			if(s.han[i][j]!=s.han[i][j+1]){
				bad=true;
				break;
			}
		}
		
		if(!bad){
			done++;
		}
	}
	
	return done==n;
}



map<ll,State> hsher;

int sz;
pii ans[280005];

void dfs(ll hsh){
	
	if(sz>=400){
		return;
	}
	
	State s=hsher[hsh];
	
	if(ok(s)){
		cout<<sz<<endl;
		for(int i=0;i<sz;i++){
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
		exit(0);
	}
	
//	cout<<"O"<<endl;
	
	for(int i=0;i<n+1;i++){
		for(int j=0;j<n+1;j++){
			if(i!=j && s.height[i]!=0 && s.height[j]!=m){
				s.height[i]--;
				s.han[j][s.height[j]]=s.han[i][s.height[i]];
				s.height[j]++;
				
				ans[sz]=make_pair(i,j);
				sz++;
				
				ll hsh=s.hash();
				if(!hsher.count(hsh)){
					hsher[hsh]=s;
					dfs(hsh);
				}
				
				sz--;
				s.height[j]--;
				s.height[i]++;
//					assert(fa==s.hash());
			}
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
//	#ifndef XGN
		freopen("ball.out","w",stdout);
//	#endif
	
	n=nextInt();
	m=nextInt();
	
	State s;
	memset(s.han,0,sizeof(s.han));
	memset(s.height,0,sizeof(s.height));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>s.han[i][j];
		}
		s.height[i]=m;
	}
	
	hsher[s.hash()]=s;
	dfs(s.hash());
	
//	hsher[s.hash()]=make_pair(-1,make_pair(-1,-1));
//	q.push(s);
//	while(!q.empty()){
//		State s=q.front();
//		q.pop();
//		
////		s.print();
//		
//		
//	}
	return 0;
}

