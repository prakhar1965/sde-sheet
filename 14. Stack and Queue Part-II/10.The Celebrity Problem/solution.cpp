// CodeStudio link: https://bit.ly/3GuImxi
// Leetcode link: https://leetcode.com/accounts/login/?next=/problems/find-the-celebrity/
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	int celeb = 0;
    for(int i=1; i<n; i++) {
        if(knows(celeb, i)) {
            celeb = i;
        }
    }
    for(int i=0; i<n; i++) {
        if(celeb != i && (knows(celeb, i) || !knows(i, celeb))) return -1;
    }
    return celeb;
}