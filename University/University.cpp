#include <iostream>
#include <vector>
using namespace std;

class Department
{
private:
    string name;
    int capacity;
    float requiredGpa;
public:
    Department() {}
    Department(string name, int capacity, float requiredGpa)
        : name(name), capacity(capacity), requiredGpa(requiredGpa) {}
    void setName(string name)
    {
        this->name;
    }
    string getName()
    {
        return name;
    }
    void setCapacity(int capacity)
    {
        this->capacity;
    }
    int getCapacity()
    {
        return capacity;
    }
    void setRequiredGpa(float requiredGpa)
    {
        this->requiredGpa;
    }
    float  getRquiredGpa()
    {
        return requiredGpa;
    }
};

class Person
{
protected:
    int id, age;
    string name;
    char gender;

public:
    Person() {}
    Person(int id, string name, int age, char gender)
    {
        this->id = id;

        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
    void setGender(char gender)
    {
        this->gender = gender;
    }
    char getGender()
    {
        return gender;
    }

};
class Student : public Person
{
private:
    int level;
    double gpa;

public:

    Student()
    {


    }
    Student(int id, string name, int age, char gender, int level, double gpa)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->level = level;
        this->gpa = gpa;
    }
    void setLevel(int level)
    {
        this->level = level;
    }
    int getLevel()
    {
        return level;
    }
    void setGpa(double gpa)
    {
        this->gpa = gpa;
    }
    double getGpa()
    {
        return gpa;
    }

};

class Professor :public Person
{
private:

    Department* dept;
    double salary;
    string degree;
public:
    Professor() {}
    Professor(int id, string name, int age, char gender, Department* dept, double salary, string degree)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        this->gender = gender;
        this->dept = dept;
        this->salary = salary;
        this->degree;

    }

    void setDepartment(Department* dept)
    {
        this->dept = dept;
    }
    Department* getDepartment()
    {
        return dept;
    }
    void setSalary(double salary)
    {
        this->salary;
    }
    double getSalary()
    {
        return salary;
    }
    void setDegree(string degree)
    {
        this->degree;
    }
    string getDegree()
    {
        return degree;
    }


};
class Course
{
private:
    string  courseName;
    double courseHours; //update
    string courseCode;
    vector<Course*> prerequisites;
    Professor* professor;
    vector<Student*> students; //registered students at the course
public:
    Course() {} //default constructor
    Course(string n, string c, double h, vector<Course*> prerequisites, Professor* p, vector<Student*> students)   //parameterized constructor
    {
        courseName = n;
        courseHours = h;
        courseCode = c;
        this->professor = p;
        this->students = students;  // Constructor to initialize the vector
        this->prerequisites = prerequisites;  // Constructor to initialize the vector

    }
    // setters & getters
    void setCourseName(string n)
    {
        courseName = n;
    }
    string getCourseName()
    {
        return  courseName;
    }
    void setCourseHours(double h)
    {
        courseHours = h;
    }
    double getCourseHours()
    {
        return courseHours;
    }
    void setCourseCode(string c)
    {
        courseCode = c;
    }
    string getCourseCode()
    {
        return courseCode;
    }
    void setProf(Professor* p)
    {
        this->professor = p;
    }
    Professor* getProf()
    {
        return professor;
    }
    void setStudents(vector<Student*> students)
    {
        this->students = students;
    }
    vector<Student*> getStudents()
    {
        return students;
    }
    void setPrerequisites(vector<Course*> prerequisites)
    {
        this->prerequisites = prerequisites;
    }
    vector<Course*> getPrerequisites()
    {
        return prerequisites;
    }

};




class University
{
private:
    vector<Department> departments;
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;

    static University* instancePtr;
    University()
    {
        addData();

    }
public:
    University(const University& obj) = delete;
    static University* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new University();
            return instancePtr;
        }
        else
        {
            return instancePtr;
        }
    }
    void addDepartment(string name, int capacity, double requiredGpa)
    {
        Department department(name, capacity, requiredGpa);
        departments.push_back(department);
    }
    void updateDepartment(string name, int capacity)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].getName() == name)
            {
                departments[i].setCapacity(capacity);
                return;
            }
        }
        cout << "No department with this name exists" << endl;
    }
    void removeDepartment(string name)
    {
        for (int i = 0; i < departments.size(); i++)
        {
            if (departments[i].getName() == name)
            {
                departments.erase(departments.begin() + i);
                return;
            }
        }
        cout << "No department with this name exists" << endl;
    }

    void addStudent(int id, string name, int age, char gender, int level, double gpa)
    {
        Student s(id, name, age, gender, level, gpa);
        students.push_back(s);

    }
    bool updateStudent(int id, double gpa)
    {

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {

                students[i].setGpa(gpa);
                return true;
            }

        }

    }
    bool removeStudent(int id)
    {

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {

                students.erase(students.begin() + i);

                return true;
            }
        }

    }
    void addProfessor(int id, string name, int age, char gender, Department* department, double salary, string degree)
    {
        Professor professor(id, name, age, gender, department, salary, degree);
        professors.push_back(professor);
    }
    void updateProfessor(int id, double salary)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].getId() == id)
            {
                professors[i].setSalary(salary);
                return;
            }
        }
        cout << "No professor with this id exists" << endl;
    }
    void removeProfessor(int id)
    {
        for (int i = 0; i < professors.size(); i++)
        {
            if (professors[i].getId() == id)
            {
                professors.erase(professors.begin() + i);
                return;
            }
        }
        cout << "No professors with this id exists" << endl;
    }
    void addCourse(string name, string code, double hour, Professor* prof, vector<Student*> students, vector<Course*> prerequisites)
    {
        {
            Course c(name, code, hour, prerequisites, prof, students);
            courses.push_back(c);

        }
    }
    bool updateCourse(double courseHours, string courseCode)
    {

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseCode() == courseCode)
            {
                courses[i].setCourseHours(courseHours);
                return true;
            }
        }


    }

    bool removeCourse(string courseCode)
    {

        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseCode() == courseCode)
            {
                courses.erase(courses.begin() + i);
                return true;
            }
        }
    }
    void addData()
    {
        Department d1("Web Development", 50, 3.2);
        departments.push_back(d1);
        Department d2("Cyber Security", 33, 3.5);
        departments.push_back(d2);
        Department d3("Artificial Intelligence", 20, 3.0);
        departments.push_back(d3);
        Department d4("Information Systems", 125, 2.5);
        departments.push_back(d4);

        Student s1(1, "Ahmed Ali", 19, 'M', 2, 2.74);
        students.push_back(s1);
        Student s2(2, "Mirna Hussein", 22, 'F', 4, 3.68);
        students.push_back(s2);
        Student s3(3, "Hamada Hossam", 28, 'M', 3, 2.37);
        students.push_back(s3);
        Student s4(4, "Taghreed Mohsen", 20, 'F', 3, 3);
        students.push_back(s4);
        Student s5(5, "Yasmin Belal", 18, 'F', 1, 3.71);
        students.push_back(s5);
        Student s6(6, "Amr Diab", 50, 'M', 4, 2.01);
        students.push_back(s6);
        Student s7(7, "Tamer Hosny", 30, 'M', 3, 2.02);
        students.push_back(s7);
        Student s8(8, "Ahmed Alaa", 21, 'M', 2, 2.49);
        students.push_back(s8);

        Professor p1(1, "Mohamed Ali", 56, 'M', &d1, 12000, "Masters");
        professors.push_back(p1);
        Professor p2(2, "Ehsan Ahmed", 43, 'M', &d2, 8500, "Masters");
        professors.push_back(p2);
        Professor p3(3, "Ahmed Mohsen", 68, 'M', &d3, 19380, "Masters");
        professors.push_back(p3);
        Professor p4(4, "Abdelhady", 61, 'M', &d4, 22728, "Masters");
        professors.push_back(p4);
        Professor p5(5, "Taghreed Mohsen", 49, 'F', &d2, 11068, "Masters");
        professors.push_back(p5);


        vector<Student*> st1;
        st1.push_back(&s1);
        st1.push_back(&s2);
        st1.push_back(&s3);
        st1.push_back(&s4);
        vector<Student*> st2;
        st2.push_back(&s5);
        st2.push_back(&s6);
        st2.push_back(&s7);
        st2.push_back(&s8);
        Course c1("HTML", "HTML123", 12, vector<Course*>(), &p1, st1);
        courses.push_back(c1);
        vector<Course*> crs1;
        crs1.push_back(&c1);
        Course c2("CSS", "CSS123", 9, crs1, &p3, st2);
        courses.push_back(c2);
        Course c3("Networks", "Net521", 18, crs1, &p5, st2);
        courses.push_back(c3);
    }

    void printAll()
    {
        for (int i = 0; i < departments.size(); i++)
        {
            cout << "Department: " << departments[i].getName() << endl;
        }
        for (int i = 0; i < professors.size(); i++)
        {
            cout << "Professor Name: " << professors[i].getName() << endl;
        }
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Student Name: " << students[i].getName() << endl;
        }
        for (int i = 0; i < courses.size(); i++)
        {
            cout << "Course Name: " << courses[i].getCourseName() << endl;
        }
    }

};

University* University::instancePtr = NULL;




int main()
{
    University* u = University::getInstance();
    u->printAll();
    u->removeCourse("Net521");
    u->printAll();

    return 0;

}
