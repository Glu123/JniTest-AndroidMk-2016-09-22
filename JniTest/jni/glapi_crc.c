
#include "glapi_crc.h"


#define USE_STATIC_LOOKUP_TABLES

#ifdef  USE_DYNAMIC_LOOKUP_TABLES
/* local protypes */
static ULONG ReturnTableEntry (INT iIndex);
static ULONG Reverse (ULONG ulValue, INT iBits);

/* The following are used to generate the lookup tabels   */
static INT      iWidth;    /* Width in bits [8,32].       */
static ULONG    ulPoly;    /* The algorithm's polynomial. */
static BOOL     fReverse;  /* Reflect input bytes         */

/* lookup tables */
static ULONG   ulTable_MPEG32[256];
static ULONG   ulTable_CRC32[256];
static WORD    awTable_CRC16[256];
static WORD    awTable_CCITT16[256];
#endif  /* USE_DYNAMIC_LOOKUP_TABLES */

#ifdef   USE_STATIC_LOOKUP_TABLES

static const ULONG ulTable_MPEG32[256] =
{
  
};

static const ULONG ulTable_CRC32[256] =
{
  
};

static const WORD awTable_CRC16[256] =
{
   
};

static const WORD awTable_CCITT16[256] =
{
   
};

#endif   /* USE_STATIC_LOOKUP_TABLES */


/*SUBTITLE CRC_MPEG32 */
/**
* @brief
*   Calculates the MPEG 32 bit CRC from a start address for the
*   size specified.   
*
* 	This the algorithm was derived from NTL code.
* @pre
*   
* @post
*          
* @param pvStartAddress 
*           start address of data for crc'ing
*
* @param ulSize 
*           block size to be crc'ed
*
* @remarks
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
ULONG glapi_crc_CRC_MPEG32(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes)
{
   ULONG ulCRC;
   PBYTE pbData;

#ifdef USE_NTL_MPEG_CRC32

#define CAL_CRC(A)   ulCRC = (ulCRC << 4) ^ ulMask_CRC[((ulCRC >> 28) ^ (A >> 4)) & 0x0f],\
                     ulCRC = (ulCRC << 4) ^ ulMask_CRC[((ulCRC >> 28) ^ (A)) & 0x0f]

   ULONG i;

   static const ULONG ulMask_CRC[] =
   {
      0x00000000L,
      0x04c11db7L,
      0x09823b6eL,
      0x0d4326d9L,
      0x130476dcL,
      0x17c56b6bL,
      0x1a864db2L,
      0x1e475005L,
      0x2608edb8L,
      0x22c9f00fL,
      0x2f8ad6d6L,
      0x2b4bcb61L,
      0x350c9b64L,
      0x31cd86d3L,
      0x3c8ea00aL,
      0x384fbdbdL
   };

   /* init the start value */
   ulCRC = 0xffffffffL;
   /* calculate CRC */
   pbData = pvStartAddress;
   for (i = 0; i < ulSize_in_bytes; i++)
   {
      /*CAL_CRC(*pbData++);*/
      CAL_CRC(pbData[i]);
   }
   return (ulCRC);


#else
   /**********************
   * Lookup Table method *
   **********************/

   /* init the start value */
   ulCRC = 0xFFFFFFFF;

   pbData = (unsigned char*)pvStartAddress;

   /* calculate CRC */
   while (ulSize_in_bytes--)
   {
      ulCRC = ulTable_MPEG32[((ulCRC>>24) ^ *pbData++) & 0xFFL] ^ (ulCRC << 8);
   }
   return ulCRC;

#endif
}  /* CRC_MPEG32 */

/**
* @brief
*   Calculates the "standard" PC 16 bit CRC from a start address 
*   for the size specified.  This the algorithm gives the same   
*   result as used by PC archiving programs that use 16 bit CRCs.
*   e.g. PKARC, LHA, LHARC, LZH etc.
*
* 	This the algorithm was derived from NTL code.
*
* @pre
*   
* @post
*          
* @param pvStartAddress 
*           start address of data for crc'ing
*
* @param ulSize 
*           block size to be crc'ed
*
* @remarks
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
WORD glapi_crc_CRC_16(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes)
{

   WORD  wCRC;
   PBYTE pbData;
   
   #ifdef CRC_DEBUG
   printf("pvStartAddress: %lx\n", (ULONG) pvStartAddress);
   printf("Size: %lx\n", (WORD) ulSize_in_bytes);
   #endif
   /* init the start value */
   wCRC = 0x0;
   /* calculate CRC */
   pbData = (unsigned char*)pvStartAddress;

   #ifdef CRC_DEBUG
   if (ulSize_in_bytes < 100)
   {
      while (ulSize_in_bytes--)
      {
         printf ("%x\n", *pbData);
         wCRC = (((wCRC >> 8) & 0xFF) ^ awTable_CRC16[((wCRC ^ *pbData++) & 0xFF)]);
         printf ("%x\n", wCRC);
      }
   }
   else
   #endif
   {
      while (ulSize_in_bytes--)
      {
         wCRC = (((wCRC >> 8) & 0xFF) ^ awTable_CRC16[((wCRC ^ *pbData++) & 0xFF)]);
      }
   }
   
   return (wCRC);

}  /* glapi_crc_CRC_16 */

/**
* @brief
*    Calculates the "standard" Computer 32 bit CRC from a start   
*   address for the size specified.  This the algorithm gives    
*   the same result as PKZIP, Ethernet and FDDI.
*
* @pre
*   
* @post
*          
* @param pvStartAddress 
*           start address of data for crc'ing
*
* @param ulSize 
*           block size to be crc'ed
*
* @remarks
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
ULONG glapi_crc_CRC_Code32(PVOID HUGE pvStartAddress, ULONG ulSize_in_bytes)
{

#define INIT  0xffffffffL
#define XOROT 0xffffffffL

   ULONG      ulCRC;
   BYTE HUGE  *pbData;          /* %% SRP changed to HuGe 15/02 */

   /* init the start value */
   ulCRC = INIT;
   pbData = (unsigned char*)pvStartAddress;
   /* calculate CRC */
   while (ulSize_in_bytes--)
   {
      ulCRC = ulTable_CRC32[(ulCRC ^ *pbData++) & 0xFFL] ^ (ulCRC >> 8);
   }
   /* XOR the output value */
   return ulCRC ^ XOROT;
}


#ifdef  USE_DYNAMIC_LOOKUP_TABLES
/**
* @brief
*   Creates the lookup tables dynamically. This can be called   
*   many times, it will only recreated the tables.    
*
* @pre
*   
* @post
*          
* @param pvStartAddress 
*           start address of data for crc'ing
*
* @param ulSize 
*           block size to be crc'ed
*
* @remarks
*	MUST be call at least once before any CRC routines are used,
*   if this is not done, all CRCs tend to be zero
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
VOID glapi_crc_CRC_CreateTables(VOID)
{
   INT i;

   /* do PC crc16 first */
   iWidth   = 16;
   ulPoly   = 0x8005;
   fReverse = TRUE;

   for (i=0; i<256; i++)
   {
      awTable_CRC16[i] = (WORD) ReturnTableEntry(i);
   }

   /* next, do PC type CRC-32 */
   iWidth   = 32;
   ulPoly   = 0x04C11DB7L;
   fReverse = TRUE;

   for (i=0; i<256; i++)
   {
      ulTable_CRC32[i] = (ULONG) ReturnTableEntry(i);
   }

   /* next, do MPEG type CRC-32 */
   iWidth   = 32;
   ulPoly   = 0x04C11DB7L;
   fReverse = FALSE;

   for (i=0; i<256; i++)
   {
      ulTable_MPEG32[i] = (ULONG) ReturnTableEntry(i);
   }


   /* finally do CCITT type CRC-16 */
   iWidth   = 16;
   ulPoly   = 0x1021;
   fReverse = FALSE;

   for (i=0; i<256; i++)
   {
      awTable_CCITT16[i] = (unsigned) ReturnTableEntry(i);
   }
}

/**
* @brief
*   This routine returns a specific entry for a lookup table.   
*   This routine uses some globally defined variables to    
*	generate the value for the requested entry.
*
* @pre
*   
* @post
*          
* @param iIndex 
*           number of entry whose value is wanted
*
* @remarks
*	Nested routine for glapi_crc_CRC_CreateTables ONLY
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
static ULONG ReturnTableEntry (INT iIndex)
{
   INT   i;
   ULONG ulRetValue;
   ULONG ulTopBit = (1L << (iWidth-1));
   ULONG ulIndexedByte = (ULONG) iIndex;

   if (fReverse)
   {
      ulIndexedByte = Reverse(ulIndexedByte,8);
   }
   ulRetValue = ulIndexedByte << (iWidth-8);
   for (i=0; i<8; i++)
   {
      if (ulRetValue & ulTopBit)
      {
         ulRetValue = (ulRetValue << 1) ^ ulPoly;
      }
      else
      {
         ulRetValue<<=1;
      }
   }
   if (fReverse)
   {
      ulRetValue = Reverse(ulRetValue, iWidth);
   }
   return ulRetValue;
}

/**
* @brief
*   This routine adjusts the data to the reversed or reflected   
*   mode, the value returned has the bottom n bits reflected.    
*
* @pre
*   
* @post
*          
* @param ulValue 
*           input value
*
* @param iBits 
*           number of bits to reflect (reverse)
*
* @remarks
*	Nested routine for glapi_crc_CRC_CreateTables ONLY
*
* @bug
*    N/A (Detail any bugs/known issues)
* 
***************************************************************************/
static ULONG Reverse (ULONG ulValue, INT iBits)
{
   INT   i;
   ULONG ulTemp = ulValue;

   for (i=0; i<iBits; i++)
   {
      if (ulTemp & 1L)
      {
         ulValue|=  (1L << ((iBits-1)-i));
      }
      else
      {
         ulValue&= ~(1L << ((iBits-1)-i));
      }
      ulTemp>>=1;
   }
   return ulValue;
}

#endif  /* USE_DYNAMIC_LOOKUP_TABLES */
