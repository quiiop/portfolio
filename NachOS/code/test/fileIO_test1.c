#include "syscall.h"

int main(void)
{
	char test[] = "abcdefghijklmnopqrstuvwxyz";
	int success;
	int i;
        int count;
	OpenFileId fid;

	success = Create("file1.test");
	// PrintInt(success);

	if (success != 1) MSG("Failed on creating file");
	fid = Open("file1.test");
	// PrintInt(fid);
	if (fid <= 0) MSG("Failed on opening file");
	for (i = 0; i < 26; ++i) {
		count = Write(test + i, 1, fid);
		if (count != 1) MSG("Failed on writing file");
	}
	success = Close(fid);
	//PrintInt(success);
	if (success != 1) MSG("Failed on closing file");
	Halt();
}

