#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> void insertionSort(DataType data[],const int left, const int right){

	int i,j;

	for(i=left; i<=right; i++){
		DataType temp=data[i];
		for(j=i-1; j>=left; j--){

			if(data[j]>temp){
				data[j+1]=data[j];
				printArray(data);
			}else{

				break;
			}
		}
		//cout<<"i is "<<i<<" j is "<<j<<endl<<endl;
		if(j!=(i-1)){
			data[j+1]=temp;
			//printArray(data);
		}
	}
}