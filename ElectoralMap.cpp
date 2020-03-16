#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "district.h"
#include "electoralmap.h"
#include <math.h>


const int ElectoralMap::NUM_DISTRICT = 3;


ElectoralMap::ElectoralMap(){
  std::map<int, District*> temp;
  electoralmap_map_ = temp;


  int i = 1;
  while(District::get_unique_id() <= NUM_DISTRICT ){
    total_districts_ +=1;
    i++;
    District *d = new District();
    total_constituents_ += d->get_total_constituents();
    electoralmap_map_.insert(std::pair<int, District*> (District::get_unique_id()-1, d));

  }

  }
void ElectoralMap::Campaign(Candidate *c, District *d){
  double p_success = 0.0;
  double p_extra_success = 0.0;



  double percent_of_constiuents = 0.0;
  double constituent_area = 0.0;
  std::cout<<""<<std::endl;

  //make sure I do not get 0 for my denomanator so that I do not get a result of inf.
  if(d->get_total_constituents() - ( d->get_party_constituents(c->affiliation) + d->get_party_constituents(Party::None) == 0)){
    percent_of_constiuents = 1;
  }
  else{
      percent_of_constiuents = (double((d->get_party_constituents(c->affiliation) +1) * 2)/ (d->get_total_constituents() - ( d->get_party_constituents(c->affiliation) + d->get_party_constituents(Party::None))));
  }

  constituent_area = (double((d->get_party_constituents(c->affiliation) +1) * 2) / (d->get_area_()));

  p_success = percent_of_constiuents* constituent_area;


  p_success = p_success * 100.0;
  if(p_success > 100.0){
    p_success = 100.0;
  }

  p_extra_success = p_success * .10;

  int result = rand() % 100 + 1;
  std::cout<<"Chances to convert: "<< p_success <<std::endl;
  std::cout<<"Chances to convert from another party: "<< p_extra_success<<std::endl;



    if( result<= p_success){
      //Checking to make sure pary None is not zero.
      if(d->get_party_constituents(Party::None) != 0){

        d->IncrementConstituents(c->affiliation);
        d->DecrementConstituents(Party:: None);
        std::cout<<"Congrats, you have converted someone from None to "<< StringifyParty(c->affiliation)<<std::endl;
      }
      else{
        std::cout<<"Sorry, no one in None to convert!"<<std::endl;
      }

    if( result <= p_extra_success){
      if(c->affiliation != d->get_majority_party_() && d->get_party_constituents(d->get_majority_party_()) != 0){
        d->IncrementConstituents(c->affiliation);
        d->DecrementConstituents(d->get_majority_party_());
        std::cout<<"Congrats, you have converted someone from "<< StringifyParty(d->get_majority_party_())<<" to "<< StringifyParty(c->affiliation)<<"!"<<std::endl;
        d->UpdateMajorities();
      }
      else if(c->affiliation == d->get_majority_party_() && d->get_party_constituents(d->get_second_majority()) != 0){
        d->IncrementConstituents(c->affiliation);
        d->DecrementConstituents(d->get_second_majority());
        std::cout<<"Congrats, you have converted someone from "<< StringifyParty(d->get_second_majority()) <<" to "<< StringifyParty(c->affiliation)<<"!"<<std::endl;
        d->UpdateMajorities();

      }
      else{
        std::cout<<"Sorry, no one in other majority to convert!"<<std::endl;
      }
    }
    }
    else{
      std::cout<<"You failed to convince anyone to join your party! Better luck next time!"<<std::endl;
    }
}



int ElectoralMap::calculateRepVote(District *d){
  int votes = 0;
  double  results = 0.0;

  results = (double(d->get_total_constituents() * 1) / get_total_constituents()) ;
  votes = floor(results * (get_total_distrcts() * 5));

  return votes;


}


std::ostream& operator<<(std::ostream& os, const ElectoralMap &em){

  for(auto itr: em.electoralmap_map_){
    os<<*itr.second;

  }
  os<<"\n";
  return os;
};
