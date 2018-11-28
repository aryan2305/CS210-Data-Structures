#include <bits/stdc++.h>

using namespace std;

// A min heap node 
struct MinHeapNode 
{ 
    int element; // The element to be stored 
    int i; // index of the array from which the element is taken 
    int j; // index of the next element to be picked from array 
}; 
  
// Prototype of a utility function to swap two min heap nodes 
void swap(MinHeapNode *x, MinHeapNode *y); 
  
// A class for Min Heap 
class MinHeap 
{ 
    MinHeapNode *harr; // pointer to array of elements in heap 
    int heap_size; // size of min heap 
public: 
    // Constructor: creates a min heap of given size 
    MinHeap(MinHeapNode a[], int size); 
  
    // to heapify a subtree with root at given index 
    void MinHeapify(int ); 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    // to get the root 
    MinHeapNode getMin() { return harr[0]; } 
  
    // to replace root with new node x and heapify() new root 
    void replaceMin(MinHeapNode x) { harr[0] = x;  MinHeapify(0); } 
}; 
  
//this function merge the k consecutive subarrays of the current_width size 
// All subarrays are assumed to be sorted.
void mergeKArrays(int arr[],int k, int curr_size,int start,int end) 
{ 
    int x = (end-start)+1;
    int arr_count=x/curr_size;
    int add=x%curr_size;
    
    int *output = new int[x-add];  // To store output array 
    
    
    // Create a min heap with k heap nodes.  Every heap node 
    // has first element of an array

    MinHeapNode *harr = new MinHeapNode[arr_count]; 
    for (int i = 0; i < arr_count ; i++) 
    { 
        harr[i].element = arr[start+i*curr_size]; // Store the first element 
        harr[i].i = i*curr_size+start;  // index of array 
        harr[i].j = start+i*curr_size+1;  // Index of next element to be stored from array 
    } 
    MinHeap hp(harr, arr_count); // Create the heap 
  
    // Now one by one get the minimum element from min 
    // heap and replace it with next element of its array 
    int count;
    for (count = 0; count < x-add; count++) 
    { 
        // Get the minimum element and store it in output 
        MinHeapNode root = hp.getMin(); 
        output[count] = root.element; 
  
        // Find the next elelement that will replace current 
        // root of heap. The next element belongs to same 
        // array as the current root. 
        if (root.j < root.i+curr_size) 
        { 
            root.element = arr[root.j]; 
            root.j += 1; 
        } 
        // If root was the n element of its array 
        else root.element =  INT_MAX; //INT_MAX is for infinite 
  
        // Replace root with next element of array 
        hp.replaceMin(root); 
    } 
    
    if(add==0)
    {
      for(int i=0; i<=(x-add-1); i++){
        arr[i+start]=output[i];
      }
    }
    else
    {
      int buffer[x];
      int index1=0, index2=x-add, buffIndex;

        for(buffIndex=0; buffIndex<x; buffIndex++){

            if(index1<=x-add-1){

             if(index2<=x-1){
               if(output[index1]<=arr[start+index2]){
                  buffer[buffIndex]=output[index1];
                  index1++;
                }
                else{
                  buffer[buffIndex]=arr[start+index2];
                  index2++;
                }

              }else{
                buffer[buffIndex]=output[index1];
                index1++;
              }

        }else{

          buffer[buffIndex]=arr[start+index2];
          index2++;
        }
      }
      for(int i=0; i<=(x-1); i++){
         arr[i+start]=buffer[i];
        }
    }
    
     
} 

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(MinHeapNode a[], int size) 
{ 
    heap_size = size; 
    harr = a;  // store address of array 
    int i = (heap_size - 1)/2; 
    while (i >= 0) 
    { 
        MinHeapify(i); 
        i--; 
    } 
} 
  
// A recursive method to heapify a subtree with root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l].element < harr[i].element) 
        smallest = l; 
    if (r < heap_size && harr[r].element < harr[smallest].element) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    } 
} 
  
// A utility function to swap two elements 
void swap(MinHeapNode *x, MinHeapNode *y) 
{ 
    MinHeapNode temp = *x;  *x = *y;  *y = temp; 
}
  
  /* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d\n", A[i]); 
    printf("\n"); 
} 
  
/* Iterative K_WayMergesort function to sort arr[0...n-1] */
void K_WayMergeSort(int arr[], int n, int k, int itr) 
{ 
   int curr_size;  // For current size of subarrays to be merged 
                   // curr_size varies from 1 to n/k 
   int left_start; // For picking starting index of left subarray 
                   // to be merged 
  
   // Merge subarrays in bottom up manner.  First merge subarrays of 
   // size 1 to create sorted subarrays of size k, then merge subarrays 
   // of size k to create sorted subarrays of size 2*k, and so on. 
   int count_itr = 0;
   for (curr_size=1; curr_size<=n-1; curr_size = k*curr_size) 
   { 

      if(count_itr==itr)
        break;

       // Pick starting point of different subarrays of current size 
       for (left_start=0; left_start<n-curr_size; left_start += k*curr_size) 
       { 
           mergeKArrays(arr,k,curr_size,left_start,min(left_start+k*curr_size-1,n-1)); 
       } 
       //printArray(arr,n);
       count_itr++;
   } 
} 
  
 

  
int main() 
{ 
    int k;
    cin>>k;
    int itr;
    cin>>itr;
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
     {
       cin>>arr[i];
     } 
  
    //printf("Given array is \n"); 
    //printArray(arr, n); 
  
    K_WayMergeSort(arr, n,k,itr); 
  
    //printf("\nSorted array is \n"); 
    printArray(arr, n); 
    return 0; 
} 