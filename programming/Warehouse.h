#pragma once
#include "IWarehouse.h"

using namespace System;
using namespace System::IO;
ref class Warehouse {
private:
    Int32 id;
    Int32 product;
    Int32 quantity;
    String^ status;

    static IWarehouse^ data = nullptr;

    Int32 GenerateRandomId() {
        Random^ random = gcnew Random();
        return random->Next(1000, 10000);
    }
public:

    Warehouse(Int32 product, Int32 quantity, String^ status)
        : id(GenerateRandomId()), product(product), quantity(quantity), status(status) {}

    Warehouse(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        product = Convert::ToInt32(sr->ReadLine());
        quantity = Convert::ToInt32(sr->ReadLine());
        status = sr->ReadLine();
    }

    property Int32 Id {
        Int32 get() { return id; }
    }

    property Product^ ProductObject {
        Product^ get() { return data->getProduct(product); }
        void set(Product^ value) { product = (data != nullptr) ? data->getProductObject(value) : 0; }
    }

    property Int32 Quantity {
        Int32 get() { return quantity; }
        void set(Int32 value) { quantity = value; }
    }

    property String^ Status {
        String^ get() { return status; }
        void set(String^ value) { status = value; }
    }

    void SetDB(IWarehouse^ _data) { data = _data; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(product);
        sw->WriteLine(quantity);
        sw->WriteLine(status);
    }
};