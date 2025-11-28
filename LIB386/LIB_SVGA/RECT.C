
#include "LIB_SYS/ADELINE.H"
#include "LIB_SYS/LIB_SYS.H"

#include <stdio.h>
#include <dos.h>
#include <i86.h>

void	Rect( LONG x0, LONG y0, LONG x1, LONG y1, LONG coul )
{
	Line( x0, y0, x1, y0, coul ) ;
	Line( x0, y1, x1, y1, coul ) ;
	Line( x0, y0, x0, y1, coul ) ;
	Line( x1, y0, x1, y1, coul ) ;
}

/*══════════════════════════════════════════════════════════════════════════*/
