#pragma once
#include "Product.h"
#include "Customer.h"

interface class IWarehouse
{
public:
	Customer^ getCustomer(int idx);
	Product^ getProduct(int idx);

	Int32  getCustomerObject(Customer^ obj);
	Int32 getProductObject(Product^ obj);
};

