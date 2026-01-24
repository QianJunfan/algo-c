/* leetcode 9 - palindrome number
 * Jan 24, 2026
 */

/* reverse */
bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int t = x;
	long long n = 0;
	while (t) {
		n = n * 10 + t % 10;
		t /= 10;
	}

	return n == (long long)x;
}
