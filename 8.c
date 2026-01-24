/* leetcode 8 - string to integer atoi
 * Jan 24, 2026
 */

int myAtoi(char *s)
{
	while (*s == ' ')
		++s;

	long long f = 1;

	if (*s == '-') {
		f = -1;
                ++s;
        } else if (*s == '+') {
                ++s;
        }
	
	long long i = 0;

	while (*s >= '0' && *s <= '9') {
		i = i * 10 + (*s - '0');

                if (f == 1 && i > INT_MAX) 
                        return INT_MAX;
                else if (f == -1 && i > (long long)INT_MAX + 1) 
                        return INT_MIN;

		++s;
	}

        i = i * f;
	return i;
}
