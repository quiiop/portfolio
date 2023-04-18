/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"
#include "../filesys/openfile.h"


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

void SysPrintInt(int input)
{
	kernel->synchConsoleOut->PrintInt(input);
}
void SysCheck(int input)
{
	/*for(int i=0; i<20; i++){
		OpenFile *openfile = kernel->fileSystem->fileDescriptorTable[i];
		cout << "fid=  "<< openfile->file <<'\n';
	}*/
	kernel->fileSystem->filecheck(input);		
}
OpenFileId SysOpen(char *filename)
{
	return kernel->fileSystem->OpenOneFile(filename); 
}

int SysWrite(char *buf, int size, OpenFileId fid)
{
	/*
	cout <<"SysWrite !!"<<'\n';
	OpenFile *openfile = new OpenFile(fid);
	if (openfile == NULL){
		cout << "open file failed"<<"\n";
	}else{
		cout << "open success, file addr = "<<openfile<<'\n';
		cout << "buf = " <<buf<<'\n';
		cout << "size = "<<size<<'\n'; 
	}
	int status = openfile->Write(buf, size);
	delete openfile;
	*/
	return kernel->fileSystem->WriteFile0(buf, size, fid);		
}

int SysRead(char *buf, int size, OpenFileId fid)
{
	return kernel->fileSystem->ReadFile0(buf, size, fid);	
}

int SysClose(OpenFileId fid)
{
	return kernel->fileSystem->fileClose0(fid);
}

int SysOSAdd(int temp1, int temp2){
	int result = temp1 + temp2;
	return result;
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
