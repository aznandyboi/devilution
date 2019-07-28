#include "diablo.h"

BOOL SystemSupported()
{
	return TRUE;
}

BOOL RestrictedTest()
{
	FILE *f;
	char Buffer[MAX_PATH];
	BOOL ret = FALSE;

	if (SystemSupported() && GetWindowsDirectory(Buffer, sizeof(Buffer))) {
		strcat(Buffer, "\\Diablo1RestrictedTest.foo");
		f = fopen(Buffer, "wt");
		if (f) {
			fclose(f);
			remove(Buffer);
		} else {
			ret = TRUE;
		}
	}
	return ret;
}

BOOL ReadOnlyTest()
{
	char *c;
	FILE *f;
	char Filename[MAX_PATH];
	BOOL ret = FALSE;

	if (GetModuleFileName(ghInst, Filename, sizeof(Filename))) {
		c = strrchr(Filename, '\\');
		if (c) {
			strcpy(c + 1, "Diablo1ReadOnlyTest.foo");
			f = fopen(Filename, "wt");
			if (f) {
				fclose(f);
				remove(Filename);
			} else {
				ret = TRUE;
			}
		}
	}
	return ret;
}
