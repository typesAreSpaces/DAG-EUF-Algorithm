#ifndef _EUF_INTERPOLANT_
#define _EUF_INTERPOLANT_

#include "TripletState.h"
#include <stack>

class EUFInterpolator : public Preprocessor {

  private:
  typedef std::stack<TripletState *>  StateStack;

  void loop();

  // Store formulas at the leaves
  z3::expr_vector results; 

  // Keep track of formulas used by the Splitting Rule
  StateStack state_stack;

  // Solver used for each state of the algorithm
  // Uses push/pop to handle complexity
  z3::solver state_solver;

  // Set of uncommon symbols
  std::set<std::string> const & uncomms;

  public:
  EUFInterpolator(
      z3::expr_vector const &, std::set<std::string> const &);
};

#endif
