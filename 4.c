/* leetcode 4 - median of two sorted arrays 
 * Jan 22, 2026
 */

/* combination */
double findMedianSortedArrays(int *a, int n, int *b, int m)
{
	int s = n + m;
	int r[s];

	int i = 0, j = 0, k = 0;

	while (i < n && j < m)
		r[k++] = a[i] < b[j] ? a[i++] : b[j++];

	while (i < n)
		r[k++] = a[i++];
	while (j < m)
		r[k++] = b[j++];
			
	if (s % 2 != 0) 
		return (double)r[s / 2];
	else 
		return (double)(r[s/2] + r[s/2 - 1]) / 2.0;

        return 0;
}


/* no combination / bs */
double findMedianSortedArrays(int *a, int n, int *b, int m)
{
	if (n > m)
		return findMedianSortedArrays(b, m, a, n);

	int s = m + n;
	int h = (s + 1) / 2; 

	int l = 0, r = n;

	while (l <= r) {
		int i = (l + r) / 2;
		int j = h - i;
		
		int la = (i == 0) ? INT_MIN : a[i - 1];
		int ra = (i == n) ? INT_MAX : a[i];
		int lb = (j == 0) ? INT_MIN : b[j - 1];
		int rb = (j == m) ? INT_MAX : b[j];

		if (la <= rb && lb <= ra) {
			if (s % 2 == 1)
				return (double)fmax(la, lb);
			else
				return (double)(fmax(la, lb) + fmin(ra, rb)) / 2.0;
		} else if (la > rb) {
			r = i - 1;
		} else {
			l = i + 1;
		}
	}


        return 0.0;
}
