#ifndef _EUF_INTERPOLANT_
#define _EUF_INTERPOLANT_

#include "TripletState.h"
#include <stack>

#define _DEBUG_MAIN_LOOP_EUF_   0

class EUFInterpolator : public Preprocessor {

  private:
  typedef std::stack<TripletState *>  StateStack;

  void collectIndexes(z3::expr const &);

  // Store formulas at the leaves
  z3::expr_vector results; 
 
  // Set of uncommon symbols
  std::set<std::string> const & uncomms;
  std::set<unsigned>            fresh_index_ids;
  z3::expr_vector               fresh_indexes;
  bool                          fresh_indexes_defined;

  public:
  EUFInterpolator(
      z3::expr_vector const &, std::set<std::string> const &);
  z3::expr getInterpolant();
  friend std::ostream & operator << (std::ostream &, EUFInterpolator const &);
};

#endif
