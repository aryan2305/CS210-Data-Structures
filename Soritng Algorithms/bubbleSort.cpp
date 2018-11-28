#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;
template <class DataType> void bubbleSort(DataType data[]){

	int i, j;

	for(i=(insize-1); i>0; i--){

		for(j=0; j<i; j++){

			if(data[j]>data[j+1]){

				swapElements(data[j],data[j+1]);
				//printArray(data);
			}
		}
	}

}