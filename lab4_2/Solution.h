#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//Абстрактный класс симптома
class AbsractSymptoms
{
protected:
	string NameSymptoms, //Наименование симптома
			ViewSymptoms; //Вид
};

//Интерфейс класса симптом
class Symptoms : public AbsractSymptoms
{
public:
	void PrintName() { cout << "Symptom - " << NameSymptoms << endl; };
	void PrintView() { cout << "View - " << ViewSymptoms << endl; };
	void virtual DetermineSymptoms() = 0;
	void WriteSymptoms(string name, string view) { NameSymptoms = name; ViewSymptoms = view; };
};

//Дочерние классы

//Низкая тяжесть симптома
class EasySymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a easy symptoms" << endl; };
};

//Средняя тяжесть симптома
class MediumSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a medium symptoms" << endl; };
};

//Высокая тяжесть симптома
class HardSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a hard symptoms" << endl; };
};


//Абстрактный класс Диагноза
class AbsractDiagnosis
{
protected:
	string NameDiagnosis,
		PeriodDisease;
};


//Интерфейс Диагноза
class Diagnosis : public AbsractDiagnosis
{
private:
	Symptoms* symptoms; //Указатель на объект Симптом
public:
	void PrintName() { cout << "Diagnosis - " << NameDiagnosis << endl; };
	void PrintPeriod() { cout << "Period - " << PeriodDisease << endl; };
	void virtual DetermineDiagnosis() = 0;
	void AddSymptoms(Symptoms* s) { symptoms = s; };
	void WriteDiagnosis(string name, string view) { NameDiagnosis = name; PeriodDisease = view; };
	void PrintSymptoms() { symptoms->PrintName(); };
	void PrintView() { symptoms->PrintView(); };
};

//Дочерние классы

//Скрытный период
class HiddenPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis hidden period" << endl; };
};

//Инкубационный период
class ProdromalPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis prodromal period" << endl; };
};

//Полный период
class FullPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis full period" << endl; };
};

//Пациент
class Patient
{
private:
	string FIO; //ФИО
	Diagnosis* diagnosis; //Указатель на объект диагноз
public:
	Patient(string s) { FIO = s; };
	void PrintName() { cout << "Patient - " << FIO << endl; };
	void PrintDiagnosis() { diagnosis->PrintName(); };
	void PrintPeriod() { diagnosis->PrintPeriod(); };
	void AddDiagnosis(Diagnosis* s) { diagnosis = s; };
	void PrintSymptoms() { diagnosis->PrintSymptoms(); };
	void PrintView() { diagnosis->PrintView(); };
};