#include <stdio.h>
int main()
{
    struct person
    {
        char name[20];
        struct address
        {
            char street[20];
            char city[15];
            char zip[10];
        } address;
    };

    struct person p;
    printf("Enter the details:\n ");
    printf("Name: ");
    scanf("%s", p.name);
    printf("Street name: ");
    scanf("%s", p.address.street);
    printf("City name: ");
    scanf("%s", p.address.city);
    printf("Zip code: ");
    scanf("%s", p.address.zip);

    printf("\nName: %s\nStreet name: %s\nCity name: %s\nZip code: %s\n", &p.name, &p.address.street, &p.address.city, &p.address.zip);
}