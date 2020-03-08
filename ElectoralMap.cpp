#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "district.h"
#include "electoralmap.h"


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
  double p_success = 0;
  double p_extra_success = 0;
  std::cout<<*d;

  double percent_of_constiuents = 0.0;
  double constituent_area = 0.0;

  percent_of_constiuents = (double((d->get_party_constituents(c->affiliation) +1) * 2)/ (d->get_total_constituents() - ( d->get_party_constituents(c->affiliation) + d->get_party_constituents(Party::None))));
  constituent_area = (double((d->get_party_constituents(c->affiliation) +1) * 2) / (d->get_area_()));
  std::cout<<"value of percent_of_constiuents is: "<<percent_of_constiuents<<std::endl;
  std::cout<<"value of constituent_area is: "<<constituent_area<<std::endl;
  //p_success = std::min(100, percent_of_constiuents * constituent_area );
  std::cout<< "p_success is: "<< p_success<<std::endl;



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
