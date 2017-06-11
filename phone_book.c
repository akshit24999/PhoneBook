#include<stdio.h>
//#include<conio.h>
 struct phonebook
 {
     char name[20];
     char email[20];
     int phno;
 };
 //testing git
 //test number2
 int add_contact (char* name,char* email,char* phone);
 int edit (int index, char* new_name,char* new_email,char* new_phone);
 int del (int index);
 int search (char* name);
int main() 
{
    int user_choice;
    char name[20],name2[20];
    struct phonebook p[10];
    int search_index = -1;
   // clrscr();
    
    while(1)
    {
        printf("enter anyone of the following options \n 1:Add a contact\n 2:Edit a cotact\n 3:Delete a contact\n 4:exit");
        scanf("%d",&user_choice);
        switch(user_choice)
        {
            case 1: add_contact("akshit","abc@gmail.com","123456797");
                    break;
            case 2: printf("enter the contact to be edited");
                    scanf("%s",name);
                    search_index = search(name);
                    edit(search_index, "akshit","abc@gmail.com","123456797");
                    break;
            case 3: printf("enter the contact to be deleted");
                    scanf("%s",name2);
                    search_index = search(name2);
                    del(search_index);
                    break;
            case 4: 
                    break;
            default: printf("enter any valid option");
                    break;
        }
        if(user_choice==4)
         break;
    }
    //getch();
    return 0;
}


int add_contact (char* name,char* email,char* phone)
{
    
    //TODO
    
    return -1;
}

 int edit (int index, char* new_name,char* new_email,char* new_phone)
 {
    
    //TODO
    
    return -1;
}

 int del (int index)
{
    
    //TODO
    
    return -1;
}

 int search (char* name)
 {
    
    //TODO
    
    return -1;
}

