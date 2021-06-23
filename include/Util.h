#ifndef _UTIL_
#define _UTIL_

#include "z3++.h"
#include <utility>
#include <set>
#include <string>

#define FRESH_COMMON_PREFIX   "fresh_"

//#define m_out std::cerr
#define m_out std::cout

#define inSet(element, set) (set.find(element) != set.end())
#define lhs(x)              x.arg(0)
#define rhs(x)              x.arg(1)
#define func_name(x)        x.decl().name().str()
#define _get_sort(x)        x.decl().range()
#define sort_name(x)        x.decl().range().name().str()
#define func_kind(x)        x.decl().decl_kind()

namespace Util {

  struct Z3Comparator;
  typedef std::set<z3::expr, Z3Comparator> Z3ExprSet;

  struct Z3Comparator {
    bool operator () (z3::expr const & a, z3::expr const & b) const;
  };

  bool isUncommon(z3::expr const &, std::set<std::string> const &);
  Z3ExprSet substitute(z3::expr const &, z3::expr const &, Z3ExprSet const &);
}

std::ostream & operator << (std::ostream &, std::pair<z3::expr, z3::expr> const &);

#endif
