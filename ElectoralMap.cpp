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
  // std::cout<<"unique_id_ is BEFORE: "<< District::get_unique_id()<<std::endl;
  // std::cout<<"NUM_DISTRICT is BEFORE: "<< NUM_DISTRICT<<std::endl;
  int i = 1;
  while(District::get_unique_id() <= NUM_DISTRICT ){
    i++;
    District *d = new District();
    electoralmap_map_.insert(std::pair<int, District*> (District::get_unique_id()-1, d));

  }
  //int num_of_districts
  //  int District::set_district_id(0);

  }
void ElectoralMap::Campaign(Candidate *c, District *d){
  double p_success = 0;
  double p_extra_success = 0;
  for(auto itr: d->get_district_map()){

    std::cout<< StringifyParty(itr.first)<<":" << itr.second<<std::endl;

  }

  std::cout<<"area is: "<<d->get_area_()<<std::endl;
  std::cout<<"trump party has this many voters is: "<<d->get_party_constituents(c->affiliation)<<std::endl;


  std::cout<<"trump party is: "<< StringifyParty(c->affiliation)<<std::endl;

  p_success = std::min(100, (((d->get_party_constituents(c->affiliation) + 1) * 2) / ((d->get_total_constituents())) - (d->get_party_constituents(Party::None) + d->get_party_constituents(c->affiliation))) *(((d->get_party_constituents(c->affiliation) + 1) * 2) /( d->get_area_())));

  p_extra_success = p_success * 0.1;
  std::cout<<p_success<<std::endl;
  std::cout<<p_extra_success<<std::endl;
  std::cout<<"It worked!"<<std::endl;





}
