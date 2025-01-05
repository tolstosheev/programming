#pragma once

#include "Customer.h"
#include "Product.h"
#include "Warehouse.h"
#include "IWarehouse.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace	System::Diagnostics;

ref class db : public IWarehouse {
private:
	String^ dbName;
	List<Customer^>^ customers;
	List<Product^>^ products;
	List<Warehouse^>^ warehouse;
public:
	static db^ data;

	db(String^ _dbName) {			
		dbName = _dbName;
		customers = gcnew List<Customer^>();
		products = gcnew List<Product^>();
		warehouse = gcnew List<Warehouse^>();
	};

	void addCustomer(Customer^ c) { customers->Add(c); }
	virtual Customer^ getCustomer(int idx) { return (idx >= 0 && idx < customers->Count) ? customers[idx] : nullptr; }
	List<Customer^>^ getCustomerSource() { return customers; }
	virtual Int32 getCustomerObject(Customer^ object) { return customers->FindIndex(gcnew Predicate<Customer^>(object, &Customer::Equals)); ; }

	void addProduct(Product^ c) { products->Add(c); }
	virtual Product^ getProduct(int idx) { return (idx >= 0 && idx < products->Count) ? products[idx] : nullptr; }
	List<Product^>^ getProductSource() { return products; }
	virtual Int32 getProductObject(Product^ object) { return products->FindIndex(gcnew Predicate<Product^>(object, &Product::Equals)); ; }

	void addWarehouse(Warehouse^ c) { warehouse->Add(c); c->SetDB(this); }
	List<Warehouse^>^ getWarehouseSource() { return warehouse; }


	void Load()
	{
		StreamReader^ sr;
		try { sr = File::OpenText(dbName); }			
		catch (Exception^ e) { Console::WriteLine("IO Error {0}", e); return; }

		int cnt = Convert::ToInt32(sr->ReadLine());		
		for (int i = 0; i < cnt; i++)
			addCustomer(gcnew Customer(sr));

		cnt = Convert::ToInt32(sr->ReadLine());
		for (int i = 0; i < cnt; i++)
			addProduct(gcnew Product(sr));

		cnt = Convert::ToInt32(sr->ReadLine());
		for (int i = 0; i < cnt; i++)
			addWarehouse(gcnew Warehouse(sr));

		sr->Close();
	}

	void Save()
	{
		StreamWriter^ sw;
		try { sw = gcnew StreamWriter(dbName); }
		catch (Exception^ e) { Debug::WriteLine("IO Error {0}", e); return; }

		sw->WriteLine(customers->Count);								
		for each (Customer ^ p in customers) p->Save(sw);
		
		sw->WriteLine(products->Count);
		for each (Product ^ p in products) p->Save(sw);
		
		sw->WriteLine(warehouse->Count);
		for each (Warehouse ^ p in warehouse) p->Save(sw);

		sw->Close();
	}

};