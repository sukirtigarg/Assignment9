#include <stdio.h>


struct erp 
    {
        char rollno[10];
        char name[20];
        char address[30];
        int age;
        float avgmarks;
    };

void stdinfo(struct erp info)
{
    printf("Roll no.: %s\n", info.rollno);
    printf("Name: %s\n", info.name);
    printf("Address: %s\n", info.address);
    printf("Age: %d\n", info.age);
    printf("Average marks: %f\n", info.avgmarks);
    
}
int main()
{
    
    struct erp info[6];
    
    for( int i = 0; i < 6; i++)
    {
        printf("Enter the roll no. of the %d student: ", i+1);
        scanf("%s", info[i].rollno);
        printf("Enter the name of the %d student: ", i+1);
        scanf("%s", info[i].name);
        printf("Enter the address of the %d student: ", i+1);
        scanf("%s", info[i].address);
        printf("Enter the age of the %d student: ", i+1);
        scanf("%d", info[i].age);
        printf("Enter the average marks of the %d student: ", i+1);
        scanf("%f", info[i].avgmarks);
    }
    
    for(int i=0; i<6; i++)
    {
        printf("Details of the %d student: ", i+1);
        stdinfo(info[i]);
    }

    return 0;
}

