#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// пузырьковый метод
/*
int main() {
    srand(time(0));
    const int SIZE = 100000;
    int array[SIZE];
    int swaps = 0;
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100 + 1;
    }

    auto start = high_resolution_clock::now();

    for (int i = 0; i < SIZE - 1; i++) {
        
        for (int j = 0; j < SIZE - 1 - i; j++) {
            
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swaps++;
            }
        }
    }
   
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    setlocale(LC_ALL, "ru");
    cout << "Сортировка заняла - " << duration.count() << " мс" << endl;
    cout << "Количество перестановок - " << swaps << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
*/

// Сортировка выбором
/*
int selectionSort(int arr[], int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

int main() {
    const int N = 100000; 

    
    int* arr = new int[N];

    
    srand(static_cast<unsigned int>(time(0)));

    
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

   
    auto start = high_resolution_clock::now();
    int swaps = selectionSort(arr, N);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    setlocale(LC_ALL, "ru");
    cout << "Размер массива: " << N << "\n";
    cout << "Количество перестановок: " << swaps << "\n";
    cout << "Время выполнения: " << duration.count() << " мс\n";
    
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) cout << "\n";
    }
    delete[] arr;

    return 0;
}
*/

// Сортировка вставкой
/*
long long insertionSort(int arr[], int n) {
    long long swaps = 0; 

    for (int i = 1; i < n; i++) {
        int key = arr[i]; 
        int j = i - 1;

      
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; 
            j--;
            swaps++; 
        }
        arr[j + 1] = key; 
    }

    return swaps;
}

int main() {
    const int N = 100000; 

    int* arr = new int[N];
    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

 
    auto start = high_resolution_clock::now();
    long long swaps = insertionSort(arr, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    setlocale(LC_ALL, "ru");
    cout << "Размер массива: " << N << "\n";
    cout << "Количество перестановок (сдвигов): " << swaps << "\n";
    cout << "Время выполнения: " << duration.count() << " мс\n";
 
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 20 == 0) cout << "\n";
    }
    cout << "\n";
    

    delete[] arr;
    return 0;
}
*/

// быстрая сортировка
/*
long long swaps = 0;
int partition(int arr[], int low, int high) {
   
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }
    
    if (i + 1 != high) {
        swap(arr[i + 1], arr[high]);
        swaps++;
    }
    return i + 1; 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);        
        quickSort(arr, pi + 1, high);      
    }
}

int main() {
    const int N = 100000; 

    int* arr = new int[N];
    srand(static_cast<unsigned int>(time(0)));

    
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

    swaps = 0;

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

   
    setlocale(LC_ALL, "ru");
    cout << "Размер массива: " << N << "\n";
    cout << "Количество перестановок: " << swaps << "\n";
    cout << "Время выполнения: " << duration.count() << " мс\n";
   
   
   for (int i = 0; i < N; i++) {
       cout << arr[i] << " ";
   }
   cout << "\n";
    
    delete[] arr;
    return 0;
}
*/

// сортировка слиянием
/*
long long swaps = 0; 
// Функция слияния двух отсортированных подмассивов
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    
    int* L = new int[n1];
    int* R = new int[n2];

    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

  
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        swaps++; 
        k++;
    }

   
    while (i < n1) {
        arr[k] = L[i];
        swaps++;
        i++; k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        swaps++;
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

// Рекурсивная функция Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);        
        mergeSort(arr, mid + 1, right);    
        merge(arr, left, mid, right);      
    }
}

int main() {
    const int N = 100000; 

    int* arr = new int[N];
    srand(static_cast<unsigned int>(time(0)));

    
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

    swaps = 0; 

   
    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    setlocale(LC_ALL, "ru");
    cout << "Размер массива: " << N << "\n";
    cout << "Количество перестановок (копирований): " << swaps << "\n";
    cout << "Время выполнения: " << duration.count() << " мс\n";
   
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
   }
   cout << "\n";
    

    delete[] arr;
    return 0;
}
*/

// шейкерная сортировка
long long shakerSort(int arr[], int n) {
    long long swaps = 0;
    int left = 0;         
    int right = n - 1;     

    while (left < right) {
       
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
            }
        }
        right--; 

        
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swaps++;
            }
        }
        left++; 
    }

    return swaps;
}

int main() {
    const int N = 100000; 

    int* arr = new int[N];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 100 + 1;
    }

    auto start = high_resolution_clock::now();
    long long swaps = shakerSort(arr, N);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    setlocale(LC_ALL, "ru");
    cout << "Размер массива: " << N << "\n";
    cout << "Количество перестановок: " << swaps << "\n";
    cout << "Время выполнения: " << duration.count() << " мс\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    

    delete[] arr;
    return 0;
}