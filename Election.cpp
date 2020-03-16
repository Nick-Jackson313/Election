
#include "electoralmap.h"
#include "election.h"
#include <vector>
#include <iostream>
#include "district.h"

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
std::map<int, int> Election::countVotes(std::vector<std::vector<Candidate*>> list_of_canidates, District *district){
std::cout<<"THIS IS THE START OF COUNT VOTES"<<std::endl;

  ElectoralMap &em = ElectoralMap::GetInstance();
  std::map<int, int> election_results;
  std::cout<<*district;



  int i = 0;
  int random_pick = -1;


    while(PartyfyInterger(i) != Party::Last){
      std::cout<< "The value of i( I want this to run 3 times): "<< i <<std::endl;
      //This is District *d, and will iteratare through all parties in the enum list.

      //This deals with party none votes.
      if(PartyfyInterger(i) == Party::None && district->get_party_constituents(Party::None) != 0){

        if(!list_of_canidates[IntegerifyParty(district->get_majority_party_())].empty()){

          random_pick = rand() % list_of_canidates[IntegerifyParty(district->get_majority_party_())].size();
          std::cout<< "Random value test: "<<random_pick<<std::endl;
          std::cout<< "This is the candidate getting the votes of NONE(unless none has zero consituents):  ["<< StringifyParty(list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->affiliation) <<"] :" <<list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->name <<std::endl;
          std::cout<< "He is going to add to his vote count this many votes: "<<district->get_party_constituents(Party::None)<<std::endl;

          election_results[list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->id] =  district->get_party_constituents(Party::None);
        }
        //This picks a totally random person if the majority party is empty.
        // else{
        //   random_pick = -1;
        //   while(random_pick != IntegerifyParty(district->get_majority_party_())){
        //     int pick_candidate = -1;
        //     random_pick = rand() % list_of_canidates.size();
        //     if(!list_of_canidates[random_pick].empty() && random_pick != IntegerifyParty(district->get_majority_party_())){
        //       std::cout<< "This is the candidate getting the votes for NONE if majority party is empty(should trigger never): " <<list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->name<<std::endl;
        //       std::cout<< "He is going to add to his vote count this many votes: "<<district->get_party_constituents(Party::None)<<std::endl;
        //       pick_candidate = rand() % list_of_canidates[random_pick].size();
        //       election_results[list_of_canidates[random_pick][pick_candidate]->id] = district->get_party_constituents(PartyfyInterger(i));
        //     }
        //     else{
        //       random_pick = IntegerifyParty(district->get_majority_party_());
        //     }
        //   }
        // }
      }

      //If a party consituents are zero I do not even go inside my logic to deal with them.
      if(district->get_party_constituents(PartyfyInterger(i)) != 0 && PartyfyInterger(i) != Party::None){
        if(!list_of_canidates[i].empty()){
          random_pick = rand() % list_of_canidates[i].size();
          election_results[list_of_canidates[i][random_pick]->id] +=  district->get_party_constituents(PartyfyInterger(i));
          std::cout<< "This is the candidate getting the votes of his party: ["<< StringifyParty(list_of_canidates[i][random_pick]->affiliation)<<"] :" <<list_of_canidates[i][random_pick]->name<<std::endl;
          std::cout<< "He is going to add to his vote count this many votes: "<<district->get_party_constituents(PartyfyInterger(i))<<std::endl;
        }
        else{

          if(!list_of_canidates[IntegerifyParty(district->get_majority_party_())].empty()){
            random_pick = rand() % list_of_canidates[IntegerifyParty(district->get_majority_party_())].size();
            election_results[list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->id] =  district->get_party_constituents(PartyfyInterger(i));
          }
          //This picks a totally random person if the majority party is empty.
          else{
            random_pick = -1;
            while(random_pick != IntegerifyParty(district->get_majority_party_())){
              int pick_candidate = -1;
              random_pick = rand() % list_of_canidates.size();
              if(!list_of_canidates[random_pick].empty() && random_pick != IntegerifyParty(district->get_majority_party_())){
                std::cout<< "This is the candidate getting the votes fopr majority or other party(should trigger twice unless one consituents is zero): "<< list_of_canidates[IntegerifyParty(district->get_majority_party_())][random_pick]->name<<std::endl;
                std::cout<< "He is going to add to his vote count this many votes: "<<district->get_party_constituents(PartyfyInterger(i))<<std::endl;
                pick_candidate = rand() % list_of_canidates[random_pick].size();
                election_results[list_of_canidates[random_pick][pick_candidate]->id] = district->get_party_constituents(PartyfyInterger(i));
              }
              else{
                random_pick = IntegerifyParty(district->get_majority_party_());
              }
            }
          }
        }

      }
          //The party has no candidates and go in to total random protocal.
        i++;
    }

    // std::cout<<"District "<< district->get_id()<<std::endl;
    std::cout<<"--------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<*district;
    for(auto district_resust : election_results){
      std::cout<<get_candadiates()[district_resust.first - 1]->name <<": " <<district_resust.second<<std::endl;

    }
    std::cout<<"--------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"THIS IS THE END OF COUNT VOTES"<<std::endl;
    return election_results;
}


RepresentativeElection::RepresentativeElection(){
  std::vector<Candidate*> temp;
  Candidates_ = temp;
}


//std::map<Candidate*, int> countVotes(std::vector<std::vector<Candidate*>>){};
