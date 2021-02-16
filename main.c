#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "plane.c"


int main()
{
  //Menu to be added ~ switch

  initPlanes();

   printf("APTS - Flight Informational Display\n");
   printf("This menu below will display options for flights: \n\n");

  int flag = 0;
  int select = 0;
  char stop;

  do{
    printf("\nMENU\n");
    printf("1. Display current flights\n");
    //printf("2. Search Plane Info\n");
    printf("3. Exit display\n");
    
    select = command();      
    
    switch(select)
      {
      case '1':
	displayWindow(planeInfo);
	break;
	
	/*	  case '2':
		  searchInfo(planeInfo);
		  break;
	*/
      case '3':
	flag = 1;
	break;
	
      }
    
    if(flag == 1)
       {
	 break;
       }
    
  }while((stop = getchar()) == '\n'); //deletes whitespace in front of the input character
  
 
  return 0;
}
