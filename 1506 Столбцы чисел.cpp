#include <stdio.h>
using namespace std;
int main()
{
	int n, k, a[101], i, j;
	scanf("%d %d", &n, &k);
	k = (n + k - 1) / k;
	for (i = 0; i < n; i++) 
		scanf("%i", &a[i]);
	for (j = 0; j < k; puts(""), j++)
		for (i = j; i < n; i += k)
			printf("%4d", a[i]);
}