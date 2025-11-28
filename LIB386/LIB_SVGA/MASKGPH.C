
#include "LIB_SYS/ADELINE.H"
#include "LIB_SYS/LIB_SYS.H"
#include "LIB_SVGA/LIB_SVGA.H"

#include	<stdlib.h>
#include	<stdio.h>
#include	<dos.h>
#include	<i86.h>


/*-------------------------------------------------------------------------*/
ULONG	CreateMaskGph( UBYTE *ptsrc, UBYTE *ptdst )
{
	UBYTE	*ptd	;
	ULONG   nbg, off;
	ULONG	*ptoff	;
	ULONG	size, i	;

	ptoff = (ULONG*)ptdst		;

	off = *(ULONG *)ptsrc		;/*	First Offset Src	*/

	*ptoff++ = off			;/*	First Offset	*/

	ptd = ptdst+off			;

	nbg = (off-4)>>2		;/*	Nombre de Graph	*/

	for ( i = 0 ; i < nbg ; i++ )
	{
		size = CalcGraphMsk( i, ptsrc, ptd )	;

		off += size			;/*	Maj Offset	*/
		*ptoff++ = off			;/*	Write Offset 	*/
		ptd += size			;/*	Maj Pt Dest	*/
	}
	return(off)	;
}
/*-------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------*/





















