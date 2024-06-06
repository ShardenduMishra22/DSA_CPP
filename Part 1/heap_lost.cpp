// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Function to heapify a subtree rooted at given index
// void heapify(vector<int>& arr, int n, int i) {
//     int largest = i; // Initialize largest as root
//     int left = 2 * i + 1; // left = 2*i + 1
//     int right = 2 * i + 2; // right = 2*i + 2

//     // If left child is larger than root
//     if (left < n && arr[left] > arr[largest])
//         largest = left;

//     // If right child is larger than largest so far
//     if (right < n && arr[right] > arr[largest])
//         largest = right;

//     // If largest is not root
//     if (largest != i) {
//         swap(arr[i], arr[largest]);

//         // Recursively heapify the affected sub-tree
//         heapify(arr, n, largest);
//     }
// }

// // Function to build a max heap from given array
// void buildHeap(vector<int>& arr) {
//     // Index of last non-leaf node
//     int n = arr.size();
//     int startIdx = (n / 2) - 1;

//     // Perform reverse level order traversal from last non-leaf node and heapify each node
//     for (int i = startIdx; i >= 0; i--) {
//         heapify(arr, n, i);
//     }
// }

// // Function to insert a new element into the heap
// void insertIntoHeap(vector<int>& arr, int key) {
//     // Insert the new element at the end of the array
//     arr.push_back(key);

//     // Get the index of the newly inserted element
//     int i = arr.size() - 1;

//     // Fix the max heap property if it is violated
//     while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
//         swap(arr[i], arr[(i - 1) / 2]);
//         i = (i - 1) / 2;
//     }
// }

// // Function to delete the root (maximum element) from the heap
// void deleteRoot(vector<int>& arr) {
//     int n = arr.size();
//     if (n == 0) return;

//     // Replace the root of the heap with the last element
//     arr[0] = arr[n - 1];

//     // Reduce the size of the heap
//     arr.pop_back();

//     // Heapify the root node to maintain the max heap property
//     heapify(arr, n - 1, 0);
// }

// // Function to print the elements of the heap
// void printHeap(const vector<int>& arr) {
//     for (int num : arr) {
//         cout << num << " ";
//     }
//     cout << endl;
// }

// int main() {
//     vector<int> heap;

//     // Insert elements into the heap
//     insertIntoHeap(heap, 10);
//     insertIntoHeap(heap, 20);
//     insertIntoHeap(heap, 15);
//     insertIntoHeap(heap, 40);
//     insertIntoHeap(heap, 50);
//     insertIntoHeap(heap, 100);
//     cout << "Heap after insertion: ";
//     printHeap(heap);

//     // Delete root of the heap
//     deleteRoot(heap);
//     cout << "Heap after deletion of root: ";
//     printHeap(heap);

//     return 0;
// }
