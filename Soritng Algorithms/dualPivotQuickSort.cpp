#include <iostream>
#include <cstdlib>

#define insize 8

using namespace std;

template <class DataType> int partition_twoPivot(DataType data[], int left, int right, int *rightPivot){

		if(data[left]>data[right])
			swapElements(data[left],data[right]);


		DataType lp= data[left];
		DataType rp= data[right];

		int j, rightPtr;
		int leftPtr=left+1;




		for(j=left+1, rightPtr=right-1; j<=rightPtr; j++){

			if(data[j]>=rp){
				while(data[rightPtr]>rp ){
					rightPtr--;
				}
				if(rightPtr<j){
					break;
				}
				swapElements(data[j], data[rightPtr]);
				rightPtr--;
				if(data[j]<lp)
				{
					swapElements(data[j],data[leftPtr]);
					leftPtr++;
				}
			}
			else if(data[j]<lp)
			{
				swapElements(data[j],data[leftPtr]);
				leftPtr++;
			}
		}
		leftPtr--;
		rightPtr++;

		swapElements(data[left], data[leftPtr]);
		swapElements(data[right],data[rightPtr]);

		*rightPivot = rightPtr;

		return(leftPtr);

}

template <class DataType> void DualPivotQuickSort(DataType data[], int left, int right){
	cout<<"Sorting from "<<left<<" to "<<right<<endl;
	if(right<=left){
		cout<<"Trivial Case: Finished Sorting from "<<left<<" to "<<right<<endl;
		return;
	}

	int leftPivot,rightPivot;
	leftPivot = partition_twoPivot(data,left,right,&rightPivot);
	DualPivotQuickSort(data,left,leftPivot-1);
	DualPivotQuickSort(data,leftPivot+1,rightPivot-1);
	DualPivotQuickSort(data,rightPivot+1,right);

	cout<<"Finished Sorting from "<<left<<" to "<<right<<endl;
	//printArray(data);
}