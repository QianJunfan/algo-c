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


