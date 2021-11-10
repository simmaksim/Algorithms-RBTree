//#define _CRT_SECURE_NO_WARNINGS
//#include <fstream>
//#include <vector>
#include <iostream>

void Sort_and_Count(int* arr,int start, int size, int *count);
int main(){
  //  std::ios_base::sync_with_stdio(false);
	//std::cin.tie(nullptr);
	//freopen("input.txt","r", stdin);
	//std::ofstream fout("output.txt");

    int n, start = 0;
    std::cin >> n;
    int* arr = new int [n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    int counter = 0;
    Sort_and_Count(arr, start, n, &counter);
    std::cout << counter;
    return 0;
}
void Sort_and_Count(int* arr, int start, int size, int *count)
{
    //std::ofstream fout("output.txt");
    //if(size <= 1){
    //    std::cout << 0;
    //}
   // else{
        if(size - 1 > start){
            int pol = (start+size)/2;
            Sort_and_Count(arr, start, pol - 1, count);
            Sort_and_Count(arr, pol, size, count);
            int* A = new int[size - start];
            int tmp = 0;
            while(pol <= size && start <= pol - 1)
            {
                if (arr[start] <= arr[pol])
                {
                    A[tmp] = arr[start];
                    start++;
                }
                else
                {
                    A[tmp] = arr[pol];
                    pol++;
                    count += pol - start + 1;
                }
                tmp++;
            }
            while(start<= pol){
                A[tmp] = arr[start];
                tmp++;
                start++;
            }
            while (pol <= size)
            {
                A[tmp] = arr[(start+size)/2];
                tmp++;
                pol++;
            }
            for (int i = start; i < size; i++)
            {
               int j = 0;
               arr[i] = A[j];
               j++; 
            }
            
        }
    
 //   }
}