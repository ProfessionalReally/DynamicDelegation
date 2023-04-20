#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

//����������� ����� ��������
class AbsractSymptoms
{
protected:
	string NameSymptoms, //������������ ��������
			ViewSymptoms; //���
};

//��������� ������ �������
class Symptoms : public AbsractSymptoms
{
public:
	void PrintName() { cout << "Symptom - " << NameSymptoms << endl; };
	void PrintView() { cout << "View - " << ViewSymptoms << endl; };
	void virtual DetermineSymptoms() = 0;
	void WriteSymptoms(string name, string view) { NameSymptoms = name; ViewSymptoms = view; };
};

//�������� ������

//������ ������� ��������
class EasySymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a easy symptoms" << endl; };
};

//������� ������� ��������
class MediumSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a medium symptoms" << endl; };
};

//������� ������� ��������
class HardSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a hard symptoms" << endl; };
};


//����������� ����� ��������
class AbsractDiagnosis
{
protected:
	string NameDiagnosis,
		PeriodDisease;
};


//��������� ��������
class Diagnosis : public AbsractDiagnosis
{
private:
	Symptoms* symptoms; //��������� �� ������ �������
public:
	void PrintName() { cout << "Diagnosis - " << NameDiagnosis << endl; };
	void PrintPeriod() { cout << "Period - " << PeriodDisease << endl; };
	void virtual DetermineDiagnosis() = 0;
	void AddSymptoms(Symptoms* s) { symptoms = s; };
	void WriteDiagnosis(string name, string view) { NameDiagnosis = name; PeriodDisease = view; };
	void PrintSymptoms() { symptoms->PrintName(); };
	void PrintView() { symptoms->PrintView(); };
};

//�������� ������

//�������� ������
class HiddenPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis hidden period" << endl; };
};

//������������� ������
class ProdromalPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis prodromal period" << endl; };
};

//������ ������
class FullPeriod : public Diagnosis
{
	void DetermineDiagnosis() override { cout << "Determine a diagnosis full period" << endl; };
};

//�������
class Patient
{
private:
	string FIO; //���
	Diagnosis* diagnosis; //��������� �� ������ �������
public:
	Patient(string s) { FIO = s; };
	void PrintName() { cout << "Patient - " << FIO << endl; };
	void PrintDiagnosis() { diagnosis->PrintName(); };
	void PrintPeriod() { diagnosis->PrintPeriod(); };
	void AddDiagnosis(Diagnosis* s) { diagnosis = s; };
	void PrintSymptoms() { diagnosis->PrintSymptoms(); };
	void PrintView() { diagnosis->PrintView(); };
};