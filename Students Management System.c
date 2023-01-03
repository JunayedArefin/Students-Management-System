#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    while(1)
    {
        system("cls");
        printf("\n");
        printf("\n\t\t\t\t\t             Students management System     \n");
        printf("\n\t\t\t\t                    Here you can manage Students!    \n");
        printf("\n\n\n");
        printf("\t\t\t\t\t                    o  Menu  o   ");

        printf("\n");
        printf("\n\t\t\t\t                      1 :: Reg Students     |");
        printf("\n\t\t\t\t                      2 :: List of Students |");
        printf("\n\t\t\t\t                      3 :: Search           |");
        printf("\n\t\t\t\t                      4 :: Delete           |");
        printf("\n\t\t\t\t                      5 :: Exit             |");
        printf("\n");
        printf("\t\t\t\t\t                ____________________");

        printf("\n\n\n\t\t\tEnter an Option no.: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            Add();
            break;
         case 2:
             List();
             break;
        case 3:
             search();
             break;
         case 4:
             Delete();
             break;
        case 5:
            return 0;
            break;
        }
    }

}

struct records
{
    char name[30],ID[30],gender[30],age[30],email[50];

};
struct records r;
void Add()
{
    getchar();
    system("cls");
    FILE *file;
    file = fopen("file.txt","ab+");
    printf("\n\t\t\t\t\t     Here You Can Add Students Details!    \n");
    printf("\n\t\t\t\tName : ");
    gets(r.name);
    printf("\n\t\t\t\tID : ");
    gets(r.ID);
    printf("\n\t\t\t\tGender : ");
    gets(r.gender);
    printf("\n\t\t\t\tAge : ");
    gets(r.age);
    printf("\n\t\t\t\tEmail : ");
    gets(r.email);

    fwrite(&r,sizeof(r),1,file);
    printf("Student Added Successfully!");
    fclose(file);

}


void Delete()
{
    getchar();
    system("cls");

    char name[40];
    unsigned flag=0;

    FILE *file,*file2;
    file=fopen("file.txt","rb");
        printf("\n\t\t\t\t\t          Delete Any Student Records    \n");


    printf("\nEnter Name for delete \n");

    gets(name);

    file2=fopen("file2.txt","ab+");
    while(fread(&r,sizeof(r),1,file)==1)
    {
        if(strcmp(name,r.name)!=0)
        {
            printf("\n\n");
            printf("     Details Deleted Successfully!\n");
            fwrite(&r,sizeof(r),1,file2);
        }
        else
            flag=1;
    }

        fclose(file);
        fclose(file2);
        remove("file.txt");
        rename("source2.txt","file.txt");
        printf("\n\t  Updated Details!  \n");


    printf("\n\nPress Any Key to Return...");
    getch();
}

void List()
{
    char ch;
    system("cls");
    FILE *file;
    file = fopen("file.txt","rb");
    printf("\n\n");
    printf("\n\n");
    printf("\n\tAll Students List       \n");
    printf("\n\n");



    while(fread(&r,sizeof(r),1,file)==1)
        printf("\n\tName     : %s\n\tID       : %s\n\tGender   : %s\n\tAge      : %s\n\tEmail    : %s\n",r.name,r.ID,r.gender,r.age,r.email);
        fclose(file);

    printf("\n\nPress Any Key to Return...");
    getch();
}


void search()
{
    system("cls");
    char id[25];
    unsigned flag=0;
    FILE *file;
    file=fopen("file.txt","ab+");

    printf("\n\t\t\t\t\t      $    Search here    $ \n");
    printf("\n\n");
    printf("\nEnter Student ID for \n");

    scanf("%s",&id);
    while(fread(&r,sizeof(r),1,file)>0 && flag==0)
    {
        if(strcmp(id,r.ID)==0)
        {
            flag=1;
            printf("\n\tName     : %s\n\tID       : %s\n\tGender   : %s\n\tAge      : %s\n\tEmail    : %s\n",r.name,r.ID,r.gender,r.age,r.email);
        }
    }
    fclose(file);
    printf("\n\nPress Any Key to Return...");
    getch();
}
