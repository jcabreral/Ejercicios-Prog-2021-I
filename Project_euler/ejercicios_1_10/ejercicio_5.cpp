/*

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

#include<iostream>

void divisor(int numa, int numb);

int main(int argc, char *argv[]){

  int a = std::atoi(argv[1]);
  int b = std::atoi(argv[2]);
  divisor(a, b);

  return 0;
}

void divisor(int numa, int numb){

  bool flag = true;
  int n = 0;
  while(flag){
    n++;
    for(int i = numa; i <= numb; i++){
      
    }
    
  }


}