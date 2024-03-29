﻿#include<time.h>
#include <iostream>
using namespace std;

void Tabular_function_1(int mas[],int n);
void Tabular_function_2(int mas[], int n);

void Bubble_sort(int mas[], int n);                         // compasion every element with each other
void Insertion_sort(int mas[], int n);                      // element inserts between higher and lower elements
void Selection_sort(int mas[], int n);                      // max element go on the last place in array
void Shell_sort(int mas[], int n);                          // distance between elements what comparing every time decreases
void Merge_sort(int* a, int n);                             // division all array on 2 patrs, each of these sort and then they merge
void Quick_sort(int mas[], int first, int last);            // if lower then middle elem go left if higher go right
void Shaker_sort(int mas[], int n);                         // updated bubble sort (in in 1 cycle no swapping - push the boundaries)

int main()
{
    int a, elem;

    srand(time(NULL));

    cout << "\n\t-----------------\n\t| Sorting types |\n\t-----------------\n\n\tBubble sort - 1\n\tInsertion sort - 2\n\tSelection sort - 3\n\tShell sort - 4\n\tMerge sort - 5\n\tQuick sort - 6\n\tShaker sort - 7\n\n\t-----------------\n\n     Enter type of sorting : ";
    cin >> a;
    cout << "     Enter count of elements : ";
    cin >> elem;

    int *arr1 = new int[elem];
    for(int i=0;i<elem;i++)
        arr1[i] = 100 + rand() % 900; // 100 ... 999

    switch (a)
    {
        case 1: Bubble_sort(arr1, elem);
            break;
        case 2: Insertion_sort(arr1, elem);
            break;
        case 3: Selection_sort(arr1, elem);
            break;
        case 4: Shell_sort(arr1, elem);
            break;
        case 5: Merge_sort(arr1, elem);
            break;
        case 6: Tabular_function_1(arr1, elem);         // tabular function are here because of Quick_sort is recursion function
            Quick_sort(arr1, 0, elem-1);                //
            Tabular_function_2(arr1, elem);             //
            break;                                      //
        case 7: Shaker_sort(arr1, elem);
            break;
        default:
            break;
    }

    delete[] arr1;

    return 0;

}

void Tabular_function_1(int mas[], int n)
{
    int b=25;
    cout << "   ____________________";

    for (int k = 0; k < n; k++)
    { 
        cout << "____";
        b += 4;
    }
    cout << "_\n";

    cout << "  |";
    for (int k = 0; k < n*4+21; k++)
        cout << " ";
    cout << "|";
    cout << "\n  |  NOT sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << mas[i] << " "; // output of sorted elements
    }
    cout << " |";
}

void Tabular_function_2(int mas[],int n)
{
    cout << "\n  |";
    for (int k = 0; k < n * 4 + 21; k++)
        cout << " ";
    cout << "|";
    cout << "\n  |  Sorted array: ";

    for (int i = 0; i < n; i++) {
        cout << mas[i] << " "; // output of sorted elements
    }
    cout << "     |\n  |____________________";
    int b = 25;
    for (int k = 0; k < n; k++)
    {
        cout << "____";
        b += 4;
    }
    cout << "_|\n";
}

void Bubble_sort(int mas[], int n)
{
    Tabular_function_1(mas,n);

    for (int i = 0; i < n; i++) {       //n - count of elements
        for (int j = 0; j < n-1; j++) {
            if (mas[j] > mas[j + 1]) {
                int b = mas[j];         // temp variable
                mas[j] = mas[j + 1];    // swap positions
                mas[j + 1] = b;         // and values of elements
            }
        }
    }

    Tabular_function_2(mas,n);
}

void Insertion_sort(int mas[], int n)
{

    Tabular_function_1(mas,n);

    int temp,                                       // temp variable 
        item,                                       // index of previous element
        * array_ptr=mas;                            //pointer on array
    for (int counter = 1; counter < n; counter++)   //n-array length 
    {
        temp = array_ptr[counter];                  // temp = present element in array
        item = counter - 1;                         // remember index of the previod element
        while (item >= 0 && array_ptr[item] > temp) 
        {
            array_ptr[item + 1] = array_ptr[item];  // swapping of array elements
            array_ptr[item] = temp;
            item--;
        }
    }

    Tabular_function_2(mas,n);
}

void Selection_sort(int mas[], int n)
{
    int max = mas[0], count=n, f=0, a=0,b=1, temp;

    Tabular_function_1(mas,n);

    while(n>0)     //n - count of elements
    {                                //
        while(f<n)                  //from smaller to bigger   
        {                            //
            if (mas[a] >= mas[b] && b!=n)    //max elem in array goes to the last place
                b++;
            else if(b != n)
            {
                max = mas[b];
                a = b;
                b++;
            }
            f++;
        }
        f = 0;
        temp = mas[n-1];
        mas[n-1] = mas[a];
        mas[a] = temp;
        n--;
        max = mas[0];
        a = 0;
        b = 1;
    }

    Tabular_function_2(mas,count);
}

void Shell_sort(int mas[], int n)
{

    Tabular_function_1(mas,n);

    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)     //n - count of elements
        for (i = step; i < n; i++)              //
        {                                       //sorting with using whjile step!=0
            tmp = mas[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mas[j - step])
                    mas[j] = mas[j - step];
                else
                    break;
            }
            mas[j] = tmp;
        }

    Tabular_function_2(mas,n);
}

void Merge_sort(int* a, int n)  
{
    int mid = n / 2; 
    if (n % 2 == 1)
        mid++;
    int h = 1; 

    Tabular_function_1(a, n);
    
    int* c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   
        int j = mid; 
        int k = 0;   
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { 
                if (a[i] < a[j])
                {
                    c[k] = a[i];
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    j++; k++;
                }
            }
            while (i < step)
            { 
                c[k] = a[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n))
            {  
                c[k] = a[j];
                j++; k++;
            }
            step = step + h; 
        }
        h = h * 2;
       
        for (i = 0; i < n; i++)
            a[i] = c[i];
    }

    Tabular_function_2(a, n);
}

void Quick_sort(int mas[], int first, int last)
{
    if(first < last)
    { 
        int left = first;
        int right = last;
        int middle = mas[(left+right)/2];       // middle elem

        do 
        {
            while (mas[left] < middle)          // if lower then middle elem
                left++;                         //
            while (mas[right] > middle)         // if higher then middle elem
                right--;                        //
            if (left <= right)                  // if they don`t point on the same element
            {
                int temp = mas[left];           // swapping of elements
                mas[left] = mas[right];
                mas[right] = temp;
                left++;
                right--;
            }
        } while (left < right);                 // while they don`t point on the same element

        Quick_sort(mas, first, right);
        Quick_sort(mas, left, last);
    }
}

void Shaker_sort(int mas[], int n)
{
    int left = 0, right = n - 1;         // first and last array elem
    int flag = 1;  
                                        // execution of the cycle while last left and right elements haven`t mets 

    Tabular_function_1(mas, n);
                                        
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //going left to right
        {
            if (mas[i] > mas[i + 1])        // swap elements like in a bubble sort
            {                               
                double t = mas[i];
                mas[i] = mas[i + 1];
                mas[i + 1] = t;
                flag = 1;                   // swappings have done in this cycle
            }
        }
        right--;                            // change last right element on the previous element

        for (int i = right; i > left; i--)  //going right to left
        {
            if (mas[i - 1] > mas[i])        // swap elements like in a bubble sort
            {            
                double t = mas[i];
                mas[i] = mas[i - 1];
                mas[i - 1] = t;
                flag = 1;    // swappings have done in this cycle
            }
        }
        left++; // change last left element on the previous element
    }

    Tabular_function_2(mas, n);
}