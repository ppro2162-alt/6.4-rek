#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Заповнення масиву випадковими числами ----------
void FillArray(int* a, const int size, const int low, const int high, int i);
template <typename T>
void FillArray(T* a, const int size, const int low, const int high, int i);

// ---------- Виведення масиву ----------
void PrintArray(const int* a, const int size, int i);
template <typename T>
void PrintArray(const T* a, const int size, int i);

// ---------- Пошук індексу максимального елемента ----------
int FindMaxIndex(const int* a, const int size, int i, int maxIndex);
template <typename T>
int FindMaxIndex(const T* a, const int size, int i, int maxIndex);

// ---------- Пошук індексу першого нуля, починаючи з i ----------
int FindZeroIndex(const int* a, const int size, int i);
template <typename T>
int FindZeroIndex(const T* a, const int size, int i);

// ---------- Добуток елементів a[from] ... a[to - 1] ----------
int ProductBetween(const int* a, const int from, const int to);
template <typename T>
T ProductBetween(const T* a, const int from, const int to);

// ---------- Добуток між першим і другим нулями ----------
bool ProductBetweenZeros(const int* a, const int size, int& product);
template <typename T>
bool ProductBetweenZeros(const T* a, const int size, T& product);

// ---------- Копіювання кожного другого елемента ----------
void CopyEveryOther(const int* src, const int size, int i, int* dst, int j);
template <typename T>
void CopyEveryOther(const T* src, const int size, int i, T* dst, int j);

// ---------- Копіювання масиву ----------
void CopyArray(const int* src, int* dst, const int size, int i);
template <typename T>
void CopyArray(const T* src, T* dst, const int size, int i);

// ---------- Перестановка: спочатку непарні позиції, потім парні ----------
void RearrangeOddEven(int* a, const int size);
template <typename T>
void RearrangeOddEven(T* a, const int size);

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cout << "n must be positive" << endl;
        return 1;
    }
    srand(static_cast<unsigned>(time(0)));

    // ===== Звичайні функції (int) =====
    cout << endl << "--- int (plain functions) ---" << endl;
    int* a = new int[n];
    FillArray(a, n, -3, 3, 0);
    cout << "Array:  ";
    PrintArray(a, n, 0);
    cout << endl;

    int maxIndex = FindMaxIndex(a, n, 0, 0);
    cout << "Max element number: " << maxIndex + 1 << endl;

    int p;
    if (ProductBetweenZeros(a, n, p))
        cout << "Product between first and second zero: " << p << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven(a, n);
    cout << "Result: ";
    PrintArray(a, n, 0);
    cout << endl;
    delete[] a;

    // ===== Шаблони, T = int =====
    cout << endl << "--- template, T = int ---" << endl;
    int* a2 = new int[n];
    FillArray<int>(a2, n, -3, 3, 0);
    cout << "Array:  ";
    PrintArray<int>(a2, n, 0);
    cout << endl;

    int maxIndex2 = FindMaxIndex<int>(a2, n, 0, 0);
    cout << "Max element number: " << maxIndex2 + 1 << endl;

    int p2;
    if (ProductBetweenZeros<int>(a2, n, p2))
        cout << "Product between first and second zero: " << p2 << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven<int>(a2, n);
    cout << "Result: ";
    PrintArray<int>(a2, n, 0);
    cout << endl;
    delete[] a2;

    // ===== Шаблони, T = double =====
    cout << endl << "--- template, T = double ---" << endl;
    double* b = new double[n];
    FillArray<double>(b, n, -3, 3, 0);
    cout << "Array:  ";
    PrintArray<double>(b, n, 0);
    cout << endl;

    int maxIndex3 = FindMaxIndex<double>(b, n, 0, 0);
    cout << "Max element number: " << maxIndex3 + 1 << endl;

    double p3;
    if (ProductBetweenZeros<double>(b, n, p3))
        cout << "Product between first and second zero: " << p3 << endl;
    else
        cout << "No product: need two zeros with elements between them" << endl;

    RearrangeOddEven<double>(b, n);
    cout << "Result: ";
    PrintArray<double>(b, n, 0);
    cout << endl;
    delete[] b;

    return 0;
}

// ================= FillArray =================
void FillArray(int* a, const int size, const int low, const int high, int i)
{
    if (i < size)
    {
        a[i] = low + rand() % (high - low + 1);
        FillArray(a, size, low, high, i + 1);
    }
}

template <typename T>
void FillArray(T* a, const int size, const int low, const int high, int i)
{
    if (i < size)
    {
        a[i] = static_cast<T>(low + rand() % (high - low + 1));
        FillArray<T>(a, size, low, high, i + 1);
    }
}

// ================= PrintArray =================
void PrintArray(const int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        PrintArray(a, size, i + 1);
    }
}

template <typename T>
void PrintArray(const T* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(5) << a[i];
        PrintArray<T>(a, size, i + 1);
    }
}

// ================= FindMaxIndex =================
int FindMaxIndex(const int* a, const int size, int i, int maxIndex)
{
    if (i >= size)
        return maxIndex;
    if (a[i] > a[maxIndex])
        maxIndex = i;
    return FindMaxIndex(a, size, i + 1, maxIndex);
}

template <typename T>
int FindMaxIndex(const T* a, const int size, int i, int maxIndex)
{
    if (i >= size)
        return maxIndex;
    if (a[i] > a[maxIndex])
        maxIndex = i;
    return FindMaxIndex<T>(a, size, i + 1, maxIndex);
}

// ================= FindZeroIndex =================
int FindZeroIndex(const int* a, const int size, int i)
{
    if (i >= size)
        return -1;
    if (a[i] == 0)
        return i;
    return FindZeroIndex(a, size, i + 1);
}

template <typename T>
int FindZeroIndex(const T* a, const int size, int i)
{
    if (i >= size)
        return -1;
    if (a[i] == T())
        return i;
    return FindZeroIndex<T>(a, size, i + 1);
}

// ================= ProductBetween =================
int ProductBetween(const int* a, const int from, const int to)
{
    if (from >= to)
        return 1;
    return a[from] * ProductBetween(a, from + 1, to);
}

template <typename T>
T ProductBetween(const T* a, const int from, const int to)
{
    if (from >= to)
        return T(1);
    return a[from] * ProductBetween<T>(a, from + 1, to);
}

// ================= ProductBetweenZeros =================
bool ProductBetweenZeros(const int* a, const int size, int& product)
{
    int first = FindZeroIndex(a, size, 0);
    if (first == -1)
        return false;
    int second = FindZeroIndex(a, size, first + 1);
    if (second == -1 || second == first + 1)
        return false;
    product = ProductBetween(a, first + 1, second);
    return true;
}

template <typename T>
bool ProductBetweenZeros(const T* a, const int size, T& product)
{
    int first = FindZeroIndex<T>(a, size, 0);
    if (first == -1)
        return false;
    int second = FindZeroIndex<T>(a, size, first + 1);
    if (second == -1 || second == first + 1)
        return false;
    product = ProductBetween<T>(a, first + 1, second);
    return true;
}

// ================= CopyEveryOther =================
void CopyEveryOther(const int* src, const int size, int i, int* dst, int j)
{
    if (i < size)
    {
        dst[j] = src[i];
        CopyEveryOther(src, size, i + 2, dst, j + 1);
    }
}

template <typename T>
void CopyEveryOther(const T* src, const int size, int i, T* dst, int j)
{
    if (i < size)
    {
        dst[j] = src[i];
        CopyEveryOther<T>(src, size, i + 2, dst, j + 1);
    }
}

// ================= CopyArray =================
void CopyArray(const int* src, int* dst, const int size, int i)
{
    if (i < size)
    {
        dst[i] = src[i];
        CopyArray(src, dst, size, i + 1);
    }
}

template <typename T>
void CopyArray(const T* src, T* dst, const int size, int i)
{
    if (i < size)
    {
        dst[i] = src[i];
        CopyArray<T>(src, dst, size, i + 1);
    }
}

// ================= RearrangeOddEven =================
void RearrangeOddEven(int* a, const int size)
{
    int* tmp = new int[size];
    CopyEveryOther(a, size, 0, tmp, 0);                 // позиції 1, 3, 5, ...
    CopyEveryOther(a, size, 1, tmp, (size + 1) / 2);    // позиції 2, 4, 6, ...
    CopyArray(tmp, a, size, 0);
    delete[] tmp;
}

template <typename T>
void RearrangeOddEven(T* a, const int size)
{
    T* tmp = new T[size];
    CopyEveryOther<T>(a, size, 0, tmp, 0);
    CopyEveryOther<T>(a, size, 1, tmp, (size + 1) / 2);
    CopyArray<T>(tmp, a, size, 0);
    delete[] tmp;
}