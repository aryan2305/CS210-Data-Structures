#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> void merge(DataType data[], int first, int mid, int last)
{
	DataType buffer[(last - first)+1];

	int index1=first, index2=mid+1, buffIndex;

	for(buffIndex=0; buffIndex<=(last-first); buffIndex++){

		if(index1<=mid){
			if(index2<=last){
				if(data[index1]<=data[index2]){
					buffer[buffIndex]=data[index1];
					index1++;
				}else{
					buffer[buffIndex]=data[index2];
					index2++;
				}

			}else{
					buffer[buffIndex]=data[index1];
					index1++;
			}

		}else{

			buffer[buffIndex]=data[index2];
			index2++;
		}
	}

	for(int i=0; i<=last-first; i++){
		data[first+i]=buffer[i];
	}
}

template <class DataType> void mergeSortBottomUp(DataType data[], const int left, const int right){

	if((right-left)<1){
		return;
	}

	//printArray(data);
	cout<<"Sorting from "<<left<<"  to "<<right<<endl;
	
	int width;

	for(width = 1 ; width<=(right-left); width*=2){
		for (int i = left; i <= right-width ; i+=(2*width))
		{
			merge(data, i, i+width-1, min(i+2*width-1,right));
		}
	}

	
	cout<<"Finished Sorting from "<<left<<"  to "<<right<<endl;
	//printArray(data);
}