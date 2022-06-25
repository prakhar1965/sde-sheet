// Solution link: https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/
// CodeStudio link: https://bit.ly/3rj7Ib1

double modularExponentiation(double x, int n) {
	double ans = 1.0;
    for(int i=1; i<=n; i++) {
        ans = ans*x;
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
  
    double low = 1, high = m;
    double limit = 1e-6;
    while(high - low > limit) {
        double mid = (low+high)/2.0;
        if(modularExponentiation(mid, n) < m) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low;
}

