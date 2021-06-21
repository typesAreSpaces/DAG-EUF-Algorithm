#include "./../include/Preprocessor.h"

z3::expr Preprocessor::normalizeInput(z3::expr const & e){
  if(e.is_app())
    switch(e.num_args()){

      case 0:
        return e;

      default:
        if(func_kind(e) == Z3_OP_NOT){
          z3::expr predicate = e.arg(0);
          assert(predicate.get_sort().is_bool());
          switch(func_kind(predicate)){
            case Z3_OP_TRUE:
              return ctx.bool_val(false);
            case Z3_OP_FALSE:
              return ctx.bool_val(true);
            case Z3_OP_EQ:       // ==
              return normalizeInput(predicate.arg(0)) 
                != normalizeInput(predicate.arg(1));
            case Z3_OP_DISTINCT: // !=
              return normalizeInput(predicate.arg(0)) 
                == normalizeInput(predicate.arg(1));
            case Z3_OP_UNINTERPRETED:
              return normalizeInput(predicate) 
                == ctx.bool_val(false);
            default:
              throw 
                "Error @ Preprocessor::normalizeInput. " 
                "Not is applied to a non predicate in EUF.";
          }
        }

        z3::func_decl f_name = e.decl();

        z3::expr_vector expr_args(ctx);
        for(unsigned i = 0; i < e.num_args(); ++i)
          expr_args.push_back(normalizeInput(e.arg(i)));

        switch(f_name.decl_kind()){
          case Z3_OP_EQ:
            return expr_args[0] == expr_args[1];
          case Z3_OP_DISTINCT:
            return expr_args[0] != expr_args[1];
          case Z3_OP_UNINTERPRETED:
            {
              z3::sort_vector sort_args(ctx);

              for(unsigned i = 0; i < e.num_args(); ++i)
                sort_args.push_back(expr_args[i].get_sort());

              z3::func_decl lifted_f_name = ctx.function(
                  func_name(e).c_str(),
                  sort_args, 
                  f_name.range());

              return lifted_f_name(expr_args);

            }
          default:
            return f_name(expr_args);
        }

    }

  throw 
    "Problem @ "
    "Preprocessor::normalizeInput "
    "Not an application";
}
