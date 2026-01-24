/* leetcode 6 - zigzag conversion
 * Jan 24, 2026
 */

/* bf */
char *convert(char *s, int n) 
{
        if (n == 1)
                return s;

        char a[n][1000];
 
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 1000; ++j) {
                        a[i][j] = (char)0;
                }
        }

        int d = 0;
        
        #define DOWN    0
        #define UP      1

        int y = 0;
        int x = 0;

        while (*s != '\0') {
                a[y][x] = *s;

                if (d == DOWN) {
                        ++y;
                } else if (d == UP) {
                        --y;
                        ++x;
                }

                if (y == n - 1) {
                        d = UP;
                } else if (y == 0) {
                        d = DOWN;
                }

                ++s;
        }

        char *r = malloc(1001);
        char *p = r;
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 1000; ++j) {
                        char c = a[i][j];
                        if (c != 0) {
                                *(p++) = c;
                        }
                }
        }

        *p = '\0';

        return r;
}


/* math */
char *convert(char *s, int n)
{
        if (n <= 1)
                return s;

        int l = strlen(s);
        char *r = malloc(l + 1);

        int p = 0;
        int c = 2 * n - 2;

        for (int i = 0; i < n; ++i) {
                for (int j = 0; j + i < l; j += c) {
                        r[p++] = s[j + i];

                        if (i != 0 && i != n - 1 && j + c - i < l)
                                r[p++] = s[j + c - i];
                }
        }

        r[p] = '\0';

        return r;
}
