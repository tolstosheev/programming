#pragma once
#include "Product.h"
#include "Customer.h"
#include "Warehouse.h"

interface class IWarehouse
{
public:
	Customer^ getCustomer(int idx);
	Product^ getProduct(int idx);

	Int32  getCustomerObject(Customer^ obj);
	Int32 getProductObject(Product^ obj);

	Int32 getWarehouseProductObject(Product^ object);
	Product^ getWarehouseProduct(Int32 index);
	
};

