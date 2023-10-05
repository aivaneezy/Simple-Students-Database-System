#include <iostream>
#include <string>
#include <ctime>
#include <vector>

// ************STUDENT DATABASE SYSTEM *********************
enum USER_INPUT
{
	ADD = 1, 
	LIST = 2,
	MODIFY = 3,
	DELETE = 4,
	EXIT = 5
};

enum MOD_STUDENT
{
	FIRST_NAME = 1,
	LAST_NAME = 2,
	COURSE = 3
};
namespace Students
{
	class c_students
	{
	public:
	void add()
	{
		std::cout << "Enter First Name: " << std::endl;
		std::getline(std::cin, student_FirstName);
		
		std:: cout << "Enter Last Name: " << std::endl;
		std::getline(std::cin, student_LastName);

		std::cout << "Enter Course" << std::endl;
		std::getline(std::cin, student_course);

		std:: cout << "Data has been added succesfully" << std::endl;
	}	
	

	void list(std::vector<Students::c_students> &s_list)
	{
		int counter = 0;
		for(int i=0  ;i <s_list.size() ; i++)
		{
			std::cout << "Index :" << counter << std::endl;
			std::cout << "First Name: " << s_list[i].student_FirstName << std::endl;
			std::cout <<  "Last Name: " << s_list[i].student_LastName << std::endl;
			std::cout << "Course: " << s_list[i].student_course << std::endl;
			std::cout << "\n";
			counter++;
		}
		
	}


	// modify student data function
	void set_Firstname()
	{
		std::cout << "Enter a new first name"<<std::endl;
		std::string newName;
		std::getline(std::cin, newName);
		student_FirstName = newName;
	}

	void set_LastName()
	{
		std::cout << "Enter a last name" << std::endl;
		std::string newLastName;
		std::getline(std::cin, newLastName);
		student_LastName = newLastName;
	}
	void set_Course()
	{
		std::cout << "Enter a new course" << std::endl;
		std::string newCourse;
		std::getline(std::cin, newCourse);
		student_course = newCourse;
	}
	void modify(std::vector<Students::c_students> &mod_students, int index)
	{
		std::cout << "Enter 1: To modify student firstname\n"
		              "Enter 2: to modify student lastname\n" 
					   "Enter 3: to modify student course\n";
		int num;
		std::cin>>num;
		std::cin.ignore(1000, '\n'); // escape newline
		switch(num)
		{
			case FIRST_NAME:
			mod_students[index].set_Firstname();
			break;
			
			case LAST_NAME:
			mod_students[index].set_LastName();
			break;

			case COURSE:
			mod_students[index].set_Course();
			break;
		}
		std::cout<<"Updated data" << std::endl;
		for(int i=0; i<mod_students.size(); i++)
		{
			std::cout << "First Name: " << mod_students[i].student_FirstName << std::endl;
			std::cout <<  "Last Name: " << mod_students[i].student_LastName << std::endl;
			std::cout << "Course: " << mod_students[i].student_course << std::endl;
			std::cout << "\n";
		}
	}

	void del(std::vector<Students::c_students> &del_students, int index)
	{
		if(index >= 0 && index < del_students.size())
		{
			/*// the .begin() will return a iterator pointer the beginning of the array. 
			by adding index numbers his effectively moves the iterator to the desired index in the vector.*/
			del_students.erase(del_students.begin() + index);
		
		}
		else
		{
			std::cout << "Invalid Index. " << std::	endl;
		}
		
	}

	private:
	std::string student_FirstName;
	std::string student_LastName;
	std::string student_course;
	int student_age;

	};
}

int main()
{	
	bool prog_is_running = true;
	int input; // user input
	Students::c_students students; // class object
	std::vector<Students::c_students> studentLists;
	while(prog_is_running)
	{
			std::cout << "1. ADD    RECORDS \n" 
	             "2. LIST   RECORDS \n"
				 "3. MODIFY RECORDS\n"
				 "4. DELETE RECORDS\n"
				 "5. EXIT   PROGRAM"<< std::endl;	
	std::cin>> input;
	std::cin.ignore(1000, '\n'); // escape newline
	switch(input)
	{
		case ADD:
		students.add();
		studentLists.push_back(students); // pushing newly creating object into the vector
		input = 0; // resetting user input
		break;

		case LIST:
		students.list(studentLists); // outputting the student list
		input = 0;
		break;

		case MODIFY:

		std::cout << "Printer the index you want to modify: " << std::endl;
		int index;
		std::cin >> index;
		students.modify(studentLists, index);
		break;

		case DELETE:
		std::cout << "Enter the index you want to delete : " << std::endl;
		int index_del;
		std::cin >> index_del;
		students.del(studentLists, index_del);
		break;

		case EXIT:
		printf("***************************************\n");
        printf("************* THANK YOU ***********\n");
        printf("***************************************\n");
		prog_is_running = false;
		break;
	} // end of swtich
		
	} // end of while loop
	return 0;
}


	