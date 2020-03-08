#ifndef ELECTORALMAP_H
#define ELECTORALMAP_H

#include "district.h"


struct Candidate{
  int id;
  std::string name;
  Party affiliation;
};

class ElectoralMap {
public:

	static ElectoralMap& GetInstance() {
		// gets instantiated the first time
		static ElectoralMap instance; // guaranteed to be destroyed

		return instance;
	}
  // Delete the methods we don't want
	ElectoralMap(ElectoralMap const&) = delete; // copy constructor
	void operator=(ElectoralMap const&) = delete; // assignment operator
  static const int NUM_DISTRICT;


   std::map< int, District*>get_district_map() { return electoralmap_map_;};
   District* get_district(int id){return  electoralmap_map_[id];};
   int get_total_constituents(){return total_constituents_;};
   int get_total_distrcts(){return total_districts_;};

   void Campaign(Candidate *c, District *d);
   int calculateRepVote(District *d);
   friend std::ostream& operator<<(std::ostream& os, const ElectoralMap &em);

 private:
 	ElectoralMap();  // private constructor
  std::map< int, District*> electoralmap_map_;
  int total_districts_;
  int total_constituents_;




};  // class Earth

#endif  // ELECTORALMAP_H
