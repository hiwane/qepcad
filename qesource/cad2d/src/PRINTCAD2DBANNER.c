/*======================================================================
                         PRINTCAD2DBANNER()
======================================================================*/
#include "cad2d.h"

/* $Format: "static const char* version = \"$ProjectVersion$\";"$ */
static const char* version = "1.65";

/* $Format: "static const char* versdate = \"$ProjectDate$\";"$ */
static const char* versdate = "Tue, 10 May 2011 13:14:52 -0400";

static void setversline() {
  int j;
  SWRITE("QEPCAD Version B ");
  SWRITE(version);
  SWRITE(", ");
  for(j = 5; j < 16; j++)
    CWRITE(versdate[j]);
}

void PRINTCAD2DBANNER()
{
Step1: /* Identification. */
       SWRITE("=======================================================\n");
       SWRITE("     CAD2D - A Program for producing CADs of R^2       \n");
       SWRITE("                                                       \n");
       SWRITE("Based on ");setversline(); SWRITE(", by Hoon Hong\n");
       SWRITE("with contributions by: Christopher W. Brown, George E. \n");
       SWRITE("Collins, Mark J. Encarnacion, Jeremy R. Johnson        \n");
       SWRITE("Werner Krandick, Richard Liska, Scott McCallum,        \n");
       SWRITE("Nicolas Robiduex, and Stanly Steinberg                 \n");
       SWRITE("=======================================================\n");

Return: /* Prepare for return. */
       return;
}
   
   
