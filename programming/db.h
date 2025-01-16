#pragma once

#include "Customer.h"
#include "Product.h"
#include "Warehouse.h"
#include "IWarehouse.h"
#include "Order.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace	System::Diagnostics;

ref class db : public IWarehouse {
private:
	String^ dbName;  // Имя базы данных
	List<Customer^>^ customers;  // Список клиентов
	List<Product^>^ products;    // Список продуктов
	List<Warehouse^>^ warehouse; // Список складов
	List<Order^>^ orders;        // Список заказов

public:
	static db^ data;  // Статический экземпляр базы данных

	// Конструктор базы данных
	db(String^ _dbName) {
		dbName = _dbName;
		customers = gcnew List<Customer^>();
		products = gcnew List<Product^>();
		warehouse = gcnew List<Warehouse^>();
		orders = gcnew List<Order^>();
	}

	// Метод для получения экземпляра базы данных
	static db^ GetData() { return data; }

	// Методы для работы с клиентами
	void addCustomer(Customer^ c) { customers->Add(c); }
	virtual Customer^ getCustomer(Int32 idx) { return (idx >= 0 && idx < customers->Count) ? customers[idx] : nullptr; }
	List<Customer^>^ getCustomerSource() { return customers; }
	virtual Int32 getCustomerObject(Customer^ object) { return customers->FindIndex(gcnew Predicate<Customer^>(object, &Customer::Equals)); }

	// Методы для работы с продуктами
	void addProduct(Product^ c) { products->Add(c); }
	virtual Product^ getProduct(Int32 idx) { return (idx >= 0 && idx < products->Count) ? products[idx] : nullptr; }
	List<Product^>^ getProductSource() { return products; }
	virtual Int32 getProductObject(Product^ object) { return products->FindIndex(gcnew Predicate<Product^>(object, &Product::Equals)); }
	virtual Int32 GetProductQuantity(Int32 productId) {
		Int32 totalQuantity = 0;
		for each (Warehouse ^ warehouseItem in warehouse) {
			totalQuantity += (warehouseItem->ProductObject != nullptr && warehouseItem->ProductObject->ID == productId) ? warehouseItem->Quantity : 0;
		}
		return totalQuantity;
	}

	// Методы для работы со складом
	void addWarehouse(Warehouse^ c) { warehouse->Add(c); c->SetDB(this); }
	virtual List<Warehouse^>^ getWarehouseSource() { return warehouse; }
	virtual Int32 getWarehouseProductObject(Product^ object) {
		for (int i = 0; i < warehouse->Count; i++) {
			Warehouse^ warehouseItem = warehouse[i];
			if (warehouseItem->ProductObject != nullptr &&
				(warehouseItem->ProductObject == object || warehouseItem->ProductObject->ID == object->ID)) {
				return i;
			}
		}
		return -1;
	}
	virtual Product^ getWarehouseProduct(Int32 index) {
		if (index >= 0 && index < warehouse->Count) {
			Warehouse^ warehouseItem = warehouse[index];
			if (warehouseItem->ProductObject != nullptr) {
				return warehouseItem->ProductObject;
			}
		}
		return nullptr;
	}
	virtual void UpdateWarehouseQuantity(Int32 productId, Int32 newQuantity) {
		for each (Warehouse ^ warehouseItem in warehouse) {
			if (warehouseItem->ProductObject != nullptr && warehouseItem->ProductObject->ID == productId) {
				warehouseItem->Quantity = newQuantity;
				warehouseItem->UpdateStatus();
				break;
			}
		}
		Save();
	}

	// Методы для работы с заказами
	void addOrder(Order^ c) { orders->Add(c); c->SetDB(this); }
	List<Order^>^ getOrderSource() { return orders; }


	// Метод для загрузки данных из файла
	void Load() {
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

		cnt = Convert::ToInt32(sr->ReadLine());
		for (int i = 0; i < cnt; i++)
			addOrder(gcnew Order(sr));

		sr->Close();
	}

	// Метод для сохранения данных в файл
	void Save() {
		StreamWriter^ sw;
		try { sw = gcnew StreamWriter(dbName); }
		catch (Exception^ e) { Debug::WriteLine("IO Error {0}", e); return; }

		sw->WriteLine(customers->Count);
		for each (Customer ^ p in customers) p->Save(sw);

		sw->WriteLine(products->Count);
		for each (Product ^ p in products) p->Save(sw);

		sw->WriteLine(warehouse->Count);
		for each (Warehouse ^ p in warehouse) p->Save(sw);

		sw->WriteLine(orders->Count);
		for each (Order ^ p in orders) p->Save(sw);

		sw->Close();
	}

	// Методы для удаления заказов и товаров
	void DeleteOrdersByCustomerID(Int32 customerId) {
		for (int i = orders->Count - 1; i >= 0; i--) {
			if (orders[i]->CustomerObject->ID == customerId) {
				orders->RemoveAt(i);
			}
		}
	}

	void DeleteOrdersByProductID(Int32 productId) {
		for (int i = orders->Count - 1; i >= 0; i--) {
			if (orders[i]->WarehouseProductObject != nullptr && orders[i]->WarehouseProductObject->ID == productId) {
				orders->RemoveAt(i);
			}
		}
	}

	void DeleteWarehouseByProductID(Int32 productId) {
		for (int i = warehouse->Count - 1; i >= 0; i--) {
			if (warehouse[i]->ProductObject != nullptr && warehouse[i]->ProductObject->ID == productId) {
				warehouse->RemoveAt(i);
			}
		}

		for (int i = orders->Count - 1; i >= 0; i--) {
			if (orders[i]->WarehouseProductObject != nullptr && orders[i]->WarehouseProductObject->ID == productId) {
				orders->RemoveAt(i);
			}
		}
	}
};