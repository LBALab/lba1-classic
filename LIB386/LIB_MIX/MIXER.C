/*──────────────────────────────────────────────────────────────────────────*
				SAMP.C 386
			      (c) Adeline 1993
 *──────────────────────────────────────────────────────────────────────────*/

#include "LIB_SYS/ADELINE.H"
#include "LIB_SYS/LIB_SYS.H"
#include "LIB_MIX/LIB_MIX.H"
#include	<stdlib.h>
#include	<stdio.h>
#include	<dos.h>
#include	<i86.h>

char	*MixerError = "Error MixerDriver:";

extern	void	*Mixer_listfcts;
extern	LONG	Mixer_Driver_Enable;

/*-------------------------------------------------------------------------*/
LONG	MixerInitDLL(char *driverpathname)
{
	char	*dll, *drvr;

   //
   // Load driver file
   //

	dll = FILE_read( driverpathname, NULL);
	if (dll==NULL)
	{
		printf("%s Could not load driver '%s'.\n", MixerError, driverpathname );
		return FALSE ;
	}

	drvr=DLL_load(dll,DLLMEM_ALLOC | DLLSRC_MEM,NULL);
	if (drvr==NULL)
	{
		printf("%s Invalid DLL image.\n", MixerError );
		return FALSE ;
	}

	Free(dll);

	Mixer_listfcts = *(void **)drvr;
	printf("%s", drvr+4);

	return (Mixer_Driver_Enable = TRUE);
}

/*-------------------------------------------------------------------------*/
