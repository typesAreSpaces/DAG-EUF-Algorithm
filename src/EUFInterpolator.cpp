#include "EUFInterpolator.h"

EUFInterpolator::EUFInterpolator(
    z3::expr_vector const & input, 
    std::set<std::string> const & uncomms):
  Preprocessor(input), 
  results(ctx),
  uncomms(uncomms)
{
#if _DEBUG_MAIN_LOOP_EUF_
  unsigned i = 1;
#endif
  StateStack state_stack = StateStack();
  state_stack.push(new TripletState(vec_input, fresh_num, uncomms));

  while (state_stack.size() > 0) {
    TripletState * current_state = state_stack.top();
#if _DEBUG_MAIN_LOOP_EUF_
    std::cout << std::endl << "Current state " << i++ << std::endl;
    std::cout << *current_state << std::endl;
    std::cout << "Current size of state stack " << state_stack.size() << std::endl;
#endif
    state_stack.pop();

    if (current_state->isLeave())
      results.push_back(current_state->getFormula());
    else {
      auto const & splits = current_state->splittingRule();
      if (splits.size() == 0)
        results.push_back(current_state->getFormula());
      else
        for (auto const & state_pointer : splits)
          state_stack.push(state_pointer);
    } 

    delete current_state;
  }
}

z3::expr EUFInterpolator::getInterpolant() const {
  return z3::mk_or(results);
}

std::ostream & operator << (std::ostream & os, EUFInterpolator const & e){
  unsigned i = 0, size = e.results.size();
  for (auto const & x : e.results) {
    os << x;
    if(++i != size)
      os << " ||" << std::endl;
  }
  return os;
}
