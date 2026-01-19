/* leetcode 1 - two sum
 * Jan 19, 2026
 * bf & 2p
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
struct item {
        int v;
        int i;
};

int cmp(const void *a, const void *b)
{
        return ((struct item*)a)->v - ((struct item*)b)->v;
}

int *twoSum(int *n, int s, int t, int *rsz)
{
        *rsz = 2;
        struct item *a = malloc(sizeof(struct item) * s);
        for (int i = 0; i < s; ++i) {
                a[i].v = n[i];
                a[i].i = i;
        }

        qsort(a, s, sizeof(struct item), cmp);

        int l = 0;
        int r = s - 1;
        while (l < r) {
                int sum = a[l].v + a[r].v;

                if (sum > t) {
                        --r;
                } else if (sum < t) {
                        ++l;
                } else { 
                        int *rt = malloc(sizeof(int) * 2);
                        rt[0] = a[l].i;
                        rt[1] = a[r].i;
                        return rt;
                }
        }
        return NULL;
}
