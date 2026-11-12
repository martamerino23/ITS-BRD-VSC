/**
 * @file myerr.h
 * @author Franz Korf, HAW Hamburg 
 * @date Januar 2018
 * @brief Dieses Modul geh�rt zur L�sung der GS Klausur WS 2017-18. 
 *        Es stellt elementare Mechanismen zur Fehlerbehandlug bereit
 */
#ifndef _MYERR_H
#define _MYERR_H

// Liste fer Fehlercodes
#define EOK						         0       // Kein Fehler ist eingetreten
#define INTERNAL_ERR                     1
#define IO_ERR                           2
#define INVALID_HRS                      3
#define INVALID_MINS                     4

/**
 * @brief  Diese Funktion loescht einen eingetragenen Fehler
 *         und setzt die Fehlerbehanldung zuruec.
 */
void resetError(void);

/**
 * @brief  Diese Funktion protokolliert den als Parameter
 *         uebergebnenen Fehler.
 * @param  errno ist die zuzutragende Fehlernummer
 */
void setError(int errno);

/**
 * @brief  Diese Funktion liefert den gespeicherten Fehler zurueck.
 * @retval Der zuletzt gespeicherte Fehler. Wurde kein Fehler protokolliert, 
 *         wird EOK zurueckgeliefert.
 */
int getError(void);

#endif
// EOF
