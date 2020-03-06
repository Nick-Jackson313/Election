
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
  unique_id_++;

  area_ = (rand() %25) + 9;
  int i = 0;

  while(PartyfyInterger(i) != Party::Last){
    int constituent_count =  (rand() %10);
    parties_demographic_[PartyfyInterger(i)] +=  constituent_count;
    total_constituents_ += constituent_count;
    if(i == 0){
      majority_party_ = PartyfyInterger(i);

    }
    else{
      if(parties_demographic_ [majority_party_] < parties_demographic_ [PartyfyInterger(i)]){
          majority_party_ = PartyfyInterger(i);
      }
    }
    i++;

  }


  std::cout<<"unique_id_ in District after constructor is run: "<< District::get_unique_id()<<std::endl;
}
void District::IncrementConstituents(Party p){

  parties_demographic_[p] += 1;

};
void District::DecrementConstituents(Party p){
  if(parties_demographic_[p] > 0){
    parties_demographic_[p] -= 1;
  }
};
