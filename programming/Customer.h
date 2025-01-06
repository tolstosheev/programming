#pragma once
using namespace System;
using namespace System::IO;
ref class Customer{
private:
	Int32 id;
	String^ name;
	String^ phone;;
	String^ address;
    String^ type;


	Int32 GenerateRandomId() {
		Random^ random = gcnew Random();
		return random->Next(1000, 10000); 
	}
public:

    Customer(String^ name, String^ phone, String^ address, String^ type)
        : id(GenerateRandomId()), name(name), phone(phone), address(address), type(type) {}

    Customer(StreamReader^ sr) {
        id = Convert::ToInt32(sr->ReadLine());
        name = sr->ReadLine();
        phone = sr->ReadLine();
        address = sr->ReadLine();
        type = sr->ReadLine();
    }

    property Int32 ID {
        Int32 get() { return id; }
    }

    property String^ Name {
        String^ get() { return name; }
        void set(String^ value) { name = value; }
    }

    property String^ Phone {
        String^ get() { return phone; }
        void set(String^ value) { phone = value; }
    }

    property String^ Address {
        String^ get() { return address; }
        void set(String^ value) { address = value; }
    }

    property String^ Type {
        String^ get() { return type; }
        void set(String^ value) { type = value; }
    }

    property Customer^ thisCustomer { 
        Customer^ get() { return this; }; 
    }

    bool Equals(Customer^ p) { return p == this; }

    void Save(StreamWriter^ sw) {
        sw->WriteLine(id);
        sw->WriteLine(name);
        sw->WriteLine(phone);
        sw->WriteLine(address);
        sw->WriteLine(type);
    }
};