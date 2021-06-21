#include "./../include/Preprocessor.h"

void Preprocessor::flattenPredicate(
    z3::expr const & formula, 
    unsigned & current_conjs_in_input){
  switch(func_kind(formula)){
    case Z3_OP_TRUE:
    case Z3_OP_FALSE:
      return;
    case Z3_OP_EQ:
      {
        auto const & lhs_form = lhs(formula);
        if (lhs_form.num_args() == 0) {
          flattenTerm(rhs(formula), current_conjs_in_input);
        }
        else
          flattenPredicateAux(formula, current_conjs_in_input);
      }
      return;
    case Z3_OP_DISTINCT:
      flattenPredicateAux(formula, current_conjs_in_input);
      return;
    case Z3_OP_UNINTERPRETED:
      assert(formula.get_sort().is_bool());
      flattenTerm(formula, current_conjs_in_input);
      return;
    default:
      throw 
        "Error at "
        "Preprocessor::flattenPredicate(z3::expr const &). "
        "Formula not in AXD";
  }
}

// Takes a binary atomic predicate,
// i.e. B(x, y) and updates the correspondant
// input side with fresh constants a, b if x
// and y arent constants (respectively) obtaining
// B(x, y)[x->a, y->b] \land x = a \land y = b
void Preprocessor::flattenPredicateAux(
    z3::expr const & atomic_predicate, 
    unsigned & current_conjs_in_input){

  z3::expr_vector old_terms(ctx); 
  z3::expr_vector fresh_consts(ctx);
  z3::expr_vector temp_predicates(ctx);

  auto const & lhs_atom = lhs(atomic_predicate);
  if(lhs_atom.num_args() > 0){
    old_terms.push_back(lhs_atom);
    fresh_consts.push_back(fresh_constant(_get_sort(lhs_atom)));
  }
  auto const & rhs_atom = rhs(atomic_predicate);
  if(rhs_atom.num_args() > 0){
    old_terms.push_back(rhs_atom);
    fresh_consts.push_back(fresh_constant(_get_sort(rhs_atom)));
  }

  // Replace old terms by fresh constants in temp_predicates
  for(unsigned i = 0; i < vec_input.size(); i++)
    temp_predicates.push_back(vec_input[i].substitute(old_terms, fresh_consts));

  // Extend temp_predicates with the equations relating old terms and fresh constants
  for(unsigned i = 0; i < old_terms.size(); i++)
    temp_predicates.push_back(fresh_consts[i] == old_terms[i]);

  vec_input = temp_predicates;
  current_conjs_in_input += old_terms.size();
}

void Preprocessor::flattenTerm(
    z3::expr const & term, 
    unsigned & current_conjs_in_input){
  if(term.num_args() > 0){
    switch(func_kind(term)){
      case Z3_OP_UNINTERPRETED:
        for(unsigned i = 0; i < term.num_args(); i++){
          auto const & curr_arg = term.arg(i);
          auto const & type_arg = _get_sort(curr_arg);
          if(curr_arg.num_args() > 0)
            cojoin(
                curr_arg, 
                fresh_constant(type_arg),  
                current_conjs_in_input);
        }
        return;
      default:
        throw 
          "Problem @ "
          "Preprocessor::flattenTerm "
          "Invalid function aplication";
    }
  }
}

void Preprocessor::cojoin(
    z3::expr const & old_term, 
    z3::expr const & new_const, 
    unsigned & current_conjs_in_input){

  z3::expr_vector temp_predicates(ctx);
  z3::expr_vector from(ctx), to(ctx);
  from.push_back(old_term);
  to.push_back(new_const);

  // Replace old terms by fresh constants in temp_predicates
  for(unsigned i = 0; i < vec_input.size(); i++)
    temp_predicates.push_back(vec_input[i].substitute(from, to));

  // Extend temp_predicates with the equations relating old terms and fresh constants
  temp_predicates.push_back(new_const == old_term);

  vec_input = temp_predicates;
  current_conjs_in_input++;
}

z3::expr Preprocessor::fresh_constant(z3::sort const & s){
  return ctx.constant((FRESH_COMMON_PREFIX + std::to_string(fresh_num++)).c_str(), s);
}
