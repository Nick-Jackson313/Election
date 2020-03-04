#ifndef DISTRICT_H
#define DISTRICT_H


//Do I need to iterate through this??
enum class Party {Democrat, Repbulican, None};

//struct Party_Constituents
//
// , Libertarian, Independant, Green,

//This is to combine the party and the amount of constituents each party has per district.
struct Party_Constituents{
  Party affiliation;
  int num_of_constituents;
};

class District{
public:
  District(int id);
  int get_id() { return id_; };
  int get_area_() { return area_; };
  int get_constituents_() { return total_constituents_; };


private:
 int id_;
 int   area_;
 int total_constituents_;
 std::vector<Party_Constituents> parties_demographic_;
};

#endif
