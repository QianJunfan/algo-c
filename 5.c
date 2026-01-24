/* leetcode 5 - longest palindromic substring
 * Jan 24, 2026
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define test longestPalindrome

/* brute force */
#include <stdio.h>
#include <string.h>

#define test longestPalindrome

/* brute force */
char *longestPalindrome(char *s)
{
        int f = 0;
        int l = strlen(s);
        int m = 0;
        int c = 0;
        int t = 0;
        if (l == 0) return s;

        for (int i = 0; i < l; ++i) {
                int r = 0;
                while (i - r >= 0 && i + r < l && s[i - r] == s[i + r]) {
                        ++r;
                        if (2 * r - 1 > m) {
                                f = 0;
                                c = i;
                                m = 2 * r - 1;
                                t = r - 1;
                        }
                }
        }

        for (int i = 0; i < l; ++i) {
                int r = 0;
                while (i - r >= 0 && i + r + 1 < l && s[i - r] == s[i + r + 1]) {
                        ++r;
                        if (2 * r > m) {
                                f = 1;
                                c = i;
                                m = 2 * r;
                                t = r - 1;
                        }
                }
        }

        if (f == 0) {
                if (c + t + 1 < l) s[c + t + 1] = '\0';
        } else {
                if (c + t + 2 < l) s[c + t + 2] = '\0';
        }
        int start = c - t;
        if (start < 0) start = 0;
        return s + start;
}


/* manacher */
char *longestPalindrome(char *str)
{
        int n = 2 * strlen(str) + 3;

        char *s = malloc(n * sizeof(char));

        s[0] = '^';
        
        for (int i = 0; i < n; ++i) {
                t[2 * i + 1] = '#';
                t[2 * i + 2] = s[i];
        }

        t[2 * n + 1] = '#';
        t[2 * n + 2] = '$';

        int *p = calloc(n, sizeof(int));

        int c = 0;
        int r = 0;
        int max = 0;
        int idx = 0;

        for (int i = 1; i < n - 1; ++i) {
                if (i < r) {
                        p[i] = MIN(r - i, p[2 * c - i]);
                } else {
                        p[i] = 1;
                }
        }
}
