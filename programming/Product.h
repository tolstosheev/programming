#pragma once
using namespace System;
using namespace System::IO;
ref class Product {
private:
    Int32 id;
    String^ name;
    String^ dimensions;
    Decimal weight;
    String^ material;
    String^ color;
    Int32 warrantyPeriod;


    Int32 GenerateRandomId() {
        Random^ random = gcnew Random();
        return random->Next(1000, 10000);
    }
public:

    Product(String^ name, String^ dimensions, Decimal weight, String^ material, String^ color, Int32 warrantyPeriod)
        : id(GenerateRandomId()), name(name), dimensions(dimensions), weight(weight), material(material), color(color), warrantyPeriod(warrantyPeriod){}

    Product(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        name = sr->ReadLine();
        dimensions = sr->ReadLine();
        weight = Convert::ToDecimal(sr->ReadLine());
        material = sr->ReadLine();
        color = sr->ReadLine();
        warrantyPeriod = Convert::ToInt32(sr->ReadLine());
    }

    property Int32 Id {
        Int32 get() { return id; }
    }

    property String^ Name {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    property String^ Dimensions {
        String^ get() { return dimensions; }
        void set(String^ value) { dimensions = value; }
    }

    property Decimal Weight {
        Decimal get() { return weight; }
        void set(Decimal value) { weight = value; }
    }

    property String^ Material {
        String^ get() { return material; }
        void set(String^ value) { material = value; }
    }

    property String^ Color {
        String^ get() { return color; }
        void set(String^ value) { color = value; }
    }

    property Int32 WarrantyPeriod {
        Int32 get() { return warrantyPeriod; }
        void set(Int32 value) { warrantyPeriod = value; }
    }

    property Product^ thisProduct { 
        Product^ get() { return this; } 
    }

    bool Equals(Product^ p) { return p == this; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(name);
        sw->WriteLine(dimensions);
        sw->WriteLine(weight);
        sw->WriteLine(material);
        sw->WriteLine(color);
        sw->WriteLine(warrantyPeriod);

    }
};