/*
You can use the "PI_Works_Technical_Questionnaire_1.sln" file to run project.This project was implemented
on by Rahim ÇUBUK and Çağrı Esen..
Write code for below problem. The input below is just an example and you should implement independent from the
input. Please paste the link to the answer shared using pastebin, dotnetfiddle, jsfiddle, or any other similar
web-site.

You will have a ORTHOGONAL TRIANGLE input from a file and you need to find the maximum sum of the numbers according
to given rules below;

1. You will start from the top and move downwards to an adjacent number as in below.
2. You are only allowed to walk downwards and diagonally.
3. You can only walk over NON PRIME NUMBERS.
4. You have to reach at the end of the pyramid as much as possible.

According to above rules the maximum sum of the numbers from top to bottom in below example is 24.

      *1
     *8 4
    2 *6 9
   8 5 *9 3

As you can see this has several paths that fits the rule of NOT PRIME NUMBERS; 1>8>6>9, 1>4>6>9, 1>4>9>9
1 + 8 + 6 + 9 = 24.  As you see 1, 8, 6, 9 are all NOT PRIME NUMBERS and walking over these yields the maximum sum.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define SIZE 4

bool is_prime (int);
void create_pyramid (int [][SIZE]);
int maxPathSum (int [][SIZE]);

int main (){

    int pyramid [SIZE][SIZE];
    create_pyramid (pyramid);
    cout << "\nsum of max path = " << maxPathSum (pyramid);

}
void create_pyramid (int pyramid [SIZE][SIZE]){
   srand(time(NULL));
   for (int i = 0; i < SIZE;  i++){
        for (int j = 0; j <= i;  j++){
            int num = 1 + rand() % 10;
            if (i == 0 || j == 0){
               for (;;){
                   if (!is_prime(num))
                      break;
                   else
                      num = 1 + rand() % 10;
               }
             }
             pyramid [i][j] = num;
             cout << " " << pyramid [i][j] << " " ;
        }
        cout << endl;
   }
}

bool is_prime (int number){
   int count = 0;
   if (number == 1)
      return false;
   for (int i = 2; i < number; i++)
       if (number % i == 0)
           count++;
   if (count == 0)
      return true;
   else
      return false;
}
int maxPathSum(int pyramid [SIZE][SIZE]){
            for (int i = SIZE - 2; i >= 0; i--)
            {
                for (int j = 0; j <= i; j++)
                {
                    if (i == (SIZE - 2))
                    {
                        if (is_prime(pyramid [i][j]))
                            pyramid[i][j] = 0;
                        else
                        {
                            if (!is_prime(pyramid[i + 1][j]) || !is_prime(pyramid[i + 1][j + 1]))
                            {
                                if (!is_prime(pyramid[i + 1][j]))
                                {
                                    if (!is_prime(pyramid[i + 1][j + 1]))
                                    {
                                        if (pyramid[i + 1][j] > pyramid[i + 1][j + 1])
                                            pyramid[i][j] += pyramid[i + 1][j];
                                        else
                                            pyramid[i][j] += pyramid[i + 1][j + 1];
                                    }
                                    else
                                        pyramid[i][j] += pyramid[i + 1][j];
                                }
                                else
                                    pyramid[i][j] += pyramid[i + 1][j + 1];
                            }
                            else
                                pyramid[i][j] = 0;
                        }
                    }
                    else
                    {
                        if (is_prime(pyramid[i][j]))
                            pyramid[i][j]= 0;
                        else
                        {
                            if (pyramid[i + 1][j] !=0 || pyramid[i + 1][j + 1] !=0)
                            {
                                if (pyramid[i + 1][j] != 0)
                                {
                                    if (pyramid[i + 1][j + 1] != 0)
                                    {
                                        if (pyramid[i + 1][j] > pyramid[i + 1][j + 1])
                                            pyramid[i][j] += pyramid[i + 1][j];
                                        else
                                            pyramid[i][j] += pyramid[i + 1][j + 1];
                                    }
                                    else
                                        pyramid[i][j]+= pyramid[i + 1][j];
                                }
                                else
                                    pyramid[i][j] += pyramid[i + 1][j + 1];
                            }
                            else
                                pyramid[i][j] = 0;
                        }
                    }
                }
            }
return pyramid[0][0];
}
