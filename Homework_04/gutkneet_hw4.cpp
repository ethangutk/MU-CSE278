#define MYSQLPP_MYSQL_HEADERS_BURIED

#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

//Interactive mode: (-I)
void interactive() {
    std::cout << "Running Interactive";
    
    /*
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    
    // Variable to build query string
    std::string qString;
    
    
    // Get user input for query
    while() { 
        // Create a query
        mysqlpp::Query query = myDB.query();
        query << std::cin; //gets input
        query.parse(); //cleans up query
        
        try{
            // Check query is correct
            query.parse();
            
            // Execute query
            // Results is a 2D vector of mysqlpp::String objects.
            mysqlpp::StoreQueryResult result = query.store();
            
            // Print the results.
            std::cout << "-----Query Result-----" << std::endl;
            for (size_t row = 0; row < result.size(); row++) {  // loop goes every row
                std::string outputLine = "| ";
                for (size_t column = 0; column < result[row].size(); column++) {  // loop goes through every column
                    outputLine = outputLine + result[row][column].c_str() + " | "; 
                }
                std::cout << outputLine << “\n”;
            }
            std::cout << "------End Result------" << std::endl;
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << qString <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
    */
    
}



 // Load mode: (-L)
void load(std::string path) {
    
    // Open file stream
    std::ifstream input(path);
    
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");

    // Some necessary variables for the file IO
    std::string line;
    int lineCounter = 0;
    
    // Read file line-by-line
    while (getline(input, line)) {
        
        // Create query string from current line
        std::vector<std::string> strVector;
        boost::split(strVector, line, boost::is_any_of(","));
        
        // Create mysql++ query
        std::string headings = strVector[1].substr(0, strVector[1].find(":"))
            + ", " + strVector[2].substr(0, strVector[2].find(":"))
            + ", " + strVector[3].substr(0, strVector[3].find(":"))
            + ", " + strVector[4].substr(0, strVector[4].find(":"))
            + ", " + strVector[5].substr(0, strVector[5].find(":"));
        
        std::string values = strVector[1].substr(strVector[1].find(":") + 1)
            + ", " + strVector[2].substr(strVector[2].find(":") + 1)
            + ", " + strVector[3].substr(strVector[3].find(":") + 1)
            + ", " + strVector[4].substr(strVector[4].find(":") + 1)
            + ", " + strVector[5].substr(strVector[5].find(":") + 1);
        
        std::string inputQuery = "INSERT INTO " + strVector[0] + " (" + headings + ") VALUES (" + values + ");";
        
        mysqlpp::Query query = myDB.query();
        query << inputQuery;
        
        //query.parse(); //cleans up query
        
        try{
            //Check query is correct
            //query.parse();
            
            std::cout << query << "\n";
            
            //Execute Query
           mysqlpp::StoreQueryResult result = query.store();
            
           std::cout << "Data Line " << lineCounter << " Loaded.";   
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << line <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
        lineCounter++;
    }
}



 // Write mode: (-W)
void write(std::string path) {
    // Open file stream
    std::ifstream input(path);
    
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");

    // Some necessary variables for the file IO
    std::string line;
    
    std::cout << "------Query Result------\n";
    // Read file line-by-line
    while (getline(input, line)) {
        // Create mysql++ query
        mysqlpp::Query query = myDB.query();
        query << line;
        try{
            //Check query is correct
            query.parse();
            
            //Execute Query
            mysqlpp::StoreQueryResult result = query.store();
            
                // Result is in 2-D vector of mysqlpp::String objects
            for (int row = 0; row < result.size(); row++) {
                std::cout << "| ";
                for (int column = 0; column < result[row].size(); column++) {
                    std::cout << result[row][column].c_str() << " | ";
                }
                std::cout << "\n";
            } // done printing results
 
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << line <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
    std::cout << "------End Result------\n";
}



 // Drop mode: (-D)
void drop(std::string tableName) {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection database("cse278", "localhost", "cse278", "S3rul3z");
    mysqlpp::Query query = database.query();
    query << "DROP TABLE " << tableName << ";";
    query.parse(); 

    try{
        mysqlpp::StoreQueryResult result = query.store();
        std::cout << "Table " << tableName <<" Dropped";

    } catch(mysqlpp::BadQuery e) {
        std::cerr << "Query: " << query <<std::endl;
        std::cerr << "Query is not correct SQL syntax" <<std::endl;
    }
}



 // Create mode: (-C)
void create() {
    std::cout << "Running Create";
    
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
 
}



//Main Method
int main(int argc, char* argv[]) {
    // Check file input
    if (argc == 2 && strcmp(argv[1], "-I") == 0) {
        //interactive();

    } else if (argc == 3 && strcmp(argv[1], "-L") == 0) {
        load(argv[2]);

    } else if (argc == 3 && strcmp(argv[1], "-W") == 0) {
        write(argv[2]);

    } else if (argc == 3 && strcmp(argv[1], "-D") == 0) {
        drop(argv[2]);

    } else if (argc == 3 && strcmp(argv[1], "-C") == 0) {
        //create();

    } else {
        std::cerr << "Input needs to be valid.\n";
        return 0;
    }
}

