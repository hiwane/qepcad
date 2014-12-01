# QEPCAD B

mirror of QEPCAD B: http://www.usna.edu/Users/cs/qepcad

```
============================================================
QEPCAD B
A program for
Quantifier Elimination and Formula Simplification
in Elementary Real Algebra via
Cylindrical Algebraic Decomposition
============================================================
```

```
=======================================================
                Quantifier Elimination                 
                          in                           
            Elementary Algebra and Geometry            
                          by                           
      Partial Cylindrical Algebraic Decomposition      
                                                       
               Version B 1.58, 02 Mar 2011
                                                       
                          by                           
                       Hoon Hong                       
                  (hhong@math.ncsu.edu)                
                                                       
With contributions by: Christopher W. Brown, George E. 
Collins, Mark J. Encarnacion, Jeremy R. Johnson        
Werner Krandick, Richard Liska, Scott McCallum,        
Nicolas Robidoux, and Stanly Steinberg                 
=======================================================
Enter an informal description  between '[' and ']':
[description]
Enter a variable list:
(a,b,c,x)
Enter the number of free variables:
3
Enter a prenex formula:
(E x) [ a /= 0 /\ a x^2 + b x + c = 0 ].


=======================================================

Before Normalization >
help
---------------------------------------------------------------------------
Program control:
assume                   finish                   quit
cell-choice-bound        full-cad                 rational-sample
...
...

For more information on command xxxx, type "whatis xxxx".

Before Normalization >
whatis sol
----------------------------------------------------------------------
solution-extension x
 
...
...
----------------------------------------------------------------------

Before Normalization >
finish

An equivalent quantifier-free formula:

a /= 0 /\ 4 a c - b^2 <= 0


=====================  The End  =======================
```
