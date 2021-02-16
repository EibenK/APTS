#include <stdio.h>
#define SIZE 15
#define NUM_STR 14
#define RANGE 9
#define MAX 50



//Arrays for Names and Destinations
char bNames[NUM_STR][SIZE] = {"Blackbird", "Grosbeak", "Crossbill", "Finch", "KingBird", "Crow", "KingFisher",
                 "Shrike", "Sparrow", "Mistral", "williwaw", "Etesians", "Bora", "Mise"}; //15 slot array[14] - bird names 

char dest[NUM_STR][SIZE] = {"ALB", "AMS", "BCN", "BOS", "CUN", "CLE", "DTW","IND", "KIN", "LAX", "MAD", "MIA", "JFK", "PHL"}; //list of destinations



//****constructors & forward decs****

struct Plane;
struct Plane initPlanes();



//****user input****

char command();

//****combiner functions - plane creation****

char* createPlane(); //combining bird names(bNames) & ID(number between 100 - 999) to form one plane name
char* getId();
char* getIndexNames();


//****combiner functions - time****

char* genHour(); //generating a military time(hours)
char* genMin(); //generating a military time(minutes)
char* getTime(); //combining times into 1 time with colon


//****gate & destination info****

int getGate();
char* getDestInd();


//****Functions****

//struct Plane searchInfo();
void displayWindow(); //display terminal window for plane
void newSeed();





