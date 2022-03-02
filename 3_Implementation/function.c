#include<stdio.h>

void get(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        list[i].balance = 0;
    } 
}

void show(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,
            list[i].balance);
    } 
}

int find(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        } 
    }
    return  - 1;
}

void collect(struct customer list[], int s, int number, int amt)
{
    int i = find(list, s, number);
    if (i ==  - 1)
    {
        printf("Record that not found");
    } 
    else
    {
        list[i].balance += amt;
    }
}

void getout(struct customer list[], int s, int number, int amt)
{
    int i = find(list, s, number);
    if (i ==  - 1)
    {
        printf("Record that not found\n");
    } 
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance in your account\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}