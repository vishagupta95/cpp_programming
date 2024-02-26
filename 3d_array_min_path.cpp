#include<bits/stdc++.h>
using namespace std;
#define length 3
#define breadth 3
#define height 3


/*

We are given a cube which can be formed using a 3-D array as cube[length][breadth][height]. The task is to calculate the minimum sum path which will be achieved by traversing the cube and hence print the result.

Let us see various input output scenarios for this -

In − int cube[length][breadth][height] = { { {2, 4, 1}, {3, 4, 5}, {9, 8, 7}}, { {5, 3, 2}, {7, 6, 5}, {8, 7, 6}}, { {3, 2, 1}, {4, 3, 2}, {5, 4, 3}}}

Out  − Minimum Sum Path In 3-D Array are: 15

Explanation − we are given a cube having length, breadth and height. Now, we will calculate the minimum sum path in 3-D array. So, it will start from 2 + 4 + 1 + 3 + 5 i.e. 15.

In − int cube[length][breadth][height] = { { {1, 2}, {7, 8}}, { {3, 5}, {9, 16}}}

Out − Minimum Sum Path In 3-D Array are: 24

Explanation − we are given a cube having length, breadth and height. Now, we will calculate the minimum sum path in 3-D array. So, it will start from 1 + 2 + 5 + 16 i.e. 24.
*/



int Minimum(int a, int b, int c){
   if(a < b){
      if(a < c){
         return a;
      }
      else{
         return c;
      }
   }
   else if(b < c){
      return b;
   }
   else{
      return c;
   }
}
int Minimum_SubPath(int cube[][breadth][height]){
   int i, j, k;
   int arr[length][breadth][height];
   arr[0][0][0] = cube[0][0][0];

   for(i = 1; i < length; i++){
      arr[i][0][0] = arr[i-1][0][0] + cube[i][0][0];
   }
   for(j = 1; j < breadth; j++){
      arr[0][j][0] = arr[0][j-1][0] + cube[0][j][0];
   }
   for(k = 1; k < height; k++){
      arr[0][0][k] = arr[0][0][k-1] + cube[0][0][k];
   }
   for(i = 1; i < length; i++){
      for(j = 1; j < breadth; j++){
         int min_val = Minimum(arr[i-1][j][0], arr[i][j-1][0], INT_MAX);
         arr[i][j][0] = min_val + cube[i][j][0];
      }
   }
   for(i = 1; i < length; i++){
      for(k = 1; k < height; k++){
         int min_val = Minimum(arr[i-1][0][k], arr[i][0][k-1], INT_MAX);
         arr[i][0][k] = min_val + cube[i][0][k];
      }
   }
   for(k = 1; k < height; k++){
      for(j = 1; j < breadth; j++){
         int min_val = Minimum(arr[0][j][k-1], arr[0][j-1][k], INT_MAX);
         arr[0][j][k] = min_val + cube[0][j][k];
      }
   }
   for(i = 1; i < length; i++){
      for(j = 1; j < breadth; j++){
         for(k = 1; k < height; k++){
            int min_val = Minimum(arr[i-1][j][k], arr[i][j-1][k], arr[i][j][k-1]);
            arr[i][j][k] = min_val + cube[i][j][k];
         }
      }
   }
   return arr[length-1][breadth-1][height-1];
}
int main(){
   int cube[length][breadth][height] = { { {2, 4, 1}, {3, 4, 5}, {9, 8, 7}},
      { {5, 3, 2}, {7, 6, 5}, {8, 7, 6}},
      { {3, 2, 1}, {4, 3, 2}, {5, 4, 3}}};
   cout<<"Minimum Sum Path In 3-D Array are: "<<Minimum_SubPath(cube);
   return 0;
