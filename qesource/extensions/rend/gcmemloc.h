/*************************************************************
 **
 **  gcmemloc.h
 **
 **  This provides a not very efficient, but sound way to
 **  declare a global, static local, or variable within a
 **  an array or structure as being saclib garbage collected.
 **  If there's not a whole bunch of deallocation, it should
 **  be reasonable though.
 **
 *************************************************************/
#ifndef _GCMEMLOC_
#define _GCMEMLOC_

/*************************************************************
 **  Includes
 *************************************************************/
extern "C" {
#include "saclib.h"
	   }


class gcmemloc
{
 public:
  
  Word W;

  gcmemloc()
  {
    W = 0;
    GCGLOBAL(&W);
  }

  gcmemloc(gcmemloc& L)
  {
    W = L.W;
    GCGLOBAL(&W);
  }

  ~gcmemloc()
  {
    Word L,T;
    Word* t,*w;

    L = GCGLOBALS;
    T = RED(L);
    w = &W;

    if ( w == (Word*) FIRST(L) )
      GCGLOBALS = RED(L);
    else{
      while( w != (Word*) FIRST(T) ) {
	L = RED(L); T = RED(T); }
      SRED(L,RED(T)); }
  
  }
};


#endif /* _GCMEMLOC_ */
