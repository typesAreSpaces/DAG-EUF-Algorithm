#ifndef _PREPROCESS_
#define _PREPROCESS_

#include "Util.h"

#define _DEBUG_PREPROCESS_ 0

class Preprocessor {

  private:
  // normalizeInput accomplishes the following:
  // 1. Remove applications of not-applications
  z3::expr normalizeInput(z3::expr const &);

  void flattenPredicate(z3::expr const &, unsigned &);
  void flattenPredicateAux(z3::expr const &, unsigned &);
  void flattenTerm(z3::expr const &, unsigned &);
  void cojoin(z3::expr const &, z3::expr const &, unsigned &);

  z3::expr fresh_constant(z3::sort const &);

  protected:
  unsigned fresh_num;
  z3::context &   ctx;
  z3::expr_vector vec_input;

  public:
  Preprocessor(z3::expr_vector const &);
};

#endif
