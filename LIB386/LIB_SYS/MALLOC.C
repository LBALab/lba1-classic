/*
			MALLOC (c) Adeline 1993

		Functions:

			- Malloc
			- Free
			- Mshrink
*/

#include <i86.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <malloc.h>

#include "adeline.h"
#include "lib_sys.h"

struct meminfo {
    unsigned LargestBlockAvail;
    unsigned MaxUnlockedPage;
    unsigned LargestLockablePage;
    unsigned LinAddrSpace;
    unsigned NumFreePagesAvail;
    unsigned NumPhysicalPagesFree;
    unsigned TotalPhysicalPages;
    unsigned FreeLinAddrSpace;
    unsigned SizeOfPageFile;
    unsigned Reserved[3];
} MemInfo;

#define DPMI_INT	0x31


// #define	DEBUG_MALLOC	1

#ifdef	DEBUG_MALLOC
LONG	ModeTraceMalloc = FALSE ;
#endif

/*──────────────────────────────────────────────────────────────────────────*/
/*	Special, Allocate Memory Under First Meg			    */
void	*DosMalloc( LONG size, ULONG *handle )
{
	union	REGS	r	;
	ULONG	strat		;
	ULONG	addr		;

	r.x.eax = 0x0100	;/*	Function allocate Dos Memory	*/
	if (size == -1)
		r.x.ebx = -1	;/*Number off Paragraphs Requested	*/
	else
		r.x.ebx =(size+15)>>4;/*Number off Paragraphs Requested	*/
	int386( 0x31, &r, &r )	;/*	Invoke DPMI			*/

	addr	= 0		;
	if (size == -1)
	{
		if( r.x.cflag )
			addr = (r.x.ebx & 0xFFFF) << 4	;
	}
	else
	{
		if( !r.x.cflag )
		{
			if (handle) *handle = r.x.edx & 0xFFFF;/*	DPMI selector*/
			addr = (r.x.eax & 0xFFFF) << 4;/*	Ok, Take this!	*/
		}
	}

	return((void *)addr)	;
}

/*──────────────────────────────────────────────────────────────────────────*/
/*	Special, Free Allocated Memory Under First Meg			    */
void	DosFree( ULONG handle )
{
	union	REGS	r	;

	r.x.eax = 0x0101	;/*	Function allocate Dos Memory	*/
	r.x.edx = handle	;/*	DPMI Selector			*/
	int386( 0x31, &r, &r )	;/*	Invoke DPMI			*/
}

/*──────────────────────────────────────────────────────────────────────────*/
void	*SmartMalloc( LONG lenalloc )
{
	void *ptr;

	if (lenalloc == -1)
	{
		return 0; /* Query memory not supported */
	}

	ptr = malloc(lenalloc);

	if (ptr == NULL)
	{
		printf("ERROR: MemoryNotAlloc (Malloc): Size = %d\n", lenalloc);
	}

	return ptr;
}

/*──────────────────────────────────────────────────────────────────────────*/
void	*Malloc( LONG lenalloc )
{
	void *ptr;

	if (lenalloc == -1)
	{
		return 0; /* Query memory not supported */
	}

	ptr = malloc(lenalloc);

	if (ptr == NULL)
	{
		printf("ERROR: MemoryNotAlloc (Malloc): Size = %d\n", lenalloc);
	}

	return ptr;
}
/*──────────────────────────────────────────────────────────────────────────*/
void	Free( void *buffer )
{
	if (buffer != NULL)
	{
		free(buffer);
	}
}
/*──────────────────────────────────────────────────────────────────────────*/
void	*Mshrink( void *buffer, ULONG taille )
{
	return _expand( buffer, (size_t)taille )	;
}
/*──────────────────────────────────────────────────────────────────────────*/
