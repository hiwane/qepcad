#include "cad2d.h"
#include <iostream>
#include <fstream>
#include "db/convenientstreams.h"

/*====================================================================
                 main(argc,argv)

Main Algorithm which drives the QEPCAD sytem. 
====================================================================*/
int main(int argc, char **argv)
{
       Word Fs,F_e,F_n,F_s,V,t,ac;
       char **av;

Step1: /* Set up the system. */
       GVContext = new QEPCADContext;
       ARGSACLIB(argc,argv,&ac,&av);
       BEGINSACLIB((Word *)&argc);
       BEGINQEPCAD(argc,argv);

Step2: /* Read input, create CAD, write result */
       PRINTCAD2DBANNER();
       INPUTRD(&Fs,&V);
       QepcadCls2D Q(V,Fs);
       BTMQEPCAD = ACLOCK();
       Q.CAD2D(Fs,&t,&F_e,&F_n,&F_s);

Step3: /* Clean up the system. */
       SWRITE("\n=====================  The End  =======================\n");
       STATSACLIB();
       ENDQEPCAD();
       ENDSACLIB(SAC_FREEMEM);
       return 0;
}

