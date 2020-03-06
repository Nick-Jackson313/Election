#include <iostream>
#include <ctime>
#include "district.h"
#include "electoralmap.h"





int main(){

  srand(time(NULL));
  //ElectoralMap &em = ElectoralMap::GetInstance();


  District test_run;
  District test_run1;
  // District test_run2;



  for(auto itr: test_run.get_parties_demographic_()){

    std::cout<< StringifyParty(itr.first)<<":" << itr.second<<std::endl;

  }
  for(auto itr: test_run1.get_parties_demographic_()){

    std::cout<< StringifyParty(itr.first)<<":" << itr.second<<std::endl;

  }
  //std::cout<<test_run.get_id()<<std::endl;
  // std::cout<<test_run1.get_id()<<std::endl;
  // std::cout<<test_run2.get_id()<<std::endl;




  return 0;
}
