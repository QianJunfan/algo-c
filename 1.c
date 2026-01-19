/* leetcode 1 - two sum
 * Jan 19, 2026
 */

/* brute force */
int *twoSum(int *n, int s, int t, int *r)
{
        *r = 2;

        for (int i = 0; i < s; ++i) {
                for (int j = i + 1; j < s; ++j) {
                        if (n[i] + n[j] == t) {
                                int* r = malloc(2 * sizeof(int));
                                r[0] = i;
                                r[1] = j;
                                return r;
                        }
                }
        }

        return NULL;
}


/* two pointer */
int *twoSum(int *n, int s, int t, int *r)
{}
