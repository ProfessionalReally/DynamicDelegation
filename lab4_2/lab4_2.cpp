#include "Solution.h"

int main()
{

	//Создание разных видов симптомов
	Symptoms* symptoms1 = new EasySymptoms(),
		* symptoms2 = new MediumSymptoms(),
		* symptoms3 = new HardSymptoms();

	//Создание разных видов диагнозов
	Diagnosis* diagnosis1 = new HiddenPeriod(),
		* diagnosis2 = new ProdromalPeriod(),
		* diagnosis3 = new FullPeriod();

	//Создание различных пациентов
	Patient* pt1 = new Patient("Ivan Ivanovich Ivanov"),
		* pt2 = new Patient("Ruslan Ahmedovich Uranov"),
		* pt3 = new Patient("Irina Pavlova Fedorova");


	
	cout << "Easy Symptoms and Hidden Period: " << endl;

	//Записать симптом
	symptoms1->WriteSymptoms("Headache", "Easy Symptoms");

	//Определить вид симптома
	symptoms1->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis1->AddSymptoms(symptoms1);

	//Записать диагноз
	diagnosis1->WriteDiagnosis("Overwork", "Hidden Period");

	//Определить вид диагноза
	diagnosis1->DetermineDiagnosis();
	
	//Поставить диагноз пациенту
	pt1->AddDiagnosis(diagnosis1);

	//Вывод конечной информации
	pt1->PrintName();
	pt1->PrintSymptoms();
	pt1->PrintView();
	pt1->PrintDiagnosis();
	pt1->PrintPeriod();

	cout << endl;


	cout << "Medium Symptoms and Prodromal Period: " << endl;

	//Записать симптом
	symptoms2->WriteSymptoms("Cough", "Medium Symptoms");

	//Определить вид симптома
	symptoms2->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis2->AddSymptoms(symptoms2);

	//Записать диагноз
	diagnosis2->WriteDiagnosis("Bronchitis", "Prodromal Period");

	//Определить вид диагноза
	diagnosis2->DetermineDiagnosis();

	//Поставить диагноз пациенту
	pt2->AddDiagnosis(diagnosis2);

	//Вывод конечной информации
	pt2->PrintName();
	pt2->PrintSymptoms();
	pt2->PrintView();
	pt2->PrintDiagnosis();
	pt2->PrintPeriod();

	cout << endl;

	cout << "Hard Symptoms and Full Period: " << endl;

	//Записать симптом
	symptoms3->WriteSymptoms("Temperature", "Hard Symptoms");

	//Определить вид симптома
	symptoms3->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis3->AddSymptoms(symptoms3);

	//Записать диагноз
	diagnosis3->WriteDiagnosis("Coronavirus", "Full Period");

	//Определить вид диагноза
	diagnosis3->DetermineDiagnosis();

	//Поставить диагноз пациенту
	pt3->AddDiagnosis(diagnosis3);

	//Вывод конечной информации
	pt3->PrintName();
	pt3->PrintSymptoms();
	pt3->PrintView();
	pt3->PrintDiagnosis();
	pt3->PrintPeriod();


	//Удаление объектов


	delete pt1,
		pt2,
		pt3;

	delete symptoms1,
		symptoms2,
		symptoms3;

	delete diagnosis1,
		diagnosis2,
		diagnosis3;

}