#pragma once
#include "IWarehouse.h"
#include <msclr/event.h>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;

ref class Order {
private:
    Int32 id;
    Int32 customer;
    Int32 product;
    Int32 quantity;
    DateTime date;
    Decimal price;

    static IWarehouse^ data = nullptr;

    Int32 GenerateRandomId() {
        Random^ random = gcnew Random();
        return random->Next(1000, 10000);
    }

    


public:
    event PropertyChangedEventHandler^ PropertyChanged;

    Order(Int32 customer, Int32 product, Int32 quantity, DateTime date)
        : id(GenerateRandomId()), customer(customer), product(product), quantity(quantity), date(date) {
        CalculatePrice(); 
    }

    Order(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        customer = Convert::ToInt32(sr->ReadLine());
        product = Convert::ToInt32(sr->ReadLine());
        quantity = Convert::ToInt32(sr->ReadLine());
        date = Convert::ToDateTime(sr->ReadLine());
        price = Convert::ToDecimal(sr->ReadLine());
    }

    property Int32 ID {
        Int32 get() { return id; }
    }

    property Customer^ CustomerObject {
        Customer^ get() { return data->getCustomer(customer); };
        void set(Customer^ value) {
            customer = (data != nullptr) ? data->getCustomerObject(value) : 0;
            OnPropertyChanged("CustomerObject");
        }
    }

    property Product^ ProductObject {
        Product^ get() { return data->getProduct(product); }
        void set(Product^ value) {
            product = (data != nullptr) ? data->getProductObject(value) : 0;
            CalculatePrice(); 
            OnPropertyChanged("ProductObject");
        }
    }

    property Int32 Quantity {
        Int32 get() { return quantity; }
        void set(Int32 value) {
            quantity = value;
            CalculatePrice();
            OnPropertyChanged("Quantity");
        }
    }

    property DateTime Date {
        DateTime get() { return date; }
        void set(DateTime value) { date = value; }
    }

    property Decimal Price {
        Decimal get() { return price; }
    }

    void SetDB(IWarehouse^ _data) { data = _data; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(customer);
        sw->WriteLine(product);
        sw->WriteLine(quantity);
        sw->WriteLine(date);
        sw->WriteLine(price);
    }

    void CalculatePrice() {
        if (data != nullptr && ProductObject != nullptr) {
            Decimal pricePerUnit = ProductObject->Price;
            price = quantity * pricePerUnit;
        }
        else {
            price = 0;
        }
        OnPropertyChanged("Price");
    }

    void OnPropertyChanged(String^ propertyName) {
        PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
    }
};