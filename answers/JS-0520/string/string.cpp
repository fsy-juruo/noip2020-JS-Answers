#include <bits/stdc++.h>

using namespace std;

string s;
int tot[26];
int numl[2000010], numr[2000010];

void cnt_ch(void) {
    memset(tot, 0, sizeof(tot));

    memset(numl, 0, sizeof(numl));
    numl[0] = 1;
    ++tot[s[0] - 'a'];
    for (int i = 1; i < s.size(); ++i) {
        ++tot[s[i] - 'a'];
        if (tot[s[i] - 'a'] % 2 == 0) {
            numl[i] = numl[i - 1] - 1;
        } else {
            numl[i] = numl[i - 1] + 1;
        }
    }

    memset(tot, 0, sizeof(tot));
    memset(numr, 0, sizeof(numr));
    numr[s.size() - 1] = 1;
    ++tot[s[s.size() - 1] - 'a'];
    for (int i = s.size() - 2; i >= 0; --i) {
        ++tot[s[i] - 'a'];
        if (tot[s[i] - 'a'] % 2 == 0) {
            numr[i] = numr[i + 1] - 1;
        } else {
            numr[i] = numr[i + 1] + 1;
        }
    }
}

int kmp[2000010];

void calc_kmp(void) {
    memset(kmp, -1, sizeof(kmp));
    kmp[0] = -1;
    for (int i = 1; i < s.size(); ++i) {
        int t = kmp[i - 1];
        while (t != -1 && s[t + 1] != s[i]) {
            t = kmp[t];
        }
        if (s[t + 1] == s[i]) {
            kmp[i] = t + 1;
        } else {
            kmp[i] = -1;
        }
    }
}

int tot_ok[2000010];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        cin >> s;

        cnt_ch();
        calc_kmp();

//        for (int i = 0; i < s.size(); ++i) {
//            cerr << kmp[i] << ' ';
//        }
//        cerr << endl;

        long long sum = 0;
        for (int i = s.size() - 1; i >= 2; --i) {
            int now_num = numr[i];
            if (numl[0] <= now_num) {
                tot_ok[0] = 1;
            } else {
                tot_ok[0] = 0;
            }
//            cerr <<';'<<numr[i]<<endl;
            for (int j = 1; j < i - 1; ++j) {
                tot_ok[j] = tot_ok[j - 1];
                if (numl[j] <= now_num) {
                    ++tot_ok[j];
//                    cerr << j << '/';
                }
            }
//            cerr << endl;

            int min_group_len = i - (kmp[i - 1] + 1);
            if (i % min_group_len != 0) {
                min_group_len = i;
            }
            for (int j = 1; min_group_len * j <= i; ++j) {
                int now_group_len = j * min_group_len;
                if (i % now_group_len == 0) {
                    sum += tot_ok[now_group_len - 2];
                }
//                cerr << i << ' ' << j << ' ' << now_group_len << ' ' <<
//                  tot_ok[now_group_len - 2] << endl;
            }
        }
        cout << sum << endl;
//        cerr << endl;
    }

	return 0;
}

