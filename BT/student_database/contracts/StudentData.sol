// SPDX-License-Identifier: MIT
pragma solidity ^0.8.24;

contract StudentData {

    struct Student {
        uint256 rollNo;
        string name;
        string course;
    }

    Student[] private students;

    event StudentAdded(uint256 rollNo, string name, string course);
    event EtherReceived(address sender, uint256 amount);

    function addStudent(
        uint256 rollNo,
        string memory name,
        string memory course
    ) public {
        students.push(Student(rollNo, name, course));
        emit StudentAdded(rollNo, name, course);
    }

    function getStudent(uint256 index)
        public
        view
        returns (uint256, string memory, string memory)
    {
        require(index < students.length, "Invalid student index");

        Student memory s = students[index];
        return (s.rollNo, s.name, s.course);
    }

    function studentCount() public view returns (uint256) {
        return students.length;
    }

    fallback() external payable {
        emit EtherReceived(msg.sender, msg.value);
    }
}

//npx hardhat compile