/*
 * Copyright (c) 1991 Peter J. Nicklin.
 * Copyright (c) 1991 Version Technology.
 * All Rights Reserved.
 *
 * $License: VT.1.1 $
 * Redistribution and use in source and binary forms,  with or without
 * modification,  are permitted provided that the following conditions
 * are met:  (1) Redistributions of source code must retain the  above
 * copyright  notice,  this  list  of  conditions  and  the  following
 * disclaimer.  (2) Redistributions in binary form must reproduce  the
 * above  copyright notice,  this list of conditions and the following
 * disclaimer in the  documentation  and/or other  materials  provided
 * with  the  distribution.  (3) All advertising materials  mentioning
 * features or  use  of  this  software  must  display  the  following
 * acknowledgement:  ``This  product  includes  software  developed by
 * Version Technology.''  Neither the name of Version  Technology  nor
 * the  name  of  Peter J. Nicklin  may  be used to endorse or promote
 * products derived from this software without specific prior  written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY
 * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE
 * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE
 * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * Report problems and direct questions to nicklin@netcom.com
 *
 * $Header: slvect.c,v 4.2 91/11/25 19:44:59 nicklin Exp $
 *
 * slvect() converts a singly-linked list into a vector. Each item in
 * the vector points to a list item. Returns a pointer to the vector,
 * otherwise NULL if no items in list or out of memory.
 */
#include <stdio.h>
#include "null.h"
#include "slist.h"

SLBLK **
slvect(slist)
	SLIST *slist;			/* pointer to list head block */
{
	char *malloc();			/* memory allocator */
	SLBLK **vp;			/* pointer to block pointer array */
	SLBLK **svp;			/* ptr to start of block ptr array */
	SLBLK *cblk;			/* current list block */

	if (SLNUM(slist) <= 0)
		return(NULL);
	else if ((svp = (SLBLK **) malloc((unsigned)SLNUM(slist)*sizeof(SLBLK *))) == NULL)
		{
		nocore();
		return(NULL);
		}
	for (vp=svp, cblk=slist->head; cblk != NULL; vp++, cblk=cblk->next)
		{
		*vp = cblk;
		}
	return(svp);
}
