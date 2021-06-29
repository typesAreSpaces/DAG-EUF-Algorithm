#include "EUFInterpolator.h"

EUFInterpolator::EUFInterpolator(
    z3::expr_vector const & input, 
    std::set<std::string> const & uncomms):
  Preprocessor(input), 
  results(ctx),
  uncomms(uncomms),
  fresh_index_ids({}),
  fresh_indexes(ctx),
  fresh_indexes_defined(false)
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

void EUFInterpolator::collectIndexes(z3::expr const & f) {
  if(f.num_args() == 0) {
    auto const & f_name = func_name(f);
    if(f_name.find(FRESH_COMMON_PREFIX) 
        != std::string::npos) {
      auto const & id = std::stoi(f_name.substr(6));
      if(!inSet(id, fresh_index_ids)) {
        fresh_index_ids.insert(id);
        fresh_indexes.push_back(f);
      }
    }
    return;
  }
  for (unsigned i = 0; i < f.num_args(); i++)
    collectIndexes(f.arg(i));
  return;
}

z3::expr EUFInterpolator::getInterpolant(){

  auto const & result = z3::mk_or(results);

  if(!fresh_indexes_defined)
    collectIndexes(result);

  if(fresh_indexes.empty())
    return result;
  
  return z3::exists(fresh_indexes, result);
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
