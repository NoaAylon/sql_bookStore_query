#include "Database.h"

Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema("book_store");
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute(
				"CREATE DATABASE IF NOT EXISTS book_store");
			con->setSchema("book_store"); // switch database
			stmt->execute("CREATE TABLE IF NOT EXISTS customer ( "
				"customer_id int(11) NOT NULL,"
				"first_name varchar(20) NOT NULL,"
				"last_name varchar(20) NOT NULL,"
				"phone varchar(20) NOT NULL,"
				"join_date date NOT NULL,"
				"bday date NOT NULL,"
				"PRIMARY KEY(customer_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS book("
				"book_id int(11) NOT NULL,"
				"title varchar(30) NOT NULL,"
				"price int(11) NOT NULL,"
				"quantity int(11) NOT NULL,"
				"author varchar(20) NOT NULL,"
				"PRIMARY KEY(book_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS providers("
				"provider_id int(11) NOT NULL,"
				"name varchar(20) NOT NULL,"
				"PRIMARY KEY(provider_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS orders("
				"order_id int(11) NOT NULL,"
				"provider_id int(11) NOT NULL,"
				"book_id int(11) NOT NULL,"
				"quantity int(11) NOT NULL,"
				"order_date date NOT NULL,"
				"is_arrived tinyint(1) NOT NULL,"
				"PRIMARY KEY(order_id),"
				"FOREIGN KEY (provider_id) REFERENCES providers(provider_id),"
				"FOREIGN KEY (book_id) REFERENCES book(book_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS provider_stock("
				"provider_id int(11) NOT NULL,"
				"book_id int(11) NOT NULL,"
				"provider_price int(11) NOT NULL,"
				"FOREIGN KEY (book_id) REFERENCES book(book_id),"
				"FOREIGN KEY (provider_id) REFERENCES providers(provider_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS salesman("
				"salesman_id int(11) NOT NULL,"
				"name varchar(20) NOT NULL,"
				"PRIMARY KEY(salesman_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS sales ("
				"book_id int(11) NOT NULL,"
				"sale_price int(11) NOT NULL,"
				"on_sale tinyint(1),"
				"FOREIGN KEY (book_id) REFERENCES book(book_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS purchase("
				"purchase_id int (11) NOT NULL,"
				"customer_id int (11) NOT NULL,"
				"salesman_id int (11) NOT NULL,"
				"purchase_date date NOT NULL,"
				"PRIMARY KEY(purchase_id),"
				"FOREIGN KEY (customer_id) REFERENCES customer(customer_id),"
				"FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)"
				")");
			stmt->execute("CREATE TABLE IF NOT EXISTS purchase_details("
				"purchase_details_id int(11) NOT NULL,"
				"purchase_id int (11) NOT NULL,"
				"book_id int(11) NOT NULL,"
				"quantity int(11) NOT NULL,"
				"PRIMARY KEY(purchase_details_id),"
				"FOREIGN KEY (book_id) REFERENCES book(book_id),"
				"FOREIGN KEY (purchase_id) REFERENCES purchase(purchase_id)"
				")");

			stmt->execute("INSERT INTO book (book_id, title, price, quantity, author) VALUES"
				"(10, 'Partners', 109, 20, 'author10'),"
				"(11, 'Alegbra', 150, 20, 'author11'),"
				"(12, 'Magazine', 160, 20, 'author12'),"
				"(13, 'Climb', 100, 20, 'author13'),"
				"(14, 'compuerScience', 200, 20, 'author14'),"
				"(15, 'Math', 100, 20, 'author15'),"
				"(16, 'VOGUE', 60, 20, 'author16'),"
				"(17, 'parents', 10, 20, 'author17'),"
				"(18, 'US', 10, 20, 'author18'),"
				"(19, 'secret', 70, 20, 'author19'),"
				"(20, 'sqlBegginers', 78, 20, 'author20')");

			stmt->execute("INSERT INTO `salesman` (`salesman_id`, `name`) VALUES"
				"(400, 'Itay'),"
				"(401, 'Shira'),"
				"(402, 'Shahar'),"
				"(403, 'Liel'),"
				"(404, 'Shay'),"
				"(405, 'Matan'),"
				"(406, 'Yafa'),"
				"(407, 'Roy'),"
				"(408, 'Rami'),"
				"(409, 'Joy'),"
				"(410, 'Shir')");

			stmt->execute("INSERT INTO `customer` (`customer_id`, `first_name`, `last_name`, `phone`, `join_date`, `bday`) VALUES"
				"(300, 'Noy', 'Cohen', '050', '2018-07-22', '2018-01-22'),"
				"(301, 'Noam', 'Cohen', '051', '2010-07-22', '2018-02-22'),"
				"(302, 'Shaul', 'Cohen', '052', '2010-07-22', '2018-03-22'),"
				"(303, 'Noya', 'Cohen', '053', '2010-07-22', '2018-04-22'),"
				"(304, 'yosi', 'Cohen', '054', '2018-07-22', '2018-05-22'),"
				"(305, 'Naory', 'Cohen', '055', '2018-04-22', '2018-06-22'),"
				"(306, 'sahar', 'Cohen', '056', '2018-02-22', '2018-07-22'),"
				"(307, 'Eli', 'Cohen', '057', '2018-05-10', '2018-08-22'),"
				"(308, 'Noga', 'Cohen', '058', '2018-03-22', '2018-09-22'),"
				"(309, 'Orel', 'Cohen', '059', '2018-07-21', '2018-10-22'),"
				"(310, 'yoram', 'Cohen', '060', '2018-07-22', '2018-11-22'),"
				"(311, 'mika', 'dayan', '061', '2018-07-25', '2018-12-22')");

			stmt->execute("INSERT INTO `providers` (`provider_id`, `name`) VALUES"
				"(200, 'Haim'),"
				"(201, 'Yaakov'),"
				"(202, 'Shlomo'),"
				"(203, 'Tzion'),"
				"(204, 'Yuval'),"
				"(205, 'Kim'),"
				"(206, 'Amit'),"
				"(207, 'Moshe'),"
				"(208, 'Haim'),"
				"(209, 'Roberto'),"
				"(210, 'Shay'),"
				"(211, 'Yossi')");

			stmt->execute("INSERT INTO `provider_stock` (`provider_id`, `book_id`, `provider_price`) VALUES"
				"(207, 10, 80),"
				"(202, 10, 80),"
				"(210, 16, 55),"
				"(203, 15, 70),"
				"(208, 18, 8),"
				"(210, 14, 150),"
				"(209, 16, 55),"
				"(202, 11, 100),"
				"(204, 15, 70),"
				"(207, 13, 60)");

			stmt->execute("INSERT INTO `orders` (`order_id`, `provider_id`, `book_id`, `quantity`, `order_date`, `is_arrived`) VALUES"
				"(500, 201, 16, 3, '2018-07-17', 0),"
				"(501, 208, 17, 5, '2018-07-25', 0),"
				"(502, 205, 14, 6, '2018-07-18', 1),"
				"(503, 209, 16, 5, '2018-07-01', 0),"
				"(504, 200, 17, 1, '2018-07-12', 0),"
				"(505, 210, 11, 5, '2018-07-19', 0),"
				"(506, 203, 18, 8, '2018-07-22', 0),"
				"(507, 205, 14, 3, '2018-07-11', 1),"
				"(508, 211, 13, 1, '2018-07-17', 0),"
				"(509, 207, 11, 5, '2018-07-18', 0)");

			stmt->execute("INSERT INTO `purchase` (`purchase_id`, `customer_id`, `salesman_id`, `purchase_date`) VALUES"
				"(100, 302, 408, '2018-01-24'),"
				"(101, 304, 408, '2018-07-24'),"
				"(102, 303, 405, '2018-07-19'),"
				"(103, 308, 402, '2018-04-18'),"
				"(104, 302, 400, '2018-06-11'),"
				"(105, 304, 406, '2018-07-11'),"
				"(106, 307, 408, '2018-07-04'),"
				"(107, 310, 406, '2018-07-04'),"
				"(108, 305, 400, '2018-07-02'),"
				"(109, 305, 406, '2018-07-01'),"
				"(110, 300, 401, '2018-05-08'),"
				"(111, 311, 403, '2018-07-20'),"
				"(112, 309, 400, '2018-03-20')");

			stmt->execute("INSERT INTO `purchase_details` (`purchase_details_id`, `purchase_id`, `book_id`, `quantity`) VALUES"
				"(8, 100, 11, 1),"
				"(9, 101, 13, 14),"
				"(10, 106, 14, 1),"
				"(11, 104, 12, 1),"
				"(12, 102, 15, 1),"
				"(13, 107, 17, 1),"
				"(15, 105, 19, 1),"
				"(16, 109, 18, 1),"
				"(17, 108, 16, 1),"
				"(18, 103, 10, 1),"
				"(19, 110, 12, 3),"
				"(20, 100, 17, 2),"
				"(21, 111, 14, 6),"
				"(22, 112, 14, 3),"
				"(23, 104, 19, 2),"
				"(24, 105, 20, 1)");

			stmt->execute("INSERT INTO `sales` (`book_id`, `sale_price`, `on_sale`) VALUES"
				"(11, 100, 0),"
				"(13, 90, 1),"
				"(14, 100, 0),"
				"(12, 100, 1),"
				"(15, 68, 0),"
				"(17, 7, 1),"
				"(10, 99, 0),"
				"(19, 71, 1),"
				"(18, 6, 0),"
				"(16, 52, 0),"
				"(20, 70, 1)");

			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}
