/** **********************************
 * \file      my_sig.h
 * \author    Loïc PETITPREZ
 * \version   1.0
 * \date      29/09/22
 * \brief     Bibliothèque Personnel de gestion de signal - basé sur <signal.h>
 * **********************************/
 
#define CHECK(sts,msg) if ((sts) == -1 )  { perror(msg);_exit(-1);}

//definitions :
struct sigaction init_sig( void (*func)() );

struct sigaction init_sig( void (*func)() ){
	
	// newact : structure permettant de positionner le masque de signaux + la fonction de traitement
	struct sigaction newact;
	
	//on initialise la fct
	newact.sa_handler = (*func);
	//(*func)(param...)
	
	// Re-initialisation du masque  de traitement des signaux
	CHECK(sigemptyset(&newact.sa_mask),"problème sigemptyset"); 

	newact.sa_flags = SA_SIGINFO;
	int sts = sigprocmask(SIG_SETMASK,&newact.sa_mask,NULL);
	
	return newact;

}



//MASK CF 223.c
/*//mask :
	sigset_t new_mask;
	sigset_t old_mask;

	// initialise un nouveau mask
	sigfillset(&new_mask);

	//bloque les signaux
	sigprocmask(SIG_SETMASK, &new_mask, &old_mask);
	
	//restore signal mask
	//sigprocmask(SIG_SETMASK, &old_mask, NULL);
*/
