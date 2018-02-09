// https://leetcode.com/problems/climbing-stairs/description/

// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.
// =====================================================================================================
class Solution {
public:
    int climbStairs(int n) {
        // cin>> n;
		int a[100];
		a[0] = 1;
		a[1] = 2;
		// a[2] = 2;
		int q = 0;
        if (n == 1)
            return a[0];
        else 
        {
            if (n == 2)
                return a[1];
            else
            {
                for( int i = 2; i<n;i++){
			        q = a[i-1] + a[i-2] + 1;
			        a[i] =q;
			
		        }
                return q;
            }
        }
        
		
		// cout<<q<<endl;
        
    }
};











































#include <iostream>
using namespace std;

int main() {
    int a[100];
    
        a[0] = 1;
        a[1] = 2;
        a[2] = 4;
        int q = 0;
        if (n == 1) return a[0];
        if (n == 2) return a[1];
        if (n==3) return a[2];
        for( int i = 3; i<n;i++){
            q = a[i-1] + a[i-2] + a[i-3];
            a[i] =q;

        }
        return q;

        
        
        // cout<<q<<endl;
    return 0;
}






string p  = "aaabbc";
vector<int> letters(26, 0);
        int res = 0, len = 1;
        for (int i = 0; i < p.size(); i++) {
            int cur = p[i] - 'a';
            cout<<cur;
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
            if (++len > letters[cur]) {
                res += len - letters[cur];
                letters[cur] = len;
            }
        }
        cout<< res;














#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
struct date
{
    int day;
    int month;
    int year;
    struct date* next;
};
struct item
{
    char item_name[30];
    char item_state[30];
    double item_price;
    char item_status[30];
    double item_price_if_not;
    struct date *issue_date;
    struct item *next;
};
struct client
{
    char client_name[30];
    char client_last_name[30];
    struct item *item_data;
    struct client *next;
};
//ADD CLIENT//
void AddClient(struct client **head, char name[30], char last_name[30])
{
    if((*head) == NULL)
    {
        *head = malloc(sizeof(struct client));
        strcpy((*head)->client_name,name);
        strcpy((*head)->client_last_name,last_name);
        (*head)->next = NULL;
        (*head)->item_data = NULL;
    }
    else
{
    struct client *temp;
    temp = (*head);
    //             //
    while(temp->next)
    temp=temp->next;
    //              //
    (temp->next) = malloc(sizeof(struct client));
    strcpy(temp->next->client_name,name);
    strcpy(temp->next->client_last_name,last_name);
    temp->next->next = NULL;
    temp->next->item_data = NULL;
}
}
//ADD CLIENT END//
//////////////////
//FIND TO ADD//
struct client *FindToAdd(struct client *head, char named[30],char last_name[30])
{
    struct client *current = head;
    while(current != NULL)
    {
        if((strcmp(current->client_name,named) == 0 )&& (strcmp(current->client_last_name,last_name) == 0))
        {
            printf("Client found :%s %s\n",current->client_name,current->client_last_name);
            return current;
        }
        current = current->next;
    }
    return (NULL);
}
//FIND TO ADD END//
///////////////////
//ADD ITEM TO CLIENT//
void AddItemToClient(struct client *head, char item_name[30], char item_state[30], double price, char status[30], double price_if_not, int day, int month, int year)
{
    struct item* it = malloc(sizeof(struct item));
    strcpy(it->item_name, item_name);
    strcpy(it->item_state, item_state);
    strcpy(it->item_status, status);
    it->item_price = price;
    it->item_price_if_not = price_if_not;
    it->issue_date = malloc(sizeof(struct date));
    it->issue_date->day = day;
    it->issue_date->month = month;
    it->issue_date->year = year;
    it->next = NULL;
    it->issue_date->next = NULL;
    if (head->item_data == NULL)
    {
        head->item_data = it;
    }
    else
    {
        struct item* node = head->item_data;
        while (node->next != NULL) node = node->next;
        node->next = it;
    }
}
//ADD ITEM TO CLIENT END//
//////////////////////////
// DISPLAY//
void Display(struct client *head)
    {int i=1,b=1;
    struct client *current;
    current = head;
        while(current != NULL)
        {
           printf("[%d] Client name:%s %s \n",i, current->client_name, current->client_last_name);
           struct item *CurrentItem = head->item_data;
           while(CurrentItem != NULL)
           {
             printf("-----------------------------------------------\n");
             printf("[%d] \n",b);
             printf("Item name: %s\n",CurrentItem->item_name);
             printf("Item state: %s\n",CurrentItem->item_state);
             printf("Item status: %s\n",CurrentItem->item_status);
             printf("Item price: %lf\n",CurrentItem->item_price);
             printf("Item price if debt wasnt paid: %lf\n",CurrentItem->item_price_if_not);
             printf("Issue date: %d/%d/%d\n",CurrentItem->issue_date->day,CurrentItem->issue_date->month,CurrentItem->issue_date->year);
             printf("-----------------------------------------------\n");
             CurrentItem = CurrentItem->next;
             b++;
           }
           current=current->next;
           i++;
        }
    }
//DISPLAY END//
///////////////
int main()
{
    struct client* List = NULL;
         int choice;
         char name[30];
         char client_name[30];
         char client_named[30];
         char client_last_named[30];
          char client_last_name[30];
          char item_name[30];
          char item_state[30];
          char to_find_name[30];
          char to_find_last_name[30];
          double price;
          char status[30];
          double price_if_not;
          int day,month,year;
         scanf( "%d", &choice );
    while( choice != 6)
    {
        printf("Option 1: New person:\nOption 2: Display\nOption 3: Add item to person\n");
    switch( choice )
    {
    case 1:
     printf( "New person: \n" );
                printf("Provide client name\n");
                scanf("%s",client_name);
                printf("Provide client last name\n");
                scanf("%s",client_last_name);
                AddClient(&List,client_name,client_last_name);
                break;
    case 2:
     printf("Display\n");
                Display(List);
                break;
    case 3:
    printf("Add item to person: \n");
    struct client *temporal = NULL;
    printf("Name of desired person\n");
      scanf("%s",client_named);
    printf("Last name of desired person\n");
      scanf("%s",client_last_named);
    temporal = FindToAdd(List,client_named,client_last_named);
    printf("Item name\n");
      scanf("%s",item_name);
    printf("Item state\n");
    scanf("%s",item_state);
    printf("Item price\n");
      scanf("%lf",&price);
    printf("Item status\n");
    scanf("%s",status);
    printf("Item price if debt wasnt paid\n");
      scanf("%lf",&price_if_not);
    printf("Issue date: day\n");
    scanf("%d",&day);
    printf("Issue date: month\n");
    scanf("%d",&month);
    printf("Issue date: year\n");
    scanf("%d",&year);
    AddItemToClient(temporal,item_name,item_state,price,status,price_if_not,day,month,year);
    break;
    case 4:
     printf("Name of desired person\n");
      scanf("%s",to_find_name);
    printf("Last name of desired person\n");
      scanf("%s",to_find_last_name);
    FindToAdd(List,to_find_name,to_find_last_name);
    break;
    default:
            printf( "Invalid choice.\n\n" );
            break;
        }
        printf( "? " );
      scanf( "%d", &choice );
    }
}



















































