#ifndef _TRIPLET_STATE_
#define _TRIPLET_STATE_

#include "Preprocessor.h"
#include "CircularPairIterator.h"
#define _DEBUG_TRIPLE_STATE_ 1

class TripletState {

  private:

  typedef Util::Z3ExprSet       Z3ExprSet;
  typedef Z3ExprSet::iterator   Z3ExprSetIterator;
  typedef std::set<std::string> StringSet ;

  void normalization();

  // Rules
  bool canApplySimplificationRule_1_0();
  bool canApplySimplificationRule_1_0_();
  bool canApplySimplificationRule_1_1();
  bool canApplySimplificationRule_1_2();
  bool canApplyDAGUpdateRule();
  bool canApplyeFreeLiteralRule();
  bool canApplySplittingRule();

  void addExplicitFormula(z3::expr const &);
  void addCommonFormula(z3::expr const &);

  void setupUncommonFormulas(z3::expr_vector const &);
  void setupUncommonFormulas(Z3ExprSet const &);
  z3::expr fresh_constant(z3::sort const &);

  z3::context &     ctx;
  unsigned &        fresh_num;
  bool              is_leave;
  StringSet const & uncomms;

  // Input separation
  Z3ExprSet explicit_formulas;
  Z3ExprSet common_formulas;
  Z3ExprSet uncommon_formulas; 

  // Circular Pair Iterator
  CircularPairIterator circular_pair_iterator;

  public:
  TripletState(z3::expr_vector const &, unsigned &, StringSet const &);
  TripletState(
      Z3ExprSet const &, 
      Z3ExprSet const &, 
      Z3ExprSet const &, 
      z3::context &, unsigned &, StringSet const &);
  TripletState(TripletState const &, z3::context &, 
      unsigned &, StringSet const &);

  z3::expr getFormula() const;

  friend std::ostream & operator << (std::ostream &, TripletState const &);
};

#endif
