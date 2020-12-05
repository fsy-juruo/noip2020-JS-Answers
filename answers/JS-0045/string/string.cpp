#include <bits/stdc++.h>

using namespace std;

int T;
int n;
char s[100043];
long long pre[1043][43], pre2[1043][43];
long long suf[1043][43], suf2[1043][43], a[1043];

long long Sum(int m, int opt) {
  long long res = 0;
  if (opt == 1) {
    for (int i = 1; i * i <= m; ++i) {
      if (m % i == 0) {
        res += i - 1;
        if (i != m / i) {
          res += m / i - 1;
        }
      }
    }
  } else {
    for (int i = 1; i * i <= m; ++i) {
      if (m % i == 0) {
        res += (i - 1) / 2;
        if (i != m / i) {
          res += (m / i - 1) / 2;
        }
      }
    }
  }
  return res;
}

long long Solve4() {
  long long res = 0;
  for (int i = 2; i <= n - 1; ++i) {
    if ((n - i) % 2 == 1) {
      res += Sum(i, 1);
    } else {
      res += Sum(i, 2);
    }
  }
  return res;
}

long long Solve1() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      pre[i][j] = pre[i - 1][j];
    }
    ++pre[i][s[i] - 'a'];
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int j = 0; j < 26; ++j) {
      if (pre[i][j] % 2 == 1) {
        ++cnt;
      }
    }
    for (int j = 0; j <= 26; ++j) {
      pre2[i][j] = pre2[i - 1][j];
    }
    ++pre2[i][cnt];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 26; ++j) {
      pre2[i][j] += pre2[i][j - 1];
    }
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j < 26; ++j) {
      suf[i][j] = suf[i + 1][j];
    }
    ++suf[i][s[i] - 'a'];
  }
  for (int i = n; i >= 1; --i) {
    int cnt = 0;
    for (int j = 0; j < 26; ++j) {
      if (suf[i][j] % 2 == 1) {
        ++cnt;
      }
    }
    a[i] = cnt;
    for (int j = 0; j <= 26; ++j) {
      suf2[i][j] = suf2[i + 1][j];
    }
    ++suf2[i][cnt];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= 26; ++j) {
      suf2[i][j] += suf2[i][j - 1];
    }
  }
  long long res = 0;
  for (int i = 2; i <= n - 1; ++i) {
    int j = i, big = i;
    while (j <= n - 1) {
      if (s[j] != s[j - i * (big / i - 1)]) break;
      if (j == big) {
        res += pre2[i - 1][a[j + 1]];
        big += i;
      }
      ++j;
    }
  }
  return res;
}

int main() {
  freopen("string.in", "r", stdin);
  freopen("string.out", "w", stdout);
  scanf("%d", &T);
  while (T--) {
    scanf("%s", &s[1]);
    n = strlen(s + 1);
    bool flag4 = true;
    for (int i = 2; i <= n; ++i) {
      if (s[i] != s[1]) {
        flag4 = false;
      }
    }
    if (flag4) {
      printf("%lld\n", Solve4());
    } else {
      memset(pre, 0, sizeof(pre)); memset(pre2, 0, sizeof(pre2));
      memset(suf, 0, sizeof(suf)); memset(suf2, 0, sizeof(suf2)); memset(a, 0, sizeof(a));
      printf("%lld\n", Solve1());
    }
  }
  return 0;
}

