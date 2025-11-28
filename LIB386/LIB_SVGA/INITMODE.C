
/*--------------------------------------------------------------------------*/
/*				INITGRAFSVGA 386				    */
/*			      (c) Adeline 1993			    	    */
/*--------------------------------------------------------------------------*/

#include	"LIB_SYS/ADELINE.H"
#include	"LIB_SYS/LIB_SYS.H"

#include	"LIB_SVGA/LIB_SVGA.H"

#include	<dos.h>
#include 	<i86.h>
#include 	<stdio.h>
#include 	<string.h>

/*--------------------------------------------------------------------------*/
void	InitGraphSvga()
{
	InitSvga();

	Log = Malloc(640L*480L);	/* 307200L	*/
	MemoLog = Log;
}

/*--------------------------------------------------------------------------*/
void	ClearGraphSvga()
{
	Free(MemoLog)		;
	ClearVideo()		;
}

/*--------------------------------------------------------------------------*/
void	InitGraphMcga()
{
	InitMcga();

	Log = Malloc(320L*200L);	/* 64000L	*/
	MemoLog = Log;
}

/*--------------------------------------------------------------------------*/
void	ClearGraphMcga()
{
	Free(MemoLog)		;
	ClearVideo()		;
}

/*--------------------------------------------------------------------------*/

