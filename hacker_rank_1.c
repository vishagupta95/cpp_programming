#include <stdio.h>
#include <string.h>
/*
 *  Lowest Starting Stair A Monkey Is Jumping On A Long Staircase, On Which Each Stair Is Numbered; Th
  2 ackerRank Question - Inorder Tree Traversal
  */

/*
 * train A goes 5km and reach in 7 hrs
train B goes 7km and rech in 5 hrs
if train A starts at 4pm and train B starts at 3pm when they reach

       3  4  5 6  6.30   7

tr a         7 14    17.5  21

tr b      5  10 15   17.5   20
*/



/*
C99 Standard 6.7.8.21
If there are fewer initializers in a brace-enclosed list than there are elements or members of an aggregate, 
the remainder of the aggregate shall be initialized implicitly the same as objects that have static storage duration.

int array_1[ 4 ] = { 0 };    //  array_1[4] = {0, 0, 0, 0};

int array_2[ 4 ] = { -1 };  // array_2[4] = { -1, 0, 0, 0};
*
*/
// prob 1
int m() {
  int x = 0;
  static int y = 0;
  x++;
  y++;
  printf("%d --%d \n", x, y);
}

int main_1() {
    m();
    m();
    return (0);
  }
// output 1-1,1-2
//

int main_2 () {

  unsigned char ch = 0;
  int count = 0;
  while (++ch <= 255) {
    count++;
    printf("%d ch  %d \n", count,ch);
  }
}

int main_3(){
  char *p ="abcde";
  printf("%lu %lu %lu",sizeof(p),strlen(p),sizeof("abcde")); //m32
  return 0;
}
// 4 5 6  on 32 bit machine
// 8 5 6  on 64 bit machine
// infinute loop
//
int main_4(){
  int x = 4;
  int *y;
  y =&x;
  (*y)++;
  printf("%d",*y);
  return 0;
}
// output 5 
//

#define ADD(x) x +x                                                                                                                                                                  
#define SUB(x) x -x

int main_5(){

        int y= ADD(3)/SUB(3); //3+3/3-3  =1  , 1+ 1 =2
        printf("%d",ADD(y));
}
//.. output 2
//
//
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main_6(){
    int a =10,b=25,c=15;
    int res =0;

     while(b>0) {

        res += (a%c) + (c%a);
        b -= a%c;
        swap(&a,&c);
    }
    printf("%d",res); // 45
}
/*
 The sprintf() function returns the number of bytes that are written in the array, not counting the ending null character.
 delete is used to deallocate storage of a single object and delete[] used to deallocate storage of an array.

 */
#define p1 "vishal"
int main () {
   char str[10];
   char abc[] = "vishal";
   char *p ="vishal";
   int n =sprintf(str, "%s",abc);
   printf("%lu %lu %lu %lu\n",sizeof(p),strlen(p),sizeof("vishal"),n); // 8 6 7 6
   printf("%lu %lu \n",sizeof(p1),strlen(p1)); //7 6
   return(0);
}
