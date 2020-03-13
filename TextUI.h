#ifndef TEXTUI_H
#define TEXTUI_H


class TextUI{
public:
  TextUI(Election *e);
  Election* get_election(){return e_;};
  static int electionChoice();
  void registerCandidates();
  void listCandidates();

  void campaigningChoice();
  void coordinateElection(int, int);
  void electionResults();
private:
  Election *e_;


};



#endif
