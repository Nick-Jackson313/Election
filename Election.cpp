#include "district.h"
#include "electoralmap.h"
#include "election.h"
#include <vector>
#include <iostream>

Election::Election(){
  std::vector<Candidate*> temp;
  Candidates_ = temp;


}
void Election::Campaign(Candidate *c, District *d){
  ElectoralMap &em = ElectoralMap::GetInstance();
  em.Campaign(c, d);
}

void Election::registerCanidate(int id, std::string name, Party p){
  Candidate* c = new Candidate;
  c->id = id;
  c->name = name;
  c->affiliation = p;
  Candidates_.push_back(c);
}

//This function returns a vector of vectors of candiates of the same party. This is inorder to randomly choose one when voting starts to happen.
std::vector<std::vector<Candidate*>> Election::storeCandidates(){
    std::vector<std::vector<Candidate*>> list_of_canidates;

    int i = 0;
    while(PartyfyInterger(i) != Party::None){
      //std::string vec_name = "List of_" + StringifyParty(PartyfyInterger(i));
      std::vector<Candidate *> vec ={};
      list_of_canidates.push_back(vec);
      i++;
    }
    i = 0;
  while(PartyfyInterger(i) != Party::None){
    for(int j = 0; j < Candidates_.size(); j++){
      if(Candidates_[j]->affiliation == PartyfyInterger(i)){
        list_of_canidates[i].push_back(Candidates_[j]);
      }
    }
    i++;
  }


  return list_of_canidates;

  }

//
std::map<Candidate*, int> Election::countVotes(std::vector<std::vector<Candidate*>> list_of_canidates, District *district){

  std::cout<< "Got in count votes"<<std::endl;
  ElectoralMap &em = ElectoralMap::GetInstance();
  std::map<Candidate*, int> election_results;



  int i = 0;
  int random_pick = -1;


    while(PartyfyInterger(i) != Party::Last){
      std::cout<< "Got in first while loop"<<std::endl;
      //This is District *d, and will iteratare through all parties in the enum list.

      //This deals with party none votes.
      if(PartyfyInterger(i) == Party::None){
        std::cout<< "Got Party None"<<std::endl;
        if(!list_of_canidates[IntegerifyParty(district->get_majority_party_())].empty()){
          random_pick = rand() % list_of_canidates[IntegerifyParty(district->get_majority_party_())].size();
          election_results[list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]] =  district->get_party_constituents(Party::None);
        }
        //This picks a totally random person if the majority party is empty.
        else{
          random_pick = -1;
          while(random_pick != i){
            int pick_candidate = -1;
            random_pick = rand() % list_of_canidates.size();
            if(!list_of_canidates[random_pick].empty() && random_pick != i){
              pick_candidate = rand() % list_of_canidates[random_pick].size();
              election_results[list_of_canidates[random_pick][pick_candidate]] += district->get_party_constituents(PartyfyInterger(i));
            }
            else{
              random_pick = i;
            }
          }
        }
      }
      //If a party consituents are zero I do not even go inside my logic to deal with them.
      if(district->get_party_constituents(PartyfyInterger(i)) != 0 && PartyfyInterger(i) != Party::None){
        if(!list_of_canidates[i].empty()){
          random_pick = rand() % list_of_canidates[i].size();
          election_results[list_of_canidates[i][random_pick]] +=  district->get_party_constituents(PartyfyInterger(i));
        }
        else{

          if(!list_of_canidates[IntegerifyParty(district->get_majority_party_())].empty()){
            random_pick = rand() % list_of_canidates[IntegerifyParty(district->get_majority_party_())].size();
            election_results[list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]] =  district->get_party_constituents(Party::None);
          }
          //This picks a totally random person if the majority party is empty.
          else{
            random_pick = -1;
            while(random_pick != i){
              int pick_candidate = -1;
              random_pick = rand() % list_of_canidates.size();
              if(!list_of_canidates[random_pick].empty() && random_pick != i){
                pick_candidate = rand() % list_of_canidates[random_pick].size();
                election_results[list_of_canidates[random_pick][pick_candidate]] += district->get_party_constituents(PartyfyInterger(i));
              }
              else{
                random_pick = i;
              }
            }
          }
        }
          }
          //The party has no candidates and go in to total random protocal.
        i++;
      }

    // std::cout<<"District "<< district->get_id()<<std::endl;
    // for(auto district_resust : election_results){
    //   std::cout<<district_resust.first->name <<": " <<district_resust.second<<std::endl;
    // }

    return election_results;
}
RepresentativeElection::RepresentativeElection(){
  std::vector<Candidate*> temp;
  Candidates_ = temp;
}

//std::map<Candidate*, int> countVotes(std::vector<std::vector<Candidate*>>){};
