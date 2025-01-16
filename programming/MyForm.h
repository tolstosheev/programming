#pragma once
#include "db.h"
namespace programming {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		db^ data;  // ��������� ���� ������
		// ����������� �����
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			db::data = gcnew db("data.txt");
			db::data->Load();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		/// ���������� �����
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ tabCustomers;
	protected:

	protected:
	// �������� ���������� �����
	private: System::Windows::Forms::TabPage^ tabProducts;
	private: System::Windows::Forms::TabPage^ tabWarehouse;
	private: System::Windows::Forms::TabPage^ tabOrder;
	private: System::Windows::Forms::TabControl^ tab;
	private: System::Windows::Forms::DataGridView^ dataCustomers;
	private: System::Windows::Forms::DataGridView^ dataProducts;
	private: System::Windows::Forms::DataGridView^ dataWarehouse;
	private: System::Windows::Forms::DataGridView^ dataOrders;

	// ������ ��� ���������� �������
	private: System::Windows::Forms::Button^ buttonCustomersDel;
	private: System::Windows::Forms::Button^ buttonCustomersAdd;
	private: System::Windows::Forms::Button^ buttonOrdersDel;
	private: System::Windows::Forms::Button^ buttonOrdersAdd;
	private: System::Windows::Forms::Button^ buttonWarehouseAdd;
	private: System::Windows::Forms::Button^ buttonWarehouseDel;
	private: System::Windows::Forms::Button^ buttonProductsDel;
	private: System::Windows::Forms::Button^ buttonProductsAdd;

	// ������� ��� DataGridView
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WarehouseID;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ WarehouseProductID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WarehouseProductQuantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WarehouseProductStatus;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WarehousePrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CustomersID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CustomersName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CustomersPhone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CustomersAddress;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ CustomerType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsDimensions;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsWeight;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsMaterial;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsColor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductsWarrantyPeriod;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ TypeProduct;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ProductPrice;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OrdersID;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ OrdersCustomerID;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ OrdersProductID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OrdersCount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OrdersDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ OrdersPrice;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		/// ��������� ��� ����������� �����
		System::ComponentModel::Container^ components;

		// ������ ����� �������� � ���������
		List<String^>^ customerTypes;
		List<String^>^ productTypes;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabCustomers = (gcnew System::Windows::Forms::TabPage());
			this->buttonCustomersDel = (gcnew System::Windows::Forms::Button());
			this->dataCustomers = (gcnew System::Windows::Forms::DataGridView());
			this->buttonCustomersAdd = (gcnew System::Windows::Forms::Button());
			this->tabProducts = (gcnew System::Windows::Forms::TabPage());
			this->buttonProductsDel = (gcnew System::Windows::Forms::Button());
			this->buttonProductsAdd = (gcnew System::Windows::Forms::Button());
			this->dataProducts = (gcnew System::Windows::Forms::DataGridView());
			this->tabWarehouse = (gcnew System::Windows::Forms::TabPage());
			this->buttonWarehouseDel = (gcnew System::Windows::Forms::Button());
			this->buttonWarehouseAdd = (gcnew System::Windows::Forms::Button());
			this->dataWarehouse = (gcnew System::Windows::Forms::DataGridView());
			this->WarehouseID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WarehouseProductID = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->WarehouseProductQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WarehouseProductStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WarehousePrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabOrder = (gcnew System::Windows::Forms::TabPage());
			this->buttonOrdersDel = (gcnew System::Windows::Forms::Button());
			this->buttonOrdersAdd = (gcnew System::Windows::Forms::Button());
			this->dataOrders = (gcnew System::Windows::Forms::DataGridView());
			this->tab = (gcnew System::Windows::Forms::TabControl());
			this->CustomersID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomersName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomersPhone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomersAddress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomerType = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ProductsID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsDimensions = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsWeight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsMaterial = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsColor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ProductsWarrantyPeriod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TypeProduct = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->ProductPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrdersID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrdersCustomerID = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->OrdersProductID = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->OrdersCount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrdersDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->OrdersPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabCustomers->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataCustomers))->BeginInit();
			this->tabProducts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataProducts))->BeginInit();
			this->tabWarehouse->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataWarehouse))->BeginInit();
			this->tabOrder->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOrders))->BeginInit();
			this->tab->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabCustomers
			// 
			this->tabCustomers->Controls->Add(this->buttonCustomersDel);
			this->tabCustomers->Controls->Add(this->dataCustomers);
			this->tabCustomers->Controls->Add(this->buttonCustomersAdd);
			this->tabCustomers->Location = System::Drawing::Point(4, 22);
			this->tabCustomers->Name = L"tabCustomers";
			this->tabCustomers->Padding = System::Windows::Forms::Padding(3);
			this->tabCustomers->Size = System::Drawing::Size(927, 234);
			this->tabCustomers->TabIndex = 3;
			this->tabCustomers->Text = L"���������";
			this->tabCustomers->UseVisualStyleBackColor = true;
			// 
			// buttonCustomersDel
			// 
			this->buttonCustomersDel->Location = System::Drawing::Point(584, 206);
			this->buttonCustomersDel->Name = L"buttonCustomersDel";
			this->buttonCustomersDel->Size = System::Drawing::Size(111, 28);
			this->buttonCustomersDel->TabIndex = 2;
			this->buttonCustomersDel->Text = L"�������";
			this->buttonCustomersDel->UseVisualStyleBackColor = true;
			this->buttonCustomersDel->Click += gcnew System::EventHandler(this, &MyForm::buttonCustomersDel_Click);
			// 
			// dataCustomers
			// 
			this->dataCustomers->AllowUserToAddRows = false;
			this->dataCustomers->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataCustomers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataCustomers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->CustomersID,
					this->CustomersName, this->CustomersPhone, this->CustomersAddress, this->CustomerType
			});
			this->dataCustomers->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataCustomers->Location = System::Drawing::Point(0, 0);
			this->dataCustomers->Name = L"dataCustomers";
			this->dataCustomers->RowHeadersVisible = false;
			this->dataCustomers->Size = System::Drawing::Size(927, 200);
			this->dataCustomers->TabIndex = 0;
			// 
			// buttonCustomersAdd
			// 
			this->buttonCustomersAdd->Location = System::Drawing::Point(276, 206);
			this->buttonCustomersAdd->Name = L"buttonCustomersAdd";
			this->buttonCustomersAdd->Size = System::Drawing::Size(111, 28);
			this->buttonCustomersAdd->TabIndex = 1;
			this->buttonCustomersAdd->Text = L"��������";
			this->buttonCustomersAdd->UseVisualStyleBackColor = true;
			this->buttonCustomersAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonCustomersAdd_Click);
			// 
			// tabProducts
			// 
			this->tabProducts->Controls->Add(this->buttonProductsDel);
			this->tabProducts->Controls->Add(this->buttonProductsAdd);
			this->tabProducts->Controls->Add(this->dataProducts);
			this->tabProducts->Location = System::Drawing::Point(4, 22);
			this->tabProducts->Name = L"tabProducts";
			this->tabProducts->Padding = System::Windows::Forms::Padding(3);
			this->tabProducts->Size = System::Drawing::Size(927, 234);
			this->tabProducts->TabIndex = 2;
			this->tabProducts->Text = L"�������";
			this->tabProducts->UseVisualStyleBackColor = true;
			// 
			// buttonProductsDel
			// 
			this->buttonProductsDel->Location = System::Drawing::Point(464, 206);
			this->buttonProductsDel->Name = L"buttonProductsDel";
			this->buttonProductsDel->Size = System::Drawing::Size(111, 28);
			this->buttonProductsDel->TabIndex = 5;
			this->buttonProductsDel->Text = L"�������";
			this->buttonProductsDel->UseVisualStyleBackColor = true;
			this->buttonProductsDel->Click += gcnew System::EventHandler(this, &MyForm::buttonProductsDel_Click);
			// 
			// buttonProductsAdd
			// 
			this->buttonProductsAdd->Location = System::Drawing::Point(183, 206);
			this->buttonProductsAdd->Name = L"buttonProductsAdd";
			this->buttonProductsAdd->Size = System::Drawing::Size(111, 28);
			this->buttonProductsAdd->TabIndex = 4;
			this->buttonProductsAdd->Text = L"��������";
			this->buttonProductsAdd->UseVisualStyleBackColor = true;
			this->buttonProductsAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonProductsAdd_Click);
			// 
			// dataProducts
			// 
			this->dataProducts->AllowUserToAddRows = false;
			this->dataProducts->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataProducts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataProducts->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->ProductsID,
					this->ProductsName, this->ProductsDimensions, this->ProductsWeight, this->ProductsMaterial, this->ProductsColor, this->ProductsWarrantyPeriod,
					this->TypeProduct, this->ProductPrice
			});
			this->dataProducts->Location = System::Drawing::Point(0, 0);
			this->dataProducts->Name = L"dataProducts";
			this->dataProducts->RowHeadersVisible = false;
			this->dataProducts->Size = System::Drawing::Size(927, 197);
			this->dataProducts->TabIndex = 0;
			// 
			// tabWarehouse
			// 
			this->tabWarehouse->Controls->Add(this->buttonWarehouseDel);
			this->tabWarehouse->Controls->Add(this->buttonWarehouseAdd);
			this->tabWarehouse->Controls->Add(this->dataWarehouse);
			this->tabWarehouse->Location = System::Drawing::Point(4, 22);
			this->tabWarehouse->Name = L"tabWarehouse";
			this->tabWarehouse->Padding = System::Windows::Forms::Padding(3);
			this->tabWarehouse->Size = System::Drawing::Size(927, 234);
			this->tabWarehouse->TabIndex = 1;
			this->tabWarehouse->Text = L"�����";
			this->tabWarehouse->UseVisualStyleBackColor = true;
			// 
			// buttonWarehouseDel
			// 
			this->buttonWarehouseDel->Location = System::Drawing::Point(479, 203);
			this->buttonWarehouseDel->Name = L"buttonWarehouseDel";
			this->buttonWarehouseDel->Size = System::Drawing::Size(111, 28);
			this->buttonWarehouseDel->TabIndex = 4;
			this->buttonWarehouseDel->Text = L"�������";
			this->buttonWarehouseDel->UseVisualStyleBackColor = true;
			this->buttonWarehouseDel->Click += gcnew System::EventHandler(this, &MyForm::buttonWarehouseDel_Click);
			// 
			// buttonWarehouseAdd
			// 
			this->buttonWarehouseAdd->Location = System::Drawing::Point(239, 203);
			this->buttonWarehouseAdd->Name = L"buttonWarehouseAdd";
			this->buttonWarehouseAdd->Size = System::Drawing::Size(111, 28);
			this->buttonWarehouseAdd->TabIndex = 3;
			this->buttonWarehouseAdd->Text = L"��������";
			this->buttonWarehouseAdd->UseVisualStyleBackColor = true;
			this->buttonWarehouseAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonWarehouseAdd_Click);
			// 
			// dataWarehouse
			// 
			this->dataWarehouse->AllowUserToAddRows = false;
			this->dataWarehouse->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataWarehouse->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataWarehouse->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->WarehouseID,
					this->WarehouseProductID, this->WarehouseProductQuantity, this->WarehouseProductStatus, this->WarehousePrice
			});
			this->dataWarehouse->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataWarehouse->Location = System::Drawing::Point(0, 0);
			this->dataWarehouse->Name = L"dataWarehouse";
			this->dataWarehouse->RowHeadersVisible = false;
			this->dataWarehouse->Size = System::Drawing::Size(927, 189);
			this->dataWarehouse->TabIndex = 0;
			// 
			// WarehouseID
			// 
			this->WarehouseID->DataPropertyName = L"ID";
			this->WarehouseID->HeaderText = L"ID";
			this->WarehouseID->Name = L"WarehouseID";
			// 
			// WarehouseProductID
			// 
			this->WarehouseProductID->DataPropertyName = L"ProductObject";
			this->WarehouseProductID->HeaderText = L"ID �������";
			this->WarehouseProductID->Name = L"WarehouseProductID";
			// 
			// WarehouseProductQuantity
			// 
			this->WarehouseProductQuantity->DataPropertyName = L"Quantity";
			this->WarehouseProductQuantity->HeaderText = L"���������� �������";
			this->WarehouseProductQuantity->Name = L"WarehouseProductQuantity";
			// 
			// WarehouseProductStatus
			// 
			this->WarehouseProductStatus->DataPropertyName = L"Status";
			this->WarehouseProductStatus->HeaderText = L"������";
			this->WarehouseProductStatus->Name = L"WarehouseProductStatus";
			// 
			// WarehousePrice
			// 
			this->WarehousePrice->DataPropertyName = L"Price";
			this->WarehousePrice->HeaderText = L"����� ���������";
			this->WarehousePrice->Name = L"WarehousePrice";
			// 
			// tabOrder
			// 
			this->tabOrder->Controls->Add(this->buttonOrdersDel);
			this->tabOrder->Controls->Add(this->buttonOrdersAdd);
			this->tabOrder->Controls->Add(this->dataOrders);
			this->tabOrder->Location = System::Drawing::Point(4, 22);
			this->tabOrder->Name = L"tabOrder";
			this->tabOrder->Padding = System::Windows::Forms::Padding(3);
			this->tabOrder->Size = System::Drawing::Size(927, 234);
			this->tabOrder->TabIndex = 0;
			this->tabOrder->Text = L"������";
			this->tabOrder->UseVisualStyleBackColor = true;
			// 
			// buttonOrdersDel
			// 
			this->buttonOrdersDel->Location = System::Drawing::Point(547, 206);
			this->buttonOrdersDel->Name = L"buttonOrdersDel";
			this->buttonOrdersDel->Size = System::Drawing::Size(111, 28);
			this->buttonOrdersDel->TabIndex = 3;
			this->buttonOrdersDel->Text = L"�������";
			this->buttonOrdersDel->UseVisualStyleBackColor = true;
			this->buttonOrdersDel->Click += gcnew System::EventHandler(this, &MyForm::buttonOrdersDel_Click);
			// 
			// buttonOrdersAdd
			// 
			this->buttonOrdersAdd->Location = System::Drawing::Point(289, 206);
			this->buttonOrdersAdd->Name = L"buttonOrdersAdd";
			this->buttonOrdersAdd->Size = System::Drawing::Size(111, 28);
			this->buttonOrdersAdd->TabIndex = 2;
			this->buttonOrdersAdd->Text = L"��������";
			this->buttonOrdersAdd->UseVisualStyleBackColor = true;
			this->buttonOrdersAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonOrdersAdd_Click);
			// 
			// dataOrders
			// 
			this->dataOrders->AllowUserToAddRows = false;
			this->dataOrders->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataOrders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataOrders->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->OrdersID,
					this->OrdersCustomerID, this->OrdersProductID, this->OrdersCount, this->OrdersDate, this->OrdersPrice
			});
			this->dataOrders->Location = System::Drawing::Point(0, 0);
			this->dataOrders->Name = L"dataOrders";
			this->dataOrders->RowHeadersVisible = false;
			this->dataOrders->Size = System::Drawing::Size(927, 191);
			this->dataOrders->TabIndex = 0;
			// 
			// tab
			// 
			this->tab->Controls->Add(this->tabOrder);
			this->tab->Controls->Add(this->tabWarehouse);
			this->tab->Controls->Add(this->tabProducts);
			this->tab->Controls->Add(this->tabCustomers);
			this->tab->Location = System::Drawing::Point(0, 0);
			this->tab->Name = L"tab";
			this->tab->SelectedIndex = 0;
			this->tab->Size = System::Drawing::Size(935, 260);
			this->tab->TabIndex = 0;
			// 
			// CustomersID
			// 
			this->CustomersID->DataPropertyName = L"Id";
			this->CustomersID->HeaderText = L"ID";
			this->CustomersID->Name = L"CustomersID";
			this->CustomersID->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// CustomersName
			// 
			this->CustomersName->DataPropertyName = L"Name";
			this->CustomersName->HeaderText = L"��������";
			this->CustomersName->Name = L"CustomersName";
			// 
			// CustomersPhone
			// 
			this->CustomersPhone->DataPropertyName = L"Phone";
			this->CustomersPhone->HeaderText = L"�������";
			this->CustomersPhone->Name = L"CustomersPhone";
			// 
			// CustomersAddress
			// 
			this->CustomersAddress->DataPropertyName = L"Address";
			this->CustomersAddress->HeaderText = L"�����";
			this->CustomersAddress->Name = L"CustomersAddress";
			// 
			// CustomerType
			// 
			this->customerTypes = gcnew List<String^>();
			customerTypes->Add("�������������� ���������������");
			customerTypes->Add("���������� ����");
			customerTypes->Add("����������� ����");
			this->CustomerType->HeaderText = L"���";
			this->CustomerType->DataPropertyName = L"Type";
			this->CustomerType->DataSource = this->customerTypes;
			this->CustomerType->Name = L"CustomerType";
			// 
			// ProductsID
			// 
			this->ProductsID->DataPropertyName = L"ID";
			this->ProductsID->HeaderText = L"�������";
			this->ProductsID->Name = L"ProductsID";
			// 
			// ProductsName
			// 
			this->ProductsName->DataPropertyName = L"Name";
			this->ProductsName->HeaderText = L"��������";
			this->ProductsName->Name = L"ProductsName";
			// 
			// ProductsDimensions
			// 
			this->ProductsDimensions->DataPropertyName = L"Dimensions";
			this->ProductsDimensions->HeaderText = L"�������� (��)";
			this->ProductsDimensions->Name = L"ProductsDimensions";
			// 
			// ProductsWeight
			// 
			this->ProductsWeight->DataPropertyName = L"Weight";
			this->ProductsWeight->HeaderText = L"��� (��)";
			this->ProductsWeight->Name = L"ProductsWeight";
			// 
			// ProductsMaterial
			// 
			this->ProductsMaterial->DataPropertyName = L"Material";
			this->ProductsMaterial->HeaderText = L"��������";
			this->ProductsMaterial->Name = L"ProductsMaterial";
			// 
			// ProductsColor
			// 
			this->ProductsColor->DataPropertyName = L"Color";
			this->ProductsColor->HeaderText = L"����";
			this->ProductsColor->Name = L"ProductsColor";
			// 
			// ProductsWarrantyPeriod
			// 
			this->ProductsWarrantyPeriod->DataPropertyName = L"WarrantyPeriod";
			this->ProductsWarrantyPeriod->HeaderText = L"����������� ���� (���)";
			this->ProductsWarrantyPeriod->Name = L"ProductsWarrantyPeriod";
			// 
			// TypeProduct
			// 
			this->TypeProduct->HeaderText = L"���";
			this->TypeProduct->Name = L"TypeProduct";
			this->productTypes = gcnew List<String^>();
			productTypes->Add("�������� ������");
			productTypes->Add("������� ������");
			productTypes->Add("�������");
			productTypes->Add("��������");
			productTypes->Add("������� ������");
			this->TypeProduct->DataPropertyName = L"Type";
			this->TypeProduct->DataSource = this->productTypes;
			this->TypeProduct->Name = L"CustomerType";
			// 
			// ProductPrice
			// 
			this->ProductPrice->DataPropertyName = L"Price";
			this->ProductPrice->HeaderText = L"��������� �� ��";
			this->ProductPrice->Name = L"ProductPrice";
			// 
			// OrdersID
			// 
			this->OrdersID->DataPropertyName = L"ID";
			this->OrdersID->HeaderText = L"ID";
			this->OrdersID->Name = L"OrdersID";
			// 
			// OrdersCustomerID
			// 
			this->OrdersCustomerID->DataPropertyName = L"CustomerObject";
			this->OrdersCustomerID->HeaderText = L"ID ���������";
			this->OrdersCustomerID->Name = L"OrdersCustomerID";
			// 
			// OrdersProductID
			// 
			this->OrdersProductID->DataPropertyName = L"WarehouseProductObject";
			this->OrdersProductID->HeaderText = L"�������� �������";
			this->OrdersProductID->Name = L"OrdersProductID";
			this->OrdersProductID->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->OrdersProductID->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// OrdersCount
			// 
			this->OrdersCount->DataPropertyName = L"Quantity";
			this->OrdersCount->HeaderText = L"����������";
			this->OrdersCount->Name = L"OrdersCount";
			// 
			// OrdersDate
			// 
			this->OrdersDate->DataPropertyName = L"Date";
			this->OrdersDate->HeaderText = L"����";
			this->OrdersDate->Name = L"OrdersDate";
			// 
			// OrdersPrice
			// 
			this->OrdersPrice->DataPropertyName = L"Price";
			this->OrdersPrice->HeaderText = L"���������";
			this->OrdersPrice->Name = L"OrdersPrice";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 261);
			this->Controls->Add(this->tab);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabCustomers->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataCustomers))->EndInit();
			this->tabProducts->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataProducts))->EndInit();
			this->tabWarehouse->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataWarehouse))->EndInit();
			this->tabOrder->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataOrders))->EndInit();
			this->tab->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->dataCustomers->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::DataGridView_CellValidating);
		this->dataProducts->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::DataGridView_CellValidating);
		this->dataWarehouse->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::DataGridView_CellValidating);
		this->dataOrders->CellValidating += gcnew System::Windows::Forms::DataGridViewCellValidatingEventHandler(this, &MyForm::DataGridView_CellValidating);

		dataCustomers->AutoGenerateColumns = false;
		dataCustomers->DataSource = db::data->getCustomerSource();

		dataProducts->AutoGenerateColumns = false;
		dataProducts->DataSource = db::data->getProductSource();

		dataWarehouse->AutoGenerateColumns = false;
		dataWarehouse->DataSource = db::data->getWarehouseSource();
		WarehouseProductID->DataSource = db::data->getProductSource();
		WarehouseProductID->ValueMember = "thisProduct";
		WarehouseProductID->DisplayMember = "ID";

		dataOrders->AutoGenerateColumns = false;
		dataOrders->DataSource = db::data->getOrderSource();
		OrdersCustomerID->DataSource = db::data->getCustomerSource();
		OrdersCustomerID->ValueMember = "thisCustomer";
		OrdersCustomerID->DisplayMember = "ID";
		OrdersProductID->DataSource = db::data->getWarehouseSource();
		OrdersProductID->ValueMember = "thisWarehouseProduct";
		OrdersProductID->DisplayMember = "thisWarehouseProductID";


	}
//�������� ���������� ������� ���������
private: System::Void DataGridView_CellValidating(System::Object^ sender, System::Windows::Forms::DataGridViewCellValidatingEventArgs^ e) {
	DataGridView^ dataGridView = (DataGridView^)sender;

	try {
		if (e->RowIndex < 0 || e->RowIndex >= dataGridView->RowCount || e->ColumnIndex < 0 || e->ColumnIndex >= dataGridView->ColumnCount) {
			e->Cancel = true;
			return;
		}

		DataGridViewCell^ cell = dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex];
		String^ newValue = e->FormattedValue->ToString();

		if (String::IsNullOrEmpty(newValue)) {
			throw gcnew Exception("���� �� ����� ���� ������");
		}

		if (cell->ValueType->ToString() == "System.Int32") {
			Int32 x = Convert::ToInt32(newValue);
			if (x < 0) {
				throw gcnew Exception("�������� �� ����� ���� �������������");
			}
		}
		else if (cell->ValueType->ToString() == "System.Decimal") {
			Decimal x = Convert::ToDecimal(newValue);
			if (x < 0) {
				throw gcnew Exception("�������� �� ����� ���� �������������");
			}
		}
		else if (cell->ValueType->ToString() == "System.DateTime") {
			DateTime x = Convert::ToDateTime(newValue);
			if (x > DateTime::Now) {
				throw gcnew Exception("���� �� ����� ���� � �������");
			}
		}

		String^ columnName = dataGridView->Columns[e->ColumnIndex]->Name;

		if (dataGridView == this->dataCustomers) {
			if (columnName == "CustomersPhone") {
				String^ phonePattern =
					"^(\\+\\d{1,3}[-\\s]?)?(\\(\\d{3}\\)|\\d{3})[-\\s]?\\d{3}[-\\s]?\\d{2}[-\\s]?\\d{2}$";
				if (!System::Text::RegularExpressions::Regex::IsMatch(newValue, phonePattern)) {
					throw gcnew Exception(
						"������� ������ ���� � ����� �� ��������:\n"
						"+X-XXX-XXX-XX-XX, +X (XXX) XXX-XX-XX, XXX-XXX-XX-XX, (XXX) XXX-XX-XX, XXXXXXXXXXX"
					);
				}
			}
			else if (columnName == "CustomersAddress") {
				String^ addressPattern =
					"^[A-Za-z�-��-�0-9\\s\\-\\.]+,\\s*\\d+[A-Za-z�-��-�]?,\\s*[A-Za-z�-��-�\\s\\-\\.]+,[A-Za-z0-9\\s\\-]{3,10},\\s*[A-Za-z�-��-�\\s\\-\\.]+$";
				if (!System::Text::RegularExpressions::Regex::IsMatch(newValue, addressPattern)) {
					throw gcnew Exception(
						"����� ������ ���� � �������:\n"
						"�����, ����� ����, �����, ������, ������\n"
						"������: ��. ������, 12�, ������, 123456, ������"
					);
				}
			}
		}
		else if (dataGridView == this->dataProducts) {
			if (columnName == "ProductsWeight") {
				Decimal weight = Convert::ToDecimal(newValue);
				if (weight <= 0) {
					throw gcnew Exception("��� ������� ������ ���� ������������� ������");
				}
			}
			else if (columnName == "ProductsDimensions") {
				String^ dimensionsPattern = "^\\d+(\\s*[x,]\\s*|\\s+)\\d+(\\s*[x,]\\s*|\\s+)\\d+$";
				if (!System::Text::RegularExpressions::Regex::IsMatch(newValue, dimensionsPattern)) {
					throw gcnew Exception(
						"�������� ������ ���� � �������: '����� x ������ x ������' ��� '����� ������ ������'\n"
						"������: 120x60x80 ��� 120 60 80"
					);
				}

				array<Char>^ separators = { 'x', ',', ' ' };
				array<String^>^ dimensions = newValue->Split(separators, StringSplitOptions::RemoveEmptyEntries);

				if (dimensions->Length != 3) {
					throw gcnew Exception("�������� ������ �������� �� ���� �����.");
				}

				Decimal length = Convert::ToDecimal(dimensions[0]);
				Decimal width = Convert::ToDecimal(dimensions[1]);
				Decimal height = Convert::ToDecimal(dimensions[2]);

				if (length <= 0 || width <= 0 || height <= 0) {
					throw gcnew Exception("�������� ������ ���� �������������� �������.");
				}
			}
		}
		else if (columnName == "WarehouseProductID") {
			if (e->RowIndex < 0 || e->RowIndex >= dataGridView->RowCount) {
				e->Cancel = true;
				return;
			}

			Warehouse^ warehouse = (Warehouse^)dataGridView->Rows[e->RowIndex]->DataBoundItem;

			Int32 newProductId = Convert::ToInt32(newValue);
			Product^ newProduct = nullptr;

			for each (Product ^ product in db::data->getProductSource()) {
				if (product->ID == newProductId) {
					newProduct = product;
					break;
				}
			}

			if (newProduct != nullptr) {
				warehouse->ProductObject = newProduct;
			}
			else {
				MessageBox::Show(
					"����� � ��������� ID �� ������ � ������ �������.",
					"������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				e->Cancel = true;
				return;
			}

			dataOrders->DataSource = nullptr;
			dataOrders->DataSource = db::data->getOrderSource();
			dataOrders->Refresh();

			dataGridView->Refresh();
		}
		else if (columnName == "WarehouseProductQuantity") {
			if (e->RowIndex < 0 || e->RowIndex >= dataGridView->RowCount) {
				e->Cancel = true;
				return;
			}

			Warehouse^ warehouse = (Warehouse^)dataGridView->Rows[e->RowIndex]->DataBoundItem;

			Int32 newQuantity = Convert::ToInt32(newValue);

			if (newQuantity < 0) {
				MessageBox::Show(
					"���������� ������� �� ����� ���� �������������.",
					"������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				e->Cancel = true;
				return;
			}

			warehouse->Quantity = newQuantity;

			if (newQuantity > 0) {
				warehouse->Status = "� �������";
			}
			else {
				warehouse->Status = "��� � �������";
			}

			if (warehouse->ProductObject != nullptr) {
				warehouse->Price = newQuantity * warehouse->ProductObject->Price;
			}
			else {
				warehouse->Price = 0;
			}

			dataGridView->Refresh();

			db::data->Save();
		}
		else if (dataGridView == this->dataOrders) {
			if (columnName == "OrdersCount") {
				Int32 count = Convert::ToInt32(newValue);
				if (count <= 0) {
					throw gcnew Exception("���������� ������� ������ ���� ������������� ������");
				}

				Order^ order = (Order^)dataGridView->Rows[e->RowIndex]->DataBoundItem;

				if (order->WarehouseProductObject == nullptr) {
					throw gcnew Exception("����� � ������ �� ������.");
				}

				Int32 warehouseQuantity = db::data->GetProductQuantity(order->WarehouseProductObject->ID);

				if (count > warehouseQuantity + order->Quantity) {
					throw gcnew Exception("���������� ������ � ������ ��������� ��������� ���������� �� ������");
				}

				Int32 oldQuantity = order->Quantity;

				db::data->UpdateWarehouseQuantity(order->WarehouseProductObject->ID, warehouseQuantity + oldQuantity - count);

				order->Quantity = count;

				if (order->Quantity >= 10) {
					MessageBox::Show(
						"��������� ������ 10% (������� ��������).",
						"������",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information
					);
				}
				order->CalculatePrice();
				dataGridView->Refresh();
			}
		}
		db::data->Save();
	}
	catch (FormatException^) {
		MessageBox::Show("�������� ������ ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		e->Cancel = true;
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		e->Cancel = true;
	}
}
	//��������������� ����� ��� �������� ����� �� DataGridView
void DeleteRow(DataGridView^ dataGridView, System::Collections::IList^ dataSource) {
	try {
		// ���������, ������� �� ���� �� ���� ������
		if (dataGridView->SelectedCells->Count == 0) {
			MessageBox::Show("�� ������� �� ���� ������ ��� �������� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// �������� ������ ������ �� ������ ��������� ������
		int selectedRowIndex = dataGridView->SelectedCells[0]->RowIndex;
		if (selectedRowIndex < 0 || selectedRowIndex >= dataSource->Count) {
			MessageBox::Show("������������ ������ ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// �������� ������ ��� ��������
		Object^ itemToDelete = dataSource[selectedRowIndex];
		String^ message = "������� ������.";
		String^ title = "��������";

		// ��������� �������� � ����������� �� ���� �������
		if (itemToDelete->GetType() == Order::typeid) {
			// �������� ������
			Order^ orderToDelete = (Order^)itemToDelete;

			// ��������������� ���������� ������ �� ������
			if (orderToDelete->WarehouseProductObject != nullptr) {
				Int32 productId = orderToDelete->WarehouseProductObject->ID;
				Int32 currentQuantity = db::data->GetProductQuantity(productId);
				Int32 newQuantity = currentQuantity + orderToDelete->Quantity;
				db::data->UpdateWarehouseQuantity(productId, newQuantity);
			}

			// ������� ����� �� ������
			db::data->getOrderSource()->Remove(orderToDelete);
			message = "����� �" + orderToDelete->ID + " ������.";
			title = "�������� ������";
		}
		else if (itemToDelete->GetType() == Customer::typeid) {
			// �������� ������� � ���� ��� �������
			Customer^ customerToDelete = (Customer^)itemToDelete;
			db::data->DeleteOrdersByCustomerID(customerToDelete->ID);
			message = "�������� '" + customerToDelete->Name + "' ������, � ����� ��� ��� ������.";
			title = "�������� ���������";
		}
		else if (itemToDelete->GetType() == Product::typeid) {
			// �������� �������� � ���� ��������� ������� � ������� �� ������
			Product^ productToDelete = (Product^)itemToDelete;
			db::data->DeleteOrdersByProductID(productToDelete->ID);
			db::data->DeleteWarehouseByProductID(productToDelete->ID);
			message = "����� '" + productToDelete->Name + "' ������ �� �������, ������� � ������.";
			title = "�������� ������";
		}
		else if (itemToDelete->GetType() == Warehouse::typeid) {
			// �������� ������ �� ������ � ���� ��������� �������
			Warehouse^ warehouseToDelete = (Warehouse^)itemToDelete;
			if (warehouseToDelete->ProductObject != nullptr) {
				db::data->DeleteOrdersByProductID(warehouseToDelete->ProductObject->ID);
				message = "����� '" + warehouseToDelete->ProductObject->Name + "' ������ �� ������ � �� �������.";
				title = "�������� �� ������";
			}
			else {
				MessageBox::Show("����� �� ������ ��� ��� ������ �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
		}

		// ������� ������ �� ��������� ������
		dataSource->RemoveAt(selectedRowIndex);

		// ��������� DataGridView
		dataGridView->DataSource = nullptr;
		dataGridView->DataSource = dataSource;

		// ��������� ������ DataGridView, ���� ��� ����������
		if (itemToDelete->GetType() == Customer::typeid || itemToDelete->GetType() == Product::typeid || itemToDelete->GetType() == Warehouse::typeid) {
			dataOrders->DataSource = nullptr;
			dataOrders->DataSource = db::data->getOrderSource();

			if (itemToDelete->GetType() == Product::typeid || itemToDelete->GetType() == Warehouse::typeid) {
				dataWarehouse->DataSource = nullptr;
				dataWarehouse->DataSource = db::data->getWarehouseSource();

				if (itemToDelete->GetType() == Product::typeid) {
					dataProducts->DataSource = nullptr;
					dataProducts->DataSource = db::data->getProductSource();
				}
			}
		}

		// ���������� ��������� �� �������� ��������
		MessageBox::Show(message, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
		db::data->Save();
	}
	catch (ArgumentOutOfRangeException^ ex) {
		MessageBox::Show("������: ������������ ������ ������. " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch (Exception^ ex) {
		MessageBox::Show("������ ��� �������� ������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

	private:
		//����� ��� ����������� � ���������� ������
		void UpdateDataSourceAndSave(DataGridView^ dataGridView, System::Collections::IList^ dataSource) {
			try {
				dataGridView->DataSource = nullptr;
				dataGridView->DataSource = dataSource;
				db::data->Save();
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ���������� ������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		//����� �������� dataSource
		bool CheckDataAvailability(System::Collections::IList^ dataSource, String^ errorMessage) {
			if (dataSource == nullptr || dataSource->Count < 1) {
				MessageBox::Show(errorMessage, "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return false;
			}
			return true;
		}

		//������ ���������� ��������
		void AddCustomer(DataGridView^ dataGridView, System::Collections::IList^ dataSource, Customer^ newCustomer) {
			try {
				if (newCustomer == nullptr) {
					MessageBox::Show("���������� �������� ������� ���������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				db::data->addCustomer(newCustomer);
				UpdateDataSourceAndSave(dataGridView, dataSource);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ���������� ���������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		void AddProduct(DataGridView^ dataGridView, System::Collections::IList^ dataSource, Product^ newProduct) {
			try {
				if (newProduct == nullptr) {
					MessageBox::Show("���������� �������� ������ �������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				db::data->addProduct(newProduct);
				UpdateDataSourceAndSave(dataGridView, dataSource);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ���������� ��������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		void AddWarehouse(DataGridView^ dataGridView, System::Collections::IList^ dataSource, Warehouse^ newWarehouse) {
			try {
				if (newWarehouse == nullptr) {
					MessageBox::Show("���������� �������� ������ �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				db::data->addWarehouse(newWarehouse);
				UpdateDataSourceAndSave(dataGridView, dataSource);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ���������� ������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		void AddOrder(DataGridView^ dataGridView, System::Collections::IList^ dataSource, Order^ newOrder) {
			try {
				if (newOrder == nullptr) {
					MessageBox::Show("���������� �������� ������ �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				db::data->addOrder(newOrder);
				UpdateDataSourceAndSave(dataGridView, dataSource);
			}
			catch (Exception^ ex) {
				MessageBox::Show("������ ��� ���������� ������: " + ex->Message, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

private:
	//����������� ������� ������
	System::Void buttonCustomersAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		Customer^ newCustomer = gcnew Customer("����� ��������", "+7-999-999-99-99", "��. ������, 12�, ������, 123456, ������", "���������� ����");
		AddCustomer(dataCustomers, db::data->getCustomerSource(), newCustomer);
	}

	System::Void buttonCustomersDel_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteRow(dataCustomers, db::data->getCustomerSource());
	}

	System::Void buttonProductsAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		Product^ newProduct = gcnew Product("����� �������", "12 12 12", 23, "������", "����������", 12, 3000, "��������");
		AddProduct(dataProducts, db::data->getProductSource(), newProduct);
	}

	System::Void buttonProductsDel_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteRow(dataProducts, db::data->getProductSource());
	}

	System::Void buttonWarehouseAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!CheckDataAvailability(db::data->getProductSource(), "��������� ������ �������")) return;
		Warehouse^ newWarehouse = gcnew Warehouse(0, 10, "� �������");
		AddWarehouse(dataWarehouse, db::data->getWarehouseSource(), newWarehouse);
	}

	System::Void buttonWarehouseDel_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteRow(dataWarehouse, db::data->getWarehouseSource());
		UpdateDataSourceAndSave(dataOrders, db::data->getOrderSource());
	}

	System::Void buttonOrdersAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!CheckDataAvailability(db::data->getProductSource(), "��������� ������ �������")) return;
		if (!CheckDataAvailability(db::data->getCustomerSource(), "��������� ������ ����������")) return;
		if (!CheckDataAvailability(db::data->getWarehouseSource(), "��� ��������� ������� �� ������")) return;

		Order^ newOrder = gcnew Order(0, 0, 1, DateTime::Now);
		AddOrder(dataOrders, db::data->getOrderSource(), newOrder);
		if (newOrder->WarehouseProductObject != nullptr) {
			newOrder->UpdateWarehouseQuantity();
		}
		db::data->Save();
	}

	System::Void buttonOrdersDel_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteRow(dataOrders, db::data->getOrderSource());
	}
};
}
