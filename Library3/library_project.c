/* Authors: Niya Markova && Victoria Dimitrova
   Project Name: Library Management System
	 Tasks: - to add new books;
	 				- to search books;
	 				- to delete books;
	 				-	to note who took the book and when;	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

COORD coord = {0, 0};

void GoToXY(int x, int y) { //Coordinate function - where to move the cursor on the console
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Books {
   char  title[50];
   char  author[50];
   char  subject[50];
   char  taken[50];
   char  deadline [50];
   int   book_id;
};

void welcome();
void menu();
int addbook();
int deletebook();
int searchbook();
int viewbook();
int editbook();
void leaving();

int choice;
int buff = 0;

int main() {
	struct Books book;

	FILE *file;
	file = fopen("bookes.bin", "ab");
	if (file == NULL) {
			printf("Could not open file ");
			return 1;
	}
	fclose (file);

	welcome();
	menu();
}

void welcome() { //Function For The Welcome Screen
	system("cls");

	GoToXY(25, 6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 7);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 8);
	printf("\xDB\xDB\xDB\xDB\xB2           WELCOME           \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 9);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 10);
  printf("\xDB\xDB\xDB\xDB\xB2             TO              \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 11);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 12);
	printf("\xDB\xDB\xDB\xDB\xB2  LIBRARY MANAGEMENT SYSTEM  \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 13);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 14);
	printf("\xDB\xDB\xDB\xDB\xB2             ***             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 15);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 16);
	printf("\xDB\xDB\xDB\xDB\xB2    MADE BY NIYA && VICKY    \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 17);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 18);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 19);
	printf("Enter any key to continue...");
	getch();
}

void menu() { //The Main Menu
	system("cls");

	GoToXY(25, 6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 7);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 8);
	printf("\xDB\xDB\xDB\xDB\xB2             MENU            \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 9);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 10);
	printf("\xDB\xDB\xDB\xDB\xB2         1. Add Books        \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 11);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 12);
	printf("\xDB\xDB\xDB\xDB\xB2       2. Delete Books       \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 13);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 14);
  printf("\xDB\xDB\xDB\xDB\xB2       3. Search Books       \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 15);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 16);
	printf("\xDB\xDB\xDB\xDB\xB2      4. View Book List      \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 17);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 18);
	printf("\xDB\xDB\xDB\xDB\xB2    5. Edit Book's Record    \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 19);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
  GoToXY(25, 20);
	printf("\xDB\xDB\xDB\xDB\xB2           6. Exit           \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 21);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 22);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	GoToXY(25, 23);
	printf("Enter your choice: ");
	choice = getchar();
	switch(choice) {
		  case '1': addbook();
								break;
			case '2': deletebook();
								break;
			case '3': searchbook();
								break;
			case '4': viewbook();
								break;
			case '5': editbook();
								break;
			case '6':	leaving();
								break;
			default: {
				GoToXY(25,23);
				printf("\aWrong Entry!!Please re-entered correct option.");
				menu();
			}
	}
}

int addbook (struct Books book) { //Function For Adding New Books In The Book List
		system("cls");

		FILE *addfile;
    addfile = fopen("bookes.bin", "ab");
    if (addfile == NULL) {
        printf("Could not open file ");
        exit(1);
    }

		GoToXY(25, 6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		GoToXY(25, 8);
		printf("\xDB\xDB\xDB\xDB\xB2        ADD NEW BOOKS        \xB2\xDB\xDB\xDB\xDB");
		GoToXY(25, 10);
		printf("\xDB\xDB\xDB\xDB\xB2 Title: ");
    fflush(stdin);
    fgets(book.title, 50, stdin);
		GoToXY(25, 12);
		printf("\xDB\xDB\xDB\xDB\xB2 Author: ");
    fflush(stdin);
    fgets(book.author, 50, stdin);
		GoToXY(25, 14);
		printf("\xDB\xDB\xDB\xDB\xB2 Subject: ");
    fflush(stdin);
    fgets(book.subject, 50, stdin);
		GoToXY(25, 16);
		printf("\xDB\xDB\xDB\xDB\xB2 Taken by: ");
    fflush(stdin);
    fgets(book.taken, 50, stdin);
		GoToXY(25, 18);
		printf("\xDB\xDB\xDB\xDB\xB2 Deadline: ");
    fflush(stdin);
    fgets(book.deadline, 50, stdin);
		GoToXY(25, 20);
		printf("\xDB\xDB\xDB\xDB\xB2 Book ID: ");
    fflush(stdin);
    scanf("%u",&book.book_id);
		GoToXY(25, 22);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    fwrite(&book,sizeof(struct Books), 1, addfile);
    fclose(addfile);

		GoToXY(25, 24);
		printf("Do you want to add new books?");
		GoToXY(25, 25);
		printf("1 - Yes.");
		GoToXY(25, 26);
		printf("2 - No.");
		GoToXY(25, 27);
		printf("Enter your choice: ");
		getchar();
		do {
			choice = getchar();
			switch(choice) {
				case '1': {
					addbook(book);
					buff = 1;
					break;
				}
				case '2': {
					menu();
					buff = 1;
					break;
				}
				default: {
					GoToXY(25,27);
					printf("\aWrong Entry!!Please re-entered correct option: ");
				}
			}
		} while(buff == 0);
}

int deletebook(struct Books book) { //Function For Deleting Books From The Book List
		system("cls");

		int found=0, deletedbook=0;

		FILE *file;
    file = fopen ("bookes.bin", "rb");
    if (file == NULL)
    {
        printf("Could not open file ");
        return 1;
    }

		FILE *dfile;
    dfile = fopen ("dbooks.bin", "wb");
    if (dfile == NULL)
    {
        printf("Could not open file ");
        return 1;
    }

		GoToXY(25, 6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		GoToXY(25, 8);
		printf("\xDB\xDB\xDB\xDB\xB2         DELETE BOOK         \xB2\xDB\xDB\xDB\xDB");
		GoToXY(25, 10);
		printf("\xDB\xDB\xDB\xDB\xB2 Enter book ID to delete: ");
    scanf("%d", &deletedbook);
		GoToXY(25, 12);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

		while (fread (&book, sizeof(book), 1, file)) {
				if(book.book_id == deletedbook)
						found = 1;
				else
						fwrite(&book,sizeof(book), 1, dfile);
		}

		GoToXY(25, 14);
    if(found==1)
        printf("Book deleted successfully from the system.");
    else
        printf("Book not found");
		fclose(file);
		fclose(dfile);
		remove("bookes.bin");
		rename("dbooks.bin","bookes.bin");

		GoToXY(25, 16);
		printf("Do you want to delete other books?");
		GoToXY(25, 17);
		printf("1 - Yes.");
		GoToXY(25, 18);
		printf("2 - No.");
		GoToXY(25, 19);
		printf("Enter your choice: ");
		getchar();
		do {
			choice = getchar();
			switch(choice) {
				case '1': {
					deletebook(book);
					buff = 1;
					break;
				}
				case '2': {
					menu();
					buff = 1;
					break;
				}
				default: {
					GoToXY(25,20);
					printf("\aWrong Entry!!Please re-entered correct option: ");
				}
			}
		} while(buff == 0);
}

int searchbook(struct Books book) { //Function For Searching Books In The Book List
		system("cls");

		int found=0;
    char title[50] = {0};
    FILE *file;
    file = fopen ("bookes.bin", "rb");
    if (file == NULL) {
        printf("Could not open file ");
        return 1;
    }

		GoToXY(25, 6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		GoToXY(25, 8);
		printf("\xDB\xDB\xDB\xDB\xB2         SEARCH BOOK         \xB2\xDB\xDB\xDB\xDB");
		GoToXY(25, 10);
		printf("\xDB\xDB\xDB\xDB\xB2 Enter title to search: ");
    fflush(stdin);
    fgets(title,50,stdin);

    while (fread (&book, sizeof(book), 1, file)) {
        if(!strcmp(book.title, title)) {
            found = 1;
            break;
        }
    }

    if(found) {
				GoToXY(25, 12);
				printf ("\xDB\xDB\xDB\xDB\xB2 Author: %s", book.author);
				GoToXY(25, 14);
				printf ("\xDB\xDB\xDB\xDB\xB2 Subject: %s", book.subject);
				GoToXY(25, 16);
				printf ("\xDB\xDB\xDB\xDB\xB2 Taken: %s", book.taken);
				GoToXY(25, 18);
				printf ("\xDB\xDB\xDB\xDB\xB2 Deadline: %s", book.deadline);
				GoToXY(25, 20);
				printf ("\xDB\xDB\xDB\xDB\xB2 Book ID: %d", book.book_id);
				GoToXY(25, 22);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

				GoToXY(25, 24);
				printf("Do you want to search other books?");
				GoToXY(25, 25);
				printf("1 - Yes.");
				GoToXY(25, 26);
				printf("2 - No.");
				GoToXY(25, 27);
				printf("Enter your choice: ");
		}
    else {
				GoToXY(25, 12);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				GoToXY(25, 14);
				printf("There is no such book in the system.");

				GoToXY(25, 16);
				printf("Do you want to delete other books?");
				GoToXY(25, 17);
				printf("1 - Yes.");
				GoToXY(25, 18);
				printf("2 - No.");
				GoToXY(25, 19);
				printf("Enter your choice: ");
		}
		fclose (file);

		do {
			choice = getchar();
			switch(choice) {
				case '1': {
					searchbook(book);
					buff = 1;
					break;
				}
				case '2': {
					menu();
					buff = 1;
					break;
				}
				default: {
					if(found)
						GoToXY(25, 28);
					else
						GoToXY(25, 20);

					printf("\aWrong Entry!!Please re-entered correct option: ");
				}
			}
		} while(buff == 0);
}

int viewbook(struct Books input) { //Book List View Function
		system("cls");

		FILE *infile;
    infile = fopen ("bookes.bin", "rb");
    if (infile == NULL) {
        printf("Could not open file ");
        return 1;
    }
    fseek(infile, 0, SEEK_SET);

		GoToXY(70, 6);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		GoToXY(70, 8);
		printf("\xDB\xDB\xDB\xDB\xB2          BOOK LIST          \xB2\xDB\xDB\xDB\xDB");
		GoToXY(25, 10);
		printf("TITLE");
		GoToXY(55, 10);
		printf("AUTHOR");
		GoToXY(70, 10);
		printf("SUBJECT");
		GoToXY(95, 10);
		printf("TAKEN");
		GoToXY(120, 10);
		printf("DEADLINE");
		GoToXY(145, 10);
		printf("BOOK ID");

		int j=12;
		while(fread(&input, sizeof(struct Books), 1, infile))	{
			GoToXY(25,j);
			printf("%s", input.title);
			GoToXY(55,j);
			printf("%s", input.author);
			GoToXY(70,j);
			printf("%s", input.subject);
			GoToXY(95,j);
			printf("%s", input.taken);
			GoToXY(120,j);
			printf("%s", input.deadline);
			GoToXY(145,j);
			printf("%d", input.book_id);
			j += 2;
		}

		j += 1;
		GoToXY(70, j);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		j += 2;
		getchar();
		GoToXY(25, j);
		printf("Enter '1' to go back to menu: ");
		do {
			choice = getchar();
			switch(choice) {
				case '1': {
					menu();
					buff = 1;
					remove("bookes.bin");
					rename("dbooks.bin","bookes.bin");
					break;
				}
				default: {
					GoToXY(25, j+1);
					printf("\aWrong Entry!!Please re-entered correct option: ");
				}
			}
		} while(buff == 0);
    fclose (infile);
}

int editbook(struct Books book) {
	system("cls");

	int i, found, edit_book;
  char ch;
  int id;
  FILE *file, *mfile;

	file=fopen("bookes.bin","rb+");
	if(file==NULL) {
		printf("Could not open file");
		return 1;
	}

	GoToXY(25, 6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 8);
	printf("\xDB\xDB\xDB\xDB\xB2          EDIT BOOK          \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 10);
	printf("\xDB\xDB\xDB\xDB\xB2 Enter book ID to edit: ");
  scanf("%d", &edit_book);
  GoToXY(25, 12);
  mfile=fopen("dbooks.bin","a+");
  if (mfile == NULL) {
   	printf("Could not open file");
		return 1;
  }
  else {
   	while(fread(&book, sizeof(book), 1, file)) {
   		if(book.book_id == edit_book) {
   			found = 1;
   			printf("\n\tTitle:\t:%s\n\tAuthor\t:%s\n\tSubject\t:%s\n\tTaken\t:%s\n\tDeadline\t:%s\n", book.title,book.author,book.subject,book.taken,book.deadline);
				printf("\n\tEdit With New Records!");
				printf("\n\t\tEnter New Title\t\t:");
				fflush(stdin);
				gets(book.title);
				printf("\n\t\tEnter New Author\t\t:");
				fflush(stdin);
				gets(book.author);
				printf("\n\t\tEnter New Subject\t\t:");
				fflush(stdin);
				gets(book.subject);
				printf("\n\t\tEnter New Taken\t\t:");
				fflush(stdin);
				gets(book.taken);
				printf("\n\t\tEnter New Deadline\t\t:");
				fflush(stdin);
				gets(book.deadline);
				printf("\n\t\tEnter New ID\t\t:");
				fflush(stdin);
				scanf("%d",&book.book_id);
				fprintf(mfile,"%s %s %s %s %s %d", book.title, book.author, book.subject, book.taken, book.deadline, book.book_id);
				fflush(stdin);
				printf("\n\nBooks has been updated......");
			}
	   }
	   if(!found)
		 	printf("\n\tNo record found!");

		 fclose(mfile);
	   fclose(file);

		 remove("bookes.bin");
	   rename("dbooks.bin","bookes.bin");

     	printf("\n\t\tPress any key to go to mainmenu.....");
     	getch();
	    menu();
   }
}

void leaving() { //Function For The GoodBye Screen
	system("cls");
	GoToXY(25, 6);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 7);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 8);
	printf("\xDB\xDB\xDB\xDB\xB2           GOODBYE           \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 9);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 10);
	printf("\xDB\xDB\xDB\xDB\xB2            FROM             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 11);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 12);
	printf("\xDB\xDB\xDB\xDB\xB2  LIBRARY MANAGEMENT SYSTEM  \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 13);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 14);
	printf("\xDB\xDB\xDB\xDB\xB2            TEAM             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 15);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 16);
	printf("\xDB\xDB\xDB\xDB\xB2        NIYA && VICKY        \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 17);
	printf("\xDB\xDB\xDB\xDB\xB2                             \xB2\xDB\xDB\xDB\xDB");
	GoToXY(25, 18);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	GoToXY(25, 19);
	printf("Exiting in 3 second...........");
	Sleep(3000);
	exit(0);
}
