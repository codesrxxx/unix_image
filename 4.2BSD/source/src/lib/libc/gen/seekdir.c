#ifndef lint
static char sccsid[] = "@(#)seekdir.c	4.10 (Berkeley) 7/1/83";
#endif

#include <sys/param.h>
#include <sys/dir.h>

/*
 * seek to an entry in a directory.
 * Only values returned by "telldir" should be passed to seekdir.
 */
void
seekdir(dirp, loc)
	register DIR *dirp;
	long loc;
{
	long curloc, base, offset;
	struct direct *dp;
	extern long lseek();

	curloc = telldir(dirp);
	if (loc == curloc)
		return;
	base = loc & ~(DIRBLKSIZ - 1);
	offset = loc & (DIRBLKSIZ - 1);
	(void) lseek(dirp->dd_fd, base, 0);
	dirp->dd_loc = 0;
	while (dirp->dd_loc < offset) {
		dp = readdir(dirp);
		if (dp == NULL)
			return;
	}
}