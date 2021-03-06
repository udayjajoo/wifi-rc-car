/**************************************************************
 * HTTPPrint.h
 * Provides callback headers and resolution for user's custom
 * HTTP Application.
 * 
 * This file is automatically generated by the MPFS Utility
 * ALL MODIFICATIONS WILL BE OVERWRITTEN BY THE MPFS GENERATOR
 **************************************************************/

#ifndef __HTTPPRINT_H
#define __HTTPPRINT_H

#include "TCPIP Stack/TCPIP.h"

#if defined(STACK_USE_HTTP2_SERVER)

extern HTTP_STUB httpStubs[MAX_HTTP_CONNECTIONS];
extern BYTE curHTTPID;

void HTTPPrint(DWORD callbackID);
void HTTPPrint_zero_bute(void);
void HTTPPrint_haut_bute(void);
void HTTPPrint_bas_bute(void);
void HTTPPrint_pot_value(void);
void HTTPPrint_etat_save(void);
void HTTPPrint_incdir(void);
void HTTPPrint_incvit(void);

void HTTPPrint(DWORD callbackID)
{
	switch(callbackID)
	{
        case 0x00000000:
			HTTPIncFile((ROM BYTE*)"header.inc");
			break;
        case 0x00000001:
			HTTPIncFile((ROM BYTE*)"footer.inc");
			break;
        case 0x00000007:
			HTTPPrint_zero_bute();
			break;
        case 0x00000008:
			HTTPPrint_haut_bute();
			break;
        case 0x00000009:
			HTTPPrint_bas_bute();
			break;
        case 0x0000000a:
			HTTPPrint_pot_value();
			break;
        case 0x0000000e:
			HTTPPrint_etat_save();
			break;
        case 0x0000000f:
			HTTPPrint_incdir();
			break;
        case 0x00000010:
			HTTPPrint_incvit();
			break;
		default:
			// Output notification for undefined values
			TCPPutROMArray(sktHTTP, (ROM BYTE*)"!DEF", 4);
	}

	return;
}

void HTTPPrint_(void)
{
	TCPPut(sktHTTP, '~');
	return;
}

#endif

#endif
