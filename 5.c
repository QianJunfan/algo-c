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


