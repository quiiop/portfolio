#include "syscall.h"

int
main()
{
    int status;
    int i;
    OpenFileId fid;
    char test[] = "abcd";
    char buf[26];
    int count;
    int success;

    fid = Open("Test.txt");
    // PrintInt(fid);
    
    /*for (i=0; i< 4; i++) {
    	status = Write(test+i, 1, fid);
    }*/
    
    count = Read(buf, 5, fid);
    // PrintInt(count);
    	
    success = Close(fid);
    PrintInt(success);
    Halt();
}

