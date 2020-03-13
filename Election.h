#ifndef ELECTION_H
#define ELECTION_H


#include <vector>
#include "district.h"
#include "electoralmap.h"


class Election {
public:
  Election();
  void registerCanidate(int, std::string, Party p);
  void Campaign(Candidate *c, District *d);
  std::vector<Candidate*> get_candadiates(){return Candidates_;};
  std::vector<std::vector<Candidate*>>storeCandidates();
  virtual std::map<Candidate*, int> countVotes(std::vector<std::vector<Candidate*>>, District *d);


  std::map<Candidate*, int> countVotes();



protected:

  std::vector<Candidate*> Candidates_;
};

class RepresentativeElection : public Election{
public:
  RepresentativeElection();
  // std::map<Candidate*, int> countVotes(std::vector<std::vector<Candidate*>>);
};






#endif
