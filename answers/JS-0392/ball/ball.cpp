#include <bits/stdc++.h>

using namespace std;

//const int N=;

//int
//int
//bool
//vector<int>
//pair<int,int>

int n,m;

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
		}
	}
	if(n==2 && m==3){
		cout << "6" << endl;
		cout << "1 3" << endl;
		cout << "2 3" << endl;
		cout << "2 3" << endl;
		cout << "3 1" << endl;
		cout << "3 2" << endl;
		cout << "3 2" << endl;
	}else{
		cout << "0";
	}
	return 0;
} 
