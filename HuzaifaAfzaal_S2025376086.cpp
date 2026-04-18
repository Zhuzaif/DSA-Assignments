/*
Name: Huzaifa Afzaal
ID: S2025376086


Q1.A.1 What is contiguous memory allocation? Why do arrays use it, and what access-time advantage does it provide?

Contiguus memory allocation is a method of assigning consecutive blocks of memory 
to a data structure. Arrays use this approach so that all elements are stored right 
next to each other in a continuous, unbroke sequence. The major advantage of this 
is access-time is because the elemnts are contiguous, the progrm can instantly 
calculate the exact memory address of any element using a base address and an offset. This results in a constant O(1) access time.


Q1.A.2 What is a memory leak? Describe one realistic scenario in C++ where working with arrays causes a memory leak.

A memory leak occurs when a program dynamically allocates memory on the heap but 
fails to properly deallocate (free) it when it is no longer needed.  This causes 
the application to consume more and more system memory.
Realistic scenario: A C++ program uses a pointer to allocate a dynamic array inside 
a loop or a function (`int* myArray = new int[500];`). If the function finishs or 
returns early without calling `delete[] myArray;`, the pointer variable is destroyed 
when it goes out of scope,  but the 500 integers remain allocated on the heap. Since 
the pointer is gone, the program has no way to access or delet that memory.


Q1.A.3 What is the difference between a fixedsize (static) array and a dynamic array? Why does fixed size matter?

A fixed-size (static) array has its size strictly determined at compile-time and 
is typically allocated on the stack. A dynamic array can have its size determined 
or adjusted at runtime and is allocated on the heep using pointers and the `new` keyword.
Fixed size matters because it creates rigidity. If you overestimate the size, you 
waste memory resources. If you underestimate the size, you run out of space to store 
your data and riks serious errors like baffer overflows if you try to insert data 
past the array's boundaries.


 Q1.A.4 Explain in your own words why array element access is O(1). Why is this not the case for a Linke List?

Array element access is O(1) (constant time) because the compyter performs a single, 
simple mathematical calculation to jump directly to any element. It just takes the 
starting memory addres of the array and adds (Index * Size of Data Type). 
This is not the case for a Linked List because a linked list's nodes are scattered 
randomly throughout memory. You cannot calclate the address of the 5th node mathematically. 
Instead, you must start at the head (1st node) and sequentially follow the pointers from 
one node to the next until you reach your destination. This makes linked list access O(N).

-----------------------------------------Bubble sort----------------------------------------------

Q2.A.1 Explain how Bubble Sort works, what happens in each pass, and why it's called 'Bubble' Sort?
Bubble Sort works by repeatedly stapping through the array, comparing adjacent 
pairs of elements, and swapping them if they are in the wrong order (e.g., if 
the left element is greater than the right element for ascending order).
In each complet pass of the array,  the largest unsorted element is pushed 
to its correct final position at the end of the array. It is called "Bubble" 
Sort because with each pess, the larger values "bubble up" to the top (end) 
of the list, much like air bubbles rising in water.

Q2.A.2Time complexity in best, average, and worst case? Impact of optimisation flag?
Best Case: O(N) 
Average Case: O(N^2)
Worst Case: O(N^2)  
If the array is already sorted, a standard Bubble Sort would normally still 
take O(N^2) time because it blindly checks every pair. However, if we use an 
optimisation flag (a boolean tracking if any swaps occurred during a pass), 
the algorithme will detect that no swaps were made in the very first pass. 
It will then terminate early, turning the time complexity for an already 
sorted array into O(N).

Q2.A.3Compare Bubble Sort and Selection Sort: which is preferred and why? Scenarios?
Selection Sort is generaly  preferred over standard Bubble Sort because it 
performs significantly fewer swaps. Bubble Sort does up to O(N^2) swaps, 
while Selection Sort does a maximum of O(N) swap. This make Selection Sort 
better when writing to memory is an expensive or slow operation.   
Scenario for Bubble Sort: Bubble Sort is preferre when the array is "nearly 
sorted." Because of the early-stopping optimisation flag, Bubble Sort can 
finish in O(N) time for a nearly sorted array, wheres Selection Sort will 
always stubbornly take O(N^2) time regardless of the array's initial state.

-----------------------------------Binary Search-------------------------------
Q3.A.1 What is the prerequisite condition for Binary Search to work correctly? Why does this condition matter?

the prerequisite condition for Binary Search is that the array MUST be sorted. 
This matters because Binary Search works by comparing the target value to the 
middle element of the array. Based on that comparison, it eliminates half of 
the remaining search space. If the array is unsorted, it's impossible to know 
which half of the array might contain the target, and the logic completely fails.


Q3.A.2 Dry-run Binary Search on {2, 5, 8, 12, 16, 23, 38, 45} with key = 23. Show low, mid, high.

Array: {2, 5, 8, 12, 16, 23, 38, 45}, Size: 8, Key: 23 
Step 1:
low = 0, high = 7  mid = (0 + 7) / 2 = 3  arr[mid] = arr[3] = 12    Since 12 < 23, we discard the left half. New low = mid + 1 = 4
   
Step 2:
low = 4, high = 7
mid = (4 + 7) / 2 = 5
arr[mid] = arr[5] = 23
Since 23 == 23, the key is found at index 5! Search ends.


Q3.A.3 Why is Binary Search faster than Linear Search for large inputs? Big O and intuitive difference.

Linear Search has a time complexity of O(N), while Binary Search is O(log N). 
Intuitively, Linear Search checks every single element sequentially from start to 
finish. If you have 1 million items, it might take 1 million checks. 
Binary Search, however, cuts the remaining elements in half with every single check. 
For 1 million items, it takes at most about 20 checks to either find the item or 
prove it doesn't exist. This logarithmic behavior makes it exponentially faster.

-------------------------------------Complexity Analysis--------------------------------

Q4.A.1 What does Big O notation describe? Why do we express complexity in Big O rather than measuring runtime in seconds?
big O notation mathematically describes the upper bound of an algorithm's growth rate. 
It tells us how the runtime or space requirements scale as the input size (n) increases.
We use Big O instead of seconds because seconds are highly dependent on hardware (CPU speed), 
background processes, and compiler optimizations. Big O provides a universal, hardware-independent 
measure of an algorithm's pure efficiency.


Q4.A.2 Explain the difference between Big O (worst case), Big Omega (best case), and Big Theta (tight bound) using an analogy.

Analogy: Driving to work.
Big Omega (Best Case): You hit every green light and there is zero traffic. It takes exactly 15 minutes.
Big O (Worst Case): There's a severe accident, a storm, and you hit every red light. It takes 90 minutes. 
Big Theta (Tight Bound): On a normal day, it almost always takes between 25 and 30 minutes.

Q4.A.3 Rank the following from fastest to slowest for large n:O(n²) O(log n),O(1),O(n log n),O(n).

   Fastest to Slowest:
O(1)        (Constant)
O(log n)    (Logarithmic)
O(n)        (Linear)
O(n log n)  (Linearithmic)
O(n^2)      (Quadratic - Slowest)


 Q4.A.4 What is Space Complexity? If a function creates a temporary array of size n internally, what is its space complexity and why?

Space complexity is the total amount of memory an algorithm uses relative to the size 
of the input. If a function creates a temporary array of size n, its auxiliary space 
complexity is O(n) because the extra memory required grows directly in proportion to 
he input size n.


Q4.A.5 A student says: 'My computer is faster, so my O(n²) solution will always beat an O(n log n) one.' Is this correct?
This is incorrect. For very small input sizes, a fast computer running an O(n^2) algorithm 
might finish faster due to hardware speed. However, as asymptotic reasoning shows, when 'n' 
becomes very large, the slower growth rate of O(n log n) will ALWAYS mathematically overtake 
the O(n^2) algorithm. The sheer number of operations in O(n^2) will eventually overwhelm 
even the fastest supercomputer.

----------------------------Singly Linked List------------------------------

Q5.A.1 What is a Singly Linked List? How does its memory structure differ from an array?
A Singly Linked List is a linear data structure consisting of a sequence of elements 
called "nodes". Each node contains two parts: the actual data, and a pointer (or reference) 
to the next node in the sequence. 
Unlike an array, which allocates a single contiguous block of memory, a linked list's 
nodes are scattered dynamically across the heap. They are only logically connected via 
pointers, meaning they do not require consecutive memory addresses.

Q5.A.2 State the time complexities for: insertion at head, insertion at tail, and deletion by value. Briefly justify each.

Insertion at head: O(1) time. We simply create a new node, point its 'next' to the current head, and update the head pointer. No traversal is needed.
Insertion at tail: O(N) time (assuming we only have a head pointer). We must traverse the entire list from the head to find the last node before we can append the new node.
Deletion by value: O(N) time. We must sequentially traverse the list to locate the node containing the target value before we can unlink and delete it.



Q5.A.3 What happens if you remove a node without calling delete? What is this problem called, and how do you avoid it?
If you bypass or remove a node from the list's logical sequence but fail to call `delete` 
on it, the memory remains allocated on the heap but becomes completely unreachable. 
This problem is called a "Memory Leak". 
To avoid it, you must temporarily store the node's address in a pointer (e.g., `Node* temp`), 
update the links to bypass the node, and finally use `delete temp;` to free the memory.

*/

// ------------------------------code------------------------------------

#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
void findMaxMin(int arr[], int size, int& maxVal, int& minVal) {
    maxVal = arr[0];
    minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        } else if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
}
void printArray(int arr[], int size) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " }" << endl;
}

void bubbleSort(int arr[], int size, int& totalSwaps) {
    totalSwaps = 0; 
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false; 
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                totalSwaps++;
            }
        }
        cout << "Array after Pass " << i + 1 << ": ";
        printArray(arr, size);
        if (!swapped) {
            cout << "-> Early stop triggered! No swaps made in Pass " << i + 1 << "." << endl;
            break;
        }
    }
}

int binarySearch(int arr[], int size, int key, int& iterations) {
    int low = 0;
    int high = size - 1;
    iterations = 0;

    while (low <= high) {
        iterations++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    return -1;
}


void nestedLoopFunction(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count++;
        }
    }
    cout << "Nested loop completed " << count << " iterations." << endl;
}

void singleLoopFunction(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++; 
    }
    cout << "Single loop completed " << count << " iterations." << endl;
}


bool checkElementsExist(int A[], int B[], int n) {
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }


    void deleteByValue(int val) {
        if (head == NULL) {
            cout << "List is empty, cannot delete " << val << "." << endl;
            return;
        }


        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Success: Deleted " << val << " from the head." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Failure: Value " << val << " does not exist in the list." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Success: Deleted " << val << " from the list." << endl;
    }
};

int main() {

    int arr1[10] = {4, 15, 7, 23, 1, 9, 42, 18, 6, 30};
    int size1 = 10;


    cout << " Q1Linear Search" << endl;
    int key = 42;
    int foundIndex = linearSearch(arr1, size1, key);
    if (foundIndex != -1) {
        cout << "Success: The key " << key << " was found at index " << foundIndex << "." << endl;
    } else {
        cout << "Failure: The key " << key << " was not found." << endl;
    }
    cout << endl;
    int maximum, minimum;
    findMaxMin(arr1, size1, maximum, minimum);
    cout << "Maximum value found: " << maximum << endl;
    cout << "Minimum value found: " << minimum << endl;
    cout << endl;
    cout << " Q2 Bubble Sort" << endl;
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int swapCount = 0;
    cout << "Initial Array sorting: ";
    printArray(arr2, size2);
    bubbleSort(arr2, size2, swapCount);
    cout << "Final Sorted Array: ";
    printArray(arr2, size2);
    cout << "Total number of swaps made: " << swapCount << endl;
 
    cout << endl;
    cout << "Q3 Binary Search Output"<< endl;
    int arr3[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int iterationsCount = 0;
    cout << "Array: { 2, 5, 8, 12, 16, 23, 38, 45, 56, 72 }" << endl;

    int key1 = 56;
    cout << "--- Case 1: Searching for key " << key1 << " ---" << endl;
    int result1 = binarySearch(arr3, size3, key1, iterationsCount);
    if (result1 != -1) {
        cout << "Success: Found at index " << result1 << " in " << iterationsCount << " iterations." << endl;
    } else {
        cout << "Failure: Not found. Iterations taken: " << iterationsCount << endl;
    }
    cout << endl;
    int key2 = 99;
    cout << "Case 2: Searching for key" << key2 <<"---" << endl;
    int result2 = binarySearch(arr3, size3, key2, iterationsCount);
    if (result2 != -1) {
        cout << "Found at index " << result2 << " in " << iterationsCount << "iterations" << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << endl;
    cout << "Q4 Complexity Analysis" << endl;

    int testArr[] = {1, 2, 3, 4, 5};
    int n = 5;

    singleLoopFunction(testArr, n);
    nestedLoopFunction(testArr, n);
    cout << endl;

    int arrayA[] = {3, 1, 5};
    int arrayB[] = {5, 4, 3, 2, 1}; 
    int arrayC[] = {5, 4, 2}; 


    if (checkElementsExist(arrayA, arrayB, 3)) {
        cout << "elements of A exist in B." << endl;
    } else {
        cout << "Not all elements of A exist in B." << endl;
    }

    if (checkElementsExist(arrayA, arrayC, 3)) {
        cout << "elements of A exist in C." << endl;
    } else {
        cout << "elements of A does not exist in C." << endl;
    }

    cout << endl;
    cout << "Q5 Singly Linked List" << endl;
    LinkedList list;
    cout << "Inserting Nodes" << endl;
    list.insertAtHead(10);
    list.insertAtHead(5);    
    list.insertAtTail(20);  
    list.insertAtTail(30);  
    list.insertAtHead(1);   
    list.display();
    cout << endl;
    
    cout << "Deleting Nodes" << endl;
    list.deleteByValue(20);
    list.deleteByValue(100);
    list.deleteByValue(1);
    cout << endl;

    cout << "Final List" << endl;
    list.display();

    return 0;
}


