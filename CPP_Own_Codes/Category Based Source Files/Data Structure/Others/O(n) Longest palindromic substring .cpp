#include <bits/stdc++.h>
using namespace std;
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

string longestPalindrome(string s)
{
        string T = preProcess(s);
        int n = T.length();
        int *P = new int[n];
        int C = 0, R = 0;
        for (int i = 1; i < n-1; i++)
        {
            int i_mirror = 2*C-i; // equals to i' = C - (i-C)

            if(R > i)
            {
                P[i] = min(R-i, P[i_mirror]);
            }
            else{
                P[i] = 0;
            }
            // Attempt to expand palindrome centered at i
            while (T[i + 1 + P[i]] == T[i - (1 + P[i])])
            {
                P[i]++;
            }

            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n-1; i++)
        {
            if (P[i] > maxLen)
            {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        int start = (int) (centerIndex - 1 - maxLen)/2.00;
        int fin = maxLen;
        return s.substr(start, fin);
}

int main()
{
    string s;
    int T;
    scanf("%d ", &T);
    for(int tc = 1; tc <= T; tc++)
    {
        getline(cin, s);
        cout<<longestPalindrome(s)<<endl;
//        string result = longestPalindrome(s);
//        printf("Case %d: %d\n", tc, result.length());
    }
}
