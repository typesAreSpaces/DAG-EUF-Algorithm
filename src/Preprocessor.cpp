#include "Preprocessor.h"
#include "z3++.h"

Preprocessor::Preprocessor(z3::expr_vector const & _vec_input):
  fresh_num(0), ctx(_vec_input.ctx()), vec_input(ctx)
{

  // --------------------------------------------------------
  // Normalize input
  for(auto const arg : _vec_input){
    vec_input.push_back(normalizeInput(arg));
  }
  // --------------------------------------------------------
  
  // --------------------------------------------------------
  // Orient equations or disequations
  z3::expr_vector temp_vec_input(ctx);
  for (auto const & x : vec_input) {
    if (rhs(x).num_args() == 0) {
      switch(func_kind(x)){
        case Z3_OP_EQ:
          temp_vec_input.push_back(rhs(x) == lhs(x));
          break;
        case Z3_OP_DISTINCT:
          temp_vec_input.push_back(rhs(x) != lhs(x));
          break;
        default:
          break;
      }
    }
    else
      temp_vec_input.push_back(x);
  }
  vec_input = temp_vec_input;
  // --------------------------------------------------------

  // --------------------------------------------------------
  // Flattenize input
  unsigned current_conjs_in_input = vec_input.size();
  for(unsigned i = 0; i < current_conjs_in_input; i++)
    flattenPredicate(vec_input[i], current_conjs_in_input);
  // --------------------------------------------------------
}
