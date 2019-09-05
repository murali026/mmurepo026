#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    total_number_of_books = (int *) malloc(total_number_of_shelves * sizeof(int));
    memset(total_number_of_books, 0, total_number_of_shelves*sizeof(int));
    total_number_of_pages = malloc(total_number_of_shelves * sizeof(int*));
    printf("number of shelves: %d adr:%p\n", total_number_of_shelves, total_number_of_pages);
    //memset(total_number_of_pages, 0, sizeof(total_number_of_shelves * sizeof(int*)));
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i) == NULL) {
            printf("Lets allocated for each shelf:%d\n", i);
            *(total_number_of_pages + i) = malloc(1100 * sizeof(int));
            printf("Shelf:%d adr:%p\n", i, *(total_number_of_pages + i));
        }
    }
    //printf("number of queries: %d", total_number_of_queries);
    //printf("\n");
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);
            int book_count = *(total_number_of_books + x);
            int* shelf = *(total_number_of_pages + x);
            printf("%d books in shelf %d adr:%p\n", book_count, x, shelf);
            *(shelf + book_count) = y;
            *(total_number_of_books + x) =  ++book_count;
            printf("book_count:%d", book_count);
        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
