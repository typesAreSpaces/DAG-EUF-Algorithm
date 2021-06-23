#include "TripletState.h"

TripletState::TripletState(
    z3::expr_vector const & vec_input, 
    unsigned & fresh_num, StringSet const & uncomms) :
  ctx(vec_input.ctx()),
  fresh_num(fresh_num),
  is_leave(false),
  uncomms(uncomms),
  explicit_formulas({}),
  common_formulas({}),
  uncommon_formulas({}),
  circular_pair_iterator(
      (setupUncommonFormulas(vec_input), 
       uncommon_formulas))
{
  normalization();
}

TripletState::TripletState(
    TripletState const & other,
    z3::context & ctx, 
    unsigned & fresh_num, StringSet const & uncomms) :
  ctx(ctx),
  fresh_num(fresh_num),
  is_leave(false),
  uncomms(uncomms),
  explicit_formulas({}),
  common_formulas({}),
  uncommon_formulas({}),
  circular_pair_iterator(
      (setupUncommonFormulas(other.uncommon_formulas), 
       this->uncommon_formulas))
{
  // Copy previous 'state'
  for (auto x : other.explicit_formulas)
    explicit_formulas.insert(x);
  for (auto x :  other.common_formulas)
    common_formulas.insert(x);

  normalization();
}
