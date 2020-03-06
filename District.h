#ifndef DISTRICT_H
#define DISTRICT_H

#include <map>
//Do I need to iterate through this??
enum class Party {Democrat, Republican, None, Last};


int IntegerifyParty(Party p);
std::string StringifyParty(Party p);
Party PartyfyInterger(int i);

class District{
public:
  District();
  int get_id() { return id_; };
  int get_area_() { return area_; };
  int get_constituents_() { return total_constituents_; };
  static int get_unique_id(){return unique_id_;};
  Party get_majority_party_(){return majority_party_;};
  void IncrementConstituents(Party p);
  void DecrementConstituents(Party p);
  std::map<Party, int> get_parties_demographic_(){return parties_demographic_;};
  // void


private:
  static int unique_id_;
  int id_;
  int   area_;
  int total_constituents_;
  Party majority_party_;
  Party second_majority_;
  std::map<Party, int> parties_demographic_;

};

#endif
