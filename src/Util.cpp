#include "./../include/Util.h"

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
