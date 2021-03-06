#include "Util.h"

bool Util::Z3Comparator::operator () (z3::expr const & a, z3::expr const & b) const {
  return a.id() < b.id();
}


bool Util::isUncommon(z3::expr const & formula, std::set<std::string> const & uncomms) {
  unsigned num_args = formula.num_args();
  auto const & name = func_name(formula);

  if (num_args == 0)
    return inSet(name, uncomms);

  if inSet(name, uncomms) 
    return true;

  for (unsigned i = 0; i < num_args; i++) 
    if (isUncommon(formula.arg(i), uncomms)) 
      return true;

  return false;
}

Util::Z3ExprSet Util::substitute(
    z3::expr const & _old, z3::expr const & _new, 
    Z3ExprSet const & z3_set){
  z3::context & ctx(_old.ctx());

  z3::expr_vector from(ctx), to(ctx);
  from.push_back(_old);
  to.push_back(_new);

  Z3ExprSet result({});

  for(z3::expr const & x : z3_set)
    result.insert(((z3::expr)x).substitute(from, to));

  return result;
}
std::ostream & operator << (
    std::ostream & os, std::pair<z3::expr, z3::expr> const & p){
  return os << p.first << ", " << p.second;
}
