(declare-sort A 0)
(declare-fun f (A A) A)
(declare-fun s1 () A)
(declare-fun s2 () A)
(declare-fun z1 () A)
(declare-fun z2 () A)
(declare-fun z3 () A)
(declare-fun z4 () A)
(declare-fun a () A)
(declare-fun b () A)
(declare-fun e () A)
(declare-fun e1 () A)
(declare-fun e2 () A)
(declare-fun t () A)
(declare-fun v1 () A)
(declare-fun v2 () A)

(define-fun input () Bool
(and (= e1 (f z1 e))
(= e2 (f z2 e))
(= v1 (f e1 a))
(= v2 (f e2 b))
))

(define-fun uniform_interpolant () Bool
(or
(and (= a b) (= v1 v2) (= z1 z2))
(and (distinct a b) (= z1 z2))
(distinct z1 z2)
))

(define-fun uniform_interpolant_2 () Bool
(=> (and (= z1 z2) (= a b)) (= v1 v2)
))

(push)
(assert (not (=> input uniform_interpolant)))
(check-sat)
(pop)

(push)
(assert (not (=> input uniform_interpolant_2)))
(check-sat)
(pop)

(push)
(assert (not (=> uniform_interpolant_2 uniform_interpolant)))
(check-sat)
(pop)

(push)
(assert (not (=> uniform_interpolant uniform_interpolant_2)))
(check-sat)
(pop)
