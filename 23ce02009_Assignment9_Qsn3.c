#include <stdio.h>
struct rand
{
    int date;
    int month;
    int year;
};
int compare(struct rand info[]);
int main()
{

    struct rand info[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Enter date, month and year: ");
        scanf("%d %d %d", info[i].date, info[i].month, info[i].year);
    }
    compare(info);
}

int compare(struct rand info[])
{
    if (info[0].year < info[1].year)
    {
        return -1;
    }
    else if (info[0].year > info[1].year)
    {
        return 1;
    }
    else if (info[0].month < info[1].month)
    {
        return -1;
    }
    else if (info[0].month > info[1].month)
    {
        return 1;
    }
    else if (info[0].date < info[1].date)
    {
        return -1;
    }
    else if (info[0].date > info[1].date)
    {
        return 1;
    }
    else
        return 0;
}