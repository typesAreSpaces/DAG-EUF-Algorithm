#include "./../include/TripletState.h"

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
