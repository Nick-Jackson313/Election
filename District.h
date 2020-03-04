#ifndef DISTRICT_H
#define DISTRICT_H

enum class Party {Democrat, Repbulica, None,Last };
//
// , Libertarian, Independant, Green,

class District {
public:
  District(int id);
  int get_id() { return id_; };
  // int get_area_() { return area_; };
  // int get_constituents_() { return constituents_; };
  int get_party_type_get_constituents_();

private:
  int id_;
  //const int area_;
  //const int constituents_;
};

#endif
