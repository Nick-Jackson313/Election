
#include <iostream>
#include <vector>
#include "district.h"

int IntegerifyParty(Party p){
  int id = static_cast<int>(p);
  return id;
}

std::string StringifyParty(Party p){
  std::string parties[] = {"Democrat", "Republican", "None"};
  std::string party = parties[IntegerifyParty(p)];
  return party;
}

Party PartyfyInterger(int i){
  Party type = static_cast<Party>(i);
  return type;
}

int District::unique_id_ = 1;
District::District(){
  std::cout<<"unique_id_ in entering District: "<< District::get_unique_id()<<std::endl;
  id_ = unique_id_;
  unique_id_++;\
  bool value_used = false;

  area_ = (rand() %25) + 9;
  int i = 0;

  while(PartyfyInterger(i) != Party::Last){
    int constituent_count =  (rand() %10);
    district_map_[PartyfyInterger(i)] +=  constituent_count;
    total_constituents_ += constituent_count;
    if(i == 0){
      majority_party_ = PartyfyInterger(i);
    }
    //auto load the second majority
    else if(i == 1){
      if(district_map_ [majority_party_] < district_map_[PartyfyInterger(i)] ){
      second_majority_ = majority_party_;
      majority_party_ = PartyfyInterger(i);
    }
    }
    else{
      //This is checking if the party type and now become the majority
      if(district_map_ [majority_party_] < district_map_[PartyfyInterger(i)]){
          majority_party_ = PartyfyInterger(i);

      }
      //This will check if its second majority but only if the value was not alredy used to fill party majority.
      if(!value_used){


      }
    }
    i++;


  }


  std::cout<<"unique_id_ in District after constructor is run: "<< District::get_unique_id()<<std::endl;
}
void District::IncrementConstituents(Party p){

  district_map_[p] += 1;

};
void District::DecrementConstituents(Party p){
  if(district_map_[p] > 0){
    district_map_[p] -= 1;
  }
};
