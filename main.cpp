#include <iostream>
#include <ctime>
#include "district.h"
#include "electoralmap.h"





int main(){

  Candidate *trump = new Candidate;

  trump->name = "trump";
  trump->id = 1;
  trump->affiliation = Party::Republican;
  srand(time(NULL));
  ElectoralMap &em = ElectoralMap::GetInstance();
  //std::cout<<em;
  em.calculateRepVote(em.get_district(1));
  em.Campaign(trump, em.get_district(1));

  //std::cout<<em.get_total_constituents()<<std::endl;



  return 0;
}
