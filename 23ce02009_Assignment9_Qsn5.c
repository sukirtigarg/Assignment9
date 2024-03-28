#include <stdio.h>
struct courserecord 
    {
        char first[10];
        char last[10];
        char roll[10];
        char dept[30];
        char cc[10];
        float arr[3];
    };
    struct courserecord cr;
float avgmark(float arr[3])
{
    float sum=0;
    for(int i=0; i<3; i++) 
    {
        sum += arr[i];
    }
    float avg = (float) sum / 3; 
    return avg; 
}
int ispass(float avg)
{
    int flag = 0;
    if (avg >= 35)
    {flag = 1;}
    return flag;
}

int main()
{
    printf("\nEnter the marks of the three subjects of the student:");
    scanf("%f %f %f", &cr.arr[0], &cr.arr[1], &cr.arr[2]);
    float avg= avgmark(cr.arr);
    printf("\nAverge: %.2f\n", avg);
    int flag = ispass(avg);
    if(flag == 1)
    printf("\nPass");
    else 
    printf("\nFail");  
}