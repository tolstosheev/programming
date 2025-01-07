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
        return (gcnew Random())->Next(1000, 10000);
    }

    void CalculatePrice() {
        if (data != nullptr && ProductObject != nullptr) {
            price = quantity * ProductObject->Price;
        }
        else {
            price = 0;
        }
        OnPropertyChanged("Price");
    }

    void UpdateStatus() {
        status = quantity > 0 ? "В наличии" : "Нет в наличии";
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

    property Int32 ID { Int32 get() { return id; } }
    property Product^ ProductObject { Product^ get() { return data->getProduct(product); } void set(Product^ value) { product = data->getProductObject(value); CalculatePrice(); } }
    property Int32 Quantity { Int32 get() { return quantity; } void set(Int32 value) { quantity = value; CalculatePrice(); UpdateStatus(); } }
    property String^ Status { String^ get() { return status; } void set(String^ value) { status = value; OnPropertyChanged("Status"); } }
    property Decimal Price { Decimal get() { return price; } void set(Decimal value) { price = value; } }
    property Product^ thisWarehouseProduct {Product^ get() { return this->ProductObject; }}
    property Int32 thisWarehouseProductID {Int32 get() { return this->ProductObject->ID; }}

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