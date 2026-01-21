/* leetcode 4 - median of two sorted arrays 
 * Jan 22, 2026
 */


/* combine */
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
}
