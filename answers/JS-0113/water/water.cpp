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

struct Fraction{
	ll up,down;
	
	Fraction(){
		up=0;
		down=1;
	}
	
	Fraction(ll up, ll down){
		this->up=up;
		this->down=down;
	}
	
	void print(){
		ll gcd=__gcd(up,down);
		
		cout<<up/gcd<<" "<<down/gcd<<endl;
	}
};

//a/b+c/d
Fraction add(Fraction a,Fraction b){
	ll lcm=a.down*b.down/__gcd(a.down,b.down);
	Fraction f=Fraction(a.up*lcm/a.down+b.up*lcm/b.down,lcm);
	
	return f;
}

Fraction divide(Fraction a, ll b){
	a.down*=b;
	return a;
}

int n,m;
vector<int> nei[100005];
Fraction water[100005];
int in[100005];

int main(){
	freopen("water.in","r",stdin);
	#ifndef XGN
		freopen("water.out","w",stdout);
	#endif
	
	n=nextInt();
	m=nextInt();
	
	for(int i=0;i<n;i++){
		int x=nextInt();
		for(int j=0;j<x;j++){
			int y=nextInt();
			y--;
			nei[i].push_back(y);
			in[y]++;
		}
	}
	
	for(int i=0;i<m;i++){
		water[i]=Fraction(1,1);
	}
	
	queue<int> q;
	for(int i=0;i<m;i++){
		q.push(i);
	}
	
	while(!q.empty()){
		int last=q.front();
		q.pop();
		
		if(nei[last].size()==0){
			continue;
		}
		
		Fraction split=divide(water[last],nei[last].size());
		for(int i=0;i<nei[last].size();i++){
			int to=nei[last][i];
			water[to]=add(water[to],split);
			in[to]--;
			if(in[to]==0){
				q.push(to);
			}
		}
		
//		cout<<"after split of "<<last<<endl;
//		for(int i=0;i<n;i++){
//			water[i].print();
//		}
	}
	
	for(int i=0;i<n;i++){
		if(nei[i].size()==0){
			water[i].print();
		}
	}
	return 0;
}

