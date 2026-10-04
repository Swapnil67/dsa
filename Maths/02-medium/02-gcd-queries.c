/*
 * Gcd Queries
 * 
 * https://www.codechef.com/JAN15/problems/GCDQ 
*/

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

int main() {
	int t;
	scanf("%d", &t);
	
	int n, q;
	scanf("%d%d", &n,&q);
	
	int nums[n];
	for (int i = 0; i < n; ++i) {
	    scanf("%d", &nums[i]);
	}
	
    // * Prefix GCD array
    int prefix_gcd[n+1];
    prefix_gcd[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix_gcd[i] = gcd(nums[i-1], prefix_gcd[i-1]);
    }
    // for (int i = 0; i <= n; ++i) {
    //     printf("%d ", prefix_gcd[i]);
    // }
    // printf("%d\n");
    
    // * Suffix GCD array
    int suffix_gcd[n+2];
    suffix_gcd[n+1] = 0;
    for (int i = n; i >= 1; --i) {
        suffix_gcd[i] = gcd(nums[i-1], suffix_gcd[i+1]);
    }
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", suffix_gcd[i]);
    // }
    // printf("%d\n");
    
    // * Find gcd for given queries
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l,&r);
        int ans = gcd(prefix_gcd[l-1], suffix_gcd[r+1]);
        printf("%d\n", ans);
    }
    
    return 0;
}

// * Input
/*
1
3 3
2 6 9
1 1
2 2
2 3
*/

// * Output
/*
3
1
2
*/