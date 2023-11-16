// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

// Build the Contract
contract MarksManagmtSys {
    // Create a structure for student details
    struct Student {
        int ID;
        string fName;
        string lName;
        int marks;
    }

    event Log(string func, address sender, uint value);

    address public owner;
    int public stdCount = 0;
    mapping(int => Student) public stdRecords;
    uint[] public data;

    modifier onlyOwner() {
        require(owner == msg.sender, "Only the owner can call this function");
        _;
    }

    constructor() {
        owner = msg.sender;
    }

    // Create a function to add the new records
    function addNewRecords(
        int _ID,
        string memory _fName,
        string memory _lName,
        int _marks
    ) public onlyOwner {
        // Increase the count by 1
        stdCount++;

        // Fetch the student details with the help of stdCount
        stdRecords[stdCount] = Student(_ID, _fName, _lName, _marks);
    }

    // Create a function to add bonus marks
    function bonusMarks(int _bonus) public onlyOwner {
        stdRecords[stdCount].marks += _bonus;
    }

    function percentage(uint k) public returns (uint[] memory) {
        data.push(k);
        return data;
    }

    fallback() external payable {
        emit Log("fallback", msg.sender, msg.value);
    }

    receive() external payable {
        emit Log("receive", msg.sender, msg.value);
    }
}
