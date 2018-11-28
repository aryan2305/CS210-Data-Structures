#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> void mergeSortTopDown(DataType data[], const int left, const int right){

	if((right-left)<1){
		return;
	}

	//printArray(data);
	cout<<"Sorting from "<<left<<"  to "<<right<<endl;
	mergeSortTopDown(data, left, (left+right)/2);
	mergeSortTopDown(data, ((left+right)/2)+1, right);

	DataType buffer[(right-left)+1];

	int index1=left, index2=((left+right)/2)+1, buffIndex;

	for(buffIndex=0; buffIndex<=(right-left); buffIndex++){

		if(index1<=(left+right)/2){
			if(index2<=right){
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

	for(int i=0; i<=right-left; i++){
		data[left+i]=buffer[i];
	}
	cout<<"Finished Sorting from "<<left<<"  to "<<right<<endl;
	//printArray(data);
}