#ifndef _EUF_INTERPOLANT_
#define _EUF_INTERPOLANT_

#include "TripletState.h"
#include <stack>

#define _DEBUG_MAIN_LOOP_EUF_   0

class EUFInterpolator : public Preprocessor {

  private:
  typedef std::stack<TripletState *>  StateStack;

  // Store formulas at the leaves
  z3::expr_vector results; 
 
  // Set of uncommon symbols
  std::set<std::string> const & uncomms;

  public:
  EUFInterpolator(
      z3::expr_vector const &, std::set<std::string> const &);
  z3::expr getInterpolant() const;
  friend std::ostream & operator << (std::ostream &, EUFInterpolator const &);
};

#endif
