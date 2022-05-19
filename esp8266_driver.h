#include "uart_config.h"


int sendCommandToEsp8266(char *cmd, char *, char *);
int estaplishUDPsoket(char[], int dIP, int lIP, char *, char *);
int sendUDPpacket(char *pkt, char *, char *);
int sendUDP(char *);
