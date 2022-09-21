#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <algorithm> 
using namespace std;

template <typename T>
//заполняет массив случайными силами от begin до end
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

//Вывод массива в консоль

template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

void type_of(int num);
void type_of(double num);
void type_of(char num);

int sum_AB(int A, int B);

//Задача1. Создаем функцию, которая принимает любое число и выводит его тип данных.


//Задача3.
template <typename T>
void middle_sort(T arr[], const int length) { 
	int first_index = 0, last_index = 0;

	for (int i = 0; i < length; i++) //индекс первого отрицательного элемента
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for (int i = length - 1; i >= 0; i--) // индекс последнего отрицательного элемента
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
		
	//Пузырьковая сортировка
	/*for (int i = last_index - 1; i > 0; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);*/
	//Быстрая сортировка
	sort(arr + first_index + 1, arr + last_index - 1);
}

//задача4

template <typename T>
void move_arr(T arr[], const int length, int num) {
	if (num >= 0) //сдвиги вправо
		for (int j = 0; j < num; j++)
			for (int i = length - 2; i >= 0; i--)
				swap(arr[i], arr[i + 1]);
	else //сдвиги влево
		for (int j = num; j < 0; j++)
			for (int i = 0; i < length - 1; i++)
				swap(arr[i], arr[i + 1]);

}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Задача 1. Тип данных

	/*cout << "12 -"; type_of(12);
	cout << "12 -"; type_of(9.11);
	cout << "12 -"; type_of('T');*/

	//Написать рекурсивную функцию, которая вычисляет сумму чисел от А до В

	/*cout << "Введите два числа: ";
	cin >> n >> m;
	cout << "Сумма чисел AB = " << sum_AB(n, m) << "\n\n";*/


	//Задача 3. Самый левый и самый правый в массиве отрицательный элемент, все, что между ними должно быть отсортировано
	/*cout << "Изначальный массив:\n";
	const int size3 = 20;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	show_arr(arr3, size3);
	middle_sort(arr3, size3);
	cout << "Итоговый массив:\n";
	show_arr(arr3, size3);
	cout << '\n';*/

	//Задача 4. Сдвиг массива

	cout << "Изначальный массив: \n";
	const int size4 = 10;
	int arr4[size4]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	show_arr(arr4, size4);
	cout << "Введите количество сдвигов: ";
	cin >> n;
	move_arr(arr4, size4, n);
	cout << "Итоговый массив: \n";
	show_arr(arr4, size4);







	return 0;
}

void type_of(int num) {
	cout << "INT\n";
}
void type_of(double num){
	cout << "DOUBLE\n";
}
void type_of(char num) {
	cout << "CHAR\n";
}

//Задача 2

int sum_AB(int A, int B) {
	if (B == A + 1)
		return A + B;
	return sum_AB(A, B - 1) + B;
}


