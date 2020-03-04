
#include <iostream>
#include <vector>
#include "district.h"

District::District(int id){

  id_ = id;
  area_ = (rand() %25) + 9;

//This seems redundent but as far as I am concerned it gets the job done.
  Party_Constituents Democrat;
  Democrat.affiliation = Party::Democrat;
  Democrat.num_of_constituents = (rand() %10);
  total_constituents_ += Democrat.num_of_constituents;
  parties_demographic_.push_back(Democrat);

  Party_Constituents Repbulican;
  Repbulican.affiliation = Party::Repbulican;
  Repbulican.num_of_constituents = (rand() %10);
  total_constituents_ += Repbulican.num_of_constituents;
  parties_demographic_.push_back(Repbulican);


  Party_Constituents None;
  None.affiliation = Party::None;
  None.num_of_constituents = (rand() %10);
  total_constituents_ += None.num_of_constituents;
  parties_demographic_.push_back(None);

  //constituents_ = constituents_


}
