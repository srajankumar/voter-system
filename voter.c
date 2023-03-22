#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define a structure to represent a candidate and the party
struct candidate
{
    char name[50];
    char party[50];
    int votes;
    struct candidate *next;
};

//Defining a global head pointer
struct candidate *head=NULL;

//Function to add a person to the linked list
void add(char name[],char party[])
{
  struct candidate *ncandidate=(struct candidate*)malloc(sizeof(struct candidate));
  strcpy(ncandidate->name,name);
  strcpy(ncandidate->party,party);
  ncandidate->votes=0;
  ncandidate->next=NULL;
  if (head==NULL)
      head=ncandidate;
  else
  {
      struct candidate *cur=head;
      while(cur->next!=NULL)
      {
          cur=cur->next;
      }
      cur->next=ncandidate;
  }
  printf("\tCandidate %s is added\n\n",name);
}

//Function to display the candidates and their votes:
void display()
{
    struct candidate *cur=head;
    while(cur!=NULL) {
        printf("\t%s from %s party has %d votes\n", cur->name, 
        cur->party, cur->votes);
        cur = cur->next;
    }
    printf("\n");
}

//Function to search an entry in the linked list
struct candidate* search(char name[])
{
    struct candidate *cur=head;
    while (cur!=NULL) {
        if (strcmp(cur->name, name) == 0)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void displaythelist()
{
    struct candidate *cur=head;
    printf("\tCandidateName \t Party\n\n");
    while(cur!=NULL)
    {
        printf("\t%s \t\t %s\n",cur->name,cur->party);
        cur=cur->next;
    }
    printf("\n");
}

//Function to vote a candidate
void vote(char name[]) {
    struct candidate *cur = search(name);
    if (cur == NULL) {
        printf("Candidate not found\n");
    } else {
        cur->votes++;
        printf("\tVoted for %s from %s party\n\n", cur->name, cur->party);
    }

}

//Function to find the winner
struct candidate* findwin()
{
    struct candidate *cur=head;
    struct candidate *winner=cur;
    while(cur!=NULL)
    {
        if(cur->votes>winner->votes)
        {
            winner=cur;
        }
        cur=cur->next;
    }
    return winner;
}

//Main function
int main()
{
    int choice;
    char name[50],party[50];
    printf("\n\t-------------------------------------------------\n");
    printf("\t|\t\t  VOTING SYSTEM\t\t\t|\n");
    printf("\t-------------------------------------------------\n");
    while(1)
    {printf("\n\tSelect a choice\n");
        printf("\n\t1.Add a candidate\n");
        printf("\t2.Cast a vote\n");
        printf("\t3.Display the candidates and their votes\n");
        printf("\t4.Display the winner and exit\n");
        printf("\n\tEnter a choice: ");
        scanf("%d",&choice);


        switch(choice)
        {
            case 1: printf("\n\tEnter the name of the candidate to add: ");
                    scanf("%s",name);
                    printf("\tEnter the party of the candidate added: ");
                    scanf("%s",party);
                    add(name,party);
                    break;
            case 2:printf("\n\tThe list of candidates and their parties are:\n\n");
                displaythelist();
                printf("\tEnter the name of the candidate to vote: ");
                scanf("%s",name);
                vote(name);

                break;
            case 3: printf("\n\tThe candidates and their votes are:\n");
                    display(head);
                    break;
            case 4:printf("\n\tDisplaying the result...\n");
                    struct candidate *win=findwin();
                    printf("\n\t%s from %s party is the winner with %d votes\n\n",win->name,win->party,win->votes);
                    return 0;
            default:printf("\n\tInvalid choice. Please try again.\n");
                    break;
        }printf("\t-------------------------------------------------\n");
     
    }   
    return 0;
}
