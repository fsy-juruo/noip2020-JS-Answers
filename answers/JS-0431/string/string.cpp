#include <bits/stdc++.h>
using namespace std;

string s;
int T;
int ans;

int judge(string str){
	int num[26]={0}, x = 0;
	for(int i = 0; i < str.size(); i++){
		num[str[i]-'a']++;
	} 
	for(int i = 1; i < 26; i++)
		if(num[i] % 2 != 0)
			x++;
	return x;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> T;
	getchar();
	for(int i = 1; i <= T; i++){
		getline(cin, s);
		for(int i = 1; i < s.size() - 2; i++){
			for(int j = 1; i + j - 1 < s.size(); j++){
				string s1 = s.substr(0, i);
				string s2 = s.substr(i + 1, j);
				string s3 = s1 + s2;
				int j1 = judge(s1);
				for(int k = 0; k < (s.size() - i - j) / (i + j); k++)
					if(s.substr(k*(i + j), i + j) == s3 && judge(s.substr(k * (i + j), s.size() - (k + 1) * (i + j))) >= j1)
						ans++;	
					else break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
1
nnrnnr
*/
