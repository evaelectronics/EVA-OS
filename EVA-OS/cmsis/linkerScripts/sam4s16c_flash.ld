/* ---------------------------------------------------------------------------- */
/*                  Atmel Microcontroller Software Support                      */
/*                       SAM Software Package License                           */
/* ---------------------------------------------------------------------------- */
/* Copyright (c) %copyright_year%, Atmel Corporation                            */
/*                                                                              */
/* All rights reserved.                                                         */
/*                                                                              */
/* Redistribution and use in source and binary forms, with or without           */
/* modification, are permitted provided that the following condition is met:    */
/*                                                                              */
/* - Redistributions of source code must retain the above copyright notice,     */
/* this list of conditions and the disclaimer below.                            */
/*                                                                              */
/* Atmel's name may not be used to endorse or promote products derived from     */
/* this software without specific prior written permission.                     */
/*                                                                              */
/* DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR   */
/* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE   */
/* DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,      */
/* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT */
/* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  */
/* OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF    */
/* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING         */
/* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, */
/* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                           */
/* ---------------------------------------------------------------------------- */

/*------------------------------------------------------------------------------
 *      Linker script for running in internal FLASH on the ATSAM4S16C
 *		Dependency: sam4s_flash.ld
 *		Edited by eva-electronics to add heap.
 *		eva-electronics.com
 *
 *		For the _sbrk function, see the bottom of the file
 *----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
MEMORY
{
  rom (rx)  : ORIGIN = 0x00400000, LENGTH = 1024K	/* 0x00100000 */
  ram (rwx) : ORIGIN = 0x20000000, LENGTH = 128K 	/* 0x00020000 */
}


/* The stack size used by the application. [NEEDS TO BE ADJUSTED TO APPLICATION NEED] */
STACK_SIZE = ALIGN(0x3000, 8);


/* Uncomment HEAP_SIZE to define the heap size directly.
 * If HEAP-SIZE is not defined, the heap size will be all of the remaining RAM.
 */
/* HEAP_SIZE  = ALIGN(0x3000, 8); */ 

INCLUDE sam4s_flash.ld



/*------------------------------------------------------------------------------*
  _sbrk function used to check if heap memory is available. 
 
 char* _sbrk (int incr) 
 {
	static char* heap = NULL;
	char *prev_heap, *next_heap;
		
	if (heap == NULL)
		heap = (char*)&_sheap;
		
	prev_heap = heap;
	next_heap = (char*)(heap + incr);
	
	if (next_heap > (char*)&_eheap) {
		return NULL; 
	} else {
		heap = next_heap;
		return (char*) prev_heap;
	}
}
 *----------------------------------------------------------------------------*/