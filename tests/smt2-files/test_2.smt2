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

(assert (= e1 (f z1 e)))
(assert (= e2 (f z2 e)))
(assert (= v1 (f e1 a)))
(assert (= v2 (f e2 b)))

(check-sat)