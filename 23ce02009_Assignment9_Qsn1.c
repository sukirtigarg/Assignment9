#include <stdio.h>
int main()
{
    struct company
    {
        char name[100];
        char address[100];
        int phone;
        int numofemp;
    };

    struct company c;
    printf("Enter the name of company: \n");
    scanf("%s", &c.name);
    printf("Enter the address of company:\n");
    scanf("%s", &c.address);
    printf("Enter the phone no. of company: \n");
    scanf("%d", &c.phone);
    printf("Enter the no. of employees: \n");
    scanf("%d", &c.numofemp);

    printf("\nName of company is: %s\nAddress of company is: %s\nPhone number of company is: %d \nNumber of employees is: %d\n", c.name, c.address, c.phone, c.numofemp);
}