#pragma once
using namespace System;
using namespace System::IO;

ref class Product {
private:
    Int32 id;                // Уникальный идентификатор продукта
    String^ name;            // Название продукта
    String^ dimensions;      // Габариты продукта
    Decimal weight;          // Вес продукта
    String^ material;        // Материал продукта
    String^ color;           // Цвет продукта
    Int32 warrantyPeriod;    // Гарантийный срок
    Decimal price;           // Цена продукта
    String^ type;            // Тип продукта

    // Генерация случайного ID для продукта
    Int32 GenerateRandomId() {
        return (gcnew Random())->Next(100000, 1000000);
    }

public:
    // Конструктор для создания нового продукта
    Product(String^ name, String^ dimensions, Decimal weight, String^ material, String^ color, Int32 warrantyPeriod, Decimal price, String^ type)
        : id(GenerateRandomId()), name(name), dimensions(dimensions), weight(weight), material(material), color(color), warrantyPeriod(warrantyPeriod), price(price), type(type) {}

    // Конструктор для загрузки продукта из файла
    Product(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        name = sr->ReadLine();
        dimensions = sr->ReadLine();
        weight = Convert::ToDecimal(sr->ReadLine());
        material = sr->ReadLine();
        color = sr->ReadLine();
        warrantyPeriod = Convert::ToInt32(sr->ReadLine());
        price = Convert::ToDecimal(sr->ReadLine());
        type = sr->ReadLine();
    }

    // Свойства для доступа к данным продукта
    property Int32 ID { Int32 get() { return id; } }
    property String^ Name { String^ get() { return name; } void set(String^ value) { name = value; } }
    property String^ Dimensions { String^ get() { return dimensions; } void set(String^ value) { dimensions = value; } }
    property Decimal Weight { Decimal get() { return weight; } void set(Decimal value) { weight = value; } }
    property Decimal Price { Decimal get() { return price; } void set(Decimal value) { price = value; } }
    property String^ Material { String^ get() { return material; } void set(String^ value) { material = value; } }
    property String^ Color { String^ get() { return color; } void set(String^ value) { color = value; } }
    property Int32 WarrantyPeriod { Int32 get() { return warrantyPeriod; } void set(Int32 value) { warrantyPeriod = value; } }
    property String^ Type { String^ get() { return type; } void set(String^ value) { type = value; } }

    // Метод для сравнения продуктов
    bool Equals(Product^ p) { return p == this; }

    // Свойство для получения текущего объекта продукта
    property Product^ thisProduct { Product^ get() { return this; } }

    // Метод для сохранения продукта в файл
    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(name);
        sw->WriteLine(dimensions);
        sw->WriteLine(weight);
        sw->WriteLine(material);
        sw->WriteLine(color);
        sw->WriteLine(warrantyPeriod);
        sw->WriteLine(price);
        sw->WriteLine(type);
    }
};