#include <stdio.h>
int main(){
    int x, y=0;
    double z=0;
    scanf("%d %d", &x, &y);
    z=((double)x/(double)y);
    printf("%0.12lf", z);
    return 0;
}