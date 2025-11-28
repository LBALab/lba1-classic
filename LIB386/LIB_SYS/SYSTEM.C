
#include	<stdlib.h>
#include	<stdio.h>
#include	<dos.h>
#include	<i86.h>

#include "LIB_SYS/ADELINE.H"
#include "LIB_SYS/LIB_SYS.H"
#include "LIB_SVGA/LIB_SVGA.H"

//extern	void	__interrupt	NewInt24(void)	;


/*--------------------------------------------------------------------------*/
void	InitSystem()
{
//	union	REGS	r	;
//	struct	SREGS	sr	;
//	void 	far	*fh	;

/*----- Install New Protected Vector 24 --------*/
//	r.x.eax = 0x2524		;/*	Function 25h for int 24	*/
//	fh = (void far*)NewInt24	;/*	Get far Pointer		*/
//	r.x.edx = FP_OFF( fh )		;/*	Get     Offset		*/
//	sr.ds 	= FP_SEG( fh )		;/*	Get	Segment		*/
//	sr.es 	= 0			;/*	Security ( ... )	*/
//	int386x( 0x21, &r, &r, &sr )	;/*	Invoke DOS 21h 		*/
}
/*--------------------------------------------------------------------------*/
void	ClearSystem()
{
//	Inutile de restorer l'int 24h
}
/*--------------------------------------------------------------------------*/


























