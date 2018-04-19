#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <queue>


using namespace std;

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

   for(int i = 0; i < 3; i++){
      cout << start_state[i][0] << " " << start_state[i][1] << "       " << goal_state[i][0] << " " << goal_state[i][1] << endl;
   }

   queue<int**> q;
   q.push(start_state);
   return 0;
}
