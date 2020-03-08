
#include <iostream>
#include <vector>
#include "district.h"

int IntegerifyParty(Party p){
  int id = static_cast<int>(p);
  return id;
}

std::string StringifyParty(Party p){
  std::string parties[] = {"Democrat","Republican","Independent","Green","None","Last"};
  std::string party = parties[IntegerifyParty(p)];
  return party;
}

Party PartyfyInterger(int i){
  Party type = static_cast<Party>(i);
  return type;
}

int District::unique_id_ = 1;
District::District(){

  id_ = unique_id_;
  unique_id_++;
  area_ = rand() % 16 + 9;

  //All three varibles used in checks on majorties
  bool not_used = true;
  int majority_party_number = 0;
  int second_majority_party_number = 0;
  int i = 0;

  while(PartyfyInterger(i) != Party::Last){

    int constituent_count =  (rand() %10);

    district_map_[PartyfyInterger(i)] =  constituent_count;


    total_constituents_ += constituent_count;
    //One there are two values aviable I check which is higher and set both majorities accordingly
    if(i == 1){
      if(district_map_[PartyfyInterger(i - 1)] < district_map_[PartyfyInterger(i)]){
        majority_party_ = PartyfyInterger(i);
        second_majority_ = PartyfyInterger(i -1);
        majority_party_number = district_map_[majority_party_];
        second_majority_party_number =  district_map_[second_majority_];

      }

      else{
        second_majority_ = PartyfyInterger(i);
        majority_party_ = PartyfyInterger(i -1);
        majority_party_number = district_map_[majority_party_];
        second_majority_party_number =  district_map_[second_majority_];
      }
    }
    // This is the rest of the checking as I load more voters into thier party. I use the bool to make sure I never repeate load a value to majortiy and second majority.
    if( majority_party_number < district_map_[PartyfyInterger(i)] && PartyfyInterger(i) != Party::None){
      majority_party_ = PartyfyInterger(i);
      majority_party_number = district_map_[PartyfyInterger(i)];
      not_used = false;
    }
    else if( second_majority_party_number < district_map_[PartyfyInterger(i)] && not_used && PartyfyInterger(i) != Party::None){

        second_majority_ = PartyfyInterger(i);
        second_majority_party_number = district_map_[second_majority_];
    }
    else if(second_majority_party_number< district_map_[PartyfyInterger(0)] && majority_party_ != PartyfyInterger(0)){
      second_majority_ = PartyfyInterger(0);
      second_majority_party_number = district_map_[ second_majority_];
    }

    not_used = true;
    i++;
  }


}
void District::IncrementConstituents(Party p){

  district_map_[p] += 1;

};
void District::DecrementConstituents(Party p){
  if(district_map_[p] > 0){
    district_map_[p] -= 1;
  }
};
void District::UpdateMajorities(){
  bool not_used = true;
  int majority_party_number = district_map_[majority_party_];
  int second_majority_party_number = district_map_[second_majority_];
  int i = 0;

  while(PartyfyInterger(i) != Party::Last){

    if( majority_party_number < district_map_[PartyfyInterger(i)] && PartyfyInterger(i) != Party::None){
      majority_party_ = PartyfyInterger(i);
      majority_party_number = district_map_[PartyfyInterger(i)];
      not_used = false;
    }
    else if( second_majority_party_number < district_map_[PartyfyInterger(i)] && not_used && PartyfyInterger(i) != Party::None){

        second_majority_ = PartyfyInterger(i);
        second_majority_party_number = district_map_[second_majority_];
    }
    else if(second_majority_party_number< district_map_[PartyfyInterger(0)] && majority_party_ != PartyfyInterger(0)){
      second_majority_ = PartyfyInterger(0);
      second_majority_party_number = district_map_[ second_majority_];
    }

    not_used = true;
    i++;
  }
};
std::ostream& operator<<(std::ostream& os, const District &d){
  os<< "District " << d.get_id()<<":"<<std::endl;
  os<<" Square miles: " <<d.area_<<std::endl;
  for(auto itr: d.district_map_){

    os<<" ["<<StringifyParty(itr.first)<<"]"<< " : " << itr.second;

  }
  os<<"\n";
  return os;
};
