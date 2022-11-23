#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "my_sig.h"

/* ==================================================== */
/* main                                                 */
/* ==================================================== */
int main(int argc, char *argv[])
{
printf("Bonjour, je suis le processus %s %d \n",argv[0],getpid());

/* newact : structure permettant de positionner le masque de signaux + la fonction de traitement */
//struct sigaction newact;
//int sts;
void deroute();
//newact.sa_handler = deroute;

/* Re-initialisation du masque  de traitement des signaux */
//CHECK(sigemptyset(&newact.sa_mask),"problème sigemptyset"); 

//newact.sa_flags = 0;
//sts = sigprocmask(SIG_SETMASK,&newact.sa_mask,NULL);

/* on installe le handler deroute sur deux signaux : SIGUSR1 et SIGINT */
//CHECK(sigaction(SIGUSR1, &newact, NULL),"problème sigaction sur SIGUSR1");
//CHECK(sigaction(SIGINT, &newact, NULL),"problème sigaction sur SIGINT");


//alarm(20);
//	pause();
//	printf("Après la pause !!\n");

// on attend les signaux

struct sigaction newact = init_sig(deroute);


//on installe le handler deroute sur deux signaux : SIGUSR1 et SIGINT 
CHECK(sigaction(SIGUSR1, &newact, NULL),"problème sigaction sur SIGUSR1");
CHECK(sigaction(SIGINT, &newact, NULL),"problème sigaction sur SIGINT");

for( ; ; ) 
{
	pause();
	printf("On est passe par ici : pause se réveille sur un signal.\n");
}
_exit(0);
}



/* ==================================================== */
/* deroute : traitement des signaux                     */
/* ==================================================== */
void deroute (int signal_number)
{
	switch (signal_number) {
		case SIGUSR1 : 
			printf("Signal SIGUSR1 reçu.\n");
			break;
		case SIGINT :
			printf("Sign	l CTRL-C bloqué \n");
			break;
		default:
			break;

	}
}
