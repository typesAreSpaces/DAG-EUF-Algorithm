#include "./../include/TripletState.h"

TripletState::TripletState(z3::expr_vector const & vec_input) :
  ctx(vec_input.ctx()),
  explicit_formulas({}),
  common_formulas({}),
  uncommon_formulas({}),
  circular_pair_iterator(
      (setupUncommonFormulas(vec_input), 
       uncommon_formulas))
{
}

TripletState::TripletState(
    Z3ExprSet const & _explicit_formulas, 
    Z3ExprSet const & _common_formulas, 
    Z3ExprSet const & _uncommon_formulas,
    z3::context & ctx) : 
  ctx(ctx),
  explicit_formulas({}),
  common_formulas({}),
  uncommon_formulas({}),
  circular_pair_iterator(
      (setupUncommonFormulas(_uncommon_formulas), 
       uncommon_formulas))
{
  // Copy previous 'state'
  for (auto const & x : _explicit_formulas)
    explicit_formulas.insert(x);
  for (auto const & x :  _common_formulas)
    explicit_formulas.insert(x);
}

TripletState::TripletState(TripletState const & other,
    z3::context & ctx) :
  ctx(ctx),
  explicit_formulas({}),
  common_formulas({}),
  uncommon_formulas({}),
  circular_pair_iterator(
      (setupUncommonFormulas(other.uncommon_formulas), 
       uncommon_formulas))
{
  // Copy previous 'state'
  for (auto const & x : other.explicit_formulas)
    explicit_formulas.insert(x);
  for (auto const & x :  other.common_formulas)
    explicit_formulas.insert(x);
}
