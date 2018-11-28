#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> int partitionNoCount(DataType data[], int left, int right){

		DataType temp = data[left];
		int leftPtr, rightPtr;




		for(leftPtr=left+1, rightPtr=right; leftPtr<=rightPtr; leftPtr++){

			if(data[leftPtr]>data[left]){
				while(data[rightPtr]>data[left]){
					rightPtr--;
				}
				if(rightPtr<leftPtr){
					break;
				}
				swapElements(data[leftPtr], data[rightPtr]);
			}
		}
		swapElements(data[left], data[leftPtr-1]);

		return(leftPtr-1);

}




template <class DataType> int partition(DataType data[], int left, int right){

		DataType temp = data[left];
		int leftPtr, rightPtr;
		int lessEqCount=0, greaterCount=0;

		for(int i=left+1; i<=right; i++){
			if(data[i]<=temp){
				lessEqCount++;
			}else{
				greaterCount++;
			}
		}


		if(lessEqCount==0){
			return(left);
		}
		if(greaterCount==0){
			swapElements(data[left], data[right]);
			return(right);
		}

		int pivotPos=left+lessEqCount;
		swapElements(data[left], data[pivotPos]);

		for(leftPtr=left, rightPtr=right; leftPtr<pivotPos; leftPtr++){

			if(data[leftPtr]>data[pivotPos]){
				while(data[rightPtr]>data[pivotPos]){
					rightPtr--;
				}
				swapElements(data[leftPtr], data[rightPtr]);
			}
		}
		return(pivotPos);
}


template <class DataType> void quickSort(DataType data[], int left, int right){
	cout<<"Sorting from "<<left<<" to "<<right<<endl;
	if(right<=left){
		cout<<"Trivial Case: Finished Sorting from "<<left<<" to "<<right<<endl;
		return;
	}

	int pivotPos = partitionNoCount(data, left, right);
	cout<<"Pivot value "<<data[pivotPos]<<"  Pivot position "<<pivotPos<<endl;
	//printArray(data);


	if(((pivotPos-1)-left)>1){
		quickSort(data, left, pivotPos-1);
	}

	if((right-(pivotPos+1))>1){
		quickSort(data, pivotPos+1, right);
	}

	cout<<"Finished Sorting from "<<left<<" to "<<right<<endl;
	//printArray(data);
}