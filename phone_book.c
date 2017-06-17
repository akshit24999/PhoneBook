#include<stdio.h>
//#include<conio.h>
#include<string.h>
 struct phonebook
 {
     char name[20];
     char email[20];
     int ph_no;
 };
 int add_contact(struct phonebook abc,char * name,char * email,int phone);
 int edit(int index, char * new_name,char * new_email,char * new_phone);
 int del(int index);
 int search(char * name);
 int find_empty_index(struct phonebook abc[]);
 int main()
{
    int user_choice,k,phone;
    char name[20],name2[20],email[20];
    struct phonebook p[10];
    int search_index,index_searched;
    //clrscr();

    //initializing p[]
    for(k=0;k<10;k++)
    {
     p[k].name[0]=0;
     p[k].email[0]=0;
    }
    while(1)
    {
	printf("enter anyone of the following options \n 1:Add a contact\n 2:Edit a cotact\n 3:Delete a contact\n 4:exit");
	scanf("%d",&user_choice);
	switch(user_choice)
	{
	    case 1:printf("enter the name \n");
	           scanf("%s",name);
	           printf("enter the email \n");
	           scanf("%s",email);
	           printf("enter the phone number \n");
	           scanf("%d",&phone);
	           index_searched=find_empty_index(p);
	           add_contact(p[index_searched],name,email,phone);
		       break;
	    case 2:printf("enter the contact to be edited");
		       scanf("%s",name);
		       search_index = search(name);
		       edit(search_index, "akshit","abc@gmail.com","123456797");
		       break;
	    case 3:printf("enter the contact to be deleted");
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


int add_contact (struct phonebook contact,char * name,char * email,int phone)
{
    strcpy(contact.name, name);
    strcpy(contact.email, email);
    contact.ph_no=phone;
    
    /* if(j<i)
    {
    printf("contact saved");
    return 0;
    }
    else
    {
    printf("error");
    return -1;
    }*/
    return 1;
}

 int edit (int index, char * new_name,char * new_email,char * new_phone)
 {

    //TODO

    return -1;
}

 int del (int index)
{

    //TODO

    return -1;
}

 int search (char * name)
 {
   int search,f=0;
   struct phonebook p[10];
   for(search=0;search<10;search++)
   {
    {if(p[search].name==name)
     f=1;
    }
   }
    if(f==0)
    printf("entered an wrong name");
    
    return search;
}
int find_empty_index(struct phonebook p[])
{
    int i=-1;
    for(i=0;i<10;i++)
    {
        if(p[i].name== 0)
        {
         return i;
        }
    }
    
    return -1;
}