#include "book.h"

void show_books() {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n>0)                   
		{
			cout << endl << "no more date" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book_id: " << res->getString("book_id") << endl 
				<< "book title: " << res->getString("title") << endl << "book author: " << res->getString("author") << endl 
				<< "book price: " << res->getString("price") << endl << "book quantity: " << res->getString("quantity") << endl << endl;
		}

		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{	 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return ;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void show_orders() {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM orders LIMIT 5  OFFSET ? ");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n>0)                      
		{
			cout << endl << "no more data" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM orders LIMIT 5  OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "order id: " << res->getString("order_id") << endl 
				<< "provider id: " << res->getString("provider_id") << endl << "book id: " << res->getString("book_id") << endl
				<< "quantity: " << res->getString("quantity") << "order date: " << res->getString("order_date") << endl
				<< "is arrived: " << res->getString("is_arrived") << endl << endl;
		}
		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{	 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{		 
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}

void show_customers() {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM customer LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                         
		{
			cout << endl << "no more data" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM customer LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "costumer: " << "id: " << res->getString("customer_id") << endl << "customer first name: " << res->getString("first_name") << endl
				<< "customer last name:" << res->getString("last_name") << endl << "customer phone: " << res->getString("phone")
				<< "join date: " << res->getString("join_date") << "Bday date: " << res->getString("bday") << endl << endl;
		}
		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void show_providers() {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM providers LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM providers LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "provider id: " << res->getString("provider_id") << endl 
				<< "provider name: " << res->getString("name") << endl << endl;
		}

		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void show_purchases_between(const string &date1, const string &date2) {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase WHERE purchase_date BETWEEN ? AND ? LIMIT 5  OFFSET ?");
		pstmt->setString(1, date1);
		pstmt->setString(2, date2);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                          
		{
			cout << endl << "no more data" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM purchase WHERE purchase_date BETWEEN ? AND ? LIMIT 5  OFFSET ?");
			pstmt->setString(1, date1);
			pstmt->setString(2, date2);
			pstmt->setInt(3, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout<< "purchase id: " << res->getString("purchase_id") << endl
				<< "customer id: " << res->getString("customer_id") << endl
				<< "salesman id: " << res->getString("salesman_id") << endl 
				<< "purchase date: " << res->getString("purchase_date") << endl << endl;
		}

		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{	 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				 
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}

void books_in_sale() {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM sales WHERE on_sale=1 LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n>0)                    
		{
			cout << endl << "no more data" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM sales WHERE on_sale=1 LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book_id: " << res->getString("book_id") << endl
				<< "sale price: " << res->getString("sale_price") << endl << endl;	
		}
		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{ 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{	 
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void if_in_stock(const string book_title) {
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book WHERE title = ? AND quantity > 0");
	pstmt->setString(1, book_title);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "Book inventory ran out" << endl << endl;
	}
	else {
		cout << "book is in stock" << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void book_providers(const string &book_id) {
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM provider_stock WHERE book_id= ? LIMIT 5 OFFSET ?");
		pstmt->setString(1, book_id);
		pstmt->setInt(2, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n>0)                   
		{
			cout << endl << "no more data" << endl << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM provider_stock WHERE book_id= ? LIMIT 5 OFFSET ?");
			pstmt->setString(1, book_id);
			pstmt->setInt(2, n);
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "provider id: " << res->getString("provider_id") << endl << endl;
		}
		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{				 
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

void book_copies_since(const string &book_id, const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(pd.quantity) FROM purchase as p, purchase_details as pd WHERE p.purchase_id = pd.purchase_id AND pd.book_id = ? and p.purchase_date >= ?");
	pstmt->setString(1, book_id);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "There is no purchases of book" << book_id<< "since" <<date << endl << endl;
	}
	else {
		cout << "book "<< book_id << " sold "<< res->getString("SUM(pd.quantity)") <<" copies since "<< date << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void customer_purchases_since(const string &customer_id, const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(pd.quantity) FROM purchase AS p, purchase_details AS pd WHERE p.purchase_id = pd.purchase_id AND p.customer_id = ? AND p.purchase_date >= ? ");
	pstmt->setString(1, customer_id);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "customer : " << customer_id << "has no purchases since : " << date<< endl << endl;
	}
	else {
		cout << "customer: " << customer_id << " purchased " << res->getString("SUM(pd.quantity)") << " books since " << date << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;

}

void most_popular_customer_since(const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement(" SELECT c.customer_id, c.purchase_date FROM (SELECT p.purchase_date, p.customer_id, SUM(pd.quantity) SumQuan FROM purchase AS p JOIN purchase_details AS pd ON pd.purchase_id = p.purchase_id GROUP BY p.customer_id) AS c WHERE c.purchase_date >= ? ORDER BY SumQuan DESC LIMIT 1");

	pstmt->setString(1, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "0 customers since : " <<date << endl << endl;
	}
	else {
		cout << "most popular costumer is: " << "id: " << res->getString("customer_id") << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;

}

void most_popular_provider_since(const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement(" SELECT o.provider_id, SUM(o.quantity) SumQUan FROM orders AS o WHERE o.order_date >= ? GROUP BY o.provider_id ORDER BY SumQuan DESC LIMIT 1" );

	pstmt->setString(1, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "0 providers since : "<<date << endl << endl;
	}
	else {
		cout << "most popular provider is provider: " << res->getString("provider_id") << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;

}

void sum_orders_between(const string &date1, const string &date2)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT SUM(o.quantity) SumQUan FROM orders AS o WHERE o.order_date BETWEEN ? AND ? ");
	pstmt->setString(1, date1);
	pstmt->setString(2, date2);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "no orders between "<< date1<<  "and" << date2 << endl <<endl;
	}
	else {
		cout << "  Sum of orders:" << res->getString("SumQUan") << " between " << date1 << "and" << date2 << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;

}

void count_orders_becomes_purchase_between(const string &date1, const string &date2)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(is_arrived) FROM orders WHERE is_arrived = 1 AND order_date BETWEEN ? AND ?" );
	pstmt->setString(1, date1);
	pstmt->setString(2, date2);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "no orders become purchases between " << date1 << "and" << date2 << endl << endl;
	}
	else {
		cout << " Count orders that became purchases" << res->getString("COUNT(is_arrived)") << " between " << date1 << "and" << date2 << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void total_discount_customer_recived_since(const string &customer_id, const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT p.customer_id ,SUM(j.price) AS discount FROM purchase AS p JOIN( SELECT pd.quantity, pd.purchase_id, SUM(d.discount * pd.quantity) AS price FROM purchase_details AS pd JOIN( SELECT b.book_id, (b.price - s.sale_price) AS discount FROM book AS b JOIN sales AS s ON b.book_id = s.book_id AND s.on_sale = 1) AS d ON pd.book_id = d.book_id GROUP BY pd.purchase_id) AS j WHERE p.purchase_id = j.purchase_id AND p.customer_id = ? AND p.purchase_date >= ? GROUP BY p.customer_id");
	pstmt->setString(1, customer_id);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "Customer :  " <<customer_id << " does not get discount since : "<< date << endl << endl;
	}
	else {
		cout << " Customer" << customer_id << " get a discount of " << res->getString("discount") << " since " << date << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void total_revenue_in_quarter()
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT QUARTER(p.purchase_date) AS Q, SUM(j.sum_purchase) FROM purchase AS p JOIN (SELECT pd.purchase_id, SUM(pd.quantity * b.price) AS sum_purchase FROM purchase_details AS pd, book AS b WHERE pd.book_id = b.book_id GROUP BY pd.purchase_id) AS j WHERE p.purchase_id = j.purchase_id GROUP BY Q");
	ResultSet *res = pstmt->executeQuery();
	while (res->next())
	{
		cout << "quarter number: " << res->getString("Q") << endl
			<< "Total income: " << res->getString("SUM(j.sum_purchase)") << endl << endl;			
	}
	delete res;
	delete con;
	delete pstmt;
}

void joined_customers_since(const string &date)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT COUNT(first_name) FROM customer WHERE join_date >= ? ");
	pstmt->setString(1, date);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "There is no new customers since :  " << date << endl << endl;
	}
	else {
		cout << " Count of customers have joined:" << res->getString("COUNT(first_name)") << " since " << date << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void amount_orders_from_provider(const string &provider_id, const string &date1, const string &date2)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT o.provider_id, SUM(t.sumAll) AS total FROM orders AS o JOIN(SELECT o.provider_id, o.book_id, o.quantity, o.order_date, ps.provider_price, (o.quantity * ps.provider_price) AS sumAll FROM orders AS o, provider_stock AS ps WHERE ps.provider_id = o.provider_id ) AS t ON o.provider_id = t.provider_id WHERE t.order_date BETWEEN ? AND ? AND o.provider_id =? GROUP BY o.provider_id");
	pstmt->setString(1, date1);
	pstmt->setString(2, date2);
	pstmt->setString(3, provider_id);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "There is no orders from provider :  " << provider_id <<"between"<<date1<< "and"<< date2 << endl << endl;
	}
	else {
		cout << "total amount from provider : " << res->getString("provider_id") << " is " << res->getString("total") << " between " << date1 << " and " << date2 << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void amount_purchases_from_salesman(const string &salesman_id, const string &date1, const string &date2)
{
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT p.salesman_id , p.purchase_date, SUM(t.sumAll) AS total FROM purchase AS p JOIN( SELECT pd.quantity, pd.book_id, pd.purchase_id, (pd.quantity * b.price) AS sumAll, b.price FROM purchase_details AS pd JOIN book AS b ON b.book_id = pd.book_id) AS t ON p.purchase_id = t.purchase_id WHERE p.purchase_date BETWEEN ? AND ? AND p.salesman_id = ? GROUP BY p.salesman_id" );
	pstmt->setString(1, date1);
	pstmt->setString(2, date2);
	pstmt->setString(3, salesman_id);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "There is no purchases from salesman :  " << salesman_id << "between" << date1 << "and" << date2 << endl << endl;
	}
	else {
		cout << "total purchaeses from salesman : " << res->getString("salesman_id") << " is " << res->getString("total") << " between " << date1 << " and " << date2 << endl << endl;
	}
	delete res;
	delete con;
	delete pstmt;
}

void top_10_books_between(const string &date1, const string &date2)
{
	int n = 0;
	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT p.purchase_date, pd.book_id, pd.quantity, SUM(pd.quantity) SumQuan FROM purchase_details AS pd JOIN purchase AS p ON p.purchase_id = pd.purchase_id WHERE p.purchase_date BETWEEN ? AND ? GROUP BY pd.book_id ORDER BY SumQuan DESC LIMIT 10 OFFSET ?");
		pstmt->setString(1, date1);
		pstmt->setString(2, date2);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();
		if (!res->next() && n>0)                           
		{
			cout << endl << "no more data" << endl;
			n -= 5;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT pd.book_id, SUM(pd.quantity) SumQuan FROM purchase_details AS pd GROUP BY pd.book_id ORDER BY SumQuan DESC LIMIT 10 OFFSET ?");
			pstmt->setString(1, date1);
			pstmt->setString(2, date2);
			pstmt->setInt(3, n);			
			res = pstmt->executeQuery();
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book_id: " << res->getString("book_id") << endl
				<< " number of books: " << res->getString("SumQuan") << endl << endl;
		}

		cout << "1.next page" << endl << "2.previous page" << endl << "0 to continue" << endl << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{ 
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				n -= 5;
			}
			else
			{
				cout << endl << "no previous data" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

