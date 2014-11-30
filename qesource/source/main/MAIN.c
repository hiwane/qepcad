#include "qepcad.h"
#include <iostream>
#include <fstream>
#include "db/convenientstreams.h"
#include <signal.h>
#include "db/CAPolicy.h"

static void SIGINT_handler(int i, siginfo_t *sip,void* uap);
static void init_SIGINT_handler();

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


       /* SWRITE("Begining test ...\n"); */
       /* {  */
       /* 	 Word L = NIL; */
       /* 	 fprintf(stderr,"&L     = %p\n",&L); */
       /* 	 L = PTRCOMP(&L,L); OWRITE(L); */
       /* 	 fprintf(stderr,"--- %p\n",PTRFIRST(L)); */
       /* 	 L = PTRCOMP(&L,L);  OWRITE(L); */
       /* 	 fprintf(stderr,"--- %p %p\n",PTRFIRST(L),PTRFIRST(PTRRED(L))); */
       /* 	 L = PTRCOMP(&L,L); OWRITE(L); */
       /* 	 fprintf(stderr,"--- %p %p %p\n",PTRFIRST(L),PTRFIRST(PTRRED(L)),PTRFIRST(PTRRED(PTRRED(L)))); */
	 
       /* 	 SWRITE("\n\n"); */
       /* 	 OWRITE(PTRRED(L)); */
       /* 	 SWRITE("\n\n"); */

       /* 	 fprintf(stderr,"pulled = %p\n",PTRFIRST(L)); */
       /* 	 L = PTRRED(L); */
       /* 	 fprintf(stderr,"pulled = %p\n",PTRFIRST(L)); */
       /* 	 L = PTRRED(L); */
       /* 	 fprintf(stderr,"pulled = %p\n",PTRFIRST(L)); */
       /* 	 L = PTRRED(L); */
       /* 	 if (L == NIL) fprintf(stderr,"List empty\n"); */
       /* 	 else fprintf(stderr,"List non-empty\n"); */
       /* } */

       init_SIGINT_handler(); /* A special handler for SIGINT is needed
                                 to shut down child processes. Also used
			         for SIGTERM. */

Step2: /* Read input, create CAD, write result */
       PCCONTINUE = FALSE;
       PRINTBANNER();
       do {
	 // Reinitialize system in between runs
	 if (PCCONTINUE == TRUE) 
	 { 
	   INITSYS();
	   PCCONTINUE = FALSE;
	 }
	 INPUTRD(&Fs,&V);
	 QepcadCls Q(V,Fs);
	 BTMQEPCAD = ACLOCK();
	 Q.QEPCAD(Fs,&t,&F_e,&F_n,&F_s);
       } while (PCCONTINUE == TRUE);
       
Step3: /* Clean up the system. */
       SWRITE("\n=====================  The End  =======================\n");
       STATSACLIB();
       ENDQEPCAD();
       ENDSACLIB(SAC_FREEMEM);
       delete GVContext;
       free(av); /* Frees the array malloc'd by ARGSACLIB */

Return: /* Prepare for return. */
       return 0;
}

static void SIGINT_handler(int i, siginfo_t *sip,void* uap)
{
  // Kill child CAServer processes
  for(ServerBase::iterator p = GVSB.begin(); p != GVSB.end(); ++p)    
    p->second->kill();
  ENDSACLIB(SAC_FREEMEM);
  exit(1);
}

static void init_SIGINT_handler() 
{
  struct sigaction *p;
  p = (struct sigaction *)malloc(sizeof(struct sigaction));
  p->sa_handler = NULL;
  p->sa_sigaction = SIGINT_handler;
  sigemptyset(&(p->sa_mask));
  p->sa_flags = SA_SIGINFO;
  sigaction(SIGINT,p,NULL);
  sigaction(SIGTERM,p,NULL);
  free(p);
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

