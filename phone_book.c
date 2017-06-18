#include<stdio.h>
#include<conio.h>
#include<string.h>
 struct phonebook
 {
     char name[20];
     char email[20];
     int ph_no;
 };
 int add_contact(struct phonebook *abc,char * name,char * email,int phone);
 int edit(struct phonebook *abc, char * new_name,char * new_email,int new_phone);
 int del(int index,int index_serached,struct phonebook abc[]);
 int search(char * name,struct phonebook abc[]);
 int find_empty_index(struct phonebook abc[]);
 int print_contacts(struct phonebook abc[]);
 int main()
{
    int user_choice,k,phone;
    char name[20],name2[20],email[20],new_name[20],new_email[20];
    struct phonebook p[10];
    int search_index,index_searched, for_index = 0, last_index =0,new_phone;
    clrscr();

    //initializing p[]
    for(k=0;k<10;k++)
    {
     p[k].name[0]=0;
     p[k].email[0]=0;
    }
    while(1)
    {
	printf("enter anyone of the following options \n 1:Add a contact\n 2:Edit a cotact\n 3:Delete a contact\n 4:exit\n 5.Print Contacts\n");
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
		   printf("\nAdding contact to index : %d\n",index_searched);
		   add_contact(&p[index_searched],name,email,phone);
		       break;
	    case 2:printf("enter the contact to be edited \n");
		       scanf("%s",name);
		       search_index = search(name,p);
		       printf("contact found at: %d \n",search_index);
		       printf("enter the new name \n");
		       scanf("%s",new_name);
		       printf("enter the new email \n");
		       scanf("%s",new_email);
		       printf("enter the new phone \n");
		       scanf("%d",&new_phone);
		       edit(&p[search_index],new_name,new_email,new_phone);
		       break;
	    case 3:printf("enter the contact to be deleted \n");
		       scanf("%s",name2);
		       search_index = search(name2,p);
		       index_searched=find_empty_index(p);
		       del(search_index,index_searched,p);
		       break;
	    case 4:
		       break;
		case 5:
			 last_index = find_empty_index(p);
		      for(for_index = 0; for_index < last_index ; for_index++){
			printf("Contact %d : \n", for_index);
			printf ("Name : %s\n", p[for_index].name);
			printf ("Email : %s\n", p[for_index].email);
			printf ("Phone Number : %d\n", p[for_index].ph_no);
		      }
		      break;
	    default: printf("enter any valid option");
		    break;
	}
	if(user_choice==4)
	 break;
    }
    fflush(stdin);
    getch();
    return 0;

}


int add_contact (struct phonebook *contact,char * name,char * email,int phone)
{
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    contact->ph_no=phone;
    return 1;
}

 int edit (struct phonebook *contact, char * new_name,char * new_email,int new_phone)
 {
     strcpy(contact->name,new_name);
     strcpy(contact->email,new_email);
     contact->ph_no=new_phone;
     return 1;
 }

 int del (int index,int index_searched,struct phonebook p[])
{
    int l;
    for(l=index;l<index_searched;l++)
    {
    strcpy(p[l].name,p[l+1].name);
    strcpy(p[l].email,p[l+1].email);
    p[l].ph_no=p[l+1].ph_no;
    }
    return 1;
}

 int search (char * name,struct phonebook p[])
 {
   int search,f=0;
   for(search=0;search<10;search++)
   {
    if(strcmp(p[search].name,name)==0)
    {
     f=1;
     break;
    }
   }
    if(f==0)
    {
    printf("entered an wrong name");
    return -1;
     }
    return search;
}
int find_empty_index(struct phonebook p[])
{
    int i=-1;
    for(i=0;i<10;i++)
    {
	if(p[i].name[0]== 0)
	{
	 return i;
	}
    }

    return -1;
}


