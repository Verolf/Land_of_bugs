#include <stdio.h>

int main () {
    int chr, nstr = 0, nword = 0;
    while ((chr = getchar()) != EOF) {
        if (chr == '\n' ) {
            ++nstr;
        }
        if ((chr == ' ') || (chr == '\n'))
            ++nword;
    }
    printf("Nubmer of str: %d\nNumber of words: %d\n", nstr, nword);
    return 0;
}
