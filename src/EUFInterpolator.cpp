#include "EUFInterpolator.h"

EUFInterpolator::EUFInterpolator(
    z3::expr_vector const & input, 
    std::set<std::string> const & uncomms):
  Preprocessor(input), 
  results(ctx),
  state_stack(),
  state_solver(ctx), 
  uncomms(uncomms)
{
  state_stack.push(new TripletState(vec_input, fresh_num, uncomms));
  loop();
}


void EUFInterpolator::loop() {
  while(state_stack.size() > 0){
    TripletState * current_state = state_stack.top();
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
#if _DEBUG_EUF_INTERPOLANT_
  std::cout << "--Results" << std::endl;
  for (auto const & x : results)
    std::cout << x << std::endl;
#endif
}
