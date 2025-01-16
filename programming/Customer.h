#pragma once
using namespace System;
using namespace System::IO;

ref class Customer {
private:
    Int32 id;          // Уникальный идентификатор клиента
    String^ name;      // Имя клиента
    String^ phone;     // Телефон клиента
    String^ address;   // Адрес клиента
    String^ type;      // Тип клиента (физическое лицо, юридическое лицо и т.д.)

    // Генерация случайного ID для клиента
    Int32 GenerateRandomId() {
        return (gcnew Random())->Next(100000, 1000000);
    }

public:
    // Конструктор для создания нового клиента
    Customer(String^ name, String^ phone, String^ address, String^ type)
        : id(GenerateRandomId()), name(name), phone(phone), address(address), type(type) {}

    // Конструктор для загрузки клиента из файла
    Customer(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        name = sr->ReadLine();
        phone = sr->ReadLine();
        address = sr->ReadLine();
        type = sr->ReadLine();
    }

    // Свойства для доступа к данным клиента
    property Int32 ID { Int32 get() { return id; } }
    property String^ Name { String^ get() { return name; } void set(String^ value) { name = value; } }
    property String^ Phone { String^ get() { return phone; } void set(String^ value) { phone = value; } }
    property String^ Address { String^ get() { return address; } void set(String^ value) { address = value; } }
    property String^ Type { String^ get() { return type; } void set(String^ value) { type = value; } }
    property Customer^ thisCustomer { Customer^ get() { return this; } }

    // Метод для сравнения клиентов
    bool Equals(Customer^ p) { return p == this; }

    // Метод для сохранения данных клиента в файл
    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(name);
        sw->WriteLine(phone);
        sw->WriteLine(address);
        sw->WriteLine(type);
    }
};