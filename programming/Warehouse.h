#pragma once
#include "IWarehouse.h"
#include <msclr/event.h>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;

ref class Warehouse {
private:
    Int32 id;          // Уникальный идентификатор склада
    Int32 product;     // Номер продукта
    Int32 quantity;    // Количество товара на складе
    String^ status;    // Статус товара (в наличии/нет в наличии)
    Decimal price;     // Общая стоимость товара на складе
    static IWarehouse^ data = nullptr;  // Ссылка на базу данных

    // Генерация случайного ID для склада
    Int32 GenerateRandomId() {
        return (gcnew Random())->Next(100000, 1000000);
    }

    // Метод для расчета стоимости товара на складе
   

public:
    event PropertyChangedEventHandler^ PropertyChanged;

    // Конструктор для создания нового склада
    Warehouse(Int32 product, Int32 quantity, String^ status)
        : id(GenerateRandomId()), product(product), quantity(quantity), status(status) {
        CalculatePrice();
        UpdateStatus();
    }

    // Конструктор для загрузки склада из файла
    Warehouse(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        product = Convert::ToInt32(sr->ReadLine());
        quantity = Convert::ToInt32(sr->ReadLine());
        status = sr->ReadLine();
        price = Convert::ToDecimal(sr->ReadLine());
    }

    // Свойства для доступа к данным склада
    property Int32 ID { Int32 get() { return id; } }
    property Product^ ProductObject { Product^ get() { return data->getProduct(product); } void set(Product^ value) { product = data->getProductObject(value); CalculatePrice(); } }
    property Int32 Quantity { Int32 get() { return quantity; } void set(Int32 value) { quantity = value; CalculatePrice(); UpdateStatus(); } }
    property String^ Status { String^ get() { return status; } void set(String^ value) { status = value; OnPropertyChanged("Status"); } }
    property Decimal Price { Decimal get() { return price; } void set(Decimal value) { price = value; } }
    property Product^ thisWarehouseProduct { Product^ get() { return this->ProductObject; } }
    property Int32 thisWarehouseProductID { Int32 get() { return this->ProductObject->ID; } }

    // Метод для установки ссылки на базу данных
    void SetDB(IWarehouse^ _data) { data = _data; }

    // Метод для сохранения склада в файл
    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(product);
        sw->WriteLine(quantity);
        sw->WriteLine(status);
        sw->WriteLine(price);
    }

    // Метод для обновления статуса товара на складе
    void UpdateStatus() {
        status = quantity > 0 ? "В наличии" : "Нет в наличии";
        OnPropertyChanged("Status");
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

    // Метод для уведомления об изменении свойства
    void OnPropertyChanged(String^ propertyName) {
        PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
    }
};