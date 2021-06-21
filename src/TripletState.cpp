#include "TripletState.h"

void TripletState::setupUncommonFormulas(z3::expr_vector const & vec_input){
  // Move everything to the uncommon part
  for(auto const & x : vec_input)
    uncommon_formulas.insert(x);
}

void TripletState::setupUncommonFormulas(Util::Z3ExprSet const & set_input){
  // Move everything to the uncommon part
  for(auto const & x : set_input)
    uncommon_formulas.insert(x);
}

z3::expr TripletState::fresh_constant(z3::sort const & s){
  return ctx.constant((FRESH_COMMON_PREFIX + std::to_string(fresh_num++)).c_str(), s);
}

//TripletState * TripletState::split(z3::expr const & f) const {
  //TripletState * new_triplet_state = new TripletState(*this);
  //new_triplet_state->addCommonFormula(f);
  //return new_triplet_state;
//}

void TripletState::addExplicitFormula(z3::expr const & f){
  explicit_formulas.insert(f);
}

void TripletState::addCommonFormula(z3::expr const & f){
  common_formulas.insert(f);
}

z3::expr TripletState::getFormula() const {
  z3::expr_vector results(ctx);
  for(auto const & x : explicit_formulas)
    results.push_back(x);
  for(auto const & x : common_formulas)
    results.push_back(x);

  switch(results.size()){
    case 0:
      return ctx.bool_val(true);
    case 1:
      return results[0];
    default:
      return z3::mk_and(results);
  }
}

std::ostream & operator << (std::ostream & os, TripletState const & ts){
  os << "Explicit Formulas:" << std::endl;
  for (auto const & x : ts.explicit_formulas)
    os << x << std::endl;
  os << "Common Formulas:" << std::endl;
  for (auto const & x : ts.common_formulas)
    os << x << std::endl;
  os << "Uncommon Formulas:" << std::endl;
  for (auto const & x : ts.uncommon_formulas)
    os << x << std::endl;
  return os;
}
