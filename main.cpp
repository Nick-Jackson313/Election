#include <iostream>
#include <ctime>

int main(){

  srand(time(NULL));
  std::cout << (rand() %9) <<std::endl;
  std::cout << (rand() %10)<<std::endl;
  std::cout << (rand() %10)<<std::endl;

  return 0;
}
