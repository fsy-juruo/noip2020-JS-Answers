// 样例只过了一组 
// |s| > 300 就会 TimeOut
// 更有机会获得 RunTimeError 的惊喜 
// 就那样吧
// 谁说noip比csp简单的.. 
/*
	
	--YFZ 
	
*/ 
#include <bits/stdc++.h>
using namespace std;

/*
//前缀和的方法来求奇数次的个数
//但是要涉及下面main函数的大面积重构
//遂放弃
//但我觉得这个更节省时间 
//特别是|s|比较大的时候 
const int inf = 1e5;

string a;
map<char, int> nn[inf];

void init(){
	for(int i = 0; i < a.size(); i++){
		nn[i].clear();
	}
	nn[0][a[0]] = 1;
	for(int i = 1; i < a.size(); i++){
		nn[i] = nn[i - 1];
		nn[i][a[i]] ++;
	}
}

int find(int x, int y){
	int ans = 0;
	map<char, int> now;
	if(x == 0){
		now = nn[y];
	} else {
		for(int i = 97; i <= 122; i++){
			now[(char)i] = nn[y][(char)i] - nn[x - 1][(char)i];
		}
	}
	for(int i = 97; i <= 122; i++){
		if(now[(char)i] % 2 == 1){
			ans ++;
		}
	}
	return ans;
}

*/

int cntt(string a){
	int ans = 0;
	for(int i = 0; i < a.length(); i++){
		string x = a.substr(0, 1);
		int cnt = 0;
		while(a.find(x) != a.npos){
			cnt ++;
			a.replace(a.find(x), 1, "");
		}
		if(cnt % 2 == 1){
			ans ++;
		}
	}
	return ans;
}

bool f(string a, string b){
	int ansa = cntt(a), ansb = cntt(b);
	return ansa <= ansb;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		long long ans = 0;
		string s;
		cin >> s;
		for(int i = 1; i <= s.length() - 2; i++){
			string a = s.substr(0, i);
			string bix = s.substr(i, s.length() - i);
			for(int j = 1; j <= bix.length() - 1; j++){
				string b = bix.substr(0, j);
				string ab = a + b;
				string ix = bix.substr(j, bix.length() - j);
				while(ix.find(ab) == 0 && ix != ""){
					if(f(a, ix)){
						ans ++;
					}
					ix.replace(0, ab.length(), "");
				}
				if(ix != "" && f(a, ix)){
					ans ++;
				}
			}
		}	
		cout << ans << endl;
	}
	return 0;
}
