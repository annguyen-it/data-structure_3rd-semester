#include <bits/stdc++.h>

#include "./class/Candidate.cpp"
#include "./includes/Array.cpp"

#include "./includes/compare_mark.cpp"

#include "./sort/BubbleSort.cpp"
#include "./sort/SelectionSort.cpp"
#include "./sort/InsertionSort.cpp"
#include "./sort/QuickSort.cpp"
#include "./sort/MergeSort.cpp"
#include "./sort/HeapSort.cpp"

using namespace std;


int main(){
    Candidate *a;
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    cin.ignore(1);
    
    a = new Candidate[n];
    InputArr(a, n, "\nNhap thi sinh thu ");
    system("cls");
    
    cout << "Danh sach thi sinh:\n";
    PrintArr(a, n, true);
    
//    BubbleSort(a, n, compare_mark);
//    cout << "\n\nBubble sort:\n";
//    PrintArr(a, n, true);

//    SelectionSort(a, n, compare_mark);
//    cout << "\n\nSelection sort:\n";
//    PrintArr(a, n, true);
    
//    InsertionSort(a, n, compare_mark);
//    cout << "\n\nInsertion sort:\n";
//    PrintArr(a, n, true);
    
//    QuickSort(a, n, compare_mark);
//    cout << "\n\nQuick sort:\n";
//    PrintArr(a, n, true);
    
//    MergeSort(a, n, compare_mark);
//    cout << "\n\nMerge sort:\n";
//    PrintArr(a, n, true);
    
    HeapSort(a, n, compare_mark);
    cout << "\n\nHeap sort:\n";
    PrintArr(a, n, true);
    
	return 0;
}
