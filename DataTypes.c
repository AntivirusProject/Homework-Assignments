#include <stdio.h>
#include <strings.h>


		
struct books{
	int publishedYear;
	char Author[50];
	char Title[20];
	int bookID;
	
	
	};


int main(){
	struct books book1, book2, book3;
	
		book1.publishedYear = 1989;
		book2.publishedYear = 2001;
		book3.publishedYear = 2015;
		
		book1.bookID = 1;
		book2.bookID = 2;
		book3.bookID = 3;
		
		strcpy(book1.Author, "Ayn Rand");
		strcpy(book2.Author, "Auldous Huxley");
		strcpy(book3.Author, "Gabriel Lewis");
		
		strcpy(book1.Title, "Anthem");
		strcpy(book2.Title, "Brave New World Part 2");
		strcpy(book3.Title, "De Capo Al Fine");
		
		printf("Enter Book ID: ");
		int x, y, z;
		
		scanf("%d, %d, %d", &x, &y, &z);
		
		book1.bookID = x;
		book2.bookID = y;
		book3.bookID = z;
		
		
		
		printf("%d, %d, %d", book1.bookID, book2.bookID, book3.bookID);
			
		
		
		
		
		return 0;
		}
		


		
	
	
