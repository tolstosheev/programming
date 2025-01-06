#pragma once
#include "IWarehouse.h"
#include <msclr/event.h>


using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;

ref class Order {
private:
    Int32 id;
    Int32 customer;
    Int32 product;
    Int32 quantity;
    DateTime date;
    Decimal price;
    Decimal discount;
    static IWarehouse^ data = nullptr;

    Int32 GenerateRandomId() {
        Random^ random = gcnew Random();
        return random->Next(1000, 10000);
    }

public:
    event PropertyChangedEventHandler^ PropertyChanged;

    Order(Int32 customer, Int32 product, Int32 quantity, DateTime date)
        : id(GenerateRandomId()), customer(customer), product(product), quantity(quantity), date(date), discount(0) {
        CalculatePrice();
    }

    Order(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        customer = Convert::ToInt32(sr->ReadLine());
        product = Convert::ToInt32(sr->ReadLine());
        quantity = Convert::ToInt32(sr->ReadLine());
        date = Convert::ToDateTime(sr->ReadLine());
        price = Convert::ToDecimal(sr->ReadLine());
        discount = Convert::ToDecimal(sr->ReadLine()); // Загружаем скидку
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

    property Decimal Discount {
        Decimal get() { return discount; }
    }

    void SetDB(IWarehouse^ _data) { data = _data; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(customer);
        sw->WriteLine(product);
        sw->WriteLine(quantity);
        sw->WriteLine(date);
        sw->WriteLine(price);
        sw->WriteLine(discount);
    }

    void CalculatePrice() {
        if (data != nullptr && ProductObject != nullptr) {
            Decimal pricePerUnit = ProductObject->Price;
            Decimal totalPrice = quantity * pricePerUnit;

            // Применяем скидку 10%, если количество изделий больше или равно 10
            if (quantity >= 10) {
                Decimal discount = totalPrice * static_cast<Decimal>(0.1); // 10% скидка
                price = Decimal::Subtract(totalPrice, discount);
            }
            else {
                price = totalPrice; // Без скидки
            }
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