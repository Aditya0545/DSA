#include<stdio.h>
#include<string.h>
typedef struct member
{
    char name[20];
    int ID;
    char fav_char;
}member;
int main()
{
    member member1, member2, member3, member4;
    strcpy(member1.name, "Aditya");
    strcpy(member2.name, "Noor");
    strcpy(member3.name, "Muskan");
    strcpy(member4.name, "Arshita");
    member1.ID = 67;
    member2.ID = 64;
    member3.ID = 79;
    member4.ID = 120;
    member1.fav_char = 'P';
    member2.fav_char = 'S';
    member3.fav_char = 'M';
    member4.fav_char = 'J';
    printf("Member1's name is %s\n",member1.name);
    printf("Id is %d\n",member1.ID);
    printf("Favourite Character is %c\n",member1.fav_char);
    printf("*****************************************\n");

    printf("Member2's name is %s\n",member2.name);
    printf("Id is %d\n",member2.ID);
    printf("Favourite Character is %c\n",member2.fav_char);
    printf("*****************************************\n");

    printf("Member3's name is %s\n",member3.name);
    printf("Id is %d\n",member3.ID);
    printf("Favourite Character is %c\n",member3.fav_char);
    printf("*****************************************\n");

    printf("Member4's name is %s\n",member4.name);
    printf("Id is %d\n",member4.ID);
    printf("Favourite Character is %c\n",member4.fav_char);

    return 0;
}