#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <queue>


using namespace std;

int check_goal(int** current, int** goal){
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if(current[i][j] != goal[i][j]){
	    //current does not equal goal
	    return 0;
	 }
      }

   }
   //current is goal
   return 1;

}
int** move_one_chicken(int** current){
   int right; // if 0 the boat is on the left if 1 the boat is on the right
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if((i == 2) && (current[i][j] == 1)){
	    right = j; // 0 being the left and 1 being right
	 }
      }
   }
   if((current[0][right] - 1) >= 0){
      int** one_chicken = new int*[3];
      for(int i = 0; i < 3; i++){
	 one_chicken[i] = new int[2];
	 for(int j = 0; j < 2; j++){
	    if(i == 0){
	       one_chicken[i][right] = current[i][right] - 1;
	       one_chicken[i][(right + 1)%2] = current[i][right] + 1;
	    }
	    else if(i == 2){
	       // boat is being moved from the "right" position to the !right position
	       one_chicken[i][right] = 0;
	       one_chicken[i][(right + 1)%2] = 1;
	    }
	    else{
	       one_chicken[i][j] = current[i][j];
	    }
	 }
      }
      //check to see if it was a valid move
      if((one_chicken[0][0] < one_chicken[1][0]) && (one_chicken[0][0] != 0)){
	 return NULL;
      }
      else if((one_chicken[0][1] < one_chicken[1][1])&&(one_chicken[0][1] != 0)){
	 return NULL;
      }
      else{
	 return one_chicken;
      }
   }
   else{
      return NULL;
   }
}

int** move_two_chicken(int** current){
   int right; // if 0 the boat is on the left if 1 the boat is on the right
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if((i == 2) && (current[i][j] == 1)){
	    right = j; // 0 being the left and 1 being right
	 }
      }
   }
   if((current[0][right] - 2) >= 0){
      int** two_chicken = new int*[3];
      for(int i = 0; i < 3; i++){
	 two_chicken[i] = new int[2];
	 for(int j = 0; j < 2; j++){
	    if(i == 0){
	       two_chicken[i][right] = current[i][right] - 2;
	       two_chicken[i][(right + 1)%2] = current[i][(right + 1)%2] + 2;
	    }
	    else if(i == 2){
	       // boat is being moved from the "right" position to the !right position
	       two_chicken[i][right] = 0;
	       two_chicken[i][(right + 1)%2] = 1;
	    }
	    else{
	       two_chicken[i][j] = current[i][j];
	    }
	 }
      }
      //check to see if it was a valid move
      if((two_chicken[0][0] < two_chicken[1][0])&&(two_chicken[0][0] != 0)){
	 return NULL;
      }
      else if((two_chicken[0][1] < two_chicken[1][1])&&(two_chicken[0][1] != 0)){
	 return NULL;
      }
      else{
	 return two_chicken;
      }
   }
   else{
      return NULL;
   }
}

int** move_one_wolf(int** current){
   int right; // if 0 the boat is on the left if 1 the boat is on the right
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if((i == 2) && (current[i][j] == 1)){
	    right = j; // 0 being the left and 1 being right
	 }
      }
   }
   if((current[1][right] - 1) >= 0){
      int** one_wolf = new int*[3];
      for(int i = 0; i < 3; i++){
	 one_wolf[i] = new int[2];
	 for(int j = 0; j < 2; j++){
	    if(i == 1){
	       one_wolf[i][right] = current[i][right] - 1;
	       one_wolf[i][(right + 1)%2] = current[i][(right + 1)%2] + 1;
	    }
	    else if(i == 2){
	       // boat is being moved from the "right" position to the !right position
	       one_wolf[i][right] = 0;
	       one_wolf[i][(right + 1)%2] = 1;
	    }
	    else{
	       one_wolf[i][j] = current[i][j];
	    }
	 }
      }
      //check to see if it was a valid move
      if((one_wolf[0][0] < one_wolf[1][0])&&(one_wolf[0][0] != 0)){
	 return NULL;
      }
      else if((one_wolf[0][1] < one_wolf[1][1])&&(one_wolf[0][1] != 0)){
	 return NULL;
      }
      else{
	 return one_wolf;
      }
   }
   else{
      return NULL;
   }
}

int** move_two_wolves(int** current){
   int right; // if 0 the boat is on the left if 1 the boat is on the right
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if((i == 2) && (current[i][j] == 1)){
	    right = j; // 0 being the left and 1 being right
	 }
      }
   }
   if((current[1][right] - 2) >= 0){
      int** two_wolves = new int*[3];
      for(int i = 0; i < 3; i++){
	 two_wolves[i] = new int[2];
	 for(int j = 0; j < 2; j++){
	    if(i == 1){
	       two_wolves[i][right] = current[i][right] - 2;
	       two_wolves[i][(right + 1)%2] = current[i][(right + 1)%2] + 2;
	    }
	    else if(i == 2){
	       // boat is being moved from the "right" position to the !right position
	       two_wolves[i][right] = 0;
	       two_wolves[i][(right + 1)%2] = 1;
	    }
	    else{
	       two_wolves[i][j] = current[i][j];
	    }
	 }
      }
      //check to see if it was a valid move
      if((two_wolves[0][0] < two_wolves[1][0])&&(two_wolves[0][0] != 0)){
	 return NULL;
      }
      else if((two_wolves[0][1] < two_wolves[1][1])&&(two_wolves[0][1] != 0)){
	 return NULL;
      }
      else{
	 return two_wolves;
      }
   }
   else{
      return NULL;
   }
}


int** move_one_wolf_chicken(int** current){
   int right; // if 0 the boat is on the left if 1 the boat is on the right
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 2; j++){
	 if((i == 2) && (current[i][j] == 1)){
	    right = j; // 0 being the left and 1 being right
	 }
      }
   }



   if(((current[0][right] - 1) >= 0) &&((current[1][right] - 1) >= 0)){
      int** one_wolf_chicken = new int*[3];
      for(int i = 0; i < 3; i++){
	 one_wolf_chicken[i] = new int[2];
	 for(int j = 0; j < 2; j++){
	    if(i == 0){
	       one_wolf_chicken[i][right] = current[i][right] - 1;
	       one_wolf_chicken[i][(right + 1)%2] = current[i][(right + 1)%2] + 1;

	    }
	    else if(i == 1){
	       one_wolf_chicken[i][right] = current[i][right] - 1;
	       one_wolf_chicken[i][(right + 1)%2] = current[i][(right + 1)%2] + 1;
	    }
	    else if(i == 2){
	       // boat is being moved from the "right" position to the !right position
	       one_wolf_chicken[i][right] = 0;
	       one_wolf_chicken[i][(right + 1)%2] = 1;
	    }
	 }
      }
      //check to see if it was a valid move
      if((one_wolf_chicken[0][0] < one_wolf_chicken[1][0])&&(one_wolf_chicken[0][0] != 0)){
	 return NULL;
      }
      else if((one_wolf_chicken[0][1] < one_wolf_chicken[1][1])&&(one_wolf_chicken[0][1] != 0)){
	 return NULL;
      }
      else{
	 return one_wolf_chicken;
      }
   }
   else{
      return NULL;
   }
}

void expand_path(int** current, int count, queue<int**>& q, queue<int>& count_q){
   //put one chicken in the boat
   int** one_chicken = move_one_chicken(current);
   if(one_chicken != NULL){
      q.push(one_chicken);
      count_q.push(count + 1);
   }
   //put two chickens in the boat
   int** two_chicken = move_two_chicken(current);
   if(two_chicken != NULL){
      q.push(two_chicken);
      count_q.push(count + 1);
   }
   //put one wolf in the boat
   int** one_wolf = move_one_wolf(current);
   if(one_wolf != NULL){
      q.push(one_wolf);
      count_q.push(count + 1);
   }
   //put two wolves in the boat
   int** two_wolves = move_two_wolves(current);
   if(two_wolves != NULL){
      q.push(two_wolves);
      count_q.push(count + 1);
   }
   //put one wolf and one chicken in the boat
   int** one_wolf_chicken = move_one_wolf_chicken(current);
   if(one_wolf_chicken != NULL){
      q.push(one_wolf_chicken);
      count_q.push(count + 1);
   }

}


void breadth_first_search(int** start, int** goal){
   int count = 0;
   int** current = start;
   queue<int**> q;
   queue<int> count_q;
   if(check_goal(current, goal) == 1){
      return;
   }	  
   else{
      expand_path(current, count, q, count_q);
      while(!q.empty()){
	 current = q.front();
	 q.pop();
	 count = count_q.front();
	 count_q.pop();
	 if(check_goal(current, goal) == 1){
	    //print out path
	    //print out number of moves
	    cout << count << endl;
	    return;
	 }
	 else{
	    expand_path(current, count, q, count_q);
	 }
      }
   }
}


int main(int argc, char*argv[]){
   int **start_state = new int*[3];
   int ** goal_state = new int*[3];
   for(int i = 0; i < 3; i++){
      start_state[i] = new int[2];
      goal_state[i] = new int[2];
      for(int j = 0; j < 2; j++){
	 start_state[i][j] = 0;
	 goal_state[i][j] = 0;
      }
   }
   // start               goal
   // [3  0]           [0   3]
   // [3  0]  ----->   [0   3]
   // [1  0]           [0   1]

   strcat(argv[1], "\0");
   ifstream start_input;
   start_input.open(argv[1]);

   strcat(argv[2], "\0");
   ifstream goal_input;
   goal_input.open(argv[2]);

   string leftstart;
   string rightstart;

   string leftgoal;
   string rightgoal;

   start_input >> leftstart;
   start_input >> rightstart;

   goal_input >> leftgoal;
   goal_input >> rightgoal;

   char delim[2] = ",";
   istringstream iss(leftstart);

   string token;

   getline(iss, token, ',');
   start_state[0][0] = stoi(token);

   getline(iss, token, ',');
   start_state[1][0] = stoi(token);

   getline(iss, token, ',');
   start_state[2][0] = stoi(token);


   istringstream oss(rightstart);

   getline(oss, token, ',');
   start_state[0][1] = stoi(token);

   getline(oss, token, ',');
   start_state[1][1] = stoi(token);

   getline(oss, token, ',');
   start_state[2][1] = stoi(token);


   istringstream uss(leftgoal);	
   getline(uss, token, ',');
   goal_state[0][0] = stoi(token);

   getline(uss, token, ',');
   goal_state[1][0] = stoi(token);

   getline(uss, token, ',');
   goal_state[2][0] = stoi(token);


   istringstream ess(rightgoal);
   getline(ess, token, ',');
   goal_state[0][1] = stoi(token);

   getline(ess, token, ',');
   goal_state[1][1] = stoi(token);

   getline(ess, token, ',');
   goal_state[2][1] = stoi(token);


   breadth_first_search(start_state, goal_state);
   /*
      for(int i = 0; i < 3; i++){
      cout << start_state[i][0] << " " << start_state[i][1] << "       " << goal_state[i][0] << " " << goal_state[i][1] << endl;
      }

      queue<int**> q;
      q.push(start_state);
      */
   return 0;
}
