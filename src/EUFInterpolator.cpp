#include "./../include/EUFInterpolator.h"

EUFInterpolator::EUFInterpolator(
    z3::expr_vector const & input, 
    std::set<std::string> const & uncomms):
  Preprocessor(input), 
  results(ctx),
  state_stack(),
  state_solver(ctx), 
  uncomms(uncomms)
{
  // Circular Pair Iterator
  //CircularPairIterator circular_pair_iterator;
  //circular_pair_iterator((initialSplit(input), uncommon_formulas))

  state_stack.push(new TripletState(vec_input));
  loop();
}


void EUFInterpolator::loop() {
  while(state_stack.size() > 0){
    TripletState * current_state = state_stack.top();
    state_stack.pop();

    // TODO:
    // Do something
    std::cout << current_state->getFormula() << std::endl;

    delete current_state;
  }
}
