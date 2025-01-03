#pragma once

#include "Customer.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace	System::Diagnostics;

ref class db {
private:
	String^ dbName;
	List<Customer^>^ customers;
public:
	static db^ data;

	db(String^ _dbName) {			// Инициализация
		dbName = _dbName;
		customers = gcnew List<Customer^>();
	};

	void addCustomer(Customer^ c) { customers->Add(c); }
	Customer^ getCustomer(int idx) { return (idx >= 0 && idx < customers->Count) ? customers[idx] : nullptr; }
	List<Customer^>^ getCustomerSource() { return customers; }
	void Load()
	{
		StreamReader^ sr;
		try { sr = File::OpenText(dbName); }			
		catch (Exception^ e) { Console::WriteLine("IO Error {0}", e); return; }

		int cnt = Convert::ToInt32(sr->ReadLine());		
		for (int i = 0; i < cnt; i++)
			addCustomer(gcnew Customer(sr));
		sr->Close();
	}
	void Save()
	{
		StreamWriter^ sw;
		try { sw = gcnew StreamWriter(dbName); }
		catch (Exception^ e) { Debug::WriteLine("IO Error {0}", e); return; }

		sw->WriteLine(customers->Count);								
		for each (Customer ^ p in customers) p->Save(sw);
		sw->Close();
	}

};