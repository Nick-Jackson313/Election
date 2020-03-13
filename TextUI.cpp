#include "district.h"
#include "electoralmap.h"
#include "election.h"
#include "textui.h"
#include <iostream>
#include <map>
#include <iterator>
#include <stdexcept>

TextUI::TextUI(Election *e){
  e_ = e;

}
int TextUI::electionChoice(){
    std::string answer = "";
    std::cout<<"What kind of election should we have (direct or representative, 0 to stop)?"<<std::endl;

    while(answer != "representative" || answer != "direct"){
      std::cin>>answer;

      if(answer == "0" ){
        return 0;
      }
      else if(answer == "direct" ){
        return 1;
      }
      else if(answer == "representative" ){
        return 2;
      }
      else{
        std::cout<<"Please choose a valid response."<<std::endl;
      }

    }
    return 0;
};
//
void TextUI::registerCandidates(){
  std::string answer = "";
  std::string name = "";

  ElectoralMap &em = ElectoralMap::GetInstance();

  int i = 0;
  int id = 1;
  //cycle through the enum list for all parties invlolved.
  while(e_->get_candadiates().empty()){
    while(PartyfyInterger(i) != Party::None){

      while(answer != "n"){
        std::cout<<"Do you want to register a candidate for party "<<StringifyParty(PartyfyInterger(i)) <<"(y or n)?"<<std::endl;
        std::cin>> answer;
        while(answer != "n" && answer != "y"){
          std::cout<<"Please choose a valid response."<<std::endl;
          std::cin.clear();

          std::cin>> answer;
        }
        if(answer == "y"){
          std::cout<< "What is their name? ";
          std::cin >> name;
          //This loads the candidate into my vector of candidates held by my election.
          e_->registerCanidate(id, name, PartyfyInterger(i));
          id += 1;
        }

      }
      //resets answer for next party
      answer = "";
      i++;
    }
    if(e_->get_candadiates().empty()){
      std::cout<<"You need candidates to run the elecion! Try again."<<std::endl;
      i = 0;
    }
    //print intial district layout and list of candidates.
    std::cout<<em;
    listCandidates();

  }


}

void TextUI::listCandidates(){
  std::cout<<"-----------------"<<std::endl;
  for(int i = 0; i < e_->get_candadiates().size(); i++ ){
    std::cout<< e_->get_candadiates()[i]->id<<": "<< e_->get_candadiates()[i]->name <<" ["<<StringifyParty(e_->get_candadiates()[i]->affiliation)<<"]"<<std::endl;
  }
  std::cout << "" <<std::endl;
}

void TextUI::coordinateElection(int c_id, int d_id){
  //This needs to move e with the right b
  ElectoralMap &em = ElectoralMap::GetInstance();
  int candidate_id = c_id - 1;
  e_->Campaign(e_->get_candadiates()[candidate_id], em.get_district(d_id));
};
void TextUI::campaigningChoice(){
  int candidate_num;
  int district_num;
  ElectoralMap &em = ElectoralMap::GetInstance();
  //This is getting the candidates id value.

  while(candidate_num != 0){
      district_num = -1;
      std::cout<<"Which candidate is campaigning (id) (0 to stop)? You can go from 0 to "<<e_->get_candadiates().size() <<": ";

      std::cin>>candidate_num;
      std::cout<<em;
      //&&  candidate_num > 0 && candidate_num <= e_->get_candadiates().size()
      // std::cin.clear();
      // std::cin.ignore(100,'/n');

      while(district_num != 0){
          std::cout<<"What district is the candidate campaigning in (id) (0 to stop) ?  You can go from 0 to " << em.get_total_distrcts()<<": ";
          std::cin>>district_num;
          // std::cin.clear();
          if(district_num != 0){
            std::cout<<e_->get_candadiates()[candidate_num-1]->name<< " is campaigning in district "<< district_num << std::endl;
            coordinateElection(candidate_num,district_num);
            std::cout<<em;
          }
          else{
            listCandidates();
          }

    }

  }
}
void TextUI::electionResults(){
  int most_votes = 0;
  Candidate winner;

  ElectoralMap &em = ElectoralMap::GetInstance();

  std::vector<std::vector<Candidate*>> list_of_canidates = get_election()->storeCandidates();
  std::map<Candidate*, int> e_r;
  for(int i = 0; i < list_of_canidates.size(); i++){
    for(int j = 0; j < list_of_canidates[i].size(); j++ ){
       e_r[list_of_canidates[i][j]] = 0;

    }
  }

  for(auto district_result : em.get_district_map()){
    std::map<Candidate*, int> district_election_results;
    district_election_results = get_election()->countVotes(list_of_canidates, district_result.second);
    for(auto test : district_election_results){
      std::cout<< "Look here this is where you think its breaking, should trigger 9 times..."<<std::endl;
      Candidate tester = *test.first;
      std::cout<<tester.name<< ": "<<test.second<<std::endl;
    }
    for(auto e_r_results : e_r){
         std::cout<<"This is hopefully a value besides 0: "<< district_election_results[e_r_results.first]<<std::endl;
         std::cout<<"This is hopefully a value besides 0: "<< district_election_results.second<<std::endl;
         e_r_results.second += district_election_results[e_r_results.first];
       }

  }
  for(auto results : e_r){
    if(most_votes < results.second){
      most_votes = results.second;
      winner = *results.first;
    }
  }
  std::cout<<"Full results: "<<std::endl;
  for(auto results : e_r){
    std::cout<<results.first->name<<": "<<results.second<<std::endl;
  }
  std::cout<<""<<std::endl;
  std::cout<<"Congratulations, "<< winner.name <<", you've won!"<<std::endl;

}
