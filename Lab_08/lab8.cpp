#define MYSQLPP_MYSQL_HEADERS_BURIED
#include <mysql++/mysql++.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

void interactive() {
    // Connect to database with: database, server, userID, password
    mysqlpp::Connection myDB("cse278", "localhost", "cse278", "S3rul3z");
    
    // Variable to build query string
    std::string qString;
    
    
    // Get user input for query
    while(/* reading in lines  &&  some conditon */ false) { 
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
}

std::string generateLoadQuery(std::string& line){
    // Create base insert query string

    // Split file on commas
    vector<string> splitLine;
    boost::split(splitLine, line, boost::is_any_of(","));
    
    // Start building query from split files (table name)

    // Strings to hold attributes and values

    // Build attribute and value strings

    // Form full query string
    return "";
}

void loadData(std::string& path){
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
        // Create mysql++ query
        mysqlpp::Query query = myDB.query();
        query << line; //gets input
        query.parse(); //cleans up query
        lineCounter++;
        
        try{
            // Check query is correct
            //Execute Query
            mysqlpp::StoreQueryResult result = query.store();
            
            std::cout << "Data Line " << lineCounter << " Loaded.";   
        } catch(mysqlpp::BadQuery e) {
            std::cerr << "Query: " << line <<std::endl;
            std::cerr << "Query is not correct SQL syntax" <<std::endl;
        }
    }
    
}

int main(int argc, char *argv[]) {
    // Ensure arguments are specified
    if( argc >= 2){
        std::cerr << "Must input correct number of arguments." <<std::endl;
        return 1;
    }

    std::string option = argv[1];
    std::string filePath;
    
    if (argc >= 3) filePath = argv[2]; 
    
    if(option.at(0) == '-' && option.at(1) == 'I') {
        interactive();     // calls interactive argument
    } 
    else if (argc >= 3 && option.at(0) == '-' && option.at(1) == 'L') {
        loadData(filePath);  // calls loads data argument
    }
    else {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    // All done
    return 0; 
}
