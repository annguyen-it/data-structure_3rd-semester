#include <bits/stdc++.h>

#include "./class/Student.cpp"
#include "./includes/Array.cpp"

#include "./includes/compare_name.cpp"

#include "./sort/BubbleSort.cpp"
#include "./sort/SelectionSort.cpp"
#include "./sort/InsertionSort.cpp"
#include "./sort/QuickSort.cpp"
#include "./sort/MergeSort.cpp"
#include "./sort/HeapSort.cpp"

using namespace std;

int main(){
    Student *a;
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    
    a = new Student[n];
    InputArr(a, n, "\nNhap sinh vien thu ");
    system("cls");
    
    cout << "Danh sach sinh vien:\n";
    PrintArr(a, n, true);
    
    BubbleSort(a, n, compare_name);
    cout << "\n\nBubble sort:\n";
    PrintArr(a, n, true);

//    SelectionSort(a, n, compare_name);
//    cout << "\n\nSelection sort:\n";
//    PrintArr(a, n, true);
    
//    InsertionSort(a, n, compare_name);
//    cout << "\n\nInsertion sort:\n";
//    PrintArr(a, n, true);
    
//    QuickSort(a, n, compare_name);
//    cout << "\n\nQuick sort:\n";
//    PrintArr(a, n, true);
    
//    MergeSort(a, n, compare_name);
//    cout << "\n\nMerge sort:\n";
//    PrintArr(a, n, true);
    
//    HeapSort(a, n, compare_name);
//    cout << "\n\nHeap sort:\n";
//    PrintArr(a, n, true);
    
	return 0;
}
