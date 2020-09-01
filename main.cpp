#include<iostream>
using namespace std;
void merge(int arr[6], int s, int e){
	
	int mid = (s+e)/2;
	int i = s;
	int j = mid+1;
	int k = s;
	int temp[100];
	
	while((i <= mid) && (j <= e)){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}
	for(int i = s; i <= e; i++){
		arr[i] = temp[i];
	}
}
void mergeSort(int arr[10], int s, int e){
	if(s>=e){
		return;
	}
	int mid = (s+e)/2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid+1, e);
	merge(arr, s, e);
}
int main(){
	int arr[10] = {4,2,1,3,6,5,34,1,129109,34};
	int s = 0;
	int e = 6;
	mergeSort(arr, s, e);
	
	for(int i = 0; i < 10; i++){
		cout << arr[i] << ", ";
	}
}































/*#include <iostream>
#include <vector>
using namespace std;

void merge(int a[], int start, int mid, int end){
    vector <int> b1, b2;
    for(int i = start; i <= mid; i++){
        b1.push_back(a[i]);
    }
    for(int i = mid + 1; i <= end; i++){
        b2.push_back(a[i]);
    }
    int p1 = 0, p2 = 0, p3 = start;
    while(p1 < b1.size() && p2 <b2.size()){
        if(b1[p1] < b2[p2]){
            a[p3++] = b1[p1++];
        } else {
            a[p3++] = b2[p2++];
        }
    }
    while(p1 < b1.size()){
        a[p3++] = b1[p1++];
    }
    while(p2 < b2.size()){
        a[p3++] = b2[p2++];
    }
}

void mergesort(int a[], int start, int end){
    if (start < end){
        int mid = (start + end)/2;
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}


signed main() {
    int a[] = {5,9,1,3,4,6,6,3,2,34,23,6,341,9,0};
    mergesort(a, 0, sizeof(a)/sizeof(int) - 1);
    for (int f: a){
        cout << f << " ";
    }
    cout << endl; 
}*/