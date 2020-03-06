#ifndef ELECTORALMAP_H
#define ELECTORALMAP_H

#include "district.h"


class ElectoralMap {
public:

	static ElectoralMap& GetInstance() {
		// gets instantiated the first time
		static ElectoralMap instance; // guaranteed to be destroyed

		return instance;
	}

   std::map< int, District*>get_district_map() { return district_map_;};
   District get_district(int id){return  *district_map_[id];};


	// Delete the methods we don't want
	ElectoralMap(ElectoralMap const&) = delete; // copy constructor
	void operator=(ElectoralMap const&) = delete; // assignment operator
  static const int NUM_DISTRICT;


 private:
 	ElectoralMap();  // private constructor
  std::map< int, District*> district_map_;




};  // class Earth

#endif  // ELECTORALMAP_H
