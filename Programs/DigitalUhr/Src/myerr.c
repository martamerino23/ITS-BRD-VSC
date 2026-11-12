/**
 * @file myerr.c
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul gehört zur Lösung der GS Klausur WS 2017-18. 
 *        Es implementiert eine einfache Fehlerbehandlung.
 */

#include "myerr.h"

static char error = EOK;     // error speichert den zuletzt gemeldeten Fehler.

void setError(int errno){
	 error = errno;
}

int getError(void){
	 return error;
}

void resetError(void) {
	 error = EOK;
}

// EOF
