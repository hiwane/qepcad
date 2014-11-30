#include "cad2d.h"
#include <iostream>
#include <fstream>
#include "db/convenientstreams.h"

void QEPCAD_ProcessRC(int argc, char **argv);

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
       QEPCAD_ProcessRC(argc,argv);
       ARGSACLIB(argc,argv,&ac,&av);
       BEGINSACLIB((Word *)&argc);
       BEGINQEPCAD();

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
       delete GVContext;

       return 0;
}

void QEPCAD_ProcessRC(int argc, char **argv)
{
  char *qepath = getenv("qe");
  if (qepath == NULL) { FAIL("QEPCAD_ProcessRC","Environment variable qe not defined!"); }
  string rcFileName = qepath + string("/default.qepcadrc");
  ifstream rcin(rcFileName.c_str());
  if (!rcin) { return; }
  string name, tmp;
  while(rcin)
  {
    slwcistream sin(rcin,slwcistream::skipleadingws);
    if (!(sin >> name)) { continue; }
    if (name == "SINGULAR")
    {      
      if (!(sin >> tmp)) { cerr << "Error reading SINGULAR path in " << rcFileName << "!" << endl; }
      else { GVContext->SingularPath = tmp; }
    }
    
  }
}
