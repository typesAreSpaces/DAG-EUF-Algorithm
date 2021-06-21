#include "./../include/TripletState.h"

void TripletState::normalization(){
  bool has_changed = true;
  while(has_changed){
    has_changed = canApplySimplificationRule_1_0();
    has_changed = canApplySimplificationRule_1_1();
    has_changed = canApplySimplificationRule_1_2();
    has_changed = canApplyDAGUpdateRule();
    has_changed = canApplyeFreeLiteralRule();
  }
}

bool TripletState::canApplySimplificationRule_1_0(){
  // TODO: implement
  return false;
}

bool TripletState::canApplySimplificationRule_1_1(){
  // TODO: implement
  return false;
}

bool TripletState::canApplySimplificationRule_1_2(){
  // TODO: implement
  return false;
}

bool TripletState::canApplyDAGUpdateRule(){
  // TODO: implement
  return false;
}

bool TripletState::canApplyeFreeLiteralRule(){
  // TODO: implement
  return false;
}

bool TripletState::canApplySplittingRule(){
  // TODO: implement
  return false;
}
