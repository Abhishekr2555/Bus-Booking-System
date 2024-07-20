#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    char name[50];
    long long int contact_no;
    int seat_no;
    char book;
    int pin;
} node;

node *hn = NULL;

void create()
{
    node *nn, *cn;
    int j = 1;
    int y = 1;
    //volatile int k = 2;
    int k = 1;

    for (int i = 1; i <= 55; i++)
    {

        if(i>=1 && i<=9)
        k = 11*i;
        else
        k = 101*i;

        nn = (node *)malloc(sizeof(node));
        nn->next = nn->prev = NULL;
        nn->seat_no = i;
        nn->pin = k;
        nn->book = 'a';

        if (hn == NULL)
        {
            hn = nn;
            nn->next = nn->prev = hn;
        }

        else
        {
            cn = hn;
            while (cn->next != hn)
                cn = cn->next;

            cn->next = nn;
            nn->prev = cn;
            nn->next = hn;
            hn->prev = nn;
        }
    }
}

void display()
{
    node *cn;
    cn = hn;
    printf("\n\t\t<<---Seat Status--->>\n-----------------------------------------------------------\n");
    while (cn->next != hn)
    {
        if (cn->seat_no == 6 || cn->seat_no == 11 || cn->seat_no == 16 || cn->seat_no == 21 || cn->seat_no == 26 || cn->seat_no == 31 || cn->seat_no == 36 || cn->seat_no == 41 || cn->seat_no == 46 || cn->seat_no == 51)
        {
            printf("\n");
        }

        if ((cn->prev)->seat_no != cn->seat_no)
            printf("| ");

        printf("%2d", cn->seat_no);

        if (cn->book == 'a')
            printf(" -> - ");
        else
            printf(" -> * ");

        if (cn->seat_no == 54)
            printf("| ");

        if ((cn->next)->seat_no != cn->seat_no)
            printf("| ");

        cn = cn->next;
    }

    printf("%2d", cn->seat_no);

    if (cn->book == 'a')
        printf(" -> - ");

    else
        printf(" -> * ");

    printf("|\n");
    printf("\n - = Available seats, * = Booked seats");
    printf("\n-----------------------------------------------------------\n");
}

void display1(node *temp[20], int n)
{
    if (n != 1)
    {
        printf("------------------------------------------------------\n");
        printf("\nTHANK YOU..!\n\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n");

        for (int i = 1; i < n; i++)
        {
            printf("\n");
            printf("Seat No.(%d) ", temp[i]->seat_no);
            printf("PIN : %d", temp[i]->pin);
            printf("\n");
        }

        printf("\n!!!!!!!!!!!!!!!!!...KEEP PIN SAFELY...!!!!!!!!!!!!!!!\n");
        printf("\nPINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n");
        printf("------------------------------------------------------\n");
    }
}

void book_seat()
{
    node *cn, *temp[20];
    int n, z, flag;
    char row;
    int seat;
    char ch;
    int a;
    char buffer;
    //char name[50];
    long long int number;

    do
    {
        z = 1;
        printf("\nEnter No of Tickets You Want to Buy : ");
        scanf("%d", &n);

        printf("\nEnter your name : ");
        //scanf("%c", &buffer); // buffer statement to clear buffer
        //scanf("%[^\n]", cn->name);
        fflush(stdin);
        gets(cn->name);

        printf("\nEnter your mobile number : ");
        scanf("%lld", &number);
        cn->contact_no = number;
        //printf("%lld", cn->contact_no);

        printf("\nEnter seat number(s) :-\n");

        for (int i = 1; i <= n; i++)
        {
            printf("\n\tSelect Seat Number(%d) = ", i);
            scanf("%d", &seat);

            cn = hn;

            if (seat >= 1 && seat <= 55)
            {
                while (cn->next != hn)
                {
                    if (cn->seat_no == seat)
                    {
                        if (cn->book == 'a')
                        {
                            cn->book = 'b';
                            temp[z] = cn;
                            z++;
                        }
                        else
                        {
                            printf("\nINVALID CHOICE..!!\n");
                            printf("\nSeat number %d is already reserved\n", seat);
                            i--;
                        }
                    }
                    cn = cn->next;
                }

                if (cn->seat_no == seat)
                {
                    if (cn->book == 'a')
                    {
                        cn->book = 'b';
                        temp[z] = cn;
                        z++;
                    }
                    else
                    {
                        printf("\nINVALID CHOICE..!!\n");
                        printf("\nSeat number %d is already reserved\n", seat);
                        i--;
                    }
                }
            }

            else
            {
                printf("\nENTER CORRECT CHOICE\n");
                i--;
            }

        } // end of for loop

        display1(temp, z);
        printf("\n\nPRESS 1 to check Seat Status \n");
        printf("PRESS 2 to Book other seat\n");
        printf("PRESS 3 to Exit Booking Portal\n");
        printf("Enter Your choice : ");
        scanf("%s", &ch);

        if (ch == 1)
            display();

    } while (ch == '2'); // end of do-while loop
}

void cancle()
{
    char ch;
    char c;
    int seat, pin;
    node *cn;
    printf("\nSEAT CANCELATION\n");

    do
    {
        ch = 'a';
        cn = hn;
        char name[50];
        long long int contact;
        printf("\nEnter your name : ");
        fflush(stdin);
        gets(name);
        printf("\nEnter your contact number : ");
        scanf("%lld", &contact);
        printf("\nEnter the SEAT NUMBER you want to delete : ");
        scanf("%d", &seat);

        if (seat >= 1 && seat <= 55)
        {
            printf("Enter PIN of the SEAT NUMBER : ");
            scanf("%d", &pin);
            while (cn->next != hn)
            {
                if (cn->seat_no == seat && cn->pin == pin)
                {
                    printf("\nAre you sure u want to cancle the seat (y/n) ");

                    scanf("%s", &c);

                    if (c == 'y' || c == 'Y')
                    {
                        printf("\nSEAT CANCELED SUCCUESFULLY..!\n");
                        cn->book = 'a';
                    }
                }
                else if (cn->seat_no == seat && cn->pin != pin)
                {
                    printf("\nInvalid Seat number & PIN combination..!\n");
                }
                cn = cn->next;
            }
            if (cn->seat_no == seat && cn->pin == pin)
            {
                printf("\nAre you sure u want to cancle the seat (y/n) ");
                scanf("%s", &c);

                if (c == 'y' || c == 'Y')
                {
                    printf("\nSEAT CANCELED SUCCUESFULLY..!\n");
                    cn->book = 'a';
                }
            }
            else if (cn->seat_no == seat && cn->pin != pin)
            {
                printf("\nInvalid Seat number & PIN combination..!\n");
            }
        }

        else
        {
            printf("\nENTER VALID INPUT\n");
        }

        printf("\n\nPRESS 1 to check seat status\n");
        printf("PRESS 2 to cancle more tickets\n");
        printf("PRESS 3 to exit cancelation portal\n");
        printf("Enter your choice : ");
        scanf("%s", &ch);

        if (ch == 1)
            display();

    } while (ch == '2');
}

int main()
{
    int choice;
    int c;
    system("COLOR 02");
    printf("\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("             WELCOME TO BUS BOOKING SYSTEM\n");
    printf("--------------------------------------------------------------------------\n");
    create();
    // display();

    do
    {
        printf("\n\n");
        printf("PRESS 1 -> BOOK TICKETS\n");
        printf("PRESS 2 -> CANCLE TICKETS\n");
        printf("PRESS 3 -> DISPLAY\n");
        printf("PRESS 4 -> EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("COLOR 06");
            display();
            book_seat();
            display();
            break;
        case 2:
            system("COLOR 04");
            display();
            cancle();
            display();
            break;

        case 3:
            system("COLOR 01");
            display();
            break;

        case 4:
            system("COLOR 0F");
            printf("--------------------------------------------------------------------------\n");
            printf("                    EXIT SUCESSFULLY                                       \n");
            printf("--------------------------------------------------------------------------\n");
            break;

        default:
            system("COLOR 04");
            printf("Enter Correct option\n");
            break;
        }

        if (choice != 4)
        {
            system("COLOR 0B");
            printf("\n\nPRESS 1 to Main Menu\n");
            printf("PRESS 2 To EXIT BOOKING SYSTEM\n");
            printf("Enter your choice\n");
            scanf("%d", &c);
        }
    } while (c == 1);

    system("COLOR 0F");
    printf("\n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("                    EXIT SUCESSFULLY                                       \n");
    printf("--------------------------------------------------------------------------\n");
    return 0;
}
