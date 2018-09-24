#include <iostream> //std::cout

#include "exceptions.h"
#include "io.h"
#include "math.h"

int main(){
	bytesOutputWithData fileA = fileToBytes((char*)"testa.txt"); //TODO: plz use getopt
	bytesOutputWithData fileB = fileToBytes((char*)"testb.txt");
	
	unsigned long long longerSize = 0;
	bool differentSize = false;

	if(fileA.size != fileB.size){
		std::cout << "size of files does not match! using size of first file.\n";
		differentSize = true;
		//throw exceptions::ERR_SIZE(); // WIP
		if(fileA.size > fileB.size){
			longerSize = fileA.size;
		}else{
			longerSize = fileB.size;
		}
	}else{
		longerSize = fileA.size;
	}
	
	int howMany = 0; // how many diffs

	for(unsigned long long a = 0; a<longerSize; a++){
		if(fileA.bufferPointer[a] != fileB.bufferPointer[a]){
			bitsInByte bitsA = byteToBit(fileA.bufferPointer[a]);
			bitsInByte bitsB = byteToBit(fileB.bufferPointer[a]);
			std::cout << buildAndPrintLine(bitsA.bits, bitsB.bits, a);
			std::cout << '\n';
			howMany++;
			a++; // offset for found diffs so bitdiff does not interpret byte shifts as diffs
		}
	}
	
	std::cout << "\nTotally diffs found: " << howMany << "\n";
	return 0;
}
