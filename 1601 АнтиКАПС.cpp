#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
    char c; bool sbeg = true;
    while ((c = getchar()) != EOF) {
        if (!sbeg) {
            c = tolower(c);
            printf("%c", char (c));
        }
        if (sbeg) {
            printf("%c", char (c));
            if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z')
                sbeg = false;
        }
        if (c == '.' || c == '!' || c == '?')
            sbeg = true;
    }
}