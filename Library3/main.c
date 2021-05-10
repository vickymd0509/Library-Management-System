#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   char  taken[50];
   char  deadline [50];
   int   book_id;
};

int main ()
{
    FILE *file;
    struct Books book;
    int view;

    file = fopen("bookes.bin", "ab");
    if (file == NULL)
    {
        printf("Could not open file ");
        return 1;
    }

    fclose (file);

    addbook();
    viewbook();
    searchbook();
    deletebook();

    return 0;
}

void viewbook(struct Books input)
{
    FILE *infile;

    infile = fopen ("bookes.bin", "rb");
    if (infile == NULL)
    {
        printf("Could not open file ");
        return 1;
    }
    fseek( infile, 0, SEEK_SET );
    while(fread(&input, sizeof(struct Books), 1, infile))
        printf ("title:%s\n author:%s\n subject:%s\n taken:%s\n deadline:%s\n book_id:%d\n\n", input.title,
        input.author, input.subject, input.taken, input.deadline, input.book_id);

    fclose (infile);
}

void addbook (struct Books book)
{
    FILE *addfile;
    addfile = fopen("bookes.bin", "ab");
    if (addfile == NULL)
    {
        printf("Could not open file ");
        exit(1);
    }
    printf("ADD NEW BOOKS\n");
    printf("Title: ");
    fflush(stdin);
    fgets(book.title, 50, stdin);
    printf("Author: ");
    fflush(stdin);
    fgets(book.author, 50, stdin);
    printf("Subject: ");
    fflush(stdin);
    fgets(book.subject, 100, stdin);
    printf("Taken by: ");
    fflush(stdin);
    fgets(book.taken, 50, stdin);
    printf("Deadline: ");
    fflush(stdin);
    fgets(book.deadline, 50, stdin);
    printf("Book ID: ");
    fflush(stdin);
    scanf("%u",&book.book_id);
    fwrite(&book,sizeof(struct Books), 1, addfile);
    fclose(addfile);
}

void searchbook(struct Books book)
{
    int found=0;
    char title[50] = {0};
    FILE *file;
    file = fopen ("bookes.bin", "rb");
    if (file == NULL)
    {
        printf("Could not open file ");
        return 1;
    }
    printf("Enter title to search:");
    fflush(stdin);
    fgets(title,50,stdin);
    while (fread (&book, sizeof(book), 1, file))
    {
        if(!strcmp(book.title, title))
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf ("title:%s\n author:%s\n subject:%s\n taken:%s\n deadline:%s\n book_id:%d\n\n", book.title,
        book.author, book.subject, book.taken, book.deadline, book.book_id);
    }
    else
    {
        printf("There is no such book in the system");
    }

    fclose (file);
}

void deletebook(struct Books book)
{
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
    printf("Enter book ID to delete:");
    scanf("%d",&deletedbook);
    while (fread (&book, sizeof(book), 1, file))
    {
        if(book.book_id != deletedbook)
        {
            fwrite(&book,sizeof(book), 1, dfile);
        }
        else
        {
            found = 1;
        }
    }
    if(found==1)
    {
        printf("Book deleted successfully from the system.");
    }else{
        printf("Book not found");
    }
    fclose(file);
    fclose(dfile);
    remove("bookes.bin");
    rename("dbooks.bin","bookes.bin");
}
