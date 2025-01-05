#pragma once
#include "IWarehouse.h"
#include <msclr/event.h>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;

ref class Warehouse {
private:
    Int32 id;
    Int32 product;
    Int32 quantity;
    String^ status;
    Decimal price;

    static IWarehouse^ data = nullptr;

    Int32 GenerateRandomId() {
        Random^ random = gcnew Random();
        return random->Next(1000, 10000);
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

    void UpdateStatus() {
        if (quantity > 0) {
            status = "В наличии";
        }
        else {
            status = "Нет в наличии";
        }
        OnPropertyChanged("Status"); 
    }

public:
    event PropertyChangedEventHandler^ PropertyChanged;

    Warehouse(Int32 product, Int32 quantity, String^ status)
        : id(GenerateRandomId()), product(product), quantity(quantity), status(status) {
        CalculatePrice(); 
        UpdateStatus(); 
    }

    Warehouse(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        product = Convert::ToInt32(sr->ReadLine());
        quantity = Convert::ToInt32(sr->ReadLine());
        status = sr->ReadLine();
        price = Convert::ToDecimal(sr->ReadLine());
    }

    property Int32 ID {
        Int32 get() { return id; }
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
            UpdateStatus(); 
            OnPropertyChanged("Quantity");
        }
    }

    property String^ Status {
        String^ get() { return status; }
        void set(String^ value) {
            status = value;
            OnPropertyChanged("Status");
        }
    }

    property Decimal Price {
        Decimal get() { return price; }
    }

    void SetDB(IWarehouse^ _data) { data = _data; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(product);
        sw->WriteLine(quantity);
        sw->WriteLine(status);
        sw->WriteLine(price);
    }

    void OnPropertyChanged(String^ propertyName) {
            PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
    }
};