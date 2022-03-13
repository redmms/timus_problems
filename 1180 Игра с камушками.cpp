#include <stdio.h>
#include <string.h>


using namespace std;

int main(){

    char s[300];
    scanf("%s", s);
    int sum = 0;
    int len = strlen(s);
    for (int i= 0; i<len; ++i){
        sum  += s[i]-'0';
    }

    if (sum%3==0)
        puts("2");
    else
           printf("1\n %d", sum%3  );


    return 0;
}