/* leetcode 3 - longest substring without repeating characters
 * Jan 20, 2026
 */


/* map */
#define reset(m) do {                   \
        for (int i = 0; i < 127; i++) { \
                m[i] = -1;               \
        }                               \
} while(0)

int lengthOfLongestSubstring(char *s)
{
        int l = strlen(s);
        int r = 0;
        int i = 0;
        
        int m[128];

        reset(m);
        int t = 0;
        while (i < l) {
                char c = s[i];

                if (m[c] == -1) {
                        m[c] = i;
                        ++t;
                        r = t > r ? t : r;
                } else {
                        i = m[c] + 1; 
                        reset(m);
                        t = 0;

                        continue;
                } 
                ++i;
        }

        return r;
} 

/* faster */
int lengthOfLongestSubstring(char *s)
{
        int m[128] = {0};

        int r = 0;
        int l = 0;

        for (int i = 0; s[i]; ++i) {
                char c = s[i];

                if (m[c] > l)
                        l = m[c];

                m[c] = i + 1;

                int t = i - l + 1;
                
                r = r > t ? r : t;
        }

        return r;
}
