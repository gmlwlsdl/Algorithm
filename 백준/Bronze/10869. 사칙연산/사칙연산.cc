#include <stdio.h>

int main(){
    int x, y=0;
    scanf("%d %d", &x, &y);
    
    printf("%d\n",x+y);
    printf("%d\n",x-y);
    printf("%d\n",x*y);
    printf("%d\n",x/y);
    printf("%d\n",x%y);
    
    return 0;
}