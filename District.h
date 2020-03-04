#ifndef DISTRICT_H
#define DISTRICT_H

//enum class Party {Democrat, Repbulican, None,Last };

//struct Party_Constituents
//
// , Libertarian, Independant, Green,

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
};

#endif
