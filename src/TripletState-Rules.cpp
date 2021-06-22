#include "TripletState.h"

void TripletState::normalization(){
  bool has_changed = true;
  while(has_changed){
    has_changed = false;
#if _DEBUG_TRIPLE_STATE_
    std::cout << "beginning" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplySimplificationRule_1_0();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done Rule 1_0" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplySimplificationRule_1_0_();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done Rule 1_0_" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplySimplificationRule_1_1();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done Rule 1_1" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplySimplificationRule_1_2();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done Rule 1_2" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplyDAGUpdateRule();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done DAG Update Rule" << std::endl;
    std::cout << *this << std::endl;
#endif
    has_changed |= canApplyeFreeLiteralRule();
#if _DEBUG_TRIPLE_STATE_
    std::cout << "done e Free Literal Rule" << std::endl;
    std::cout << *this << std::endl;
#endif
  }
}

bool TripletState::canApplySimplificationRule_1_0(){
  bool has_changed = false;
  for (Z3ExprSetIterator it = uncommon_formulas.begin();
      it != uncommon_formulas.end();
      ) {
    auto const formula = *it;
    if (func_kind(formula) == Z3_OP_EQ 
        && lhs(formula).id() == rhs(formula).id()) {
      MODIFY_UNCOMMS(it++, ;);
      has_changed = true;
    }
    else ++it;
  }
  return has_changed;
}

bool TripletState::canApplySimplificationRule_1_0_(){
  for (Z3ExprSetIterator it = uncommon_formulas.begin();
      it != uncommon_formulas.end();
      ) {
    auto const formula = *it;
    if (func_kind(formula) == Z3_OP_DISTINCT
        && lhs(formula).id() == rhs(formula).id()) {
      is_leave = true;
      explicit_formulas.clear();
      common_formulas.clear();
      common_formulas.insert(ctx.bool_val(false));
      return true;
    }
    else ++it;
  }
  return false;
}

bool TripletState::canApplySimplificationRule_1_1(){
  bool has_changed = false;

  unsigned uncomms_size = uncommon_formulas.size(), gas;
  if (uncomms_size % 2 == 0)
    gas = (uncomms_size/2)*(uncomms_size - 1);
  else
    gas = ((uncomms_size-1)/2)*uncomms_size;

  while (gas--) {
    EXTRACT_PAIR(first_eq, second_eq);
    if (func_kind(first_eq) == Z3_OP_EQ 
        && func_kind(second_eq) == Z3_OP_EQ 
        && rhs(first_eq).id() == rhs(second_eq).id()){
      has_changed = true;
      break;
    }
    ++circular_pair_iterator;
  }

  if (has_changed) {
    auto const & first_iterator 
      = circular_pair_iterator.getFirstIterator();
    auto const & second_iterator 
      = circular_pair_iterator.getSecondIterator();
    uncommon_formulas.insert(
        lhs((*first_iterator)) == lhs((*second_iterator)));
    MODIFY_UNCOMMS(second_iterator, ;);
    return true;
  }

  return false;
}

bool TripletState::canApplySimplificationRule_1_2(){
  for (Z3ExprSetIterator it = uncommon_formulas.begin();
      it != uncommon_formulas.end();
     ) {
    auto const formula = *it;
    auto const & lhs = lhs(formula);
    auto const & rhs = rhs(formula);
    if (func_kind(formula) == Z3_OP_EQ
        && lhs.num_args() == 0 && rhs.num_args() == 0 
        && Util::isUncommon(lhs, uncomms) && Util::isUncommon(rhs, uncomms)) {
      assert(lhs.id() != rhs.id());
      auto const & lhs_name = func_name(lhs);
      auto const & rhs_name = func_name(rhs);
      if (lhs_name > rhs_name) {
        MODIFY_UNCOMMS(it++, 
            auto const & _uncommon_formulas = \
            Util::substitute(lhs, rhs, uncommon_formulas);\
            uncommon_formulas.clear();\
            uncommon_formulas = _uncommon_formulas;\
            );
      }
      else {
        MODIFY_UNCOMMS(it++, 
            auto const & _uncommon_formulas = \
            Util::substitute(rhs, lhs, uncommon_formulas);\
            uncommon_formulas.clear();\
            uncommon_formulas = _uncommon_formulas;\
            );
      }
      return true;
    }
    else ++it;
  }

  return false;
}

bool TripletState::canApplyDAGUpdateRule(){
  bool has_changed = false;
  for (Z3ExprSetIterator it = uncommon_formulas.begin();
      it != uncommon_formulas.end();
      ) {
    auto const formula = *it;
    auto const & lhs = lhs(formula);
    auto const & rhs = rhs(formula);
    if (func_kind(formula) == Z3_OP_EQ
        && Util::isUncommon(lhs, uncomms) 
        && !Util::isUncommon(rhs, uncomms)
       ) {
      MODIFY_UNCOMMS(it++, 
          auto const & _sort = _get_sort(lhs);\
          auto const & _new_constant = fresh_constant(_sort);\
          auto const & _uncommon_formulas = \
          Util::substitute(lhs, _new_constant, uncommon_formulas);\
          uncommon_formulas.clear();\
          uncommon_formulas = _uncommon_formulas;\
          explicit_formulas.insert(_new_constant == rhs);
          );
      has_changed = true;
    }
    else ++it;
  }
  return has_changed;
}

bool TripletState::canApplyeFreeLiteralRule(){
  bool has_changed = false;
  for(Z3ExprSetIterator it = uncommon_formulas.begin();
      it != uncommon_formulas.end();
     ){
    auto const formula = *it;
    if (!Util::isUncommon(formula, uncomms)) {
      MODIFY_UNCOMMS(it++, ;);
      common_formulas.insert(formula);

      has_changed = true;
    }
    else ++it;
  }
  return has_changed;
}

TripletState::StatePointerVec TripletState::splittingRule(){
  StatePointerVec result;
  // TODO: implement
  //TripletState * new_triplet_state = new TripletState(*this);
  //new_triplet_state->addCommonFormula(f);
  //return new_triplet_state;

  unsigned uncomms_size = uncommon_formulas.size(), gas;
  if (uncomms_size % 2 == 0)
    gas = (uncomms_size/2)*(uncomms_size - 1);
  else
    gas = ((uncomms_size-1)/2)*uncomms_size;

  while (gas--) {
    EXTRACT_PAIR(first_eq, second_eq);
    auto const & rhs_first_eq = rhs(first_eq), 
         rhs_second_eq = rhs(second_eq);
    auto const & different_set = differenceSet(rhs_first_eq, rhs_second_eq);
    if (func_kind(first_eq) == Z3_OP_EQ 
        && func_kind(second_eq) == Z3_OP_EQ 
        && areCompatible(rhs_first_eq, rhs_second_eq) 
        && isValidDifferenceSet(different_set)
       ) {
#if 1
      unsigned in;
      unsigned actual_size = different_set.size()/2;
      TripletState * new_triplet_state = new TripletState(*this);
      // ---------------------------------------------------------------------------
      // First node
      for (unsigned i = 0; i < actual_size; i+=2) {
        std::cout << "hmm" << std::endl;
        new_triplet_state->addCommonFormula(different_set[i] == different_set[i+1]);
        std::cout << "hmm 1" << std::endl;
      }
      std::cout << "hmm 2" << std::endl;
      new_triplet_state->addUncommonFormula(lhs(first_eq) == lhs(second_eq));
      std::cout << "hmm 3" << std::endl;
      new_triplet_state->removeUncommonFormula(circular_pair_iterator.getSecondIterator());
      std::cout << "hmm 4" << std::endl;
      result.push_back(new_triplet_state);
      std::cout << "What just happened 1" << std::endl;
      std::cin >> in;
      // ---------------------------------------------------------------------------
      // Others node
      for (unsigned i = 0; i < actual_size; i++) {
        new_triplet_state = new TripletState(*this);
        new_triplet_state->addCommonFormula(different_set[i] != different_set[i+1]);
        result.push_back(new_triplet_state);
      }
      // ---------------------------------------------------------------------------
      std::cout << "What just happened 2" << std::endl;
      std::cin >> in;
#endif
      return result;
    }
    ++circular_pair_iterator;
  }

  return result;
}
