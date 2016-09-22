
#ifndef __GLAPI_CRC_H__
#define __GLAPI_CRC_H__

/***************************************************************************
* include files
***************************************************************************/

/* #include entries required for exported functions and variables */

#define HUGE
/***************************************************************************
* public defines
***************************************************************************/

#ifndef ULONG
typedef unsigned long   ULONG;
#endif

#ifndef VOID
typedef void            VOID;
#endif

#ifndef WORD
typedef unsigned short  WORD; 
#endif

#ifndef PVOID
typedef void*			PVOID;
#endif

#ifndef BYTE
typedef unsigned char   BYTE;
#endif

#ifndef PBYTE
typedef BYTE*			PBYTE;
#endif

/* #define's for export */


/***************************************************************************
* public type definitions
***************************************************************************/
ULONG glapi_crc_CRC_MPEG32(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes);
WORD glapi_crc_CRC_16(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes);
ULONG glapi_crc_CRC_Code32(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes);
VOID glapi_crc_CRC_CreateTables(VOID);

/* typedef's for export, typically only those required for */
/* exported functions */

#endif /* __GLAPI_CRC_H__ */

