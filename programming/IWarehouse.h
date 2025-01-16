#pragma once
#include "Product.h"
#include "Customer.h"
#include "Warehouse.h"

interface class IWarehouse {
public:
    // Методы для работы с клиентами и продуктами
    Customer^ getCustomer(Int32 idx);
    Product^ getProduct(Int32 idx);

    Int32 getCustomerObject(Customer^ obj);
    Int32 getProductObject(Product^ obj);

    Int32 getWarehouseProductObject(Product^ object);
    Product^ getWarehouseProduct(Int32 index);
    Int32 GetProductQuantity(Int32 productId);
    void UpdateWarehouseQuantity(Int32 productId, Int32 newQuantity);
};