#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorter.h"

int main (int argc, char** argv){

  char * buffer = NULL;//current line of csv being accessed
  size_t buffSize = 1000;//size of buffer allocated (may be adjusted as needed)
  char* currString = NULL;//variable to hold various strings
  int inputType = -1;//input type to be fed to roy's sorter

  char*** inputMat;//matrix to be fed to sorter
  int matHeight = 0;//current allocated height of matrix
  int currHeight = 0;//current height of matrix being created

  int columnCnt =0;//count of column in question (to be fed to sorter)
  int currCol = 0;//current colummn being populated

  int tempCnt = 0;//counter for test print method


  inputMat = (char***)malloc(sizeof(char**)*50);
  matHeight += 50;


  //list of all categories
  char* categories []= {"color","director_name","num_critic_for_reviews",
		       "duration","director_facebook_likes","actor_3_facebook_likes",
		       "actor_2_name","actor_1_facebook_likes","gross","genres",
		       "actor_1_name","movie_title","num_voted_users",
		       "cast_total_facebook_likes","actor_3_name","facenumber_in_poster",
		       "plot_keywords","movie_imdb_link","num_user_for_reviews",
		       "language","country","content_rating","budget","title_year",
		       "actor_2_facebook_likes","imdb_score","aspect_ratio",
		       "movie_facebook_likes"};
  

  //list of types of those categories. 0 is string, 1 is numeric, 2 is date/time
  int codes []= {0,0,1,2,1,1,0,1,1,0,0,0,1,1,0,1,0,0,1,0,0,0,1,1,1,1,1,1};

  if(argc != 3){
    printf("Invalid number of arguments!");
  }
  currString = argv[2];
  for(columnCnt = 0; columnCnt < 28; columnCnt++){

    if(strcasecmp(currString, categories[columnCnt]) == 0){
      inputType = codes[columnCnt];
      break;
    }
  }
  if(inputType == -1){
    printf("Invalid category name!");
    return 0;
  }


  while(1){

    getline(&buffer, &buffSize, stdin);

    if(strcmp(buffer,"")==0){
      break;
    }

    printf("this buffer is: %s\n", buffer);//TESTING

    //check if matrix has reached limit
    if(currHeight>=matHeight){
      matHeight+=50;
      inputMat = realloc(inputMat, sizeof(char**)*matHeight);
    }
    //allocate new row
    inputMat[currHeight] = (char**)malloc(sizeof(char*)*28);
    currCol = 0;//reset column

    while(strlen(buffer)!= 0){
      if(buffer[0] == 34){
	//method for dealing with comma-containing values
      }else{
	//ordinary field, no commas
	currString = strsep(&buffer,",");

	printf("buffer now is: %s\n",buffer);//TESTING 

	printf("added: %s\n", currString);

	inputMat[currHeight][currCol] = currString;

	currCol++;//increment column count

      }
      if(!buffer){
	break;
      }
    }
   
    currHeight++;

  }
  //this loop will allow me to prevent the last line from cycling

  //test printing method
  for(tempCnt = 0; tempCnt < currHeight; tempCnt++){
    if(inputMat[tempCnt]!= NULL){
      for(columnCnt = 0; columnCnt<28; columnCnt++){
	printf("%s(row%d, col%d),",inputMat[tempCnt][columnCnt], tempCnt, columnCnt);
      }
    }
    printf("\n");
  }


  free(buffer);

  return 0;


}
