// Copyright Ethan Gutknecht
#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
using namespace boost::asio::ip;
using namespace boost::asio;
using namespace std;

// Function to return date
std::string make_daytime_string() {
  char date[26];
  std::time_t now = std::time(0);
  return ctime_r(&now, date);
}

// thisCasts user input as to an int - if error then a message will be returned
int checkPort(std::string inputString) {
  int portNum;
    
  try {
    portNum = stoi(inputString);
  }
  catch (std::exception& e) {
    // Provide some error message and return 0   Must supply port number↲
      std::cout << "Must supply port number\n";
      return 0;
  }

  return portNum;
}


int main(int argc, char** argv) {
    boost::asio::io_service io_service;
    
    // Check user inputs for port number
    if (argc == 1) {
        std::cout << "Must supply port number\n";
        return 0;
    }
    
    // Validate input is numeric
    int portNumber = checkPort(argv[1]);
    if (portNumber == 0) return 0;
    
    // Check port number is valid
    if (portNumber <= 1024) {
        std::cout << "Cannot use privileged ports\n";
        return 0;
    }
    
    // Create the endpoint for the server
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), portNumber));
    
    // Create the socket (and any other necessary objects)
    tcp::socket socket(io_service);
    
    // Wait and listen for a client to connect
    acceptor.accept(socket);
    cout << "Listening on port " << acceptor.local_endpoint().port() << endl;
    
    // Prepare message to send back to client
    boost::system::error_code ignored_error;
    
    // Write the message for current time to the socket
    write(socket, boost::asio::buffer(make_daytime_string()), ignored_error);

    return 0;
}

