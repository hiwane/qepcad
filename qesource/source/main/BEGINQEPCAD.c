/*======================================================================
                         BEGINQEPCAD()

Does all the system setup to get qepcad ready.  Assumes saclib has
already been initialized!
======================================================================*/
#include "qepcad.h"
#include "db/CAServer.h"
#include "db/OriginalPolicy.h"
#include "db/SingularPolicy.h"
#include "db/SingSacPolicy.h"

ServerBase GVSB;
CAPolicy *GVCAP = 0;
QEPCADContext* GVContext = 0;

void BEGINQEPCAD()
{
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
