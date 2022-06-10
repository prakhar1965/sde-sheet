// Solution link: https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
// CodeStudio link: https://bit.ly/3tlM60B
// Leetcode link: https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h> 
using namespace std;
void sort012(int *arr, int n)
{
   int ptr1 = 0, ptr2 = 0, ptr3 = n-1;

   while(ptr2 <= ptr3)
   {
       switch (arr[ptr2])
       {
       case 0:
           swap(arr[ptr2],arr[ptr1]);
           ptr1++;
           ptr2++;
           break;
       case 1:
            ptr2++;
            break;
       case 2:
           swap(arr[ptr3],arr[ptr2]);
           ptr3--;
       }
   }
   
}