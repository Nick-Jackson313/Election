#include <iostream>
#include <vector>
#include <map>
#include "district.h"
#include "electoralmap.h"

const int ElectoralMap::NUM_DISTRICT = 3;
ElectoralMap::ElectoralMap(){
  std::map<int, District*> temp;
  district_map_ = temp;
  // std::cout<<"unique_id_ is BEFORE: "<< District::get_unique_id()<<std::endl;
  // std::cout<<"NUM_DISTRICT is BEFORE: "<< NUM_DISTRICT<<std::endl;
  int i = 1;
  while(District::get_unique_id() <= NUM_DISTRICT ){
    i++;
    District *d = new District();
    district_map_.insert(std::pair<int, District*> (District::get_unique_id()-1, d));

  }
  //int num_of_districts
  //  int District::set_district_id(0);

  }
