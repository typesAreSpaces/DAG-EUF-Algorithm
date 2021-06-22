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

void TripletState::addExplicitFormula(z3::expr const & f){
  explicit_formulas.insert(f);
}

void TripletState::addCommonFormula(z3::expr const & f){
  common_formulas.insert(f);
}

void TripletState::addUncommonFormula(z3::expr const & f){
  uncommon_formulas.insert(f);
  circular_pair_iterator.reset();
}

void TripletState::removeUncommonFormula(CircularPairIterator::Container::iterator const & it){
  std::cout << "what" << std::endl;
  uncommon_formulas.erase(it);
  std::cout << "what 2" << std::endl;
  circular_pair_iterator.reset();
  std::cout << "what 3" << std::endl;
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

bool TripletState::isLeave() const {
  return is_leave;
}

bool TripletState::areCompatible(z3::expr const & f1, z3::expr const & f2) const {
  if (f1.num_args() != f2.num_args())
    return false;

  if(f1.num_args() == 0)
    return false;

  for (unsigned i = 0; i < f1.num_args(); i++) {
    auto const & arg_1 = f1.arg(i);
    auto const & arg_2 = f2.arg(i);
    if(arg_1.id() != arg_2.id() 
        && (Util::isUncommon(arg_1, uncomms) || Util::isUncommon(arg_2, uncomms)))
      return false;
  }

  return true;
}

z3::expr_vector TripletState::differenceSet(z3::expr const & f1, z3::expr const & f2) const {
  assert(f1.num_args() == f2.num_args() && f1.num_args() > 0);
  z3::expr_vector results(ctx);
  for (unsigned i = 0; i < f1.num_args(); i++)
    if (!Util::isUncommon(f1.arg(i), uncomms) && !Util::isUncommon(f2.arg(i), uncomms)) { 
      results.push_back(f1.arg(i));
      results.push_back(f2.arg(i));
    }

  return results;
}

bool TripletState::isValidDifferenceSet(z3::expr_vector const & different_set) const {
  unsigned actual_size = different_set.size()/2;
  for(unsigned i = 0; i < actual_size; i+=2) {
    auto const & lhs = different_set[i];
    auto const & rhs = different_set[i+1];
    auto const & curr_disequation_1 = lhs != rhs;
    auto const & curr_disequation_2 = rhs != lhs;
    for (Z3ExprSetIterator it = common_formulas.begin();
        it != common_formulas.end();
        ++it
        ) {
      if(curr_disequation_1.id() == (*it).id())
        return false;
    }
    for (Z3ExprSetIterator it = common_formulas.begin();
        it != common_formulas.end();
        ++it
        ) {
      if(curr_disequation_2.id() == (*it).id())
        return false;
    }
  }
  return true;
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
