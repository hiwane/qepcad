/*======================================================================
                         BEGINQEPCAD()

Does all the system setup to get qepcad ready.  Assumes saclib has
already been initialized!
======================================================================*/
#include <fstream>
#include "qepcad.h"
#include "db/CAServer.h"
#include "db/OriginalPolicy.h"
#include "db/SingularPolicy.h"
#include "db/SingSacPolicy.h"
#include "db/convenientstreams.h"
#include "db/CAPolicy.h"

void QEPCAD_ProcessRC(int argc, char **argv);

/*
  This is a somewhat graceful way for me to work on experimental
  features.
 */
int experimentalExtensionFlag = 0; 

ServerBase GVSB;
CAPolicy *GVCAP = 0;
QEPCADContext* GVContext = 0;

void BEGINQEPCAD(int &argc, char**& argv)
{
  /* Check for the -exp flag */
  for(int i = 1; i < argc; ++i)
    if (strcmp(argv[i],"-exp") == 0) { experimentalExtensionFlag = 1; }

  /* Set things up so Singular can be used as a CAServer */
  GVContext = new QEPCADContext;
  QEPCAD_ProcessRC(argc,argv);

  QEGLOBALS();
  SETUPSYS();
  
  /* Line buffer output */
  setlinebuf(stdout); 
  
  /* Initialize the qepcad system globals. */
  INITSYS();
  
  /* Launch CA Servers and set up CA Policy */
  if (GVContext->SingularPath == "")
    GVCAP = new OriginalPolicy;
  else
  {
    pair<string,CAServer*> tp(string("Singular"),new SingularServer(GVContext->SingularPath));
    GVSB.insert(tp);
    GVCAP = new SingSacPolicy;
  }

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

