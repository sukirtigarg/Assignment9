#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct student
{
    char name[100];
    int roll_no ;
    float percentage;
} STUDENT;

void swapdata(STUDENT*data_1,STUDENT*data_2)
{
    STUDENT temp= *data_1;
    *data_1=*data_2;
    *data_2=temp;
}

// void swapname(char*name1,char*name2)
// {
//     char temp[100];
//     strcpy(temp,name1);
//     strcpy(name1,name2);
//     strcpy(name2,temp);
// }

// void swaproll(int*roll_1,int*roll_2)
// {
//     int temp=*roll_1;
//     *roll_1=*roll_2;
//     *roll_2=temp;
// }

// void swappercentage(float*per1,float*per2)
// {
//     float temp=*per1;
//     *per1=*per2;
//     *per2=temp;
// }

void insert(STUDENT*data,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the name of the student %d : ",i+1);
        scanf("%s",data[i].name);
        printf("\nEnter roll number : ");
        scanf("%d",&data[i].roll_no);
        printf("\nEnter percentage of the student : ");
        scanf("%f",&data[i].percentage);
    }
}

int lexical(char*name1,char*name2)
{
    if (stricmp(name1,name2) > 0) return 0;
    else return 1;
}

void sortbyroll(STUDENT*data,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(data[j].roll_no>data[j+1].roll_no)
            {
                // swapname(data[j].name,data[j+1].name);
                // swaproll(&data[j].roll_no,&data[j+1].roll_no);
                // swappercentage(&data[j].percentage,&data[j+1].percentage);
                swapdata(&data[j],&data[j+1]);
            }
        }
    }
}

void sortbyname(STUDENT*data,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(lexical(data[j].name,data[j+1].name)==0)
            {
                swapdata(&data[j],&data[j+1]);
                // swapname(data[j].name,data[j+1].name);
                // swaproll(&data[j].roll_no,&data[j+1].roll_no);
                // swappercentage(&data[j].percentage,&data[j+1].percentage);
            } 
        }
    }
}

void findOne(STUDENT*data,int n,char*findstring)
{
    for(int i=0;i<n;i++)
    {
        if(strncmp(data[i].name,findstring,strlen(findstring))==0)
        {
            printf("Found string in - %s",data[i].name);
            break;
        } 
    }
}

int highest_percentage(STUDENT*data,int n)
{
    int max=data[0].percentage;
    for(int i=0;i<n;i++)
    if(data[i].percentage>max) max=data[i].percentage;
    return max;
}

int lowest_percentage(STUDENT*data,int n)
{
    int min=data[0].percentage;
    for(int i=0;i<n;i++)
    if(data[i].percentage<min) min=data[i].percentage;
    return min;
}

double mean(STUDENT*data,int n)
{
    double avg=0;
    for(int i=0;i<n;i++) avg+=data[i].percentage*1.0/n;
    return avg;
}

double std_deviation(STUDENT*data,int n)
{
    double sum_deviation_square=0;
    for(int i=0;i<n;i++) sum_deviation_square+=pow((data[i].percentage-mean(data,n)),2);
    return pow(sum_deviation_square/n,0.5);
}

void specs(STUDENT*data,int n,double*arr)
{
    arr[0]=n;
    arr[1]=highest_percentage(data,n);
    arr[2]=lowest_percentage(data,n);
    arr[3]=mean(data,n);
    arr[4]=std_deviation(data,n);
}

void delete(STUDENT*data,int*n,int roll)
{
    for(int i=0;i<*n;i++)
    {
        if(data[i].roll_no== roll)
        {
            for(int j=i;j<*n-1;j++) //j<----j+1
            {
                data[j]=data[j+1];
                // strcpy(data[j].name,data[j+1].name);
                // data[j].percentage=data[j+1].percentage;
                // data[j].roll_no=data[j+1].roll_no;
            }
        }
    }
    (*n)--;
}

void main()
{
    int num_of_students;
    while(1){
    printf("\nEnter the number of students for records to be entered : ");
    scanf("%d",&num_of_students);

    STUDENT studentarray[num_of_students];
    
    insert(studentarray,num_of_students);
    sortbyroll(studentarray,num_of_students);
    for (int i = 0; i < num_of_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", studentarray[i].name);
        printf("Roll No: %d\n", studentarray[i].roll_no);
        printf("Percentage: %.2f\n", studentarray[i].percentage);
        printf("\n");
    }
    printf("******************\n");

    sortbyname(studentarray,num_of_students);
    for (int i = 0; i < num_of_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", studentarray[i].name);
        printf("Roll No: %d\n", studentarray[i].roll_no);
        printf("Percentage: %.2f\n", studentarray[i].percentage);
        printf("\n");
    }
    printf("******************\n");

    findOne(studentarray,num_of_students,"xyz");
    printf("\n******************\n");

    double details[5];
    specs(studentarray,num_of_students,details);
    printf("\n");
    for(int i=0;i<5;i++) printf("\t%0.2lf",details[i]);
    printf("\n******************\n");

    
    int roll_to_delete;
    printf("\nEnter roll number of the student to delete : ");
    scanf("%d",&roll_to_delete);
    delete(studentarray,&num_of_students,roll_to_delete);
    for (int i = 0; i < num_of_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", studentarray[i].name);
        printf("Roll No: %d\n", studentarray[i].roll_no);
        printf("Percentage: %.2f\n", studentarray[i].percentage);
        printf("\n");
    }
    printf("******************");
    }
}