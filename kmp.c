#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 //Printing Prefix table
void print_prefix(char * p, int * lcs, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%2c ", p[i]);
    printf("\n");
    for (i = 0; i < n; i++)
        printf("%2d ", lcs[i]);
    printf("\n");
    return;
}
//Generation of Prefix table
void generate_prefix(char * p, int * lcs, int n) {
    int j = 0, i = 1;
    while (i < n) {
        if (p[j] == p[i])
            lcs[i] = j + 1, j++, i++;
        else {
            if (!j)
                lcs[i] = 0, i++;
            else
                j = lcs[j - 1];
        }
    }
    print_prefix(p, lcs, n);
    return;
}
//Matching Text and Pattern
int kmp(char * t, char * p, int * lcs, int m, int n) {
    int i = 0, j = 0, count = 0;
    while (i < m) {
        if (t[i] == p[j]) {
            if (j == n - 1) {
                count++;
                i++;
                j = lcs[j];
            } else
                j++, i++;
        } else {
            if (!j)
                i++;
            else
                j = lcs[j - 1];
        }
    }
    return count;
}
int main() {
    char t[100], p[20];
    int m, n, nos;
    printf("Enter the Text and Pattern..\n");
    scanf("%s%s", t, p);
    m = strlen(t), n = strlen(p);
    int * lcs = (int * ) calloc(n, sizeof(int));
    generate_prefix(p, lcs, n);
    nos = kmp(t, p, lcs, m, n);
    printf("Number of substrings Matched is %d\n", nos);
    return 0;
}
/**************************Example***************************************
Enter the Text and Pattern..
adbadbadb
adbadb
 a  d  b  a  d  b 
 0  0  0  1  2  3 
Number of substrings Matched is 2
adbabddabdadbadbadqcdsda
adbadbadq
 a  d  b  a  d  b  a  d  q 
 0  0  0  1  2  3  4  5  0 
Number of substrings Matched is 1
Enter the Text and Pattern..
abacadbadccadbadx
adbadx
 a  d  b  a  d  x 
 0  0  0  1  2  0 
Number of substrings Matched is 1
Enter the Text and Pattern..
abxabcabcaby
abcaby
 a  b  c  a  b  y 
 0  0  0  1  2  0 
Number of substrings Matched is 1
Enter the Text and Pattern..
abababa
aba
 a  b  a 
 0  0  1 
Number of substrings Matched is 3
*********************************************************************/