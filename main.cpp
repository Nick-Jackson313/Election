#include <iostream>
#include <ctime>
#include "district.h"
#include "electoralmap.h"
#include "election.h"
#include "textui.h"




int main(){
    srand(time(NULL));
  //Candidate *trump = new Candidate;

  ElectoralMap &em = ElectoralMap::GetInstance();
  int election_type = 1;
//  election_type = TextUI::electionChoice();

  std::map<Candidate*, int> election_results;

  while(election_type){
    election_type = TextUI::electionChoice();
    if(election_type == 1){
      Election *e = new Election;
      TextUI ui(e);
      ui.registerCandidates();
      ui.campaigningChoice();
      ui.electionResults();
    }
    else if(election_type == 2){
      RepresentativeElection *re = new RepresentativeElection;
      TextUI ui(re);
      ui.registerCandidates();
      ui.campaigningChoice();
      ui.electionResults();
    }

  }


  return 0;
}
