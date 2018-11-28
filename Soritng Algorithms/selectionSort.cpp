#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> void selectionSort(DataType data[]){
	int i,j;
	int minIndex;

	for(i=0; i<insize-1; i++){
		minIndex=i;
		for(j=i+1; j<insize; j++){

			if(data[j]<data[minIndex]){
				minIndex=j;
			}
		}

		if(minIndex!=i){
			swapElements(data[i], data[minIndex]);
			//printArray(data);
		}

	}

}

template <class DataType> void selectionSort_shifting(DataType data[]){
	int i,j;
	int minIndex;

	for(i=0; i<insize-1; i++){
		minIndex=i;
		for(j=i+1; j<insize; j++){

			if(data[j]<data[minIndex]){
				minIndex=j;
			}
		}

		DataType key  = data[minIndex];
		while(minIndex>i){
			
			data[minIndex]=data[minIndex-1];
			minIndex--;
		}
		data[i]=key;
		//printArray(data);

	}
}