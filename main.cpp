#include <iostream>
#include <ctime>
#include "district.h"
#include "electoralmap.h"





int main(){

  srand(time(NULL));
  ElectoralMap &em = ElectoralMap::GetInstance();



  Candidate *Trump = new Candidate;
  Trump->name = "Trump";
  Trump->id = 1;
  Trump->affiliation = Party::Republican;

  Candidate *Sanders = new Candidate;
  Sanders->name = "Sanders";
  Sanders->id = 2;
  Sanders->affiliation = Party::Democrat;
  em.Campaign(Trump, em.get_district(1));



  // for(auto itr: test_run.get_district_map()){
  //
  //   std::cout<< StringifyParty(itr.first)<<":" << itr.second<<std::endl;
  //
  // }
  // for(auto itr: test_run1.get_district_map()){
  //
  //   std::cout<< StringifyParty(itr.first)<<":" << itr.second<<std::endl;
  //
  // }
  //std::cout<<test_run.get_id()<<std::endl;
  // std::cout<<test_run1.get_id()<<std::endl;
  // std::cout<<test_run2.get_id()<<std::endl;




  return 0;
}
