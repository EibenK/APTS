#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <stddef.h>
#include <stdint.h>
#include "plane.h"

//struct for plane terminal window
struct Plane
{
  int gate; //gate for plane 
  char* name; //plane name
  char* dest; //destination
  char* time; //time  
   
}planeInfo[SIZE];


char command()
{
  return getchar(); 
}

struct Plane initPlanes()
{
  
  newSeed();
  for(int i = 0; i < SIZE; i++)
    {
      planeInfo[i].name = createPlane();
      planeInfo[i].time = getTime();
      planeInfo[i].dest = getDestInd();
      planeInfo[i].gate = getGate();
    }

  return planeInfo[SIZE];
}


//*************************************CREATING THE PLANE******************************************************
void newSeed()
{
   srand((unsigned int)time(NULL));
}
char* createPlane()
{

  char* merge;
  char* ind = getIndexNames();
  char* iD = getId();
  
  merge = (char*)malloc(sizeof(ind) + sizeof(iD) + 1); //sizeof(char*) * sizeof(ind) == sizeof(ind)
  strcpy(merge, ind);
  strcat(merge, iD);
  
  return merge;

}
char* getId()
{
  int num = 0;
  char temp;
  char* result = (char*)malloc(3 * sizeof(char*) + 1);
  for(int i = 0; i < 3; i++)
    {
      num = (rand() % RANGE);
      temp = num + '0';
      result[i] = temp;
       
    }
  
  // free(result);   **Need to make a free function
  return result;    
}

char* getIndexNames()
{
   return bNames[(rand() % NUM_STR)];
}


//***********************************************CALCULATING TIME HOURS/MINUTES***************************
char* genHour()
{
  char* timeHr = (char*)malloc(2 * sizeof(char*) + 1);
  int hr = 0;
  char temp;
  hr = (rand() % 3);
  temp = hr + '0';
  timeHr[0] = temp;
  hr = 0;
  temp = '\0';
  
  if(timeHr[0] <= 1)
    {
      hr = (rand() % 10);
    }
  else
    {
      hr = (rand() % 4); 
    }
  temp = hr + '0';
  timeHr[1] = temp;

  return timeHr;
}
char* genMin()
{
  char* timeMin = (char*)malloc(3 * sizeof(char*) + 1);
  int min = 0;
  char temp;
  timeMin[0] = ':';
  min = (rand() % 6);
  temp = min + '0';
  timeMin[1] = temp;
  min = 0;
  temp = '\0';

  min = (rand() % 10);
  temp = min + '0';
  timeMin[2] = temp;

  return timeMin;
}

char* getTime()
{

  char* time;
  char* hours = genHour();
  char* minutes = genMin();

  time = (char*)malloc(sizeof(hours) + sizeof(minutes) + 1);
  strcpy(time, hours);
  strcat(time, minutes);

  return time; 

}
//**************************************DESTINATION/GATE INFORMATION******************************************************
int getGate()
{
  return (rand() % (100));
}

char* getDestInd()
{
   return dest[(rand() % NUM_STR)];

}

//**************************************DISPLAYING PLANE INFORMATION**************************************************

void displayWindow(struct Plane planeInfo[])
{
  printf("\nPlane Name\t\tArrival Time\t\tDestination\t\t Gate #\n");
  printf("----------\t\t------------\t\t-----------\t\t ------\n");
  
  for(int i = 0; i <  SIZE; i++)
    {
      printf("%-14s %14s %21s %23i\n", planeInfo[i].name, planeInfo[i].time,  planeInfo[i].dest,  planeInfo[i].gate);

    }
  printf("\n");
}

//*************************************SPECIALIZATION*************************************************
/*
struct Plane searchInfo()
{
  printf("\nHow would you like to search our system today?\n");
  printf("1: Plane Name.\n");
  printf("2: Time of departure.\n");
  printf("3: Destination(abbrev.).\n");
  printf("4: Gate Number");
  char c = getchar();
  char str[NUM_STR];
    
  while(1)
    {
      //Searching by name
      switch(c)
	{
	case '1':
	  {
	    scanf("%[^\n]%*c", str);
	    
	    
	    for(int i = 0; i < SIZE; i++)
	      {
		
		if(strcmp(str, planeInfo[i].name) == 0)
		  {};
	      }
	    break;
	  }
	case '2':
	  {
	    break;
	  }
	case '3':
	  {
	    break;
	    
	  }
	case '4':
	  {
	    break;
	    
	  }
	case '0':
	  {
	    printf("\nSorry, that was not one of the options in the list.\n");
	    printf("Return to the search options or go back to the main menu?\n");
	    printf("1: Main Menu.\n");
	    printf("2: Search Menu.\n");
	    break;
	  }
	}
    }
  //come back to this function
  return planeInfo[0];
}
*/
